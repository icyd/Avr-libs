/*! 
 *\file crc16.h
 *
 * \author Alberto Vázquez
 * \date 3/2/2018
 *
 * Library to calculate CRC16, using initial value and mask, as parameter. All functions will work with pointer to the input data, so arrays can be given.
 * Use gcc compiler options:
 *      USETABLE -> to compile functions that use a lookup table.
 *      USEBIT  -> to compile funciton that calculates crc bitwise.
 *      
 * Both could be use with dynamically given masks and initial values, or with constants. In important to take into consideration that if muliple masks are required trough the program, the dynamic version is the best suited (overall the bitwise). But if only one mask will be required, the smaller code generated is with the table version, with a constant lookup table.
 *
 * To compile the static versions of the function please define MASK and INITVALUE with option -D of the gcc compiler, or with defines.
 */
#ifndef CRC16_H
#define CRC16_H

#include <stdint.h>

#if defined(USEBIT) && defined(MASK) && defined(INITVALUE)
  /*!
   * \brief Function to calculate crc16, using bitwise calculation, with static definition of initvalue and mask via definition.
   * \note to activate this define USEBIT, MASK=mask and INITVALUE=init with compiler's -D option.
   * \param length is the length of the data array to be processed.
   * \param *data is a pointer to the data array.
   * \return crc16 calculated.
   */
    uint16_t crc16Calc(uint16_t length, uint8_t *data);
#elif defined(USEBIT)
  /*!
   * \brief Function to calculate crc16, with the values of initvalue and mask given as parameters of the function.
   * \note to activate this define USEBIT only.
   * \param initvalue give the initial value to generate the crc.
   * \param mask is the mask to calculate the crc.
   * \param length is the length of the data array to be processed.
   * \param *data pointer to the data array.
   * \return return crc16 calculated.
   */
    uint16_t crc16Calc(uint16_t initvalue, uint16_t mask, uint16_t length,\
        uint8_t *data);
#endif

#if defined(USETABLE) && defined(MASK) && defined(INITVALUE)
  /*! 
   * \brief Function to calculate the crc16, using a lookup table, with the initial value and mask predefined.
   * \note to activate this define USEBIT, MASK=mask and INITVALUE=init with compiler's -D option.
   * \param *table pointer to do array containing the table of data.
   * \param length indicates the length of the data to be processed.
   * \param *data pointer to the data.
   * \return crc16 calculated.
   */
    uint16_t crc16CalcTable(const uint16_t *table, uint16_t length, uint8_t *data);
#elif defined(USETABLE)
    /*!
     * \brief Function to dynamic generate a lookup table given the initial value and mask to fast crc calculation.
     * \note to activate this define USEBIT, MASK=mask and INITVALUE=init with compiler's -D option.
     * \param initValue indicates the initial value for crc calculation, it will be stored in a static structure.
     * \param mask past the mask for crc calculation.
     * \return crc16 calculated.
     */
    void crc16TableGen(uint16_t initValue, uint16_t mask);
    /*!
     * \brief Function to compute the crc with a table generated with \sa crc16TableGen
     * \note to activate this define USEBIT, MASK=mask and INITVALUE=init with compiler's -D option.
     * \param length indicates the length of the data to process.
     * \param *data pointer to the data used to calculate crc.
     * \return crc16 calculated.
     */
    uint16_t crc16CalcTable(uint16_t length, uint8_t *data);
#endif
#endif
