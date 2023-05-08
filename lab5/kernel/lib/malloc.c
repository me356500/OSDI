
#include "uart.h"
#include "malloc.h"
extern char __startup_allocator_start;
char * startup_allocator_start = (char *) &__startup_allocator_start;

void *smalloc(unsigned long size)
{
    char *r = startup_allocator_start;
    //
    size = (size + 0x10 - 1) / 0x10 * 0x10;
    startup_allocator_start += size;
    return r;
}

void *memcpy(void *dest, const void *src, unsigned long long n) {
    char *cdest = dest;
    const char *csrc = src;

    while (n--)
    {
        *cdest++ = *csrc++;
    }

    return dest;
}