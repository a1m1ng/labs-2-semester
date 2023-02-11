#include <iostream>

namespace my {
	class String {
    private:
        size_t m_size = 0;
        char* m_str = nullptr;
        unsigned long long npos{ static_cast<size_t>(-1) };

    public:
        String() = default;

        // 1)������� �����������
        String(char* str);

        String(char c, size_t size);

        // 2)����������� �����������
        String(const String& other) : String(other.m_str) {};

        // 3)�������� ������������ ������������
        String& operator=(const String& other);

        // 4)����������
        ~String();

        // 5)��������� + � +=
        String operator+(const String& s) const;
        String& operator+=(const String& s);

        // 6)�������� [] 
        char& operator[](int index);

        // 7)��������� <, >, ==
        bool operator==(const String& s) const;
        bool operator>(const String& s) const;
        bool operator<(const String& s) const;

        // 9)����� find 
        unsigned int find(char c);

        // 10)����� length
        size_t length();

        // 11)����� c_str
        char* c_str();

        // 12)����� at
        char& at(unsigned int index);

        friend std::ostream& operator<<(std::ostream& out, const String& s);
        friend std::istream& operator>>(std::istream& in, String& s);
    };

    // 8)��������� ����� � ������ � �����
    std::ostream& operator<<(std::ostream& out, const String& s);
    std::istream& operator>>(std::istream& in, String& s);
}