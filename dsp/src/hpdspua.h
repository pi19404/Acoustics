/*
 * Copyright (C) 2009-2011 Texas Instruments Incorporated - http://www.ti.com/
 * 
 *  Redistribution and use in source and binary forms, with or without 
 *  modification, are permitted provided that the following conditions 
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright 
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the 
 *    documentation and/or other materials provided with the   
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
*/

#ifndef _C_OOBDEMO_H
#define _C_OOBDEMO_H  /* #defined if this .h file has been included */
// C++ / C Function Declarations
#ifdef __cplusplus
#define _extern extern "C"
#define _externfar extern "C" far
#else
#define _extern extern
#define _externfar extern far
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include "netmain.h"
#include <_stack.h>
#include "cgiparse.h"
#include "cgiparsem.h"
#include "console.h"
#include "servers.h"
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/hal/Hwi.h>
#include <ti/bios/include/swi.h>
#include "platform.h"
#include "resource_mgr.h"
#include <stack/inc/nimuif.h>

#include <xdc/std.h>
#include <xdc/runtime/IHeap.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/Memory.h>
#include <xdc/runtime/Error.h>

#ifdef C665_PLATFORMS
#include "emac_drv.h"
#endif

/* Our version */
#define BLM_VERSION	"2.00.00.04"

/* Max size of a file that can be posted...
 *   including form fields and boundary markers!
 */
#define MAX_POST_FILESZ	 20000000

/*
 *  COFF MAGIC NUMBERS for checking COFF images
 */
#define COFF_MAGIC_0    0xc0      /* ORIGINAL VERSION OF COFF */
#define COFF_MAGIC_1    0xc1
#define COFF_MAGIC_2    0xc2

/*
 * The following defines are used for the Flash (for the older C64 Platforms)
 */
#define APP_MAGIC_NUM				(0xA1ACED11)		/* Magic number for a bootable image 		*/
#define START_BLOCK_NUM 			(1)					/* Block where we write the botoable image	*/

/* Image header for a boot image for Einfo chips baseline */
typedef struct _EI_NAND_BOOT_HEADER
{
	uint32_t uiMagic;			/* Magic number												*/
	uint32_t uiNumPage;		/* Number of pages where boot loader is stored 				*/
	uint32_t uiBlock;			/* starting block number where User boot loader is stored 	*/
	uint32_t uiPage;			/* starting page number where boot-loader is stored 		*/
} EI_NAND_BOOT_HEADER;


/* Address block for NAND */
typedef struct _FLASH_ADDRESS
{
  uint32_t block;			/* Block to write at */
  uint32_t page;			/* Page to write at  */
} FLASH_ADDRESS;


/* Holds information about the Platform we are running on */
extern platform_info	gPlatformInfo;

/*
 * Maximum number of Ethernet Ports on an EVM
 */
#ifdef C665_PLATFORMS
#define MAX_ETHERNET_PORTS  1
#else
#define MAX_ETHERNET_PORTS	2
#endif

/*
 *  Defines for dealing with IP services so we can report on the state of them.
 * See netcfg.h in the NDK and callback in hpdspua.c.
 */
typedef struct _service_state {
	char name[10];
	uint32_t report;
	uint32_t status;
}Service_state_s;
extern char *ReportStr[];
extern char *StatusStr[];
extern Service_state_s ServiceStatus[CFGITEM_SERVICE_MAX];

/* Populates or removes pages from the web server */
extern void AddWebFiles(void);
extern void RemoveWebFiles(void);

/* Standard HTML bits to use when building pages dynamically -- see webpages.c */
extern char *PAGEHEAD;
extern char *PAGEWRAPPER;
extern char *PAGEWRAPPERBACK;
extern char *PAGEFOOTER;	
extern char *MAINHDR;
extern char *HDR;
extern char *ROW_END;
extern char *ROW_START;

/* Buffer to hold our file uploads  */
extern uint8_t gRxBuffer[MAX_POST_FILESZ];

/* Routines that dynamically create pages -- done through the CGI interface */
extern int32_t serveInformationPage(SOCKET htmlSock, int32_t ContentLength, char *pArgs );
extern int32_t serveDiagnosticPage(SOCKET htmlSock, int32_t ContentLength, char *pArgs );
extern int32_t processDiagnosticRequest(SOCKET htmlSock, int32_t ContentLength, char *pArgs );
extern int32_t serveFlashPage(SOCKET htmlSock, int32_t ContentLength, char *pArgs );
extern int32_t serveStatisticsPage(SOCKET htmlSock, int32_t ContentLength, char *pArgs );
extern int32_t serveTaskPage(SOCKET htmlSock, int32_t ContentLength, char *pArgs );
extern int32_t serveFlashWritePage(SOCKET htmlSock, int32_t ContentLength, char *pArgs );
extern int32_t serveFlashReadPage(SOCKET htmlSock, int32_t ContentLength, char *pArgs );
extern int32_t serveFlashErasePage(SOCKET htmlSock, int32_t ContentLength, char *pArgs );
extern int32_t serveEepromWritePage(SOCKET htmlSock, int32_t ContentLength, char *pArgs );
extern int32_t serveEepromReadPage(SOCKET htmlSock, int32_t ContentLength, char *pArgs );
extern int32_t ndkThroughputBench(SOCKET htmlSock, int32_t ContentLength, char *pArgs );
extern int32_t ndkLoopbackStart(SOCKET htmlSock, int32_t ContentLength, char *pArgs );
extern int32_t ndkLoopbackStop(SOCKET htmlSock, int32_t ContentLength, char *pArgs );

#endif
