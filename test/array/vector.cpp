#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "array/vector.h"
#include <iostream>

BOOST_AUTO_TEST_SUITE(VectorTest)

	BOOST_AUTO_TEST_CASE(DotTest) {
		const int size = 5;
		int * arr1 = new int[5];
		int * arr2 = new int[5];
		int * arr3 = new int[5];
		for (int i = 0; i < size; i++) {
			arr1[i] = i;
			arr2[i] = i * i;
			arr3[i] = i * i * i;
		}
		const auto v1 = Vector <int>(arr1, size);
		const auto v2 = Vector <int>(arr2, size);
		const auto v3 = Vector <int>(arr3, size);
		BOOST_CHECK_EQUAL(v3, v1 * v2);
	}

BOOST_AUTO_TEST_SUITE_END()
