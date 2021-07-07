#include "log.h"
#include <stdarg.h>
#include <stdio.h>
#include <pthread.h>

static enum log_level global_level = LOG_INFO;

void set_log_level(enum log_level level)
{
    global_level = level;
}

enum log_level log_level()
{
    return global_level;
}

#define LOG_MESSAGE(level, prefix) {\
    if (global_level > level) return;\
    va_list args;\
    va_start(args, fmt);\
    fputs(prefix, stderr);\
    vfprintf(stderr, fmt, args);\
    fputs("\n", stderr);\
    va_end(args);\
}

void log_error(char *fmt, ...)
{
    LOG_MESSAGE(LOG_ERROR, "error: ");
}

void log_info(char *fmt, ...)
{
    LOG_MESSAGE(LOG_INFO, "info: ");
}

void log_warn(char *fmt, ...)
{
    LOG_MESSAGE(LOG_WARN, "warning: ");
}

void log_debug(char *fmt, ...)
{
    LOG_MESSAGE(LOG_DEBUG, "debug: ");
}
