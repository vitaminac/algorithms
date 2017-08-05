#include "aritmetic.hpp"
#include <boost/math/tools/config.hpp>

int sum (int a, int b) {
	// force cast to unsigned, to prevent calling it self
	return sum(static_cast <unsigned long long>(a), static_cast <unsigned long long>(b));
}

unsigned long long sum (unsigned long long a, unsigned long long b) {
	auto sum = a;
	auto carry = b;
	while (carry) {
		auto temp = sum;
		sum = temp ^ carry;
		carry = (temp & carry) << 1;
	}
	return sum;
}

int subtract (int a, int b) {
	return sum(a, sum(~b, 1));
}

int mod (int a, int b) {
	return a % b;
}


// The operation of modular exponentiation calculates the remainder 
// when an integer b (the base) raised to the eth power (the exponent), b^e, is divided by a positive integer m 
// The straightforward method of calculating b^e directly,
// then to take this number modulo m, is unable to apply in case when exp is large enough
int exp_mod (int base, int exp, int m) {
	int result = 1;
	// exponent e be converted to binary notation
	// e = �� n-1, i=0 , ai*2^i; a��{0,1}
	// b^e = b ^ ��n-1,i=0 = �� n-1, i=0, (b^2^i)^ai
	// result = �� n-1, i=0 (b^2^i)^ai (mod m)
	while (exp > 0) {
		// if ai = 0; pass; because n^0 = 1
		// if ai = 1; (b^2^i * (�� i-1, j=0, (b^2^j)^aj mod m)) mod m
		if (exp & 0x1) {
			// ab mod m �� (a * (b mod m)) mod m
			result = mod(multiply(result, base), m);
		}
		// a �� b mod m => a^2 �� b^2 mod m
		// b^2^(i+1) �� (b^2^(i) * b^2^(i)) mod m
		base = mod(base * base, m);
		exp >>= 1;
	}
	return result;
}

int multiply (int a, int b) {
	unsigned int multiplicand = (static_cast <unsigned>(a << 1) >> 1) == a ? a : sum(~a, 1);
	unsigned int multiplier = (static_cast <unsigned>(b << 1) >> 1) == b ? b : sum(~b, 1);
	auto product = static_cast <unsigned int>(multiply(multiplicand, multiplier));
	if (static_cast <unsigned>((a ^ b) << 1) >> 1 != (a ^ b)) {
		product = sum(~product, 1);
	}
	return product;
}

unsigned long long int multiply (unsigned int multiplicand, unsigned int multiplier) {
	auto mark = 0x1;
	long long unsigned product = 0;
	while (multiplier) {
		if (multiplier & mark) {
			product = sum(product, multiplicand);
		}
		multiplicand <<= 1;
		multiplier >>= 1;
	}
	return product;
}

int find_first_significant_bit_position (int n) {
	//auto p = new unsigned long(0);
	//_BitScanReverse(p, n);
	//n = static_cast <int>(*p);
	//delete p;
	//return n;
	__asm{
		bsr eax, n
	}
}

// The Karatsuba algorithm is a fast multiplication algorithm
int karatsuba (int a, int b) {
	// if a < base 2, b < base; directly calculate
	if (! ((a >> 1) && (b >> 1))) {
		return (a && b) ? (a >> 1 ? a : b) : 0;
	}
	auto p1 = find_first_significant_bit_position(a);
	auto p2 = find_first_significant_bit_position(b);
	auto m = sum(std::max(p1, p2), 1) >> 1;
	auto x1 = a >> m;
	auto y1 = b >> m;
	auto temp = subtract(pow(2, m), 1);
	auto x0 = a & temp;
	auto y0 = b & temp;
	auto z2 = karatsuba(x1, y1);
	auto z0 = karatsuba(x0, y0);
	auto z1 = subtract(subtract(karatsuba(sum(x1, x0), sum(y1, y0)), z2), z0);
	return sum(sum((z2 << (m << 1)), (z1 << m)), z0);
}

int divide (int dividend, int divisor) {
	return dividend / divisor;
}

// copy comment from wikipedia: https://en.wikipedia.org/wiki/Exponentiation_by_squaring
// exponentiating by squaring is a general method for fast computation 
// of large positive integer powers of a number n and n is positive
long long unsigned pow_sqrt (unsigned int base, unsigned int exp) {
	long long unsigned temp = 1;
	while (exp) { // if exp is not 0
		if (exp & 0x1) { //exp is odd
			// cached value to temp variable
			exp ^= 0x1; // exp = exp - 1
			temp = multiply(base, temp);
		} else { // exp is even
			base = multiply(base, base);
			exp >>= 1; // exp = exp / 2
		}
	}
	return temp;
}
