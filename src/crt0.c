#include "stdlib.h"

extern int main();

void _start()
{
    int exit_code = main();
    exit(exit_code);
}
