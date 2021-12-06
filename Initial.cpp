#include "ApprovalTests.hpp"
#include "catch2/catch.hpp"

extern "C"
{
//#include "sample.h"
}

struct IPAddress {
    char bytes[4];
};

struct IPAddressBuilderStruct {
    char bytes[4];
};

IPAddressBuilderStruct anIPAddress() {
    IPAddressBuilderStruct builder { .bytes = {127, 0, 0, 1 } };
    return builder;
}

IPAddress buildIPAddress(IPAddressBuilderStruct abs) {
    IPAddress ipaddress = { .bytes = {abs.bytes[0], abs.bytes[1], abs.bytes[2], abs.bytes[3] } };
    return ipaddress;
}

IPAddressBuilderStruct withIP(char a, char b, char c, char d, IPAddressBuilderStruct builder) {
    builder.bytes[0] = a;
    builder.bytes[1] = b;
    builder.bytes[2] = c;
    builder.bytes[3] = d;
    return builder;
}

enum Protocol {
    LEGACY_TCP, LEGACY_UDP
};

struct Channel {
    int port;
    Protocol protocol;
    IPAddress address;
};

struct ChannelBuilderStruct {
    int port;
    Protocol protocol;
    IPAddress address;
};

ChannelBuilderStruct aChannel() {
    ChannelBuilderStruct builder {
        .port = 1,
        .protocol = LEGACY_TCP,
        .address = buildIPAddress(anIPAddress())};
    return builder;
}

ChannelBuilderStruct withPort(int port, ChannelBuilderStruct builder) {
    builder.port = port;
    return builder;
}

ChannelBuilderStruct withProtocol(Protocol protocol, ChannelBuilderStruct builder) {
    builder.protocol = protocol;
    return builder;
}

ChannelBuilderStruct withChannelAddress(IPAddress address, ChannelBuilderStruct builder) {
    builder.address = address;
    return builder;
}

Channel buildChannel(ChannelBuilderStruct cbs) {
    Channel channel { .port = cbs.port, .protocol = cbs.protocol, .address = cbs.address };
    return channel;
}

TEST_CASE ("ChannelBuilder") {
    SECTION("setting port to 2") {
        Channel channel = buildChannel(
                withPort(2, aChannel())
        );
        REQUIRE(channel.port == 2);
    }
    SECTION("setting protocol to LEGACY_UDP") {
        Channel channel = buildChannel(
                withProtocol(LEGACY_UDP, aChannel())
        );
        REQUIRE(channel.protocol == LEGACY_UDP);
    }
    SECTION("setting ip address") {
        Channel channel = buildChannel(
                withChannelAddress(
                        buildIPAddress(
                        withIP(1, 1, 1, 1, anIPAddress())
                ),
                aChannel())
        );
        REQUIRE(channel.address.bytes[0] == 1);
        REQUIRE(channel.address.bytes[1] == 1);
        REQUIRE(channel.address.bytes[2] == 1);
        REQUIRE(channel.address.bytes[3] == 1);
    }
    SECTION("setting 2 parameters") {
        Channel channel = buildChannel(
                withPort(2,
                         withProtocol(LEGACY_UDP,
                                      aChannel()))
        );
        REQUIRE(channel.port == 2);
        REQUIRE(channel.protocol == LEGACY_UDP);
    }
    SECTION("setting simple and nested fields") {
        Channel channel = buildChannel(
                    withPort(2,
                    withProtocol(LEGACY_UDP,
                    withChannelAddress(
                        buildIPAddress(
                                withIP(1, 1, 1, 1, anIPAddress())
                        ),
                        aChannel()))
        ));
        REQUIRE(channel.port == 2);
        REQUIRE(channel.protocol == LEGACY_UDP);
        REQUIRE(channel.address.bytes[0] == 1);
        REQUIRE(channel.address.bytes[1] == 1);
        REQUIRE(channel.address.bytes[2] == 1);
        REQUIRE(channel.address.bytes[3] == 1);
    }
}


/* BELOW: Converted to cgreen
TEST_CASE ("IPAdressBuilder") {
    SECTION("the default address") {
        IPAddress address = buildIPAddress(anIPAddress());
        REQUIRE(address.bytes[0] == 127);
        REQUIRE(address.bytes[1] == 0);
        REQUIRE(address.bytes[2] == 0);
        REQUIRE(address.bytes[3] == 1);
    }
    SECTION("switching to another famous ip address") {
        IPAddress address = buildIPAddress(
                withIP(1, 1, 1, 1,
                    anIPAddress())

        );
        REQUIRE(address.bytes[0] == 1);
        REQUIRE(address.bytes[1] == 1);
        REQUIRE(address.bytes[2] == 1);
        REQUIRE(address.bytes[3] == 1);
    }
}
    SECTION("the default channel") {
        Channel channel = buildChannel(aChannel());
        REQUIRE(channel.port == 1);
        REQUIRE(channel.protocol == LEGACY_TCP);
        REQUIRE(channel.address.bytes[0] == 127);
        REQUIRE(channel.address.bytes[1] == 0);
        REQUIRE(channel.address.bytes[2] == 0);
        REQUIRE(channel.address.bytes[3] == 1);
    }

 */
