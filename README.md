# Embedded Systems Bare-Metal STM32 Programming from the Ground Up: Program 9

[Code Development follows this Udemy Course](https://www.udemy.com/course/embedded-systems-bare-metal-programming/)

## Specs

Host

* MS Windows 10.0.19042
* STM32CubeIDE 1.8.0
* RealTerm 2.0.0.70

Device

* STM32F401RE chip
* STM32 Nucleo-64 development board

## Description

This program demonstrates how to convert a sensor's analog signal to a digital signal.

We use a temperature sensor (variable resistor) to provide our input analog signal.

## Design

Schematic Diagram of Input Sensor

![Schematic Diagram](Design/STM32F4-9_adc_single_conversion-temperature-schematic_diagram.png)

Breadboard Circuit connected to Nucleo-64

![Breadboard Circuit](Design/STM32F4-9_adc_single_conversion-temperature-hardware.png)

## Output

### Video of Debugger

![Debugger shows changing Analog Input and Digital Output](Output/STM32F4-9_adc_single_conversion-temperature.mp4)

