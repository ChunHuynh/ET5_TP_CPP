#include "class.hpp"

T::T() {
	std::cout << "Constructed " << this << std::endl;
}

T::T(T const &t) {
	std::cout << this << ": constructed from " << &t << std::endl;
}

T& T::operator=(T const &t) {
	std::cout << this << ": assigned from " << &t << std::endl;
	return *this;
}

T::~T() {
	std::cout << "Destructed " << this << std::endl;
}

