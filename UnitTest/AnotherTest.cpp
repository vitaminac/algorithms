#include <boost/test/unit_test.hpp>
#include "base.h"

BOOST_AUTO_TEST_SUITE(AnotherTest)

	BOOST_AUTO_TEST_CASE(TestingDelete) {
		Object * o = new Object(1);
		BOOST_CHECK_EQUAL(1, o->getB());
		Object * & o2 = o;
		BOOST_CHECK_EQUAL(o, o2);
		delete o2;
		auto x = o->getB();
		BOOST_CHECK_EQUAL(1, x);
	}

	BOOST_AUTO_TEST_CASE(TestingDeleteOnReference) {
		BOOST_CHECK_EQUAL(2 * 9, 18);
	}

BOOST_AUTO_TEST_SUITE_END()
