#include "class.hpp"
#include "file.hpp"

using namespace std;

void f1(T const &t) {}
void f2(T t) {}
T f3() { return T(); }
T f4() { T t; return t; }
void f5(T &t) { t = T(); }

struct U {
	T v1, v2;
	U(T const &t): v2(t) { v1 = t; }
};



int main() {
	/********	Exercice1	********
	T a;
	f1(a);
	f2(a);
	T b = a;
	T c = f3();
	T d = f4();
	f5(d);
	U e(a);
	********************************/
	/********	Exercice2	********
	file f("test1.txt");
	f.write("first string for test1\n");
	file g("test2.txt");
	g.write("first string for test2\n");
	f.write("second string for test1\n");
	********************************/
	file f("test3.txt");
	f.write("first string for test3\n");
	file g(std::move(f));
	g.write("second string for test3\n");
}