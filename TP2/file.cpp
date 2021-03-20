#include "file.hpp"

file::file(std::string filePath) {
	this->doc = fopen(filePath.c_str(), "w");
}

void file::write(std::string update) {
	fwrite(update.c_str(), sizeof(char), update.size(), this->doc);
}

file::~file() {
	fclose(this->doc);
}