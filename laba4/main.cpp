#include <iostream>
#include <Matrix.hpp>

int main() {
    int mas[2][2] = { {1, 2}, {3, 4} };
    my::Matrix<int, 2, 2> m1(mas);
    my::Matrix<int, 2, 2> m2 = m1;
    std::cout << m2;

    int mas2[2][2] = {{4, 3}, {2, 1}};
    m2 = my::Matrix<int, 2, 2>(mas2);
    std::cout << m2;

    /*Matrix<int, 2, 2> m3;
    std::cin >> m3;
    std::cout << m3;*/

    m1 += m2;
    std::cout << m1;
    std::cout << m1 + m2;

    std::cout << m2 * m2;;
    m2 *= m2;
    std::cout << m2;

    int mas3[3][3]{ {1, 2, 3}, {4, 5, 6}, {7, 8, 10} };
    my::Matrix<int, 3, 3> m3(mas3);

    //*, *=, +, += for m2[2][2], m3[3][3] undefined

    std::cout << m1;
    m1++;
    std::cout << m1;

    std::cout << m3;
    std::cout << m3.det() << std::endl;

    std::cout << m2;
    std::cout << m2.det() << std::endl;

    std::cout << m2[1][1] << std::endl;
}