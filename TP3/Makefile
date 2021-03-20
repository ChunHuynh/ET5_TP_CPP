CXX=g++
CXXFLAGS=-Wall -Wextra -std=c++17

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -c -o $@

main: class_ex1.o class_ex2.o main.o
	$(CXX) $^ -o $@

.PHONY: clean

clean:
	rm -f *.o *~ core