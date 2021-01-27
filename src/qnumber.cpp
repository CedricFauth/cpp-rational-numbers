#include "qnumber.hpp"

QNumber::QNumber() : num_(0), denom_(1) { }

QNumber::QNumber(int value) : num_(value), denom_(1) { }

QNumber::QNumber(int numerator, int denominator) {
	if (denominator == 0) throw ZeroException();
	num_ = denominator > 0 ? numerator : -numerator;
	denom_ = denominator > 0 ? denominator : -denominator;

	simplify();
}

QNumber::QNumber(double dvalue) {
	int off = 1;
	while (dvalue-static_cast<int>(dvalue) != 0 && off < 100000) {
		off *= 10;
		dvalue *= 10;
	}

	//std::cout << off << ' ' << dvalue << ' ' << round(dvalue)/off << std::endl;

	num_ = round(dvalue);
	denom_ = off;

	simplify();
}

QNumber::QNumber(float fvalue) : QNumber(static_cast<double>(fvalue)) {
	std::cout << "float constructor called" << std::endl;
}

void QNumber::simplify() {
	int a = num_ > denom_ ? num_ : denom_;
	int b = num_ > denom_ ? denom_ : num_;
	int divisor = gcd(a, b);
	num_ /= divisor;
	denom_ /= divisor;
}

int QNumber::gcd(int a, int b){
	if (a == 0) return abs(b);
	if (b == 0) return abs(a);

	int remainder;
	do {
		remainder = a % b;
		a = b;
		b = remainder;
	} while (b != 0);

	return abs(a);
}

std::ostream& operator<<(std::ostream& os, QNumber& qnum) {
	os << '(' << qnum.num_ << '/' << qnum.denom_ << ')';
	return os;
}
