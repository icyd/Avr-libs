# Avr-libs
## Library of exponential weighted moving average

This library is design to calculate the ewma of samples given the initial value of the average, the numerator and denominator of $$\alpha_1 = \frac{NUM}{DEN}$$, via `gcc -DINITVALUE=0 -DNUM=3 -DDEN=4` (the initial value is optional).

The calculation perform will be: ![equation](http://www.sciweavers.org/tex2img.php?eq=%24%24y_k%20%3D%20%5Calpha_1%20y_%7Bk-1%7D%20%2B%20%5Calpha_2%20x_k%2C%20where%20%5C%3B%20%5Calpha_2%20%3D%201%20-%20%5Cfrac%7BNUM%7D%7BDEN%7D%24%24&bc=White&fc=Black&im=jpg&fs=12&ff=arev&edit=0) 

__Documentation:__ to generate documentation of the source code use `doxygen doxygen.conf` and also *MATHJAX* is required.

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
