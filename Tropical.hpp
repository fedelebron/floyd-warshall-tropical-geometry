#ifndef TROPICAL_HPP
#define TROPICAL_HPP

#include <cmath>
#include <iostream>
#include <limits>

using std::min;
using std::numeric_limits;
using std::ostream;

template<typename T> class Tropical {
 private:
  T val_;

 public:
  Tropical() : val_(numeric_limits<T>::infinity()) {}
  explicit Tropical(const T& v) : val_(v) {}
  template<typename S> explicit Tropical(const S& v) : val_(v) {}
  template<typename S> Tropical& operator=(const S& v);
  Tropical operator+(const Tropical& t) const;
  Tropical operator*(const Tropical& t) const;

  template<typename S> friend ostream& operator<<(ostream& os, Tropical<S> t);
};

template<typename T> ostream& operator<<(ostream& os, Tropical<T> t);

template<typename T> template<typename S> Tropical<T>& Tropical<T>::operator=(
    const S& v) {
  val_ = v;
  return *this;
}

template<typename T> Tropical<T> Tropical<T>::operator+(
    const Tropical<T>& t) const {
  return Tropical(min(t.val_, val_));
}

template<typename T> Tropical<T> Tropical<T>::operator*(
    const Tropical<T>& t) const {
  return Tropical(t.val_ + val_);
}

template<typename T> ostream& operator<<(ostream& os, Tropical<T> t) {
  os << t.val_;
}

#endif  // TROPICAL_HPP