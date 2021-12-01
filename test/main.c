#include <cgreen/cgreen.h>
#include "test_channel.c"

TestSuite *channel_tests_suite() {
    TestSuite *suite = create_test_suite();
    add_test_with_context(suite, Channel, the_default_channel);
    return suite;
}


int main(int argc, char **argv) {
    TestSuite *suite = create_test_suite();
    add_suite(suite, channel_tests_suite());
    if (argc > 1) {
        return run_single_test(suite, argv[1], create_text_reporter());
    }
    return run_test_suite(suite, create_text_reporter());
}
