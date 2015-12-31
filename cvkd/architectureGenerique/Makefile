GOALS = test
HEADERS_DIR = .
all : $(GOALS)

test : Case.o Pion.o test.o
	g++ -o test Case.o Pion.o test.o
Case.o : Case.cpp Pion.hpp
	g++ -Wall -I $(HEADERS_DIR) -c Case.cpp
Pion.o : Pion.cpp Case.hpp
	g++ -Wall -I $(HEADERS_DIR) -c Pion.cpp
test.o : test.cpp Case.hpp Pion.hpp
	g++ -Wall -I $(HEADERS_DIR) -c test.cpp

clean :
	rm *.o $(GOALS)
