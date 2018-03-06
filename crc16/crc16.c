/*! 
 *\file crc16.c
 *
 * \author Alberto Vázquez
 * \date 3/2/2018
 *
 * Functions used to calculate crc16.
 */
#include "crc16.h"

#if defined(USEBIT) && defined(MASK) && defined(INITVALUE)
  uint16_t crc16Calc(uint16_t length, uint8_t *data) {
    uint16_t i, crc;
    uint8_t j;

    crc = INITVALUE;
    for (i=length; i>0; i--) {
        crc = crc ^ *(data + length - i);
        for (j=8; j>0; j--) {
            if(crc & 1)
                crc = (crc >> 1) ^ MASK;
            else
                crc >>= 1;
        }
    }
    return crc;
}
#elif defined(USEBIT)
  uint16_t crc16Calc(uint16_t initvalue, uint16_t mask, uint16_t length,\
        uint8_t *data) {
    uint16_t i, crc;
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

#if defined(USETABLE) && defined(MASK) && defined(INITVALUE)
uint16_t crc16CalcTable(const uint16_t *table, uint16_t length, uint8_t *data) {
    uint16_t i, crc;

    crc = INITVALUE;
    for(i=length; i>0; i--)
        crc = (crc >> 8) ^ *(table + ((uint8_t)(*(data + length - i)) ^ (uint8_t)crc));
    return crc;
}
#elif defined(USETABLE)
//! define the maximal number of posible values of data.
#define MAX     256
//! define maximal iteration.
#define MAX2    (MAX - 1)

/*!
 * \brief Static structure that holds all the data required to calculate crc16 with a lookup table.
 */
static struct {
    uint16_t table[MAX]; //!< Array of 256 holding the values to calculate the lookup table.
    uint16_t initValue; //!< Initial value to calculate the crc.
    uint16_t mask; //!< Value of the mask to calculate crc.
} _crcStruct;

void crc16TableGen(uint16_t initValue, uint16_t mask) {
    uint8_t i, j;
    uint16_t crc;
    
    _crcStruct.mask = mask;
    _crcStruct.initValue = initValue;
    i = 0;
    // for(i=MAX; i>0; i--) {
    do {
        crc = MAX2 - i;
        for(j=8; j>0; j--) {
            if ((uint8_t)crc & 1)
                crc = mask ^ (crc >> 1);
            else
                crc >>= 1;
        }
        *(_crcStruct.table + MAX2 - i) = crc;
        i--;
    } while(i>0);
}

uint16_t crc16CalcTable(uint16_t length, uint8_t *data) {
    uint16_t i, crc;

    crc = _crcStruct.initValue;
    for(i=length; i>0; i--)
        crc = (crc >> 8) ^ *(_crcStruct.table + ((uint8_t)(*(data + length - i)) ^ (uint8_t)crc));
    return crc;
}
#endif
