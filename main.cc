#include <iostream>

#include "Matrix.cc"
#include "Tropical.cc"
#include "FloydWarshall.cc"

using namespace std;

int main() {
  int n;

  cin >> n;
  
  Matrix<double> Adjacency(n, n);
  cin >> Adjacency;
  cout << "Adjacency:" << endl << Adjacency << endl;

  Matrix<Tropical<double>> TropicalAdjacency(Adjacency);
  cout << "Tropical Adjacency:" << endl << TropicalAdjacency << endl;

  Matrix<double> Distance = FloydWarshall(Adjacency);
  Matrix<Tropical<double>> TropicalDistance = TropicalAdjacency.pow(n);

  cout << "Distance:" << endl << Distance << endl;
  cout << "Tropical Distance:" << endl << TropicalDistance << endl;
}