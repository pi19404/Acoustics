#include "common.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "math.h"
#include "common.h"
#include <string.h>
#include <stdlib.h>
#include <c6x.h>
#include "ti/ndk/inc/netmain.h"
#include "hpdspua.h"
#ifdef C66_PLATFORMS
#include "csl_cpsw_3gfAux.h"
#endif

#include <c6x.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ti/sysbios/hal/Hwi.h>
#include <cerrno>
#include <ti/sysbios/BIOS.h>
#include <ti/bios/include/swi.h>
#include "ti/platform/platform.h"
#include "ti/platform/resource_mgr.h"
#include "ti/platform/evmc6670l/platform_lib/include/platform_internal.h"


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <errno.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Version String */
char *VerStr = BLM_VERSION;

/**************************************************************************
** IP Stack - NDK Routines
***************************************************************************/

void acquire_data();
void compute_data();
void dis_data();
SOCKET   stcp = INVALID_SOCKET;


/* Our NETCTRL callback functions */
static void   NetworkOpen();
static void   NetworkClose();
static void   NetworkIPAddr( IPN IPAddr, uint32_t IfIdx, uint32_t fAdd );

/*  Reporting function - IP stack calls it to give us updates */
static void   ServiceReport( uint32_t Item, uint32_t Status, uint32_t Report, HANDLE hCfgEntry );


char  HostName[CFG_HOSTNAME_MAX];       // Host name we will use in a DHCP Request
char *LocalIPAddr = "0.0.0.0";          // Set to "0.0.0.0" for DHCP client option
char *PCStaticIP  = "192.168.2.101";    // Static IP address for host PC
char *EVMStaticIP = "192.168.2.100";    //    "   IP     "   for EVM
char *LocalIPMask = "255.255.255.0";    // Mask for DHCP Server option
char *GatewayIP   = "192.168.2.100";    // Not used when using DHCP
char *DomainName  = "demo.net";         // Not used when using DHCP
char *DNSServer   = "0.0.0.0";          // Used when set to anything but zero

HANDLE            hCfg;                 // Handle to our IP stack configuration

#ifdef INCLUDE_TELNET_SERVICE
CI_SERVICE_TELNET telnet;               // Configuration data for telnet including handle
#endif
CI_SERVICE_HTTP   http;                 // Configuration data for http including handle
CI_SERVICE_DHCPC dhcpservice;           // Configuration data for dhcp client including handle

uint8_t DHCP_OPTIONS[] = { DHCPOPT_SERVER_IDENTIFIER, DHCPOPT_ROUTER };

/* Platform Information - we will read it form the Platform Library */
platform_info   gPlatformInfo;

/* Status of the call to initialize the platform */
int32_t pform_status;

void compute_time_diff();

#define MAX_SAMPLES 300
#define NEGATIVE_VALUE_MARGIN 9000
#define FULL_SCALE_VALUE 16383
#define THRESHOLD_VALUE 200  //For FPGA program (3.3V pulse (5406 value in ADC)); has to be set accordingly
#define DSP_clockcycles_persec 1474600000
#define fc 22000
#define SAMPLING_FREQUENCY 100000   //100kSPS for each channel
#define SAMPLING_TIME 1/SAMPLING_FREQUENCY
#define PULSE_TIME 0.004
#define PI 3.141592
#define PING_DELAY 2
#define sound_speed 1497
#define PULSE_SAMPLE (int)(PING_DELAY*SAMPLING_FREQUENCY)  //200000 samples

int log_flag=1;
int FILTER_SAMPLE=270;//(int)(PULSE_TIME*SAMPLING_FREQUENCY);   //400 samples
//int FILTER_SAMPLE_A=0,FILTER_SAMPLE_B=0;
int data_bufferA[PULSE_SAMPLE],data_bufferB[PULSE_SAMPLE],data_buffer[2*14*PULSE_SAMPLE];//sample_databuffer[28];
double sumA=0, sumB=0, cos_theta, angle, time_diff;
float distance=0.4;  //in meters
int i,j, led_no, signalA_tstart, signalB_tstart, data_index, interrupt_call_count = 0, number_of_cores=0;
volatile int flag=0,data_bit=1;

