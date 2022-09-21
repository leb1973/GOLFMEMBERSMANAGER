#ifndef MEMBERSENTITY_H
#define MEMBERSENTITY_H

#include <vector>
#include <iostream>
#include "MemberInfo.h"
#include <string>

class MembersEntity
{
public:
    MembersEntity();
    virtual ~MembersEntity();
    void loadMembersInfo();
    void printMembersInfo(int index);
    void printMembersInfo(std::string name);
    void printMembersInfo(int *cardNum);
    void addMembersInfo(MemberInfo member);
    void memoryToDB();
    bool delMembersInfo(int *cardNum);
    bool findMembersInfo(int *cardNum);
    bool findMembersInfo(std::string name);
    // void addmemberInfo(MemberInfo member);
    // void delmemberInfo(MemberInfo member);
    // void MakeDBMembersInfo();

private:
    std::vector<MemberInfo> vecMembersList;
    MemberInfo memberInfo;
    FILE *fpDBData;
    FILE *fpDBData2;

};

#endif