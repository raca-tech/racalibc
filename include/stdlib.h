#pragma once

#include "stdint.h"

void *malloc(size_t size);
void *calloc(size_t n, size_t size);
void free(void *addr);
void exit(int code);

void *memcpy(void *dest, void *src, long Num);
void *realloc(void *ptr, size_t size);
