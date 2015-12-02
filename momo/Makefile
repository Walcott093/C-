GOALS = main
HEADERS_DIR = .
all : $(GOALS)

main : Plateau.o Case.o Pion.o main.o
	g++ -o main Plateau.o Case.o Pion.o main.o
Plateau.o : Plateau.cpp
	g++ -Wall -std=c++11 -I $(HEADERS_DIR) -c Plateau.cpp
Case.o : Case.cpp
	g++ -Wall -std=c++11 -I $(HEADERS_DIR) -c Case.cpp
Pion.o : Pion.cpp
	g++ -Wall -std=c++11 -I $(HEADERS_DIR) -c Pion.cpp
main.o : main.cpp Plateau.hpp Case.hpp Pion.hpp
	g++ -Wall -std=c++11 -I $(HEADERS_DIR) -c main.cpp
clean :
	rm *.o $(GOALS)
