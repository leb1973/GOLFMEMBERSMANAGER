#include <iostream>
#include "mfrc522.h"
#include "Listener.h"

int main(void)
{
    mfrc522 rfid(new SPI(10, 3000000));  // 3Mz
    Listener *listener = new Listener(&rfid);
    
    while (1)
    {
        listener -> checkEvent();
        delay(1000);
        printf("hihi\n");
    }
}