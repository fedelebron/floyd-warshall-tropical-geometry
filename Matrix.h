#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iosfwd>

using std::istream;
using std::ostream;
using std::vector;

template<typename T> class Matrix {
 public:
  Matrix(int rows, int columns) : 
    rows_(rows), 
    columns_(columns), 
    entries_(vector<vector<T>>(rows, vector<T>(columns, T()))) {
  }

  template<typename S> Matrix(const Matrix<S>& other);

  int rows() const {
    return rows_;
  }

  int columns() const {
    return columns_;
  }

  T& operator()(int i, int j);
  const T& operator()(int i, int j) const;

  Matrix operator*(const Matrix& other) const;
  Matrix pow(int n) const;

 private:
  vector<vector<T>> entries_;
  int rows_;
  int columns_;
};

template<typename T> istream& operator>>(istream& is, Matrix<T>& matrix);
template<typename T> ostream& operator<<(ostream& os, const Matrix<T>& matrix);

#endif  // MATRIX_H
