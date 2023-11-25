#include <iostream>

using namespace std;

class Matrix2x2 {
protected:
    double a11, a12, a21, a22;

public:
    Matrix2x2() : a11(0), a12(0), a21(0), a22(0) {}
    Matrix2x2(double a, double b, double c, double d) : a11(a), a12(b), a21(c), a22(d) {}

    void print() const {
        cout << "| " << a11 << "  " << a12 << " |\n| " << a21 << "  " << a22 << " |\n";
    }

    Matrix2x2 operator*(const Matrix2x2& other) const {
        Matrix2x2 result;
        result.a11 = a11 * other.a11 + a12 * other.a21;
        result.a12 = a11 * other.a12 + a12 * other.a22;
        result.a21 = a21 * other.a11 + a22 * other.a21;
        result.a22 = a21 * other.a12 + a22 * other.a22;
        return result;
    }

    Matrix2x2 operator*(double x) const {
        Matrix2x2 result;
        result.a11 = a11 * x;
        result.a12 = a12 * x;
        result.a21 = a21 * x;
        result.a22 = a22 * x;
        return result;
    }

    friend Matrix2x2 operator*(double x, const Matrix2x2& matrix) {
        Matrix2x2 result;
        result.a11 = x * matrix.a11;
        result.a12 = x * matrix.a12;
        result.a21 = x * matrix.a21;
        result.a22 = x * matrix.a22;
        return result;
    }

    double determinant() const {
        return a11 * a22 - a12 * a21;
    }
};

class SumDiagonalMatrix2x2 : public Matrix2x2 {
public:
    SumDiagonalMatrix2x2() : Matrix2x2() {}
    SumDiagonalMatrix2x2(double a, double b, double c, double d) : Matrix2x2(a, b, c, d) {}

    // Переопределение функции determinant для возврата суммы элементов на побочной диагонали
    double determinant() const override {
        return a12 + a21;
};

int main() {
    Matrix2x2 matrix1(1, 2, 3, 4);
    SumDiagonalMatrix2x2 derivedMatrix(5, 6, 7, 8);

    Matrix2x2* matrixPtr;

    matrixPtr = &matrix1;
    cout << "Определитель базовой матрицы: " << matrixPtr->determinant() << '\n';

    matrixPtr = &derivedMatrix;
    cout << "Определитель производной матрицы (сумма диагоналей): " << matrixPtr->determinant() << '\n';

    return 0;
}
