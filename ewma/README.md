# Avr-libs
## Library of exponential weighted moving average

This library is design to calculate the ewma of samples given the initial value of the average, the numerator and denominator of $$\alpha_1 = \frac{NUM}{DEN}$$, via `gcc -DINITVALUE=0 -DNUM=3 -DDEN=4` (the initial value is optional).

The calculation perform will be: $$y_k = \alpha_1 y_{k-1} + \alpha_2 x_k, \quad \alpha_1 = 1 - \frac{NUM}{DEN}$$.

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
