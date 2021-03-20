#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <cstdio>
#include <string>

class file {

public:
	FILE * doc;

	file(std::string filePath);
	void write(std::string update);
	file(const file&) = delete;
	file &operator=(const file&) = delete;
	~file();

};


#endif //FILE_H