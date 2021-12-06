#include <cgreen/cgreen.h>
#include "channel.h"
#include "test_data_builders.h"

Describe(Channel);

BeforeEach(Channel) {}

AfterEach(Channel) {}

Ensure(Channel, the_default_address) {
    IPAddress address = buildIPAddress(anIPAddress());
    assert_that(address.bytes[0], is_equal_to(127));
    assert_that(address.bytes[1], is_equal_to(0));
    assert_that(address.bytes[2], is_equal_to(0));
    assert_that(address.bytes[3], is_equal_to(1));
}

Ensure(Channel, switching_to_a_famous_ip_address) {
    IPAddress address =
            buildIPAddress(
                    withIP(1, 1, 1, 1,
                           anIPAddress()));
    assert_that(address.bytes[0], is_equal_to(1));
    assert_that(address.bytes[1], is_equal_to(1));
    assert_that(address.bytes[2], is_equal_to(1));
    assert_that(address.bytes[3], is_equal_to(1));
}

Ensure(Channel, the_default_channel) {
    Channel channel = buildChannel(aChannel());
    assert_that(channel.port, is_equal_to(1));
//    REQUIRE(channel.protocol == LEGACY_TCP);
//    REQUIRE(channel.address.bytes[0] == 127);
//    REQUIRE(channel.address.bytes[1] == 0);
//    REQUIRE(channel.address.bytes[2] == 0);
//    REQUIRE(channel.address.bytes[3] == 1);
}
