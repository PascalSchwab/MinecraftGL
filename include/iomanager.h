#ifndef __IOMANAGER__
#define __IOMANAGER__

typedef struct
{
    char *path;
    char *text;
} File;

File *readFile(char *path);

#endif