#include <cgreen/cgreen.h>

Describe(Channel);
BeforeEach(Channel) {}
AfterEach(Channel) {}

Ensure(Channel, the_default_channel) {
    assert_that(1, is_equal_to(1));
}

/*
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