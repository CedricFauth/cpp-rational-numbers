#include <iostream>
#include "qnumber.hpp"

int main(int argc, char const *argv[])
{
	QNumber q0;
	QNumber q1 = 2;
	QNumber q2 (6, 8);
	QNumber q3 = 0.2;
	QNumber *q4 = new QNumber;
	delete q4;
	std::cout << q1 << '\n' << q2 << std::endl;
	return 0;
}
