#include "MembersEntity.h"
#include <cstring>

MembersEntity::MembersEntity()
{
    
    loadMembersInfo();
    
}

MembersEntity::~MembersEntity()
{

}

void MembersEntity::loadMembersInfo()
{
    fpDBData = fopen("memberLists.bin","r");
    if(fpDBData == NULL){
        printf("file open error!\n");
        return;
    }
    while (fread(&memberInfo, sizeof(MemberInfo), 1, fpDBData))
    {
        vecMembersList.push_back(memberInfo);
    }
    fclose(fpDBData);
}

void MembersEntity::printMembersInfo(int index)
{
    if(index > (int)vecMembersList.size()) {
        fprintf(stderr,"Out of range Member Count!");
        return;
    }
    printf("%04d , %s , %s , %s , %0x-%0x-%0x-%0x-%0x  \n",
    vecMembersList[index].id,
    vecMembersList[index].name,
    vecMembersList[index].address,
    vecMembersList[index].phoneNumber,
    vecMembersList[index].cardNum[0],
    vecMembersList[index].cardNum[1],
    vecMembersList[index].cardNum[2],
    vecMembersList[index].cardNum[3],
    vecMembersList[index].cardNum[4]
    );
}

void MembersEntity::printMembersInfo(std::string name)
{
    for (const auto &member : vecMembersList) {
        if (strcmp(member.name, name.c_str()) == 0) {
            printMembersInfo(member.id);
            return;
        }
    }
}

void MembersEntity:: printMembersInfo(int *cardNum)
{
    for (const auto &member : vecMembersList) {
        if (memcmp(member.cardNum, cardNum,sizeof(member.cardNum)) == 0) {
            printMembersInfo(member.id);
            return;
        }
    }
   
}

bool MembersEntity::findMembersInfo(std::string name)
{
    for (const auto &member : vecMembersList) {
        if (strcmp(member.name, name.c_str()) == 0) {
            printMembersInfo(member.id);
            return true;
        }
    }
    return false;
}

bool MembersEntity:: findMembersInfo(int *cardNum)
{
    for (const auto &member : vecMembersList) {
        if (memcmp(member.cardNum, cardNum,sizeof(member.cardNum)) == 0) {
            printMembersInfo(member.id);
            return true;
        }
    }
    return false;
}

void MembersEntity::addMembersInfo(MemberInfo member)
{
    vecMembersList.push_back(member);
}

bool MembersEntity::delMembersInfo(int *cardNum)
{
    std::vector<MemberInfo>::iterator itrMember;

    for(itrMember = vecMembersList.begin(); itrMember != vecMembersList.end(); itrMember++){
        if (memcmp(itrMember->cardNum, cardNum,sizeof(itrMember->cardNum)) == 0){
            vecMembersList.erase(itrMember);
            return true;
        }
    }
    
    return false;
}

void MembersEntity::memoryToDB()
{
    // //
    // file open
    // // vecMembersList의 배열을 하나씩 read
    // // vecMembersList 값을 file에 vecMembersList 끝까지 write.
    // file close
    // //

    fpDBData = fopen("memberLists.bin","w");
    FILE *fpDBData2 = fopen("membersLists.txt","w");
    if(fpDBData == NULL){
        fprintf(stderr, "file open error!\n");
        return;
    }
    for (const auto &member : vecMembersList) {
        fwrite(&memberInfo, sizeof(MemberInfo), 1, fpDBData);
        fprintf(fpDBData2, "%05d,%s\n",member.id, member.name);
    }
    fclose(fpDBData);
     fclose(fpDBData2);

}