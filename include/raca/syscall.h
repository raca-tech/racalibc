#pragma once

#include <stdint.h>

enum syscall_nums
{
    RACA_PRINT = 0,
    RACA_CPUID = 1,
    RACA_OPEN = 2,
    RACA_WRITE = 3,
    RACA_READ = 4,
    RACA_DUMPHEXBUF = 5,
    RACA_CREATPROC = 6,
    RACA_MALLOC = 7,
    RACA_FREE = 8,
    RACA_CLOSE = 9,
    RACA_LSEEK = 10,
    RACA_FSIZE = 11,
    RACA_OPENPIPE = 12,
    RACA_LISTDIR = 13,
    RACA_DIRITEMNUM = 14,
    RACA_CHANGECWD = 15,
    RACA_GETCWD = 16,
    RACA_CREATE = 17,
    RACA_GETTYPE = 18,
    RACA_MOUNT = 19,
    RACA_EXIT = 20,
    RACA_WAIT4 = 21,
};

uint64_t syscall(uint64_t number, uint64_t arg1, uint64_t arg2, uint64_t arg3,
                 uint64_t arg4, uint64_t arg5);
