GOALS = test
HEADERS_DIR = .
all : $(GOALS)

test : Case.o Pion.o test.o
	g++ -std=c++11 -o test Case.o Pion.o test.o
Case.o : Case.cpp Pion.hpp
	g++ -std=c++11 -Wall -I $(HEADERS_DIR) -c Case.cpp
Pion.o : Pion.cpp Case.hpp
	g++ -std=c++11 -Wall -I $(HEADERS_DIR) -c Pion.cpp
test.o : test.cpp Case.hpp Pion.hpp
	g++ -std=c++11 -Wall -I $(HEADERS_DIR) -c test.cpp

clean :
	rm *.o $(GOALS)
