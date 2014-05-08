#ifndef LOGGER_H
#define LOGGER_H
#define LOGLINE_MAX 10000
#include "platform.h"
#include "common.h"
#define EDEBUG 1
#define DEBUG  2
#define INFO   3
#define WARN   4
#define ERROR  5
#define FATAL  6

int lprintf1(const char *FILEN,const char *Function,int line1,unsigned int level,char *fmt, ...);



#endif // LOGGER_H
