#include "ApprovalTests.hpp"
#include "catch2/catch.hpp"

extern "C"
{
//#include "sample.h"
}
enum Protocol {
    LEGACY_TCP, LEGACY_UDP
};

struct Channel {
    int port;
    Protocol protocol;
};

struct ChannelBuilderStruct {
    int port;
    Protocol protocol;
};

ChannelBuilderStruct aChannel() {
    ChannelBuilderStruct builder { .port = 1, .protocol = LEGACY_TCP };
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

Channel buildChannel(ChannelBuilderStruct cbs) {
    Channel channel { .port = cbs.port, .protocol = cbs.protocol };
    return channel;
}

TEST_CASE ("ChannelBuilder") {
    SECTION("the default channel") {
        Channel channel = buildChannel(aChannel());
        REQUIRE(channel.port == 1);
        REQUIRE(channel.protocol == LEGACY_TCP);
    }
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
    SECTION("setting 2 parameters") {
        Channel channel = buildChannel(
                withPort(2,
                withProtocol(LEGACY_UDP,
                             aChannel()))
        );
        REQUIRE(channel.port == 2);
        REQUIRE(channel.protocol == LEGACY_UDP);
    }
    /*
User aUser = UserBuiler.aUser()      // [x] default
             .withName("John")       // [ ]readably set value
             .withPassword("42abc")
             .build();               // [x]
     */
}


