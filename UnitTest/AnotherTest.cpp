#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(AnotherTest)

	BOOST_AUTO_TEST_CASE(TestingIf2x5equals10) {
		BOOST_CHECK_EQUAL(2 * 5, 10);
	}

	BOOST_AUTO_TEST_CASE(TestingIf2x9equals18) {
		BOOST_CHECK_EQUAL(2 * 9, 18);
	}

BOOST_AUTO_TEST_SUITE_END()
