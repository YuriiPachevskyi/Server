#ifndef _LOG_H
#define _LOG_H

#include <stdio.h>
#include <sys/time.h>
#include <pthread.h>
#include <unistd.h>

extern pthread_mutex_t ___LOGLOCKER___;

enum {
    PRINT_ERROR,
    PRINT_WARNING,
    PRINT_VERBOSE,
    PRINT_INFO
};

#ifndef LOG_STATUS
#define LOG_STATUS PRINT_ERROR
#endif //LOG_STATUS

#define PRINT_FUNCTION_NAME 1

#ifndef THREAD
#define THREAD "THREAD"
#endif //THREAD

void log(char c);

#define LOGE(format, args...) if(PRINT_ERROR <= LOG_STATUS) { pthread_mutex_lock(&___LOGLOCKER___); log('E'); \
        if(PRINT_FUNCTION_NAME) { printf("(%s) ", __FUNCTION__); } \
        printf(format, ## args); printf("\n"); pthread_mutex_unlock(&___LOGLOCKER___); }

#define LOGW(format, args...) if(PRINT_WARNING <= LOG_STATUS) { pthread_mutex_lock(&___LOGLOCKER___); log('W'); \
        if(PRINT_FUNCTION_NAME) { printf("(%s) ", __FUNCTION__); } \
        printf(format, ## args); printf("\n"); pthread_mutex_unlock(&___LOGLOCKER___); }

#define LOGV(format, args...) if(PRINT_VERBOSE <= LOG_STATUS) { pthread_mutex_lock(&___LOGLOCKER___); log('V'); \
        if(PRINT_FUNCTION_NAME) { printf("(%s) ", __FUNCTION__); } \
        printf(format, ## args); printf("\n"); pthread_mutex_unlock(&___LOGLOCKER___); }

#define LOGI(format, args...) if(PRINT_INFO <= LOG_STATUS) { pthread_mutex_lock(&___LOGLOCKER___); log('I'); \
        if(PRINT_FUNCTION_NAME) { printf("(%s) ", __FUNCTION__); } \
        printf(format, ## args); printf("\n"); pthread_mutex_unlock(&___LOGLOCKER___); }

#endif //_LOG_H
