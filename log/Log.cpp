#include "Log.h"

pthread_mutex_t ___LOGLOCKER___;

void log(char c) {
    timeval tv;
    gettimeofday(&tv, 0);
    printf("%ld ", (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000);

    if (THREAD) {
        printf("%c/%s(%lu): ", c, THREAD, pthread_self());
    }
}
