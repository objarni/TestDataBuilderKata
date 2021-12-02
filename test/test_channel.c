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
    assert_that(address.bytes[0], is_equal_to(127));
    assert_that(address.bytes[1], is_equal_to(0));
    assert_that(address.bytes[2], is_equal_to(0));
    assert_that(address.bytes[3], is_equal_to(1));
}

/*
        IPAddress address = buildIPAddress(
                withIP(1, 1, 1, 1,
                    anIPAddress())

        );
        REQUIRE(address.bytes[0] == 1);
        REQUIRE(address.bytes[1] == 1);
        REQUIRE(address.bytes[2] == 1);
        REQUIRE(address.bytes[3] == 1);
 */