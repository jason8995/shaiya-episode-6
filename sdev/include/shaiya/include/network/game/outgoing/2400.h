#pragma once
#include <shaiya/include/common.h>
#include <shaiya/include/common/CraftName.h>
#include <shaiya/include/common/Gems.h>

// CUser::PacketPvP

namespace shaiya
{
    #pragma pack(push, 1)
    struct PvPExchangeItemOutgoing
    {
        UINT16 opcode{ 0x240D };
        UINT8 destSlot;
        UINT8 type;
        UINT8 typeId;
        UINT8 count;
        UINT16 quality;
        Gems gems;
        CraftName craftName;
    };
    #pragma pack(pop)

    #pragma pack(push, 1)
    struct PvPExchangeItemOutgoing2
    {
        UINT16 opcode{ 0x240D };
        UINT8 destSlot;
        UINT8 type;
        UINT8 typeId;
        UINT8 count;
        UINT16 quality;
        ULONG fromDate;
        ULONG toDate;
        Gems gems;
        CraftName craftName;
    };
    #pragma pack(pop)
}
