#ifndef __LOGGER__
#define __LOGGER__

#include <stdarg.h>

#define LOG_ERRORS 1
#define LOG_WARNINGS 0
#define LOG_INFOS 0

void logInfo(const char *text, ...);
void logWarning(const char *text, ...);
void logError(const char *text, ...);

static void logColoredText(const char *color, const char *text, va_list args);

#endif