#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "sort/sorting.h"

struct FSorting {
	FSorting () {
	}

	~FSorting () {
		delete[] arr;
	}

	int * arr = new int[10]{3, 6, 2, 8, 7, 9, 5, 4, 1, 0};
};

BOOST_FIXTURE_TEST_SUITE(SortingTest, FSorting)
	BOOST_AUTO_TEST_CASE(InplaceSortTesting) {
		Sorting <int>::inplacesort(this->arr, 10);
		for (int i = 0; i < 10; i++) {
			BOOST_CHECK_EQUAL(i, this->arr[i]);
		}
	}

BOOST_AUTO_TEST_SUITE_END()
