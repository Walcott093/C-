GOALS = test
HEADERS_DIR = .
ES_DIR = ../jeux/EchelleSerpent/
all : $(GOALS)

test : A.o B.o test.o
	g++ -std=c++11 -o test A.o B.o test.o
A.o : A.cpp
	g++ -std=c++11 -Wall -I $(HEADERS_DIR) -c A.cpp
B.o : B.cpp
	g++ -std=c++11 -Wall -I $(HEADERS_DIR) -c B.cpp
test.o : test.cpp A.hpp B.hpp
	g++ -std=c++11 -Wall -I $(HEADERS_DIR) -c test.cpp

clean :
	rm *.o $(GOALS)
