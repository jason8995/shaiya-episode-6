#pragma once
#include <include/shaiya/common.h>

namespace shaiya
{
    #pragma pack(push, 1)
    struct SConnectionTBaseReconnect
    {
        static void Send(void* clientTo, void* buf, int len);
    };
    #pragma pack(pop)
}
