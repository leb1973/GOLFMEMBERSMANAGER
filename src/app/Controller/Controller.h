#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include "Monitor.h"
#include "DeviceData.h"
#include "MembersManageService.h"

class Controller
{
public:
    Controller();
    virtual ~Controller();
    void updateEvent(DeviceData data);

private:
    Monitor *monitor;
    MembersManageService *membersManageService;
    

};

#endif