enum log_level {
    LOG_DEBUG,
    LOG_INFO,
    LOG_WARN,
    LOG_ERROR,
    LOG_DISABLE,
};

void set_log_level(enum log_level);
enum log_level log_level();

void log_error(char *fmt, ...);
void log_info(char *fmt, ...);
void log_warn(char *fmt, ...);
void log_debug(char *fmt, ...);