unsigned int product_result=0;

//For timer
unsigned int tscl_val, tsch_val;
long long elapsed_time;

void compute_time_diff();
void acquire_data();
void compute_data();

#define LOG_COUNT 5
#define MAX_SAMPLES 300
#define NEGATIVE_VALUE_MARGIN 9000
#define FULL_SCALE_VALUE 16383
#define THRESHOLD_VALUE 200  //For FPGA program (3.3V pulse (5406 value in ADC)); has to be set accordingly
#define DSP_clockcycles_persec 1474600000
#define fc 22000
#define SAMPLING_FREQUENCY 100000   //100kSPS for each channel
#define SAMPLING_TIME 1/SAMPLING_FREQUENCY
#define PULSE_TIME 0.004
#define PI 3.141592
#define PING_DELAY 2
#define sound_speed 1497
#define PULSE_SAMPLE (int)(PING_DELAY*SAMPLING_FREQUENCY)  //200000 samples



//For timer
unsigned int tscl_val, tsch_val;
long long elapsed_time;


typedef struct _IMG_STORE_REQST_TYP {   /* Image Store Request Structure */
    int hydrophone;                     /* Image Type */
    int number;                     /* numbers of pages */
} IMG_STORE_REQST_TYP;

#define RECORD_SIZE (sizeof(tLogRecord) + ((NUM_LOG_ITEMS - 1) * 1))

#pragma DATA_SECTION(next, ".sharedVar")
#pragma DATA_ALIGN (next, 128)
typedef union
{
	uint32_t core;
	uint8_t padding[128];
} n;

n next;





/*************************************************************************
 * main()
 * Entry point for the application.
 ************************************************************************/
int main()
{
    /* Start the BIOS 6 Scheduler - it will kick off our main thread ledPlayTask() */
    platform_write("Start BIOS 6\n");

    BIOS_start();
}


/*************************************************************************
 * EVM_init()
 * Initialises the platform hardware. This routine is configured to start in
 * the evm.cfg configuration file. It is the first routine that BIOS
 * calls and is executed before Main is called. If you are debugging within
 * CCS the default option in your target configuration file may be to execute
 * all code up until Main as the image loads. To debug this you should disable
 * that option.
 ************************************************************************/
void
write_uart
(
 char*      msg
 )
{
    uint32_t i;
    uint32_t msg_len = strlen(msg);

    /* Write the message to the UART */
    for (i = 0; i < msg_len; i++)
    {
        platform_uart_write(msg[i]);
    }
}
void EVM_init()
{
    platform_init_flags sFlags;
    platform_init_config sConfig;
    int32_t pform_status;
    platform_info    sPlatformInfo;

    /* Initialise the UART
     * You can choose what to initialise on the platform by setting the following
     * flags. Things like the DDR, PLL, etc should have been set by the boot loader.
     */
    memset( (void *) &sFlags, 0, sizeof(platform_init_flags));
    memset( (void *) &sConfig, 0, sizeof(platform_init_config));

    sFlags.pll = 0; /* PLLs for clocking */
    sFlags.ddr = 1; /* External memory */
    sFlags.tcsl = 1; /* Time stamp counter */
    sFlags.phy = 1; /* Ethernet */
    sFlags.ecc = 0; /* Memory ECC */
    sConfig.pllm = 0; /* Use libraries default clock divisor */

    pform_status = platform_init(&sFlags, &sConfig);

    /* If we initialised the platform okay */
    if (pform_status != Platform_EOK) {
        /* Initialisation of the platform failed... die */
        platform_write("Platform failed to initialise. Error code %d \n", pform_status);
        platform_write("We will die in an infinite loop... \n");
        while (1) {
            (void) platform_led(1, PLATFORM_LED_ON, PLATFORM_USER_LED_CLASS);
            (void) platform_delay(50000);
            (void) platform_led(1, PLATFORM_LED_OFF, PLATFORM_USER_LED_CLASS);
            (void) platform_delay(50000);
        }
    }

    memset( (void *) &sPlatformInfo, 0, sizeof(platform_info));
    platform_get_info(&sPlatformInfo);
    memset( (void *) &sPlatformInfo, 0, sizeof(platform_info));
       //platform_get_info(&sPlatformInfo);
       platform_get_info(&gPlatformInfo);
    number_of_cores = sPlatformInfo.cpu.core_count;
    platform_write(sPlatformInfo.board_name);
    platform_uart_init();
    platform_uart_set_baudrate(115200);

    platform_write_configure (PLATFORM_WRITE_ALL);
    //write_uart("\r\n\r\nBooting Hello World image from NAND flash via IBL over I2C 0x51 ...");

    //MultiProc_setLocalId((Uint16) platform_get_coreid());

    return;
}


