#include "test_data_builders.h"
#include "channel.h"

IPAddressBuilderStruct anIPAddress() {
    IPAddressBuilderStruct builder = { .bytes = {127, 0, 0, 1 } };
    return builder;
}

IPAddress buildIPAddress(IPAddressBuilderStruct abs) {
    IPAddress ipaddress = { .bytes = {abs.bytes[0], abs.bytes[1], abs.bytes[2], abs.bytes[3] } };
    return ipaddress;
}
