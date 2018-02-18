#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <iostream>

#include "array/matrix.h"

BOOST_AUTO_TEST_SUITE(MatrixTest)

	BOOST_AUTO_TEST_CASE(PrintTest) {
		const auto m = Matrix <int>::eye(5);
		std::cout << *m << std::endl;
		delete m;
	}

BOOST_AUTO_TEST_SUITE_END()