/*****************************************************************************
*
* Function: Converts a core local L2 address to a global L2 address
*   Input addr:  L2 address to be converted to global.
*   return:  uint32_t   Global L2 address
*
*****************************************************************************/

uint32_t convert_CoreLocal2GlobalAddr (uint32_t addr) {

 uint32_t coreNum;

 /* Get the core number. */
 coreNum = CSL_chipReadReg(CSL_CHIP_DNUM);

 /* Compute the global address. */
 return ((1 << 28) | (coreNum << 24) | (addr & 0x00ffffff));

}

/*************************************************************************
 * ledPlayTask()
 *
 * This is the main task for the example. It will write send text
 * messages to both the console and the UART using platform_write and then
 * twinkle the LEDs. This task is configured to start in led_play.cfg
 * configuration file and it is called from BIOS.
 *
 ************************************************************************/

void nullsrv()
{

    SOCKET   stcpactive = INVALID_SOCKET;
    struct   sockaddr_in sin1;
    struct   timeval timeout;           // Timeout struct for select
    int      size;
    int      cnt;
    char     *pBuf;
    HANDLE   hBuffer;

    //gpioEnableGlobalInterrupt();
    // Allocate the file environment for this task
    fdOpenSession( TaskSelf() );


    TaskSleep(30000);
    platform_write("Raw Eth Task Started ... \n");
    // Create the main TCP listen socket
    platform_write("creating main TCP listen socket\n");

    int k=0;
        int n=0;
       IMG_STORE_REQST_TYP a;
            a.number=PULSE_SAMPLE*sizeof(int);
            int *data;//(int *)malloc(sizeof(int)*a.number+1);
            //int *data1=(int *)malloc(sizeof(int)*a.number+1);
            int *orig=data;
           //int *orig2=data1;
           int i1;
           for(;;)
           {

                   acquire_data();
                   compute_data();
                   //dis_data();

                   for(k=0;k<2;k++)
                   {
                    if(k==0)
                    data=&data_bufferA[0];
                    else
                    data=&data_bufferB[0];
                   //WWdis_data();
                        stcp = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
                       if( stcp == INVALID_SOCKET )
                       {
                           int ret=fdError();

                           goto leave;

                       }


        timeout.tv_sec  = 30;
        timeout.tv_usec = 0;
        setsockopt( stcp, SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof( timeout ) );
        setsockopt( stcp, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof( timeout ) );

        platform_write("created main TCP client socket\n");
        // Set Port = 1001, leaving IP address = Any
        bzero( &sin1, sizeof(struct sockaddr_in) );
        sin1.sin_family = AF_INET;
        sin1.sin_addr.s_addr =inet_addr(PCStaticIP);
        sin1.sin_port   = htons(7000);
        sin1.sin_len    = sizeof( sin1 );




        platform_write("LLL %d \n",(sin1.sin_addr.s_addr));



              if( connect(stcp, (struct sockaddr *) &sin1, sizeof(sin1)) < 0)
              {
                  perror("ERROR connect to socket");
                  platform_write("Fail connect, %d\n", fdError());
                  platform_write("Writing error string %s",strerror(fdError()));
                  continue;
              }
          platform_write("completed connect \n");
         a.hydrophone=k;
         n=0;
            n = send(stcp,&a,sizeof(a),0);
              if (n < 0)
              {
                  perror("ERROR writing to socket");
                  continue;
              }


              platform_write("writing hydrophone %d,bytes %d\n",k,a.number);

                n=0;
                int c=0;
                //platform_write("writing %s  \n",data);
                do
                {
                n = send(stcp,data,a.number-c,0);
                //platform_write("writing %d bytes \n",n);
                  if (n < 0)
                  {
                      perror("ERROR writing to socket");
                      continue;
                  }
                  c=c+n;
                  data=data+n;
                }while(c<a.number);
                if (n < 0)
                    continue;
                //free(orig);
                int status;
                HANDLE hbuffer;
                n = recv(stcp, &status, sizeof(status),0);

                if(status==0)
                {
                    platform_write("Client request success\n");
                }
                else
                {
                    platform_write("Client request error");
                    continue;
                }
                if( stcp != INVALID_SOCKET )
                fdClose(stcp);


             }
               //TaskSleep(5);



    }

leave:

    TaskSleep(5000);
    // We only get here on an error - close the sockets
  //  if( stcp != INVALID_SOCKET )
    //    fdClose( stcp );

    platform_write("NullSrv Fatal Error\n");

//    NetworkClose((HANDLE)TaskSelf());
    // This task is killed by the system - here, we block
    //TaskBlock( TaskSelf() );
}

