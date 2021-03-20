CXX=g++
CXXFLAGS=-Wall -Wextra -std=c++17

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -c -o $@

main: file.o class.o main.o
	$(CXX) $^ -o $@

.PHONY: clean

clean:
	rm -f *.o *~core