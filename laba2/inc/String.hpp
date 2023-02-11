#include <iostream>

namespace my {
	class String {
    private:
        size_t m_size = 0;
        char* m_str = nullptr;
        unsigned long long npos{ static_cast<size_t>(-1) };

    public:
        String() = default;

        // 1)Базовый конструктор
        String(char* str);

        String(char c, size_t size);

        // 2)Конструктор копирования
        String(const String& other) : String(other.m_str) {};

        // 3)Оператор присваивания копированием
        String& operator=(const String& other);

        // 4)Деструктор
        ~String();

        // 5)Операторы + и +=
        String operator+(const String& s) const;
        String& operator+=(const String& s);

        // 6)Оператор [] 
        char& operator[](int index);

        // 7)Операторы <, >, ==
        bool operator==(const String& s) const;
        bool operator>(const String& s) const;
        bool operator<(const String& s) const;

        // 9)Метод find 
        unsigned int find(char c);

        // 10)Метод length
        size_t length();

        // 11)Метод c_str
        char* c_str();

        // 12)Метод at
        char& at(unsigned int index);

        friend std::ostream& operator<<(std::ostream& out, const String& s);
        friend std::istream& operator>>(std::istream& in, String& s);
    };

    // 8)Операторы ввода и вывода в поток
    std::ostream& operator<<(std::ostream& out, const String& s);
    std::istream& operator>>(std::istream& in, String& s);
}