#pragma once
#include <shaiya/include/common.h>
#include <shaiya/include/common/Country.h>
#include <shaiya/include/common/Equipment.h>
#include <shaiya/include/common/Family.h>
#include <shaiya/include/common/Gems.h>
#include <shaiya/include/common/Grow.h>
#include <shaiya/include/common/Job.h>
#include <shaiya/include/common/PartyType.h>
#include <shaiya/include/common/Sex.h>
#include "include/shaiya/include/SNode.h"

namespace shaiya
{
    #pragma pack(push, 1)
    struct CloneUser
    {
        SNode node;           //0x00
        bool dead;            //0x08
        bool sitting;         //0x09
        Country country;      //0x0A
        Family family;        //0x0B
        UINT8 hair;           //0x0C
        UINT8 face;           //0x0D
        UINT8 size;           //0x0E
        Job job;              //0x0F
        Sex sex;              //0x10
        PartyType partyType;  //0x11
        Grow grow;            //0x12
        PAD(1);
        UINT32 kills;         //0x14
#ifdef SHAIYA_EP6_4_PT
        // 0x18
        ShapeEquipment<17> equipment;
#else
        // 0x18
        ShapeEquipment<8> equipment;
#endif
        // 6.4: 0x4B, 5.4: 0x30
        CharArray<21> charName;
        // 6.4: 0x60, 5.4: 0x45
        CloakBadge cloakBadge;
        // 6.4: 0x66, 5.4: 0x4B
        CharArray<25> guildName;
        // 6.4: 0x7F, 5.4: 0x64
        UINT8 packetLength;
#ifndef SHAIYA_EP6_4_PT
        PAD(3);
#endif
        // 6.4: 0x80, 5.4: 0x68
    };
    #pragma pack(pop)

#ifdef SHAIYA_EP6_4_PT
    static_assert(sizeof(CloneUser) == 0x80);
#else
    static_assert(sizeof(CloneUser) == 0x68);
#endif
}
