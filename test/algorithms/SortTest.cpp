#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <memory>
#include <vector>
#include "function/sort/SortingAlgorithm.h"
#include "function/sort/InplaceSort.h"
#include "function/sort/QuickSort.h"
#include "function/Comparator.h"
using std::vector;
using std::make_unique;
using std::unique_ptr;

struct FSort {
	FSort () {
		BOOST_TEST_MESSAGE("setup fixture");
		this->soters.push_back(make_unique <InplaceSort <int>>(DefaultComparator <int>));
		this->soters.push_back(make_unique <QuickSort <int>>(DefaultComparator <int>));
	}

	~FSort () {
		BOOST_TEST_MESSAGE("teardown fixture");
	}

	vector <unique_ptr <SortingAlgorithm <int>>> soters = vector <unique_ptr <SortingAlgorithm <int>>>();
};

BOOST_FIXTURE_TEST_SUITE(SortTest, FSort)
	BOOST_AUTO_TEST_CASE(SimpleTest) {
		for (const auto & sorter : this->soters) {
			int arr[10] = {5, 4, 8, 3, 6, 2, 9, 1, 7, 0};
			sorter->sort(arr, 10);
			for (int i = 0; i < 10; i++) {
				BOOST_CHECK_EQUAL(i, arr[i]);
			}
		}
	}

BOOST_AUTO_TEST_SUITE_END()
