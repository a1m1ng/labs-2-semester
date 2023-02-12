#include <iostream>
#include <Complex.hpp>

int main() {
	my::Complex z1(1, 1);
	my::Complex z2 = z1;
	z2 += z1;
	std::cout << z2 << std::endl;

	z2 = z1 + z1;
	std::cout << z2 << std::endl;


	z2 *= z1 * 2;
	std::cout << z1 * 2 << " * " << z1 * 2 << " = " << z2 << std::endl;

	std::cout << z1 << std::endl;
	my::Complex z3 = z1++;
	std::cout << z3 << " " << z1 << std::endl;

	++z1;
	std::cout << z1 << std::endl;

	return 0;
}