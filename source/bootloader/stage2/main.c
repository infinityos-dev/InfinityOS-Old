#include "stdint.h"
#include "stdio.h"

void encodeGdtEntry(uint8_t *target, struct GDT source)
{
    // Check the limit to make sure that it can be encoded
    if (source.limit > 0xFFFFF) {kerror("GDT cannot encode limits larger than 0xFFFFF");}
    
    // Encode the limit
    target[0] = source.limit & 0xFF;
    target[1] = (source.limit >> 8) & 0xFF;
    target[6] = (source.limit >> 16) & 0x0F;
    
    // Encode the base
    target[2] = source.base & 0xFF;
    target[3] = (source.base >> 8) & 0xFF;
    target[4] = (source.base >> 16) & 0xFF;
    target[7] = (source.base >> 24) & 0xFF;
    
    // Encode the access byte
    target[5] = source.access_byte;
    
    // Encode the flags
    target[6] |= (source.flags << 4);
}

void _cdecl cstart_(uint16_t bootDrive)
{
    const char far* far_str = "far string";

    puts("Hello world from C!\r\n");
    printf("Formatted %% %c %s %ls\r\n", 'a', "string", far_str);
    printf("Formatted %d %i %x %p %o %hd %hi %hhu %hhd\r\n", 1234, -5678, 0xdead, 0xbeef, 012345, (short)27, (short)-42, (unsigned char)20, (signed char)-10);
    printf("Formatted %ld %lx %lld %llx\r\n", -100000000l, 0xdeadbeeful, 10200300400ll, 0xdeadbeeffeebdaedull);
    for (;;);
}
