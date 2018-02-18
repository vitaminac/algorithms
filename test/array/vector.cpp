#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "array/vector.h"
#include <iostream>

BOOST_AUTO_TEST_SUITE(VectorTest)

	BOOST_AUTO_TEST_CASE(DotTest) {
		const int size = 5;
		int * arr1 = new int[5]{2, 3, 5, 7, 11};
		int * arr2 = new int[5]{13, 17, 23, 31, 37};
		int * arr3 = new int[5]{26, 51, 115, 217, 407};
		const auto v1 = Vector <int>(arr1, size);
		const auto v2 = Vector <int>(arr2, size);
		const auto v3 = Vector <int>(arr3, size);
		const auto r = v1 * v2;
		BOOST_CHECK_EQUAL(v3, *r);
		delete r;
	}

BOOST_AUTO_TEST_SUITE_END()
