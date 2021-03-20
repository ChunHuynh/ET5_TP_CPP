// 3.1) Les fonctions de base doivent au moins être en protected pour pouvoir
//		être redéfini dans les classes héritées.

// 3.2)	Les constructeurs et destructeurs devront être redéfinies.

#include "rectangle.h"
#include <assert.h>

rectangle::rectangle() {
	longueur = 2;
	largeur = 1;
}

rectangle::rectangle(int lng, int lrg) {
	assert(lng > 0);
	assert(lrg > 0);
	assert(lng > lrg);
	this->longueur = lng;
	this->largeur = lrg;
}
 
rectangle::~rectangle() {

}

rectangle::rectangle(const rectangle &rect) {
	longueur = rect.longueur;
	largeur = rect.largeur;
}

void rectangle::setLng(int lng) {
	this->longueur = lng;
}

void rectangle::setLrg(int lrg) {
	this->largeur = lrg;
}

int rectangle::calculAire() {
	return this->longueur * this->largeur;
}

int rectangle::getLng() const {
	return longueur;
}

int rectangle::getLrg() const {
	return largeur;
}

namespace std {
	ostream& operator<<(ostream& os, const rectangle &rect) {
		os<<"(" <<rect.getLng()<< "," <<rect.getLrg()<< ")";
		return os;
	}
}

void swap(rectangle &left,rectangle &right){
    int temp;
    temp = left.getLng();
    left.setLng(right.getLng());
    right.setLng(temp);
    temp = left.getLrg();
    left.setLrg(right.getLrg());
    right.setLrg(temp);
}

void test_area(rectangle * subject) {
	srand(time(NULL));
	int test_lng = rand() % 20;
	int test_lrg = rand() % 20;
	subject->setLng(test_lng);
	subject->setLrg(test_lrg);
	assert(subject->calculAire() == test_lng * test_lrg);
}