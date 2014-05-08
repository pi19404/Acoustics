#ifndef LOGGER_H
#define LOGGER_H
#define LOGLINE_MAX 10000
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "time.h"
#include <sys/time.h>
#include <stdarg.h>
#define EDEBUG 1
#define DEBUG  2
#define INFO   3
#define WARN   4
#define ERROR  5
#define FATAL  6
int lprintf1(const char *FILEN,const char *Function,int line1,unsigned int level,char *fmt, ...)
{
    int fd;
    int rc;
    va_list ap;
    struct timeval tv;
    time_t curtime;
    char buf[30]="\0";
    char date[50]="\0";


    //static char line[LOGLINE_MAX];
    char line[LOGLINE_MAX]="\0";
    char line2[LOGLINE_MAX]="\0";
    char line3[6]="\0";
    char line4[LOGLINE_MAX]="\0";
    //static char threadnum[10];
    char threadnum[20];
    int cnt;
    char *levels[7] =
    { "[(bad)] ","EDEBUG", "[DEBUG] ", "[INFO ] ", "[WARN ] ", "[ERROR] ", "[FATAL] " };
    char file[100]="\0";
    char func[100]="\0";
int i=0;


        char FILEN1[100]="0";
        char *firstToken=NULL,*tmpServerName=NULL;
        firstToken=(char *)strrchr((const char *)FILEN,'/');
        if(firstToken!=0)
        {
        tmpServerName=firstToken+1;
        strcpy(FILEN1,tmpServerName);
        }
        else
        {
 		strcpy(FILEN1,FILEN);
        }

        strcpy(file,FILEN1);
    file[25]='\0';
    strcpy(func,Function);
    func[30]='\0';
    sprintf(line2,"-- [%-25s],[%-5d] -- ",file,line1);

    //if(log_open_flag!=1)
    {
        memset(date, 0, sizeof(date));
        gettimeofday (&tv, NULL);
        curtime = tv.tv_sec;
        strftime(date, 50, "%b %d %T", localtime(&curtime));
        memset(buf, 0, sizeof(buf));
        strcat(date, buf);
        sprintf(threadnum, "(%-5lu) (%-3lu) ",getpid(),(unsigned long) pthread_self());
        /*removing the logging mode
    cnt = snprintf(line, sizeof(line), "%s%s:%s%s", date,line2,levels[level],threadnum);
        */
    cnt = snprintf(line, sizeof(line), "%s%s:%s", date,line2,threadnum);
    va_start(ap, fmt);
        vsnprintf(line + cnt, sizeof(line) - cnt, fmt, ap); /*if log too long , then truncate */
        va_end(ap);
        line[sizeof(line) - 1] = '\0';
    printf("\n%s\n",line);
    }

    return 0;


}



#endif // LOGGER_H
