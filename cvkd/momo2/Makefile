GOALS = main
HEADERS_DIR = .
all : $(GOALS)

main : Plateau.o Case.o Pion.o Echelle_Serpent.o main.o
	g++ -o main Plateau.o Case.o Pion.o Echelle_Serpent.o main.o
Plateau.o : Plateau.cpp
	g++ -Wall -std=c++11 -I $(HEADERS_DIR) -c Plateau.cpp
Case.o : Case.cpp
	g++ -Wall -std=c++11 -I $(HEADERS_DIR) -c Case.cpp
Pion.o : Pion.cpp
	g++ -Wall -std=c++11 -I $(HEADERS_DIR) -c Pion.cpp
Echelle_Serpent.o : Echelle_Serpent.cpp
	g++ -Wall -std=c++11 -I $(HEADERS_DIR) -c Echelle_Serpent.cpp
main.o : main.cpp Plateau.hpp Case.hpp Pion.hpp Echelle_Serpent.hpp
	g++ -Wall -std=c++11 -I $(HEADERS_DIR) -c main.cpp
clean :
	rm *.o $(GOALS)
