#ifndef LISTENER_H
#define LISTENER_H


#include "Monitor.h"
#include "Controller.h"
#include "CardReader.h"
#include "ManageButton.h"



class Listener
{
private:
    
    uint8_t rfidData[16];
    CardReader *rfid;
    ManageButton *modeButton;
    Controller *controller;

public:
    Listener();
    ~Listener();
    bool checkRfid();
    void checkEvent();


};

#endif