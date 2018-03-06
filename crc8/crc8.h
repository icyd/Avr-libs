/*! 
 *\file crc8.h
 *
 * \author Alberto Vázquez
 * \date 3/5/2018
 *
 * Library to calculate crc8 using initial value and mask, as parameter. All functions will work with pointer to the input data, so arrays can be given.
 * Could be use with dynamically given masks and initial values, or with constants. In important to take into consideration that if muliple masks are required trough the program, the dynamic version is the best suited (overall the bitwise). But if only one mask will be required, the smaller code generated is with the table version, with a constant lookup table.
 *
 * To compile the static versions of the function please define CRC8_MASK and CRC8_INIT with option -D of the gcc compiler, or with defines.
 */
#ifndef CRC8_H
#define CRC8_H

#include <stdint.h>

#if defined(CRC8_MASK) && defined(CRC8_INIT)
  /*!
   * \brief Function to calculate crc8, using bitwise calculation, with static definition of initvalue and mask via definition.
   * \note to activate this define USEBIT, CRC8_MASK=mask and CRC8_INIT=init with compiler's -D option.
   * \param length is the length of the data array to be processed.
   * \param *data is a pointer to the data array.
   * \return value of crc calculated.
   */
    uint8_t crc8Calc(uint8_t length, uint8_t *data);
#else
  /*!
   * \brief Function to calculate crc8, with the values of initvalue and mask given as parameters of the function.
   * \note to activate this define USEBIT only.
   * \param initvalue give the initial value to generate the crc.
   * \param mask is the mask to calculate the crc.
   * \param length is the length of the data array to be processed.
   * \param *data pointer to the data array.
   * \return return value of crc calculated.
   */
    uint8_t crc8Calc(uint8_t initvalue, uint8_t mask, uint8_t length,\
        uint8_t *data);
#endif
#endif
