/**
 * @file digipot.ino
 * @author Joseph Telaak
 * @version 0.1
 * @date 2022-05-14
 * 
 * @brief Example code to control the MCP4151 digital potentiometer.
 * 
 * @copyright Copyright (c) 2022
 * 
 */


// Include the Digital Potentiometer Library
#include <mcp4xxx.h>
using namespace icecave::arduino;

// Create a global pointer to the Digital Potentiometer
MCP4XXX* digi_pot;

// Resolution of the Digital Potentiometer (i.e. 8-bit = 255 or 2^8-1)
#define DIGIPOT_RES 255

// SPI Chip Select Pin (ANY Availaible Pin; No PWM Required)
#define DIGIPOT_PIN 9

// Arduino Setup Function (Run Once)
void setup() {
    // Setup Digital Potentiometer
    digi_pot = new MCP4XXX(DIGIPOT_PIN);
    
    // Zeroes the Potentiometer position by decrementing 256 times
    for (int i = 0; i < DIGIPOT_RES; i++) {
        digi_pot -> decrement();
        
    }
}

// Arduino Perodic Loop
void loop() {
    // 200ms Delay
    delay(200);

    // Increments the Potentiometer postion
    digi_pot -> increment();

}