#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE "polyglot-cpp"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(truth) {
  BOOST_CHECK(true);
}
