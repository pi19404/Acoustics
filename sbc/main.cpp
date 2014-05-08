#include <iostream>

using namespace std;

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>

#include <iostream>
#include "logger.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <netdb.h>
#include<fstream>
int shutdown_socket=0;
int sockfd;
struct sockaddr_in server_addr;
pthread_mutex_t accept_lock;
pthread_mutex_t accept_lock1;

char* dataFileName;
typedef struct _IMG_STORE_REQST_TYP {   /* Image Store Request Structure */
    int hydrophone;                 	/* Image Type */
    int number;                 	/* numbers of pages */
} IMG_STORE_REQST_TYP;

/* init_socket
*  params: [port_name]            server socket port
*  params: [nums_of_accept]  numbers of accepting thread
*  return: [int]             0 success, <0 fail
*  function:                 init server socket descriptor
*                            init threadpool for accepting
*/
int init_socket(char *port_name, int nums_of_accept,int portnum);

/* destrory_socket
*  function:                 close server socket fd
*                            destroy threadpool for accepting
*/
int destroy_socket(void);
int socket_read(int socket, void *data, int len);
// Writes data into a socket connection 
int socket_write(int socket, void *data, int len) {
    int n = 0;
    unsigned char *p = NULL;
    lprintf1(__FILE__,__FUNCTION__,__LINE__, DEBUG, "in socket write...");
    n = write(socket, data, len);
    lprintf1(__FILE__,__FUNCTION__,__LINE__, DEBUG, "Total Bytes = %d, No. of Bytes written = %d",
        len, n);
    if (n < 0 || len != n)
    {
    return -1;
    }
    lprintf1(__FILE__,__FUNCTION__,__LINE__, DEBUG, "out socket write.");
    return 0;
}


void writeOutput(char* fileName,char *data,int len) {
    int *data1=(int *)data;
    char fileName2[100];
    sprintf(fileName2,"%s_1",fileName);
    
    ofstream fout(fileName, ios::out | ios::app);
    ofstream fout1(fileName2, ios::out | ios::app|ios::trunc);
    if (fout.is_open())
    {
        for (int i = 0; i < (len/sizeof(int)); ++i) {
            fout << data1[i] << ',';
            fout1 << data1[i] << ',';
        }
        fout << "\n";
        fout1 << "\n";
    }
    // for each row

    fout.close();
    fout1.close();
}

void process_message(int new_fd, char *client_ip)
{
IMG_STORE_REQST_TYP store_req;
memset(&store_req, 0, sizeof(IMG_STORE_REQST_TYP));
while(1)
{
    int status = socket_read(new_fd, &store_req, sizeof(IMG_STORE_REQST_TYP));
    if (status==0)
    {
        int nbytes=store_req.number;
        int hyd=store_req.hydrophone;
        lprintf1(__FILE__,__FUNCTION__,__LINE__, DEBUG, "Received Request for hydrophone %d for %d bytes",hyd,nbytes);

        char *data=(char *)malloc(nbytes+1);
        if(data==NULL)
        {
            lprintf1(__FILE__,__FUNCTION__,__LINE__, ERROR, "Error in allocating memory");
            break;
        }
        if(socket_read(new_fd,data,nbytes) == 0)
        {
            lprintf1(__FILE__,__FUNCTION__,__LINE__, DEBUG, "Completed Request for hydrophone %d for %d bytes",hyd,nbytes);
            data[nbytes]=0;
           // lprintf1(__FILE__,__FUNCTION__,__LINE__, DEBUG, "data read is %s",data);
            status=0;
            if(socket_write(new_fd,&status,sizeof(status)))
            {
                lprintf1(__FILE__,__FUNCTION__,__LINE__, ERROR, "Error in writing status");
                break;
            }
            /////store files/////
            char filename[100];
            sprintf(filename,"%s_%d.txt",dataFileName,hyd);
            writeOutput(filename,data,nbytes);
		
	   //system("rosservice call /auv_debug/hydrophone_interface/graph_plot \" {}\" ");
        }
        else
        {
            lprintf1(__FILE__,__FUNCTION__,__LINE__, ERROR, "Error in Read Request for hydrophone %d for %d bytes",hyd,nbytes);
            break;
        }
    }
    else
    {
        lprintf1(__FILE__,__FUNCTION__,__LINE__,ERROR,"Error in reading from socket ");
        break;
    }
    break;
}
shutdown(new_fd,2);
close(new_fd);
}

