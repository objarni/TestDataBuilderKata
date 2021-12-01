#include <cgreen/cgreen.h>

Describe(Channel);
BeforeEach(Channel) {}
AfterEach(Channel) {}

Ensure(Channel, test_1) {
    assert_that(1, is_equal_to(1));
}