static HANDLE hSendRaw = 0;
static void NetworkOpen()
{

     hSendRaw = TaskCreate( nullsrv, "TxRawEthTsk", OS_TASKPRINORM, 0x1400, 0, 0, 0 );
    //hEcho = DaemonNew( SOCK_STREAMNC, 0, 7, nullsrv,
    //                       OS_TASKPRINORM, OS_TASKSTKNORM, 0, 3 );


}
static void NetworkClose()
{

    if( stcp != INVALID_SOCKET )
        fdClose( stcp );
    return;
}

static void NetworkIPAddr( IPN IPAddr, uint32_t IfIdx, uint32_t fAdd )
{
    static uint32_t fAddGroups = 0;
    IPN             IPTmp;

    if( fAdd )
        platform_write("Network Added: ");
    else
        platform_write("Network Removed: ");

    /* Print a message */
    IPTmp = ntohl( IPAddr );
    platform_write("If-%d:%d.%d.%d.%d \n", IfIdx,
            (uint8_t)(IPTmp>>24)&0xFF, (uint8_t)(IPTmp>>16)&0xFF,
            (uint8_t)(IPTmp>>8)&0xFF, (uint8_t)IPTmp&0xFF );


    /* This is a good time to join any multicast group we require */
    if( fAdd && !fAddGroups )
    {
        fAddGroups = 1;
/*      IGMPJoinHostGroup( inet_addr("224.1.2.3"), IfIdx ); */
    }

    return;
}

