#include "test_data_builders.h"
#include "channel.h"

IPAddressBuilderStruct anIPAddress() {
    IPAddressBuilderStruct builder = { .bytes = {127, 0, 0, 1 } };
    return builder;
}

IPAddressBuilderStruct withIP(char a, char b, char c, char d, IPAddressBuilderStruct builder) {
    builder.bytes[0] = a;
    builder.bytes[1] = b;
    builder.bytes[2] = c;
    builder.bytes[3] = d;
    return builder;
}

IPAddress buildIPAddress(IPAddressBuilderStruct abs) {
    IPAddress ipaddress = { .bytes = {abs.bytes[0], abs.bytes[1], abs.bytes[2], abs.bytes[3] } };
    return ipaddress;
}

