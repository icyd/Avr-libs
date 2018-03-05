#include <stdio.h>
#include <inttypes.h>

void crc16TableGen(uint16_t mask, uint16_t *table);

int main(int argc, char *argv[]) {
    uint16_t i, mask, table[256];

    mask = strtoimax(argv[1], NULL, 16);

    printf("With MASK = %#04x\n",mask);
    crc16TableGen(mask, table);
    printf("const uint16_t lookupTable[] = {");
    for(i=256; i>0; i--)
        if(i>1)
            printf("%#04x, ",table[256-i]);
        else
            printf("%#04x};",table[256-i]);
    printf("\n");

    return 0;
}

void crc16TableGen(uint16_t mask, uint16_t *table) {
    uint8_t j;
    uint16_t i, crc;
    
    for(i=256; i>0; i--) {
        crc = 256 - i;
        for(j=8; j>0; j--) {
            if (crc & 1)
                crc = mask ^ (crc >> 1);
            else
                crc >>= 1;
        }
        *(table + 256 - i) = crc;
    }
}
