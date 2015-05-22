#include "Circle.h"
#include <boost/test/unit_test.hpp>

using namespace poly;

BOOST_AUTO_TEST_CASE(hitTestCenter) {
  Circle c({0, 0}, 1);
  BOOST_CHECK(c.hitTest({0, 0}));
}

BOOST_AUTO_TEST_CASE(hitTestEdge) {
  Circle c({4, 0}, 4);
  BOOST_CHECK(c.hitTest({0, 0}));
}

BOOST_AUTO_TEST_CASE(histTestNegative) {
  Circle c({4, 4}, 4);
  BOOST_CHECK(!c.hitTest({0, 0}));
}
