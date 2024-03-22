#ifndef LOGGER_H
#define LOGGER_H

#include "main.h"

#define LOG_ERRORS 1
#define LOG_WARNINGS 0
#define LOG_INFOS 0

void logInfo(const char *text);
void logWarning(const char *text);
void logError(const char *text);

static void logColoredText(const char *text, const char *color);
static void logText(const char *text);

#endif