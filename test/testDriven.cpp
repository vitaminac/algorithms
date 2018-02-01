#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <iostream>

BOOST_AUTO_TEST_SUITE(TestDriven)

	BOOST_AUTO_TEST_CASE(TestDrivenDev) {
		std::cout << "Test Driven Development" << std::endl;
	}

	BOOST_AUTO_TEST_CASE(BOOSTVersionCheck) {
		BOOST_CHECK(BOOST_VERSION >= 106600);
		std::cout << BOOST_VERSION << std::endl;
	}

BOOST_AUTO_TEST_SUITE_END()
