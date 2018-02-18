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

	BOOST_AUTO_TEST_CASE(MultiplyTest) {
		const auto A = Matrix <int>::square(new int[9]{1, 2, 3, 4, 5, 6, 7, 8, 9}, 3);
		const auto B = Matrix <int>::square(new int[9]{9, 8, 7, 6, 5, 4, 3, 2, 1}, 3);
		const auto C = Matrix <int>::square(new int[9]{30, 24, 18, 84, 69, 54, 138, 114, 90}, 3);
		const auto R = (*A) * (*B);
		BOOST_CHECK_EQUAL(*C, *R);
	}

BOOST_AUTO_TEST_SUITE_END()
