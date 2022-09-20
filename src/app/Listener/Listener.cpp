#include "Listener.h"

Listener::Listener(mfrc522 *rfid)
: rfid(rfid)  // 초기화 ,  mfrc522 *rfid = rfid;
{
     
}

Listener::~Listener()
{

}

void Listener::checkEvent()
{
    uint8_t byte;
    if((byte = rfid -> mfrc522_request(PICC_REQALL, rfidData)) == CARD_FOUND)
    {
        rfid -> mfrc522_get_card_serial(rfidData);
        for(int i = 0; i < 5; i++)
            printf("%02x ", rfidData[i]);
    }
}