#include <stdio.h>

#include "logger.h"

#define RED "\033[1;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[1;33m"
#define RESET_COLOR "\033[0m"

void logInfo(const char *text, ...)
{
    if (LOG_INFOS)
    {
        va_list args;
        va_start(args, text);
        logColoredText(GREEN, text, args);
        va_end(args);
    }
}

void logWarning(const char *text, ...)
{
    if (LOG_WARNINGS)
    {
        va_list args;
        va_start(args, text);
        logColoredText(YELLOW, text, args);
        va_end(args);
    }
}

void logError(const char *text, ...)
{
    if (LOG_ERRORS)
    {
        va_list args;
        va_start(args, text);
        logColoredText(RED, text, args);
        va_end(args);
    }
}

static void logColoredText(const char *color, const char *text, va_list args)
{
    printf(color);
    vprintf(text, args);
    printf("\n");
    printf(RESET_COLOR);
}