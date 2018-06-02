#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "object.h"
#include "function/comparator.h"

struct FObject {
	FObject () {
		this->objects.emplace_back(1);
		this->objects.emplace_back(9);
		this->objects.emplace_back(-1);
		this->objects.emplace_back(0);
		this->objects.emplace_back(0);
	}

	std::vector <Object> objects = std::vector <Object>();
};

BOOST_FIXTURE_TEST_SUITE(ADTTest, FObject)

	BOOST_AUTO_TEST_CASE(TestingTotalOrder) {
		const Comparator <Object> comparator = DefaultComparator <Object>;
		for (const auto & o1 : this->objects) {
			for (const auto & o2 : this->objects) {
				BOOST_CHECK_EQUAL(comparator(o1, o2) == 0, o1.getB() == o2.getB());
				BOOST_CHECK_EQUAL(comparator(o1, o2) < 0, o1.getB() < o2.getB());
				BOOST_CHECK_EQUAL(comparator(o1, o2) <= 0, o1.getB() <= o2.getB());
				BOOST_CHECK_EQUAL(comparator(o1, o2) > 0, o1.getB() > o2.getB());
				BOOST_CHECK_EQUAL(comparator(o1, o2) >= 0, o1.getB() >= o2.getB());
			}
		}
	}

	//BOOST_AUTO_TEST_CASE(TestingOperatorOverloadingPointer) {
	//	const Comparator <Object *> comparator = DefaultComparator <Object *>;
	//	for (auto o1 : this->objects) {
	//		Object * po1 = &o1;
	//		for (auto o2 : this->objects) {
	//			Object * po2 = &o2;
	//			BOOST_CHECK_EQUAL(comparator(po1, po2) == 0, o1.getB() == o2.getB());
	//		}
	//	}
	//}

BOOST_AUTO_TEST_SUITE_END()