//-----------------------------------------------------------
//	 SOCKET ACCEPT
//	Function to accept the socket connection
//-----------------------------------------------------------
int socket_accept()
{
    int rtn = 0;
    int new_fd = 0;
    int sock_fd=sockfd;
    int sin_size=0;
    struct sockaddr_in client_addr;
    char *client_ip;
    fd_set fd_read;
    fd_set fd_error;

    memset(&client_addr, 0, sizeof(struct sockaddr_in));

    FD_ZERO(&fd_error);
    FD_ZERO(&fd_read);
    FD_SET(sock_fd,&fd_error);
    FD_SET(sock_fd,&fd_read);

    lprintf1(__FILE__,__FUNCTION__,__LINE__,EDEBUG, "Starting socket accept routiene");
    int ret=0;

    // Main loop for accepting connections
    while (1) {

    // Set socket length
    sin_size = sizeof(client_addr);



        // Accept new connections

    if ((new_fd = accept(sock_fd, (struct sockaddr *) &client_addr,(socklen_t *)&sin_size))==-1) {
         int option_toggle= 1;
         int sizeval=sizeof(int);
         rtn= getsockopt(sock_fd, SOL_SOCKET, SO_ERROR, (char *)&option_toggle, (socklen_t*)&(sizeval));
        lprintf1(__FILE__,__FUNCTION__,__LINE__,ERROR,"Error in accpeting Socket Connection .Exiting Thread :%s ",strerror(errno));
        return -1;
      }


    // Convert ip to string
     client_ip = inet_ntoa(client_addr.sin_addr);
     lprintf1(__FILE__,__FUNCTION__,__LINE__,INFO,"reveived message IP %s  port %d",client_ip,ntohs(client_addr.sin_port));

    //process message
     process_message(new_fd, client_ip);
     close(new_fd);
    }
return 0;
}


int init_socket(char *port_name, int nums_of_accept,int portnum)
{
    int yes = 1;
    int rtn = 0;
    int i = 0;
    int            optval = 1;
    struct linger           linger;
    struct servent *serv;
    int port = 0;
    shutdown_socket = 0;

    // Create a new socket connection
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    lprintf1(__FILE__,__FUNCTION__,__LINE__, ERROR, "socket create failed. ");
    return -1;
    }
    // Set the socket options
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR,(char *)&yes, sizeof(int)) == -1)
    {
    lprintf1(__FILE__,__FUNCTION__,__LINE__, ERROR, "setsockop SO_REUSEADDR failed. ");
    return -1;
    }
    linger.l_onoff = 1;
    linger.l_linger = 0;
   if(setsockopt (sockfd, SOL_SOCKET, SO_LINGER, (char *)(&linger), sizeof(linger))==-1)
   {
        lprintf1(__FILE__,__FUNCTION__,__LINE__, ERROR, "setsockopt SO_LINGER failed. ");
        return -1;
   }

    /*
   if(setsockopt (sockfd, SOL_SOCKET, TCP_NODELAY, (char *)(&optval), sizeof(optval))==-1)
   {
    lprintf1(__FILE__,__FUNCTION__,__LINE__, ERROR, "setsockopt TCP_NODELAY failed. ");
        return -1;
   }*/

    if(portnum==0)
    {
    // Retrieves service information for the port-name in the config file
    serv = getservbyname(port_name, "tcp");
    if (serv == NULL)
    {
    lprintf1(__FILE__,__FUNCTION__,__LINE__, ERROR, "getservbyname failed. port_name = [ %s ]. ", port_name);
    return -1;
    }
    // We retrieve the port number
    port = ntohs(serv->s_port);
    lprintf1(__FILE__,__FUNCTION__,__LINE__, ERROR, "setting port number as = [ %d ]. ", portnum);
    }
    else
       port=portnum;


    // Set up Socket configuration
    server_addr.sin_family = AF_INET;	// host byte order
    server_addr.sin_port = htons(port);	// short, network byte order
    server_addr.sin_addr.s_addr = inet_addr("192.168.2.101");	// automatically fill with my IP
    memset(server_addr.sin_zero, '\0', sizeof(server_addr.sin_zero));


    //printf("%d \n",inet_addr("192.168.2.101"));

    // Binds a name to the socket
    if (bind(sockfd, (struct sockaddr *) &server_addr, sizeof server_addr) == -1) {
    lprintf1(__FILE__,__FUNCTION__,__LINE__, ERROR, "bind failed. errno: %d", errno);
    return -1;
    }
    // Starts listening for requests
    if (listen(sockfd,nums_of_accept) == -1) {
    lprintf1(__FILE__,__FUNCTION__,__LINE__, ERROR, "listen failed. ");
    return -1;
    }
    // create the mutex
    if ((rtn = pthread_mutex_init(&accept_lock, NULL)) != 0) {
    lprintf1(__FILE__,__FUNCTION__,__LINE__, FATAL, "pthread_mutex_init %s. ", strerror(rtn));
    return -1;
    }

    // create the mutex
    if ((rtn = pthread_mutex_init(&accept_lock1, NULL)) != 0) {
        lprintf1(__FILE__,__FUNCTION__,__LINE__, FATAL, "pthread_mutex_init %s. ", strerror(rtn));
        return -1;
    }

    return 0;
}

