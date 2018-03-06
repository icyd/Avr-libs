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

static EWMA_DATATYPE _average = EWMA_INIT; //!< Static value that holds the average.

__attribute__ ((always_inline)) inline void ewmaReset(void) {
    _average = EWMA_INIT;
}

__attribute__ ((always_inline)) inline EWMA_DATATYPE ewmaValue(void) {
    return _average;
}

EWMA_DATATYPE ewma(EWMA_DATATYPE sample) {
    EWMA_DATATYPE tmp;
    uint8_t roundup;

    tmp = (_average * EWMA_NUM) + (sample * (EWMA_DEN - EWMA_NUM));
    roundup = ((tmp & (EWMA_DEN - 1)) < (EWMA_DEN >> 1)) ? 0 : 1;
    _average = (tmp >> SHIFTS) + roundup;
    
    return _average;
}
