# Avr-libs
## Library to calculate crc8

This library is design to realize calculation of crc8 (with diferent initial values and masks) over a variable size array of data.

The value of the initial seed to the crc calculation and the mask value, could be predefined if only one value will be used (through compiler's options `-DINITVALUE=init` and `-DMASK=mask`). Both definitions have to be given to use those methods.

When mask and initial values are required to change through the code, and the table based solution is required the function `crc16GenTable` needs to be called before any attempt to calculate the crc.

__Documentation:__ to generate documentation of the source code use `doxygen doxygen.conf`.

****************************************************************************
Firmware Copyright (C):
    2018 - Alberto Vazquez aka IcyD

        This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

        This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

        You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

****************************************************************************
