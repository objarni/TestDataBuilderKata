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
    assert_that(channel.address.bytes[0], is_equal_to(127));
    assert_that(channel.address.bytes[1], is_equal_to(0));
    assert_that(channel.address.bytes[2], is_equal_to(0));
    assert_that(channel.address.bytes[3], is_equal_to(1));
    assert_that(channel.protocol, is_equal_to(LEGACY_TCP));
}

Ensure(Channel, setting_port_to_2) {
    Channel channel = buildChannel(
            withPort(2, aChannel())
    );
    assert_that(channel.port, is_equal_to(2));
}

Ensure(Channel, setting_protocol_to_legacy_udp) {
    Channel channel = buildChannel(
            withProtocol(LEGACY_UDP, aChannel())
    );
    assert_that(channel.protocol, is_equal_to(LEGACY_UDP));
}

Ensure(Channel, setting_2_channel_parameters) {
    Channel channel = buildChannel(
            withPort(2,
                     withProtocol(LEGACY_UDP,
                                  aChannel()))
    );
    assert_that(channel.port, is_equal_to(2));
    assert_that(channel.protocol, is_equal_to(LEGACY_UDP));
}

Ensure(Channel, setting_address_of_channel) {
    Channel channel = buildChannel(
            withChannelAddress(
                    buildIPAddress(
                            withIP(1, 1, 1, 1, anIPAddress())
                    ),
                    aChannel())
    );
    assert_that(channel.address.bytes[0], is_equal_to(1));
    assert_that(channel.address.bytes[1], is_equal_to(1));
    assert_that(channel.address.bytes[2], is_equal_to(1));
    assert_that(channel.address.bytes[3], is_equal_to(1));
}

Ensure(Channel, setting_simple_and_nested_fields) {
    Channel channel = buildChannel(
            withPort(2,
                     withProtocol(LEGACY_UDP,
                                  withChannelAddress(
                                          buildIPAddress(
                                                  withIP(1, 1, 1, 1, anIPAddress())
                                          ),
                                          aChannel()))
            ));
    assert_that(channel.port, is_equal_to(2));
    assert_that(channel.protocol, is_equal_to(LEGACY_UDP));
    assert_that(channel.address.bytes[0], is_equal_to(1));
    assert_that(channel.address.bytes[1], is_equal_to(1));
    assert_that(channel.address.bytes[2], is_equal_to(1));
    assert_that(channel.address.bytes[3], is_equal_to(1));
}

