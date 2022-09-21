#ifndef GOLFMEMBERSHIPMANAGER_H
#define GOLFMEMBERSHIPMANAGER_H

#include "Listener.h"


class GolfMembershipManager
{
public:
    GolfMembershipManager();
    virtual ~GolfMembershipManager();
    void run();

private:
    Listener *listener;

   
};

#endif