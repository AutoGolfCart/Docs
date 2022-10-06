/**
 * @brief Get the pedal pos
 * 
 */

void get_pedal_pos() {
    digitalWrite(COM_LED, HIGH);

    int pedal_pos = map(analogRead(PEDAL_POT), 0, 1023, 0, 255);

    struct can_frame can_msg_out;

    can_msg_out.can_id = CAN_ID;
    can_msg_out.can_dlc = CAN_DLC;
    can_msg_out.data[0] = 0x0C;
    can_msg_out.data[1] = 0x0C;
    can_msg_out.data[2] = 0x0A;
    can_msg_out.data[3] = 0x0D;
    can_msg_out.data[4] = 0;
    can_msg_out.data[5] = 0;
    can_msg_out.data[6] = pedal_pos >> 8;
    can_msg_out.data[7] = pedal_pos & 0xFF;

    can.sendMessage(&can_msg_out);
    digitalWrite(COM_LED, LOW);
    
}