#ifndef TROPICAL_H
#define TROPICAL_H

#include <iosfwd>
#include <limits>

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

namespace std {
  template<typename T> class numeric_limits<Tropical<T>> {
   public:
    static T infinity() {
      return numeric_limits<T>::infinity();
    }
  };
}

#endif  // TROPICAL_H
