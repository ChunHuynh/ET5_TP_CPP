#ifndef CLASS_H
#define CLASS_H

#include<iostream>

class T {

public:
	T(); 					// Constructeur par défaut
	T(const T&); 			// Constructeur par copie
	T &operator=(const T&);	// Assignation par copie
	~T();					// Destructeur

};



#endif // CLASS_H