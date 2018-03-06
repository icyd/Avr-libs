/*! 
 *\file ring_buffer.h
 *
 * \author Alberto Vázquez
 * \date 3/1/2018
 *
 * Implementation of circular buffer with variable array size.
 * The use of power of 2 for the buffer size, will produce a smaller code's size.
 * \warning to use this library is necessary to define the size of the buffer to create 'RING_BUFFER_SIZE', recommended method is to define it with option -D of the compiler.
 */

#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stdint.h>

//! Definition of type of variable for type of data stored inside the buffer
#define RING_BUFFER_DATATYPE uint8_t

//! General definition
#define TRUE 1
//! General definition
#define FALSE 0

//! Checks if RING_BUFFER_SIZE definition exists. And based on the size, define the type of variable used to store read \& write header.
#ifndef RING_BUFFER_SIZE
    #error "RING_BUFFER_SIZE not defined!\n Define it using compiler option -D"
#elif ((RING_BUFFER_SIZE > 0) || (RING_BUFFER_SIZE <= 256))
    #define CTYPE uint8_t
#elif ((RING_BUFFER_SIZE > 256UL) && (RING_BUFFER_SIZE <= 65536UL))
    #define CTYPE uint16_t
#else
    #error "Please select a RING_BUFFER_SIZE greater or equal to 2 and smaller or equal to 65536"
#endif

//! Definition of mask for the buffer size definition
#define RING_BUFFER_SIZE_MASK     (RING_BUFFER_SIZE - 1)

/*! 
 *  \struct cque
 *  \brief This struct holds the definition of the buffer
 */
typedef struct{
    RING_BUFFER_DATATYPE buffer[RING_BUFFER_SIZE]; //!< Buffer variable of size RING_BUFFER_SIZE and type RING_BUFFER_DATATYPE.
    CTYPE read; //!< Holds the position of the reader window.
    CTYPE write; //!< Store the position of the writer window.
    uint8_t isFull; //!< Flag to indicate if the array is full.
} cque;

//! Indicates if the buffer is full
#define RingBufferIsFull(x)      (x->isFull)
//! Indicates if the buffer is empty
#define RingBufferIsEmpty(x)     (!(x->isFull) && (x->read == x->write))

/*!
 *  \brief This function is used to initialize or reset the buffer.
 *  \param x Pointer to the circle buffer to be initialized.
 */
extern void RingBufferInit(cque *x);

/*!
 *  \brief Function to add data to the circle buffer.
 *  Data will be added to the buffer until the next write header is equal to the read header. In that case, isFull flag will be set and the data won't be added to the buffer. 
 *  \param x Pointer of the circle buffer where the data will be added.
 *  \param d Data to be stored in the buffer.
 *  \return Will return 0 in case of the data correctly stored inside the buffer, and 1 if the buffer is already Full.
 */
uint8_t RingBufferPush(cque *x, RING_BUFFER_DATATYPE d);

/*!
 *  \brief Funtion to remove data from the circle buffer.
 *  Data will be removed from the buffer unless the read and write windows are the same.
 *  \param x Pointer to the circle buffer, from the data to be read.
 *  \param d The data removed is returned by reference.
 *  \return Will return 0 if is data to remove, otherwise returns 1.
 */
uint8_t RingBufferPop(cque *x, RING_BUFFER_DATATYPE *d);

#endif
