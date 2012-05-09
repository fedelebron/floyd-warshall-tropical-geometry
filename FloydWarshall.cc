#include "FloydWarshall.h"

#include <stdexcept>
#include <cmath>

using std::min;
using std::domain_error;

template<typename T> Matrix<T> FloydWarshall(const Matrix<T>& adjacency) {
  if (adjacency.columns() != adjacency.rows()) {
    throw domain_error(
      "Adjacency matrices should be square for Floyd-Warshall");
  }

  Matrix<T> result(adjacency);

  int n = adjacency.columns();

  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        result(i, j) = min(result(i, j), result(i, k) + result(k, j));
      }
    }
  }

  return result;
}