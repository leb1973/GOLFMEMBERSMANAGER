#include "ManageButton.h"

ManageButton::ManageButton(int pin, std::string name)
: Button(pin)
{
    buttonData.devName = name;
}

ManageButton::~ManageButton()
{

}

bool ManageButton::checkButton()
{
    if (getState() == RELEASE_ACTIVE){
        return true;
    }
    else{
    return false;
    }
}

DeviceData ManageButton::getButtonData()
{
    // cardData.devName = "ModeButton";
    buttonData.devData.clear();
    buttonData.devData.push_back(1);
    return buttonData;
}