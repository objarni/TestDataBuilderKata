#include <cgreen/cgreen.h>
#include "channel.h"
#include "test_data_builders.h"

Describe(Channel);
BeforeEach(Channel) {}
AfterEach(Channel) {}

Ensure(Channel, the_default_address) {
    IPAddress address = buildIPAddress(anIPAddress());
    assert_that(address.bytes[0], is_equal_to(127));
}

/*
    SECTION("the default address") {
        IPAddress address = buildIPAddress(anIPAddress());
        REQUIRE(address.bytes[0] == 127);
        REQUIRE(address.bytes[1] == 0);
        REQUIRE(address.bytes[2] == 0);
        REQUIRE(address.bytes[3] == 1);
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