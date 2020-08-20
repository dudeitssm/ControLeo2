// This library controls the functions of ControLeo
//  - LCD display and backlight
//  - Buzzer
//  - Thermocouple

// Written by Peter Easton
// Released under WTFPL license
//
// Change History:
// 14 August 2014        Initial Version
// 19 August 2020     Changed pinout for Controleo2 DIY Toner Transfer Copperclad Etched Build

#ifndef CONTROLEO2_H
#define CONTROLEO2_H

#include "ControLeo2_LiquidCrystal.h"
#include "ControLeo2_MAX31855.h"


// Defines for the 2 buttons
#define CONTROLEO_BUTTON_TOP_PIN     13    // Top button is on D13
#define CONTROLEO_BUTTON_BOTTOM_PIN  5    // Bottom button is on D5
#define CONTROLEO_BUTTON_NONE        0
#define CONTROLEO_BUTTON_TOP         1    // S1
#define CONTROLEO_BUTTON_BOTTOM      2    // S2

// The Buzzer is on D3
#define CONTROLEO_BUZZER_PIN         3



#endif // CONTROLEO2_H
