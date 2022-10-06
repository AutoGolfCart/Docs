/**
 * @file can_read.ino
 * @author Joseph Telaak
 * @version 0.1
 * @date 2022-05-14
 * 
 * @brief Example code to monitor the CAN bus
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// Include CAN Library
#include <mcp2515.h>

// SPI Chip Select Pin (ANY Availaible Pin; No PWM Required)
#define CAN_CS 10

// CAN Adapter Object
MCP2515 mcp2515(CAN_CS);

// CAN Message Pointer
struct can_frame canMsg;

// Arduino Setup Function (Run Once)
void setup() {
  // Arduino Begin Serial Monitor (Not required for normal operation)
  Serial.begin(115200);

  // Setup the Adapter
  mcp2515.reset();
  mcp2515.setBitrate(CAN_125KBPS);
  mcp2515.setNormalMode();

  // Print output header
  Serial.println("------- CAN Read ----------");
  Serial.println("ID  DLC   DATA");

}

// Arduino Perodic Loop
void loop() {
  // If the message is valid
  if (mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK) {
    // Print CAN Header ID
    Serial.print(String(canMsg.can_id) + " "); 

    // Print CAN Header Data Length
    Serial.print(String(canMsg.can_dlc) + " "); 
    
    // Print the CAN Data
    for (int i = 0; i < canMsg.can_dlc; i++)  {  
      Serial.print(canMsg.data[i]);
      Serial.print(" ");

    }

    // New Line
    Serial.println();   

  }
}