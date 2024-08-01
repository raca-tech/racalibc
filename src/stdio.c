#include <raca/syscall.h>
#include "stdio.h"
#include "stdarg.h"
#include "stdint.h"
#include "string.h"

int open(const char *filename, mode_t mode)
{
    return syscall(RACA_OPEN, (uint64_t)filename, strlen(filename),
                   (uint64_t)mode, 0, 0);
}

int write(int fd, char *buf, size_t len)
{
    return syscall(RACA_WRITE, (uint64_t)fd, (uint64_t)buf, (uint64_t)len, 0,
                   0);
}

int close(int fd)
{
    return syscall(RACA_CLOSE, fd, 0, 0, 0, 0);
}

const char *terminal_path = "/dev/terminal";

int printf(const char *fmt, ...)
{
    char buf[4096];

    va_list args;

    va_start(args, fmt);
    int len = vsprintf(buf, fmt, args);
    va_end(args);

    int fd = open(terminal_path, O_RDWR);
    write(fd, buf, len);
    close(fd);

    return len;
}
