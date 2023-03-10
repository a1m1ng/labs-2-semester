#pragma once
#include <iostream>

namespace my {
    template<typename T, size_t N, size_t M>
    class Matrix {
    private:
        T** m_matrix = nullptr;
        size_t len = N;
        size_t wid = M;


    public:
        // Default constructor
        Matrix() {
            m_matrix = new T * [N];
            for (int i = 0; i < N; i++) {
                m_matrix[i] = new T[M];
            }
        }

        // Constructor
        Matrix(T matrix[N][M]) {
            m_matrix = new T * [N];
            for (int i = 0; i < N; i++) {
                m_matrix[i] = new T[M];
                for (int j = 0; j < M; j++) {
                    m_matrix[i][j] = matrix[i][j];
                }
            }
        }

        // 1)Copy constructor
        Matrix(const Matrix& other) {
            m_matrix = new T * [N];
            for (int i = 0; i < N; i++) {
                m_matrix[i] = new T[M];
                for (int j = 0; j < M; j++) {
                    m_matrix[i][j] = other.m_matrix[i][j];
                }
            }
        }

        // 2)Copy assignment constructor
        Matrix& operator=(const Matrix& other) {
            Matrix temp = other;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    std::swap(this->m_matrix[i][j], temp.m_matrix[i][j]);
                }
            }
            return *this;
        }
        // 4) +=, +, *, *=
        Matrix& operator+=(const Matrix& matrix) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    this->m_matrix[i][j] += matrix.m_matrix[i][j];
                }
            }
            return *this;
        }

        Matrix operator+(const Matrix& other) {
            Matrix temp = other;
            temp += *this;
            return temp;
        }

        Matrix operator*(const Matrix<T, M, N>& other) {
            Matrix temp;
            for (int i = 0; i < len; i++) {
                for (int j = 0; j < wid; j++) {
                    temp.m_matrix[i][j] = 0;
                    for (int x = 0; x < wid; x++) {
                        temp.m_matrix[i][j] += this->m_matrix[i][x] * other.m_matrix[x][j];
                    }
                }
            }
            return temp;
        }

        Matrix& operator*=(const Matrix<T, M, N>& other) {
            *this = *this * other;
            return *this;
        }

        // 5) ++
        Matrix& operator++(int) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    this->m_matrix[i][j] += 1;
                }
            }
            return *this;
        }

        // 6)Determinant
        int det() {
            int determinant = 0;
            if (len != wid) {
                return determinant;
            }
            switch (len) {
            case 3:
                // Метод треугольников
                determinant += m_matrix[0][0] * m_matrix[1][1] * m_matrix[2][2];
                determinant += m_matrix[0][1] * m_matrix[1][2] * m_matrix[2][0];
                determinant += m_matrix[0][2] * m_matrix[1][0] * m_matrix[2][1];

                determinant -= m_matrix[0][2] * m_matrix[1][1] * m_matrix[2][0];
                determinant -= m_matrix[0][1] * m_matrix[1][0] * m_matrix[2][2];
                determinant -= m_matrix[0][0] * m_matrix[1][2] * m_matrix[2][1];

                break;
            case 2:
                determinant += m_matrix[0][0] * m_matrix[1][1];
                determinant -= m_matrix[0][1] * m_matrix[1][0];

                break;
            case 1:
                determinant = m_matrix[0][0];

                break;
            }
            return determinant;
        }

        // 7) []
        T* operator[](size_t index) {
            return m_matrix[index];
        }

        // Destructor
        ~Matrix() {
            for (int i = 0; i < M; i++) {
                delete[] m_matrix[i];
            }
            delete[] m_matrix;
            
        }

        template<typename T, size_t N, size_t M>
        friend std::ostream& operator<<(std::ostream& out, const Matrix<T, N, M>& matrix);

        template<typename T, size_t N, size_t M>
        friend std::istream& operator>> (std::istream& in, const Matrix<T, N, M>& matrix);
    };

    // 3)>>, <<
    template<typename T, size_t N, size_t M>
    std::ostream& operator << (std::ostream& out, const Matrix<T, N, M>& matrix) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                out << matrix.m_matrix[i][j] << " ";
            }
            out << std::endl;
        }
        return out;
    }

    template<typename T, size_t N, size_t M>
    std::istream& operator>> (std::istream& in, const Matrix<T, N, M>& matrix) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                in >> matrix.m_matrix[i][j];
            }
        }
        return in;
    }
}