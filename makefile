CXX=clang++
CXXFLAGS=-std=c++11 -Wall -g -Werror -Wsign-conversion
VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all --error-exitcode=99

SOURCES= Player.cpp Edge.cpp Vertex.cpp Board.cpp DevelopmentCard.cpp Plot.cpp Resource.cpp

OBJECTS=$(SOURCES:.cpp=.o)

demo: Demo.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o demo

test: TestCounter.o Test.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $< -o test


run: test
	./test
	

tidy:
	clang-tidy $(SOURCES) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-*

valgrind: demo
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./demo 2>&1 | { egrep "lost| at " || true; }

clean:
	rm -f *.o demo test


