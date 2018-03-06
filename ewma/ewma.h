/*! 
 *\file ewma.h
 *
 * \author Alberto Vázquez
 * \date 3/5/2018
 *
 * Calculates the exponential weighted moving average over the sample with an initial average and calculates the division with roundup if the result of the division is not exact.
 *
 * It uses divisions based on denominators that are power of 2, so the division is faster.
 *
 * Also the if the default type of data (uint16_t) is used, it allows numerators until 256 with uint8_t, without overflow.
 * 
 * The formula for the average calculation is: \f$y_k = \alpha_1 y_{k-1} + \alpha_2 x_k\f$ where \f$\alpha_1 = \frac{EWMA_NUM}{EWMA_DEN}, \quad \alpha_2 = 1 - \alpha_1\f$.
 *
 * The values of the numerator and denominator of \f$\alpha_1\f$ should be defined with the compiler's option -D.
 */
#ifndef EWMA_H
#define EWMA_H 1

#include <stdint.h>

#if !defined(EWMA_INIT) || defined(__DOXIGEN__)
//! Defines the initial value of the average after reset.
#define EWMA_INIT       0
#endif

#if !defined(EWMA_DATATYPE) || defined(__DOXYGEN__)
//! Defines the type of data that holds the average value.
#define EWMA_DATATYPE        uint16_t
#endif

#if defined(__DOXYGEN__)
//! Defines the numerator of \f$\alpha_1\f$.
#define EWMA_NUM         3
//! Defines the denominator of \f$\alpha_1\f$.
#define EWMA_DEN         4
#else
#if !defined(EWMA_NUM) || !defined(EWMA_DEN)
#error "EWMA_NUM and EWMA_DEN should be defined with compiler's option -D"
#else
#if (EWMA_DEN & (EWMA_DEN - 1))
#error "EWMA_DEN have to be a power of two"
#endif
#if !(EWMA_DEN > EWMA_NUM)
#error "EWMA_NUM have to be smaller than EWMA_DEN"
#endif
#endif
#endif

#ifndef __DOXYGEN__
#define NBITS2(n)   ((n&2)?1:0)
#define NBITS4(n)   ((n&(0xC))?(2+NBITS2(n>>2)):(NBITS2(n)))
#define NBITS8(n)   ((n&0xF0)?(4+NBITS4(n>>4)):(NBITS4(n)))
#define NBITS16(n)  ((n&0xFF00)?(8+NBITS8(n>>8)):(NBITS8(n)))
#define NBITS32(n)  ((n&0xFFFF0000)?(16+NBITS16(n>>16)):(NBITS16(n)))
#define LOG_2(n)    (n==0?0:NBITS32(n))
#endif

//! Calculates the number of left shift required to perform the division. 
#define SHIFTS     LOG_2(EWMA_DEN) 

/*!
 * \brief Reset the value of the average to EWMA_INIT
 */
extern void ewmaReset(void); 
/*!
 * \brief Returns the actual value of the average, without modifying it.
 * \return The actual value of the average.
 */
extern EWMA_DATATYPE ewmaValue(void);
/*!
 * \brief Calculates the average based on the new sample.
 * \param sample New sample to average.
 * \return New value of the average.
 */
EWMA_DATATYPE ewma(EWMA_DATATYPE sample);

#endif
