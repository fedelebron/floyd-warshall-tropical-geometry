#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <limits>
#include <stdexcept>
#include <vector>

using std::domain_error;
using std::endl;
using std::istream;
using std::numeric_limits;
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

template<typename T> template<typename S> Matrix<T>::Matrix(
    const Matrix<S>& other) : 
    rows_(other.rows()), 
    columns_(other.columns()), 
    entries_(vector<vector<T>>(other.rows(), vector<T>(other.columns(), T()))) {

  for (int i = 0; i < rows(); ++i) {
    for (int j = 0; j < columns(); ++j) {
      entries_[i][j] = other(i, j);
    }
  }
}


template<typename T> const T& Matrix<T>::operator()(int i, int j) const {
  return entries_[i][j];
}

template<typename T> T& Matrix<T>::operator()(int i, int j) {
  return entries_[i][j];
}

template<typename T> Matrix<T> Matrix<T>::operator*(
  const Matrix<T>& other) const {
  
  if (columns_ != other.rows_) {
    throw domain_error("Incompatible matrix dimensions in multiplication.");
  }

  Matrix<T> result(rows_, other.columns_);

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < other.columns_; ++j) {
      T accumulator;
      for (int k = 0; k < columns_; ++k) {
        accumulator = accumulator + (entries_[i][k] * other.entries_[k][j]);
      }
      result(i, j) = accumulator;
    }
  }

  return result;
}

template<typename T> Matrix<T> Matrix<T>::pow(int n) const {
  if (columns_ != rows_) {
    throw domain_error(
      "Matrix powers only make sense for square matrices.");
  }

  Matrix<T> result(*this);

  for (int i = 0; i < n-1; ++i) {
    result = result * *this;
  }

  return result;
}

template<typename T> istream& operator>>(istream& is,
                                         Matrix<T>& matrix) {
  int rows = matrix.rows();
  int columns = matrix.columns();

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
      is >> matrix(i, j);
    }
  }

  return is;
}

template<typename T> ostream& operator<<(ostream& os, 
                                         const Matrix<T>& matrix) {
  int rows = matrix.rows();
  int columns = matrix.columns();

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
      os << matrix(i, j) << " ";
    }
    os << endl;
  }

  return os;
}

#endif  // MATRIX_HPP