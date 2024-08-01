#pragma once

#include <stdint.h>

enum syscall_nums
{
    RACA_PRINT = 0,
    RACA_CPUID,
    RACA_OPEN,
    RACA_WRITE,
    RACA_READ,
    RACA_DUMPHEXBUF,
    RACA_CREATPROC,
    RACA_MALLOC,
    RACA_FREE,
    RACA_CLOSE,
    RACA_LSEEK,
    RACA_OPENPIPE,
    RACA_LISTDIR,
    RACA_DIRITEMNUM,
    RACA_CHANGECWD,
    RACA_GETCWD,
    RACA_CREATE,
    RACA_GETTYPE,
    RACA_MOUNT,
    RACA_EXIT,
    RACA_WAIT4,
};

uint64_t syscall(uint64_t number, uint64_t arg1, uint64_t arg2, uint64_t arg3,
                 uint64_t arg4, uint64_t arg5);
