#include "logger.h"

#define RED "\033[1;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[1;33m"
#define RESET_COLOR "\033[0m"

void logInfo(const char *text)
{
    if (LOG_INFOS)
    {
        logColoredText(text, GREEN);
    }
}

void logWarning(const char *text)
{
    if (LOG_WARNINGS)
    {
        logColoredText(text, YELLOW);
    }
}

void logError(const char *text)
{
    if (LOG_ERRORS)
    {
        logColoredText(text, RED);
    }
}

static void logText(const char *text)
{
    printf("%s\n", text);
}

static void logColoredText(const char *text, const char *color)
{
    printf(color);
    logText(text);
    printf(RESET_COLOR);
}