int init()
{
      int ret=0;
      ret = init_socket("hydrophone",10,0);
      if (ret != 0)
      {
      lprintf1(__FILE__,__FUNCTION__,__LINE__,ERROR,"Init socket failed. %d", ret);
      return -1;
      }
      lprintf1(__FILE__,__FUNCTION__,__LINE__,DEBUG,"completed socket initialization %d", ret);

      socket_accept();

      destroy_socket();
}




int destroy_socket()
{
    lprintf1(__FILE__,__FUNCTION__,__LINE__,DEBUG,"Entering destroy_socket ");
    int rtn = 0;
    int i = 0;
    //set_socket_socket(1);
    lprintf1(__FILE__,__FUNCTION__,__LINE__,DEBUG,"Closing the socket ");
    shutdown(sockfd,2);
    close(sockfd);
    lprintf1(__FILE__,__FUNCTION__,__LINE__,DEBUG,"Closing the socket successful ");
    return 0;
}


// Reads data from a socket
int socket_read(int socket, void *data, int len)
{
    int n = 0, count = 0, eof = 0;
    int ret = 0;
    int sizes_of_read = 1024;
    unsigned char *p = NULL;
    unsigned char *bufptr = NULL;
    struct timeval tv;
    fd_set fd_read;
    bufptr = (unsigned char *) data;
    FD_ZERO(&fd_read);
    FD_SET(socket, &fd_read);
    lprintf1(__FILE__,__FUNCTION__,__LINE__, DEBUG, "reading socket %d",socket);
    tv.tv_sec = 10;
    tv.tv_usec = 0;

    // Determines where the socket descriptor is ready for read/write
    ret = select(socket + 1, &fd_read, (fd_set *) 0, (fd_set *) 0, &tv);
    if (ret == 0)
    {				/*timeout */
    lprintf1(__FILE__,__FUNCTION__,__LINE__, ERROR, "Read timeout. ");
    return -2;
    }
    if (ret < 0)
    {
    lprintf1(__FILE__,__FUNCTION__,__LINE__, ERROR, "Socket failed ERROR = [%d]. ", errno);
    return -1;
    }
    // Read from the socket
    while (!(FD_ISSET(socket, &fd_read)));

    do {
    n = -1;
    if (len - count < sizes_of_read)
        sizes_of_read = len - count;
    n = read(socket, bufptr, sizes_of_read);
    if (n < 0) {
        return -1;
    }

    /* Connection lost */
    if (n == 0) {
        return -1;
    };
    count += n;
    bufptr += n;
    }
    while (count < len && n > 0);
    bufptr = (unsigned char *) data;
    lprintf1(__FILE__,__FUNCTION__,__LINE__, DEBUG, "Total Bytes = %d, No. of Bytes read = %d", len, count);
    //lprintf1(__FILE__,__FUNCTION__,__LINE__, DEBUG, "Socket read.");
    return 0;
}







int main(int argc,char** argv)
{
    dataFileName = new char[100];
    if(argc <= 1){
        printf("Error\n"); 
    }

    dataFileName = argv[1];
    std::cout<<"Writing to file\n"<<dataFileName;
    init();

}
