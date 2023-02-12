#include <Complex.hpp>

namespace my {
	Complex::Complex(const Complex& z) {
		this->m_a = z.m_a;
		this->m_b = z.m_b;
	}

	Complex& Complex::operator=(Complex z) {
		std::swap(this->m_a, z.m_a);
		std::swap(this->m_b, z.m_b);
		return *this;
	}

	Complex& Complex::operator+=(const Complex& z) {
		this->m_a += z.m_a;
		this->m_b += z.m_b;
		return *this;
	}

	Complex Complex::operator+(const Complex& z) const {
		Complex temp = z;
		temp += *this;
		return temp;
	}

	Complex& Complex::operator*=(const Complex& z) {
		Complex temp = *this;

		this->m_a = temp.m_a * z.m_a - temp.m_b * z.m_b;
		this->m_b = temp.m_a * z.m_b + temp.m_b * z.m_a;

		return *this;
	}

	Complex Complex::operator*(const Complex& z) const {
		Complex temp = z;
		temp *= *this;
		return temp;
	}

	Complex& Complex::operator++() {
		this->m_a++;
		return *this;
	}

	Complex& Complex::operator++(int) {
		Complex temp = *this;
		this->m_a += 1;
		return temp;
	}

	std::ostream& operator<<(std::ostream& out, const Complex& z) {
		out << z.m_a << "+" << z.m_b << "i";
		return out;
	}

	std::istream& operator>>(std::istream& in, const Complex& z) {
		in >> z.m_a >> z.m_b;
		return in;
	}
};
