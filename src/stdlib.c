#include "raca/syscall.h"
#include "stdlib.h"
#include "stdint.h"

void *malloc(size_t size)
{
    return (void *)syscall(RACA_MALLOC, (uint64_t)size, 0, 0, 0, 0);
}

void *calloc(size_t n, size_t size)
{
    return (void *)syscall(RACA_MALLOC, (uint64_t)(n * size), 0, 0, 0, 0);
}

void free(void *addr)
{
    syscall(RACA_FREE, (uint64_t)addr, 0, 0, 0, 0);
}

void exit(int code)
{
    syscall(RACA_EXIT, (uint64_t)code, 0, 0, 0, 0);
}

void *memcpy(void *dest, void *src, long Num)
{
    int d0, d1, d2;
    __asm__ __volatile__("cld	\n\t"
                         "rep	\n\t"
                         "movsq	\n\t"
                         "testb	$4,%b4	\n\t"
                         "je	1f	\n\t"
                         "movsl	\n\t"
                         "1:\ttestb	$2,%b4	\n\t"
                         "je	2f	\n\t"
                         "movsw	\n\t"
                         "2:\ttestb	$1,%b4	\n\t"
                         "je	3f	\n\t"
                         "movsb	\n\t"
                         "3:	\n\t"
                         : "=&c"(d0), "=&D"(d1), "=&S"(d2)
                         : "0"(Num / 8), "q"(Num), "1"(dest), "2"(src)
                         : "memory");
    return dest;
}

void *realloc(void *ptr, size_t size)
{
    void *res = NULL;
    if (!ptr)
        return malloc(size);
    if (!size)
    {
        free(ptr);
        return NULL;
    }
    res = malloc(size);
    memcpy(res, ptr, size);
    free(ptr);
    return res;
}
