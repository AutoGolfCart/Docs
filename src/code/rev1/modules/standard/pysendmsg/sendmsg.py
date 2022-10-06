# PySerial (Tested with v3.3)
import serial

# Connect to our Arduino-based CAN Adapter
arduino = serial.Serial("/dev/tty.usbmodem141101", 115200, timeout=.1)

# Send CAN Message with our custom adapter implementation
command = ">(4081) 10 1 12 1 255 0 0 0"
message = bytes(command.encode())
arduino.write(message)