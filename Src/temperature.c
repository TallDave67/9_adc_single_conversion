/*
 * temperature.c
 *
 *  Created on: 13 Dec 2021
 *      Author: bellisd
 */
#include <math.h>
#include "temperature.h"

#define RS (10000.0) //resistor in series with thermistor
#define VCC (3.3) //supplied voltage

#define A (0.001125308852122)
#define B (0.000234711863267)
#define C (0.000000085663516)

/* Steinhart - Hart Equation 1/T = A+B(LnR)+C(LnR)^3
 * T is Temperature in degrees Kelvin
 * LnR is the Natural Log of the measured thermistor resistance
 * A, B and C are the manufacturer coefficients
 */

float get_temperature_from_voltage(uint32_t value)
{
	float R = (RS * (value - VCC)) / value;
	float LnR = log(R);
    float T = 1 / (A + (B + (C * LnR * LnR ))* LnR );
    T = T - 273.15; // k to c conversion
    return T;
}
