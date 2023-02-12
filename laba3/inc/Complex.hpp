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

		// 1)Базовый конструктор
		Complex(double a, double b) : m_a(a), m_b(b) {};

		// 2)Конструктор копирования
		Complex(const Complex& z);

		// 3)Оператор присваивания копированием
		Complex& operator=(Complex z);

		// 4)Деструктор
		~Complex() = default;

		// 5)Операторы += и +, *= и *
		Complex& operator+=(const Complex& z);

		Complex operator+(const Complex& z) const;

		Complex& operator*=(const Complex& z);

		Complex operator*(const Complex& z) const;

		// 6)Оператор ++ префиксный и постфиксный 
		// Префиксный
		Complex& operator++();

		// Постфиксный
		Complex& operator++(int);

		friend std::ostream& operator<<(std::ostream& out, const Complex& z);
		friend std::istream& operator>>(std::istream& in, const Complex& z);
	};

	// 7)Операторы ввода и вывода
	std::ostream& operator<<(std::ostream& out, const Complex& z);

	std::istream& operator>>(std::istream& in, const Complex& z);
}