int hpdspuaStart (void) {

	   uint32_t coreId;
	   QMSS_CFG_T      qmss_cfg;
	      CPPI_CFG_T      cppi_cfg;
	   /* determine the core number. */
	      coreId = CSL_chipReadReg (CSL_CHIP_DNUM);
	      led_no=coreId;

	      platform_write("num of cores  %d starts twinkling its LED\n", number_of_cores);
	      platform_write("core = %d starts twinkling its LED\n", coreId);
	      //platform_uart_init();
	      //platform_uart_set_baudrate(115200);
//	      write_uart("AAAAAAAA");
	      gpioInit();
	      gpioSetDirection(GPIO_7 ,GPIO_IN);   //DOUTA pin
	      gpioSetDirection(GPIO_3 ,GPIO_OUT);   //CNVST pin
	      gpioSetDirection(GPIO_13 ,GPIO_OUT);  //CS pin
	      gpioSetDirection(GPIO_10 ,GPIO_OUT);  //SCLK

	      //ADDR = 0, VA1 and VB1 are sampled;  ADDR =1, VA2 and VB2 are sampled
	      //Right now VA1 and VB1 are being sampled
	      gpioSetOutput(GPIO_10);   //By default clock high
	      gpioSetOutput(GPIO_3);   // by default conversion pin high
	      gpioSetOutput(GPIO_13);   // BY Default CS pin high

          gpioSetFallingEdgeInterrupt(GPIO_7);
          gpioSetRisingEdgeInterrupt(GPIO_7);
	  	  gpioEnableGlobalInterrupt();

	  	  //Wait for 100us before starting first conversion
	      platform_delay(100);
	      int rc=0;
	      while(1) {
		    if(coreId==0)
		    {



		    	    if (platform_get_coreid() == 0)
		    	    {
		    	        qmss_cfg.master_core        = 1;
		    	    }
		    	    else
		    	    {
		    	        qmss_cfg.master_core        = 0;
		    	    }
		    	    qmss_cfg.max_num_desc       = MAX_NUM_DESC;
		    	    qmss_cfg.desc_size          = MAX_DESC_SIZE;
		    	    qmss_cfg.mem_region         = Qmss_MemRegion_MEMORY_REGION0;
		    	    if (res_mgr_init_qmss (&qmss_cfg) != 0)
		    	    {
		    	        platform_write ("Failed to initialize the QMSS subsystem \n");
		    	        goto main_exit;
		    	    }
		    	    else
		    	    {
		    	        platform_write ("QMSS successfully initialized \n");
		    	    }


		    	    if (platform_get_coreid() == 0)
		    	    {
		    	        cppi_cfg.master_core        = 1;
		    	    }
		    	    else
		    	    {
		    	        cppi_cfg.master_core        = 0;
		    	    }
		    	    cppi_cfg.dma_num            = Cppi_CpDma_PASS_CPDMA;
		    	    cppi_cfg.num_tx_queues      = NUM_PA_TX_QUEUES;
		    	    cppi_cfg.num_rx_channels    = NUM_PA_RX_CHANNELS;
		    	    if (res_mgr_init_cppi (&cppi_cfg) != 0)
		    	    {
		    	        platform_write ("Failed to initialize CPPI subsystem \n");
		    	        goto main_exit;
		    	    }
		    	    else
		    	    {
		    	        platform_write ("CPPI successfully initialized \n");
		    	    }


		    	    if (res_mgr_init_pass()!= 0) {
		    	        platform_write ("Failed to initialize the Packet Accelerator \n");
		    	        goto main_exit;
		    	    }
		    	    else
		    	    {
		    	        platform_write ("PA successfully initialized \n");
		    	    }



		    	    rc = NC_SystemOpen( NC_PRIORITY_HIGH, NC_OPMODE_INTERRUPT );

		    	    if( rc ) {
		    	        platform_write("NC_SystemOpen Failed (%d). Will die in an infinite loop so you need to reset...\n",rc);
		    	        for(;;);
		    	    }

		    	    platform_write("HUA version %s\n", BLM_VERSION);

		    	        hCfg = CfgNew();
		    	    if( !hCfg )
		    	    {
		    	        platform_write("Unable to create a configuration for the IP stack.\n");
		    	        goto main_exit;
		    	    }


		    	    strcpy (HostName, "tidemo-");
		    	    i = strlen(HostName);
		    	    j = strlen(gPlatformInfo.serial_nbr);

		    	    if (j > 0) {
		    	        if (j > 6) {
		    	            memcpy (&HostName[i], &gPlatformInfo.serial_nbr[j-6], 6);
		    	            HostName[i+7] = '\0';
		    	        }
		    	        else {
		    	            memcpy (&HostName[i], gPlatformInfo.serial_nbr, j);
		    	            HostName[i+j+1] = '\0';
		    	        }
		    	    }


		    	    if( strlen( DomainName ) >= CFG_DOMAIN_MAX ||
		    	        strlen( HostName ) >= CFG_HOSTNAME_MAX )
		    	    {
		    	        platform_write("Domain or Host Name too long\n");
		    	        goto main_exit;
		    	    }

		    	    platform_write("Setting hostname to %s \n", HostName);

		    	    platform_write("MAC Address: %02X-%02X-%02X-%02X-%02X-%02X \n",
		    	            gPlatformInfo.emac.efuse_mac_address[0], gPlatformInfo.emac.efuse_mac_address[1],
		    	            gPlatformInfo.emac.efuse_mac_address[2], gPlatformInfo.emac.efuse_mac_address[3],
		    	            gPlatformInfo.emac.efuse_mac_address[4], gPlatformInfo.emac.efuse_mac_address[5]);

		    	    CfgAddEntry( hCfg, CFGTAG_SYSINFO, CFGITEM_DHCP_HOSTNAME, 0,
		    	                 strlen(HostName), (uint8_t *)HostName, 0 );

		    	    if (!platform_get_switch_state(1)) {

		    	        CI_IPNET NA;
		    	        CI_ROUTE RT;
		    	        IPN      IPTmp;
		    	        bzero( &NA, sizeof(NA) );
		    	        NA.IPAddr  = inet_addr(EVMStaticIP);
		    	        NA.IPMask  = inet_addr(LocalIPMask);
		    	        strcpy( NA.Domain, DomainName );


		    	        CfgAddEntry( hCfg, CFGTAG_IPNET, 1, 1, sizeof(CI_IPNET), (uint8_t *)&NA, 0 );

		    	        bzero( &RT, sizeof(RT) );
		    	        RT.IPDestAddr = inet_addr(PCStaticIP);
		    	        RT.IPDestMask = inet_addr(LocalIPMask);
		    	        RT.IPGateAddr = inet_addr(GatewayIP);

		    	        CfgAddEntry( hCfg, CFGTAG_ROUTE, 0, 1, sizeof(CI_ROUTE), (uint8_t *)&RT, 0 );


		    	        platform_write("EVM in StaticIP mode at %s\n",EVMStaticIP);
		    	        platform_write("Set IP address of PC to %s\n", PCStaticIP);
		    	    }




		    	       rc = DBG_WARN;
		    	    CfgAddEntry( hCfg, CFGTAG_OS, CFGITEM_OS_DBGPRINTLEVEL,
		    	                 CFG_ADDMODE_UNIQUE, sizeof(uint), (uint8_t *)&rc, 0 );

		    	       rc = 64000;
		    	    CfgAddEntry( hCfg, CFGTAG_IP, CFGITEM_IP_SOCKTCPTXBUF,
		    	                 CFG_ADDMODE_UNIQUE, sizeof(uint), (uint8_t *)&rc, 0 );

		    	    rc = 64000;
		    	    CfgAddEntry( hCfg, CFGTAG_IP, CFGITEM_IP_SOCKTCPRXBUF,
		    	                 CFG_ADDMODE_UNIQUE, sizeof(uint), (uint8_t *)&rc, 0 );

		    	    rc = 64000;
		    	    CfgAddEntry( hCfg, CFGTAG_IP, CFGITEM_IP_SOCKTCPRXLIMIT,
		    	                 CFG_ADDMODE_UNIQUE, sizeof(uint), (uint8_t *)&rc, 0 );

		    	    rc = 8192;
		    	    CfgAddEntry( hCfg, CFGTAG_IP, CFGITEM_IP_SOCKUDPRXLIMIT,
		    	                 CFG_ADDMODE_UNIQUE, sizeof(uint), (uint8_t *)&rc, 0 );


		    	    do
		    	    {
		    	        rc = NC_NetStart( hCfg, NetworkOpen, NetworkClose, NetworkIPAddr );
		    	    } while( rc > 0 );



		    	    platform_write("Done with this utility. Shutting things down\n");





		    	    CfgFree( hCfg );


		    	main_exit:
		    	    platform_write("Exiting the system\n");
		    	    //NC_SystemClose();
		    	    TaskExit();
		    	    return(0);


		    }
		    else
		    {
		    	while(1)
		    	{
		    		platform_write("done processing .exiting core %d \n", coreId);
		    		platform_delay(300000);
		    		break;
		    	}
		    	platform_delay(300000);
		    	break;
		    }
	 }

	 platform_write("done processing .exiting core %d", coreId);

	 platform_delay(3000000);
	 return 0;
}



