#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdarg.h>
#include<time.h>
#include "logger.h"

const int DISABLE_DEBUG_MODE = 0;
const int ENABLE_DEBUG_MODE = 1;

static const char *LOG_LEVEL_DEBUG = "DEBUG";
static const char *LOG_LEVEL_INFO = "INFO";
static const char *LOG_LEVEL_WARNING = "WARNING";
static const char *LOG_LEVEL_ERROR = "ERROR";

/***
 * Set buffer to display date and log level to be displayed in log
 *  @parameter level : Log level
 *  @parameter buf   : Output string buffer
 */
static void get_time_format(const char *level, char *buf){
    time_t t = time(NULL);
    struct tm *local = localtime(&t);
    char now_date[21];
    strftime(now_date, sizeof(now_date), "%Y-%m-%d %H:%M:%S",local);
    sprintf(buf,"%s %s ",now_date, level);
}

void debug(const char *format, ...) {
    // No log output when debug mode is off
    if (debug_mode == DISABLE_DEBUG_MODE){
        return;
    }
    char buf[1024];
    get_time_format(LOG_LEVEL_DEBUG, buf);

    va_list ap;
    va_start(ap, format);
    printf("%s", buf);
    vprintf(format, ap);
    va_end(ap);
}

void info(const char *format, ...) {
    char buf[1024];
    get_time_format(LOG_LEVEL_INFO, buf);

    va_list ap;
    va_start(ap, format);
    printf("%s", buf);
    vprintf(format, ap);
    va_end(ap);
}

void warning(const char *format, ...) {
    char buf[1024];
    get_time_format(LOG_LEVEL_WARNING, buf);

    va_list ap;
    va_start(ap, format);
    printf("%s", buf);
    vprintf(format, ap);
    va_end(ap);
}

void error(const char *format, ...) {
    char buf[1024];
    get_time_format(LOG_LEVEL_ERROR, buf);

    va_list ap;
    va_start(ap, format);
    printf("%s", buf);
    vprintf(format, ap);
    va_end(ap);
}
