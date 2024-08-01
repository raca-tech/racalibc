#pragma once

#include "stdint.h"
#include "stdarg.h"

typedef enum
{
    O_RDONLY = 0,
    O_RDWR,
} mode_t;

int open(const char *filename, mode_t mode);
int write(int fd, char *buf, size_t len);
int close(int fd);

int vsprintf(char *buf, const char *fmt, va_list args);
int printf(const char *, ...);