void hwiGPIOnFunc(UArg arg)
{
	interrupt_call_count++;
	if(interrupt_call_count<2)      //To avoid multiple entries in ISR within one clock cycle
	{
	if(data_bit==0)
		data_bit=1;
	else
		data_bit=0;
	}
	return;
}


void compute_time_diff()
{
//	if(FILTER_SAMPLE_A>200 && FILTER_SAMPLE_B>200)  //To avoid very low counts which means not properly sampled
//	{
	//Initialise data buffer indices
	unsigned int filter_index, overall_index, max_index=0 , max_product=0;

	//Compute t start for signal A
	for(overall_index=0; overall_index<PULSE_SAMPLE-FILTER_SAMPLE; overall_index++)
	{
		product_result=0;

		for (filter_index=overall_index;filter_index<(overall_index+FILTER_SAMPLE);filter_index++) //compute for FILTER_SAMPLE_A samples
			product_result=product_result+data_bufferA[filter_index];  // filer[i] = 1 for all i

		if(product_result>max_product)
		{
			max_product=product_result;
			max_index=overall_index;
		}
	}

	platform_write("\nMax Product A: %d",max_product);
	platform_write("\nMax index for A: %d",max_index);
	signalA_tstart = max_index;

	max_index = 0;
	max_product = 0;

	//Compute t start for signal B
	for(overall_index=0; overall_index<PULSE_SAMPLE-FILTER_SAMPLE; overall_index++)
	{
		product_result=0;

		for (filter_index=overall_index;filter_index<(overall_index+FILTER_SAMPLE);filter_index++) //compute for FILTER_SAMPLE_B samples
			product_result=product_result+data_bufferB[filter_index];  // filer[i] = 1 for all i

		if(product_result>max_product)
		{
			max_product=product_result;
			max_index=overall_index;
		}
	}

	platform_write("\nMax Product B: %d",max_product);
	platform_write("\nMax index for B: %d",max_index);
	signalB_tstart = max_index;

	//Calculate time difference and heading angle
    if(abs(signalB_tstart-signalA_tstart)<MAX_SAMPLES)
    {
    	time_diff = (signalB_tstart-signalA_tstart)/(float)SAMPLING_FREQUENCY;  //Time diff in us
    	cos_theta = (time_diff*sound_speed)/distance;
    	angle = acos(cos_theta);
    	platform_write("\nTime difference: %lf micro seconds",(time_diff)*1000000);
    	platform_write("\nAngle (in degrees): %lf\n\n",(angle*180)/PI);
    }

//	FILTER_SAMPLE_A=FILTER_SAMPLE_B=0;
}




