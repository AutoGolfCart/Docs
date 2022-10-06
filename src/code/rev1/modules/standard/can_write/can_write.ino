/**
 * @file can_write.ino
 * @author Joseph Telaak
 * @version 0.1
 * @date 2022-05-14
 * 
 * @brief Example code to send messages the CAN bus
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
struct can_frame can_msg;

// Arduino Setup Function (Run Once)
void setup() {
  // Setup CAN
  mcp2515.reset();
  mcp2515.setBitrate(CAN_125KBPS);
  mcp2515.setNormalMode();

  // Make Message
  can_msg.can_id  = 0x0F6;
  can_msg.can_dlc = 8;
  can_msg.data[0] = 0x8E;
  can_msg.data[1] = 0x87;
  can_msg.data[2] = 0x32;
  can_msg.data[3] = 0xFA;
  can_msg.data[4] = 0x26;
  can_msg.data[5] = 0x8E;
  can_msg.data[6] = 0xBE;
  can_msg.data[7] = 0x86;

}

// Arduino Perodic Loop
void loop() {
  // Send Message
  mcp2515.sendMessage(&can_msg);
  
  // Delay 100ms
  delay(100);

}
