#include "Tropical.h"

#include <cmath>
#include <limits>

using std::min;

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

namespace std {
	template<typename T> class numeric_limits<Tropical<T>> {
	 public:
		static T infinity() {
	  	return numeric_limits<T>::infinity();
	  }
	};
}
