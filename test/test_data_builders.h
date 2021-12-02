#pragma once
#include "channel.h"

typedef struct {
    char bytes[4];
} IPAddressBuilderStruct;


IPAddressBuilderStruct anIPAddress();

IPAddress buildIPAddress(IPAddressBuilderStruct abs);
