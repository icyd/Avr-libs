/*! 
 *\file ewma.c
 *
 * \author Alberto Vázquez
 * \date 3/5/2018
 *
 * Functions to calculate the weighted moving average.
 */
#include "ewma.h"
#include <stdio.h>

static DATATYPE _average = INITVALUE; //!< Static value that holds the average.

__attribute__ ((always_inline)) inline void ewmaReset(void) {
    _average = INITVALUE;
}

__attribute__ ((always_inline)) inline DATATYPE ewmaValue(void) {
    return _average;
}

DATATYPE ewma(DATATYPE sample) {
    DATATYPE tmp;
    uint8_t roundup;

    tmp = (_average * NUM) + (sample * (DEN - NUM));
    roundup = ((tmp & (DEN - 1)) < (DEN >> 1)) ? 0 : 1;
    _average = (tmp >> SHIFTS) + roundup;
    
    return _average;
}
