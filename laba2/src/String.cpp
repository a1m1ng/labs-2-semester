#include <iostream>
#include <String.hpp>

namespace my {
    String::String(char* str) : m_size(strlen(str)), m_str(new char[m_size + 1]) {
        std::copy(str, str + m_size, m_str);
    }

    String::String(char c, size_t size) : m_size(size), m_str(new char[size + 1]) {
        std::fill(m_str, m_str + m_size, c);
    }

    String& String::operator=(const String& other) {
        String temp = other;

        std::swap(m_size, temp.m_size);
        std::swap(m_str, temp.m_str);
        return *this;
    }

    String String::operator+(const String& s) const {
        size_t count = this->m_size + s.m_size;
        String temp(' ', count);

        for (int i = 0; i < this->m_size; i++) {
            temp.m_str[i] = this->m_str[i];
        }
        for (int i = 0; i < s.m_size; i++) {
            temp.m_str[this->m_size + i] = s.m_str[i];
        }

        temp.m_str[count] = 0;

        return temp;
    }

    String& String::operator+=(const String& s) {
        String temp = *this + s;

        std::swap(this->m_size, temp.m_size);
        std::swap(this->m_str, temp.m_str);
        return *this;
    }

    char& String::operator[](int index) {
        return this->m_str[index];
    }

    bool String::operator==(const String& s) const {
        if (this->m_size != s.m_size) {
            return false;
        }
        for (int i = 0; i < s.m_size; i++) {
            if (this->m_str[i] != s.m_str[i]) {
                return false;
            }
        }
        return true;

    }

    bool String::operator>(const String& s) const {

        if (this->m_size < s.m_size) {
            return false;
        }
        if (this->m_size > s.m_size) {
            return true;
        }

        if (*this == s) {
            return false;
        }

        for (int i = 0; i < s.m_size; i++) {
            if (this->m_str[i] > s.m_str[i]) {
                return true;
            }
            else return false;
        }
    }

    bool String::operator<(const String& s) const {
        if (this->m_size > s.m_size) {
            return false;
        }
        if (this->m_size < s.m_size) {
            return true;
        }

        if (*this == s) {
            return false;
        }

        for (int i = 0; i < s.m_size; i++) {
            if (this->m_str[i] < s.m_str[i]) {
                return true;
            }
            else return false;
        }
    }


    unsigned int String::find(char c) {
        std::string::npos;
        for (int i = 0; i < this->m_size; i++) {
            if (this->m_str[i] == c) {
                return i;
            }
        }
        return this->npos;
    }

    size_t String::length() {
        return this->m_size;
    }
    char* String::c_str() {
        return this->m_str;
    }

    char& String::at(unsigned int index) {
        if (index < this->m_size) {
            return this->m_str[index];
        }
        std::cout << "Выход за границы" << std::endl;
    }

    String::~String() {
        if (m_str != nullptr) {
            delete[] m_str;
        }
    }

    std::ostream& operator<<(std::ostream& out, const String& s) {
        for (int i = 0; i < s.m_size; i++) {
            out << s.m_str[i];
        }
        return out;
    }
    std::istream& operator>>(std::istream& in, String& s) {
        std::cout << "Введите количество символов: ";
        unsigned int count;
        std::cin >> count;
        String temp(' ', count);
        in >> temp.m_str;
        if (strlen(temp.m_str) != count) {
            std::cout << "Не совпадает количество символов!" << std::endl; // Тут должна быть обработка исключения, но её пока что не завезли
        }
        std::swap(s.m_size, temp.m_size);
        std::swap(s.m_str, temp.m_str);
        return in;
    }
};