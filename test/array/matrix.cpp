#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <iostream>

#include "array/matrix.h"

struct FMatrix {
	const Matrix <int> * A = Matrix <int>::square(new int[9]{1, 2, 3, 4, 5, 6, 7, 8, 9}, 3);
	const Matrix <int> * B = Matrix <int>::square(new int[9]{9, 8, 7, 6, 5, 4, 3, 2, 1}, 3);
	const Matrix <int> * C_Sum = Matrix <int>::square(new int[9]{10, 10, 10, 10, 10, 10, 10, 10, 10}, 3);
	const Matrix <int> * C_Sub = Matrix <int>::square(new int[9]{-8, -6, -4, -2, 0, 2, 4, 6, 8}, 3);
	const Matrix <int> * C_Multiply = Matrix <int>::square(new int[9]{30, 24, 18, 84, 69, 54, 138, 114, 90}, 3);

	~FMatrix () {
		delete A;
		delete B;
		delete C_Sum;
		delete C_Sub;
		delete C_Multiply;
	}
};

BOOST_FIXTURE_TEST_SUITE(MatrixTest, FMatrix)

	BOOST_AUTO_TEST_CASE(PrintTest) {
		const auto m = Matrix <int>::eye(5);
		std::cout << *m << std::endl;
		delete m;
	}

	BOOST_AUTO_TEST_CASE(SumTest) {
		const auto R = (*this->A) + (*this->B);
		BOOST_CHECK_EQUAL(*(this->C_Sum), *R);
	}

	BOOST_AUTO_TEST_CASE(SubTest) {
		const auto R = (*this->A) - (*this->B);
		BOOST_CHECK_EQUAL(*(this->C_Sub), *R);
	}

	BOOST_AUTO_TEST_CASE(MultiplyTest) {
		const auto R = (*this->A) * (*this->B);
		BOOST_CHECK_EQUAL(*(this->C_Multiply), *R);
	}

BOOST_AUTO_TEST_SUITE_END()