void acquire_data()
{
	//GPIO_3-CNVST,  GPIO_13-CS
	//Start the ADC communication
	for(data_index=0; data_index<PULSE_SAMPLE; data_index++)
	{
		//Pull CNVST low
		//platform_write("eeee");
		gpioClearOutput(GPIO_3);
		//platform_write("BBBB");
		//Wait for 50ns right now without any delay (10ns minimum)
		//Set CNVST high again
		gpioSetOutput(GPIO_3);
		//platform_write("CCCCC");
		platform_delaycycles(650); //Approximately 650 ns for 500 argument and 720ns for 600 argument
		//Pull CS pin low
		gpioClearOutput(GPIO_13);
		//platform_write("DDDDD");
		gpioSetOutput(GPIO_10);
		for(i=0; i<28; i++)
		{
				gpioClearOutput(GPIO_10);
				if(i==0 || i==14)
				{
					platform_delaycycles(100);
					//platform_write("AAAA");
					data_bit=gpioReadInput(GPIO_7);
					//platform_write("FFFFF");
				}
				else
					platform_delaycycles(60);

				data_buffer[28*data_index+i] = data_bit;

				gpioSetOutput(GPIO_10);
				//platform_write("GGGG");
				interrupt_call_count=0;
		}

		//Release CS pin
		gpioSetOutput(GPIO_13);
	}
}

