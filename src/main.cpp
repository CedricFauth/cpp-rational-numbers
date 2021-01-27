#include <iostream>
#include "qnumber.hpp"

int main(int argc, char const *argv[])
{
	QNumber q1 (6,8);
	QNumber q2 (0.3);
	std::cout << q1 << '\n' << q2 << std::endl;
	return 0;
}
