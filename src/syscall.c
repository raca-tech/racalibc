#include <stdint.h>

__attribute__((naked)) uint64_t syscall(uint64_t number, uint64_t arg1,
                                    uint64_t arg2, uint64_t arg3, uint64_t arg4,
                                    uint64_t arg5)
{
    asm volatile("mov %rdi, %rax");
    asm volatile("mov %rsi, %rdi");
    asm volatile("mov %rdx, %rsi");
    asm volatile("mov %rcx, %rdx");
    asm volatile("mov %r8, %r10");
    asm volatile("mov %r9, %r8");
    asm volatile("syscall");
    asm volatile("ret");
}
