#ifndef CPP_QNUMBER
#define CPP_QNUMBER

#include <stdexcept>

class QNumber
{
public:
	QNumber();
	QNumber(int numerator);
	QNumber(int numerator, int denominator);
	QNumber(double dvalue);
	QNumber(float fvalue);

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
