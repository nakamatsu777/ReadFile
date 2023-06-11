const int DISABLE_DEBUG_MODE;
const int ENABLE_DEBUG_MODE;
extern int debug_mode;

void debug(const char *format, ...);
void info(const char *format, ...);
void warning(const char *format, ...);
void error(const char *format, ...);