/*! 
 *\file crc8.c
 *
 * \author Alberto Vázquez
 * \date 3/5/2018
 *
 * Functions used to calculate crc8.
 */
#include "crc8.h"

#if defined(CRC8_MASK) && defined(CRC8_INIT)
  uint8_t crc8Calc(uint8_t length, uint8_t *data) {
    uint8_t i, crc;
    uint8_t j;

    crc = CRC8_INIT;
    for (i=length; i>0; i--) {
        crc = crc ^ *(data + length - i);
        for (j=8; j>0; j--) {
            if(crc & 1)
                crc = (crc >> 1) ^ CRC8_MASK;
            else
                crc >>= 1;
        }
    }
    return crc;
}
#else
  uint8_t crc8Calc(uint8_t initvalue, uint8_t mask, uint8_t length,\
        uint8_t *data) {
    uint8_t i, crc;
    uint8_t j;

    crc = initvalue;
    for (i=length; i>0; i--) {
        crc = crc ^ *(data + length - i);
        for (j=8; j>0; j--) {
            if(crc & 1)
                crc = (crc >> 1) ^ mask;
            else
                crc >>= 1;
        }
    }
    return crc;
}
#endif
