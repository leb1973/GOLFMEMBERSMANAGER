#include "MembersManageService.h"
#include <cstring>

MembersManageService::MembersManageService()
{
    membersEntity = new MembersEntity();
    membersManagerState = CARD_READER;
}

MembersManageService::~MembersManageService()
{

}

void MembersManageService::updateStateEvent(std::string devName)
{
    switch (membersManagerState)
    {
        case CARD_READER :
        if(devName == "ModeButton") {
            membersManagerState = CARD_REGISTER;
            printf("changed to CARD_REGISTER state\n");
        }
        break;
        case CARD_REGISTER :
        if (devName == "ModeButton") {
            membersManagerState = CARD_READER;
            printf("changed to CARD_READER state\n");
        }
        break;
    }
}

void MembersManageService::checkCardNumber(int *cardNum)
{
    switch (membersManagerState)
    {
        case CARD_READER :
            if (membersEntity->findMembersInfo(cardNum)) {
                printf("Registered Member!\n");
            }
            else {
                printf("Not Registered Member!\n");
            }
        break;
        case CARD_REGISTER :
        MemberInfo tempMember;
        tempMember.id = 100000;
        strcpy(tempMember.name, "LeeSoonShin");
        strcpy(tempMember.address, "101Dong 123Ho");
        strcpy(tempMember.phoneNumber, "010-1234-5678");
        memcpy(tempMember.cardNum, cardNum,sizeof(tempMember.cardNum));
        membersEntity->addMembersInfo(tempMember);
        printf("Member Registered!\n");
        break;
    }
}