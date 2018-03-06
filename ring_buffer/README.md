# Avr-libs
## Circular buffer with variable size

Implementation of circular buffer in C.

To use it compile it with option -D of gcc: `gcc -D RING_BUFFER_SIZE=(desired buffer size)`.

By defaults the element stored by the buffer are of type `uint8_t`, but it can be changed to other type using the definition `gcc -D RING_BUFFER_DATATYPE=(data type desired)`.

The maximun length of the buffer is 2^16 = 65536.

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

    k***************************************************************************
