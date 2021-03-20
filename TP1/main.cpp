#include <iostream>
#include "rectangle.h"
#include "square.h"
#include <boost/core/swap.hpp>

using namespace std;

int main() {
	square c1(2);
	square c2(3);

	rectangle rect = rectangle();
	cout << rect << endl;
	cout << c2 << endl;

	boost::swap(rect, static_cast<rectangle&>(c2));

	cout << rect << endl;
	cout << c2 << endl;

	test_area(&c1);
	// Le LSP n'est pas respecté car les setter ont été modifiés par square
	// lors du calcul de l'aire, les cotés sont égaux alors que les 
	// longueurs et largeurs générées sont différentes

	return 0;
}