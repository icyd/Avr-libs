/*! 
 *\file circbuff.c
 *
 * \author Alberto Vázquez
 * \date 3/1/2018
 *
 * Functions for the circular buffer implementation with variable array size.
 */

#include "circbuff.h"

//! If B_SIZE isn't power of 2: Checks if after adding the value is greater or equal to B_SIZE, in this case the value will be wrap around to 0.
#define __addmod_pow2(x)        (((x + 1) >= B_SIZE) ? 0 : (x + 1)) 
//! If B_SIZE is power of 2: Will apply a bitwise and operation to the value plus 1 with a mask of value (B_SIZE - 1).
#define __addmod_not_pow2(x)    ((x + 1) & B_SIZE_MASK) 

#if (B_SIZE & B_SIZE_MASK)
   #define __addmod(x)  __addmod_not_pow2(x)  
#else
  #define __addmod(x)   __addmod_pow2(x)
#endif

  
__attribute__ ((always_inline)) inline void RingBufferInit(cque *x) { 
  x->read = 0;
  x->write = 0;
  x->isFull = FALSE;
}

uint8_t RingBufferPush(cque *x, DATATYPE d){

    if (!x->isFull){
        //x->buffer[x->write] = d;
        *(x->buffer + x->write) = d;
        x->write = __addmod(x->write);
        if(x->read == x-> write)
            x->isFull = TRUE;
    } else {
      return 1;
    }

    return 0;
}

uint8_t RingBufferPop(cque *x, DATATYPE *d){

  if(x->isFull || (x->read != x->write) ) {
        //*d = x->buffer[x->read];
        *d = *(x->buffer + x->read);
        x->read = __addmod(x->read);
        x->isFull = FALSE;
  } else {
    return 1;
  }
    return 0;
}