void dis_data()
{
	uint32_t data_lengthB,data_lengthA;
	char data_resultA[10],data_resultB[10];
	//platform_uart_write('a');

	 // sprintf(boot_msg, "\r\n\r\nBooting Hello World image on Core %d from Core 0 ...", core);
	   //         write_uart("0");
	        //    platform_write("0");
	for(i=0; i<PULSE_SAMPLE; i++)
	{
			ltoa(data_bufferA[i], data_resultA);
			ltoa(data_bufferB[i], data_resultB);
			data_lengthA = strlen((char *)data_resultA);
			data_lengthB = strlen((char *)data_resultB);

			for (j = 0; j < data_lengthA; j++)
				platform_uart_write(data_resultA[j]);

			platform_uart_write(',');

			for (j = 0; j < data_lengthB; j++)
				platform_uart_write(data_resultB[j]);

			platform_uart_write(',');
	}

	platform_uart_write('\n');

}


void compute_data()
{
	int sig_start_A,sig_start_B,flag_A=1,flag_B=1;
	for(i=0; i<PULSE_SAMPLE; i++)
	{
		for(j=0,sumA=0; j<14; j++)
			sumA = sumA + pow(2,j)*data_buffer[28*i+13-j];

		if(sumA>NEGATIVE_VALUE_MARGIN)                //Means negative value
			data_bufferA[i] = sumA-FULL_SCALE_VALUE;  //Invert the value
		else
			data_bufferA[i] = sumA;

		for(j=14,sumB=0; j<28; j++)
			sumB = sumB + pow(2,j-14)*data_buffer[28*i+27+14-j];

		if(sumB>NEGATIVE_VALUE_MARGIN)                //Means negative value
			data_bufferB[i] = sumB-FULL_SCALE_VALUE;  //Invert the value
		else
			data_bufferB[i] = sumB;

//		if(data_bufferA[i]>THRESHOLD_VALUE)
//			FILTER_SAMPLE_A++;

//		if(data_bufferB[i]>THRESHOLD_VALUE)
//			FILTER_SAMPLE_B++;
//		if(data_bufferA[i]>100 && data_bufferB[i]>500)
		//platform_write("\ndata buffer A=%d, data buffer B=%d",data_bufferA[i],data_bufferB[i]);
/*		if((data_bufferA[i]>THRESHOLD_VALUE) && flag_A==1)
		{
			sig_start_A = i;
			flag_A=0;
		}
		if((data_bufferB[i]>THRESHOLD_VALUE) && flag_B==1)
		{
			sig_start_B = i;
			flag_B=0;
		}
	}
	if(abs(sig_start_B-sig_start_A)<100)
	{
		platform_write("\nsig_start_A=%d, sig_start_B=%d",sig_start_A,sig_start_B);
		time_diff = (sig_start_B-sig_start_A)/(float)SAMPLING_FREQUENCY;  //Time diff in us
	    cos_theta = (time_diff*sound_speed)/distance;
	    angle = acos(cos_theta);
	    platform_write("\nTime difference: %lf micro seconds",(time_diff)*1000000);
	    platform_write("\nAngle (in degrees): %lf\n\n",(angle*180)/PI);
	}
*/}
/*	for(i=0; i<2*14*PULSE_SAMPLE; i++)
	{
		platform_write("\nBit = %d", data_buffer[i]);
	}*/

}
