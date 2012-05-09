#ifndef FLOYD_WARSHALL_H
#define FLOYD_WARSHALL_H

#include "Matrix.h"

template<typename T> Matrix<T> FloydWarshall(const Matrix<T>& adjacency);

#endif  // FLOYD_WARSHALL_H