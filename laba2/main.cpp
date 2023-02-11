#include <iostream>
#include <String.hpp>

int main()
{
    setlocale(LC_ALL, "ru");

    my::String s("123");
    my::String s1("321"), s2("123");
    
    my::String s3 = s1 + s2;
    my::String s4 = s1 += s2;
    for (int i = 0; i < s3.length(); i++) {
        std::cout << s3[i];
    }
    std::cout << std::endl << s3.length() << std::endl;

    
    std::cout << s[1] << std::endl;
    s[1] = '9';
    std::cout << s[1] << std::endl;

    std::cout << (s == s2) << std::endl;

    std::cout << (s1 < s) << std::endl;

    std::cout << s1 << std::endl;

    std::cin >> s3;
    std::cout << s3 << std::endl;

    std::cout << s.find('5') << std::endl;

    std::cout << s.length() << std::endl;

    char* mas = s.c_str();
    std::cout << mas[0] << mas[1] << mas[2] << std::endl;

    std::cout << s.at(0) << std::endl;
    s.at(0) = '8';
    std::cout << s.at(0) << std::endl;

    return 0;
}
