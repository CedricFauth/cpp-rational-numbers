#ifndef CPP_QNUMBER
#define CPP_QNUMBER

#include <stdexcept>
#include <iostream>

class QNumber
{
public:
	QNumber();
	QNumber(int numerator);
	QNumber(int numerator, int denominator);
	QNumber(double dvalue); // only up to 5 positions after decimal point
	QNumber(float fvalue);  // use carefully, precision is low

	friend std::ostream& operator<<(std::ostream& os, QNumber& qnum);

private:
	void simplify();
	int gcd(int a, int b);

	int num_;
	int denom_;
};

class ZeroException : public std::runtime_error {
	public:
	ZeroException()
		: runtime_error("Error: Dividing by zero.") { }
};

#endif //CPP_QNUMBER
