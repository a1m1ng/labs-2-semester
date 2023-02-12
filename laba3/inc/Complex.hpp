#pragma once
#include <iostream>

namespace my {
	class Complex {
	private:
		double m_a = 0;
		double m_b = 0;

	public:
		Complex() = default;

		Complex(double a) : m_a(a), m_b(0) {};

		// 1)������� �����������
		Complex(double a, double b) : m_a(a), m_b(b) {};

		// 2)����������� �����������
		Complex(const Complex& z);

		// 3)�������� ������������ ������������
		Complex& operator=(Complex z);

		// 4)����������
		~Complex() = default;

		// 5)��������� += � +, *= � *
		Complex& operator+=(const Complex& z);

		Complex operator+(const Complex& z) const;

		Complex& operator*=(const Complex& z);

		Complex operator*(const Complex& z) const;

		// 6)�������� ++ ���������� � ����������� 
		// ����������
		Complex& operator++();

		// �����������
		Complex& operator++(int);

		friend std::ostream& operator<<(std::ostream& out, const Complex& z);
		friend std::istream& operator>>(std::istream& in, const Complex& z);
	};

	// 7)��������� ����� � ������
	std::ostream& operator<<(std::ostream& out, const Complex& z);

	std::istream& operator>>(std::istream& in, const Complex& z);
}