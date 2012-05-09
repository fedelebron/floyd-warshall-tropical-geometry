#ifndef TROPICAL_H
#define TROPICAL_H

#include <iosfwd>

template<typename T> class Tropical {
 private:
  T val_;

 public:
  Tropical() : val_(0) {}
  explicit Tropical(const T& v) : val_(v) {}
  template<typename S> explicit Tropical(const S& v) : val_(v) {}
  template<typename S> Tropical& operator=(const S& v);
  Tropical operator+(const Tropical& t) const;
  Tropical operator*(const Tropical& t) const;

  template<typename S> friend ostream& operator<<(ostream& os, Tropical<S> t);
};

template<typename T> ostream& operator<<(ostream& os, Tropical<T> t);

#endif  // TROPICAL_H
