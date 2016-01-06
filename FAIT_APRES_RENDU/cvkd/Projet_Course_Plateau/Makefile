GOALS = main
HEADERS_DIR = .
AG_DIR = architectureGenerique/
ES_DIR = jeux/EchelleSerpent/
CA_DIR = jeux/Cartagena/
all : $(GOALS)

main : $(AG_DIR)Pion.o $(AG_DIR)Joueur.o $(AG_DIR)Case.o $(AG_DIR)Jeu.o $(AG_DIR)Plateau.o $(ES_DIR)EchelleSerpent.o $(ES_DIR)ObjetEchelleSerpent.o $(ES_DIR)CaseEchelleSerpent.o  $(AG_DIR)main.o
	g++ -std=c++11 -o main Pion.o Joueur.o Case.o Plateau.o Jeu.o EchelleSerpent.o ObjetEchelleSerpent.o CaseEchelleSerpent.o main.o
$(AG_DIR)Pion.o : $(AG_DIR)Pion.cpp $(AG_DIR)Constantes.hpp
	g++ -std=c++11 -Wall -I $(HEADERS_DIR) -c $(AG_DIR)Pion.cpp
$(AG_DIR)Joueur.o : $(AG_DIR)Joueur.cpp $(AG_DIR)Pion.hpp
	g++ -std=c++11 -Wall -I $(HEADERS_DIR) -c $(AG_DIR)Joueur.cpp
$(AG_DIR)Case.o : $(AG_DIR)Case.cpp $(AG_DIR)Constantes.hpp $(AG_DIR)Pion.hpp $(ES_DIR)ObjetEchelleSerpent.hpp
	g++ -std=c++11 -Wall -I $(HEADERS_DIR) -c $(AG_DIR)Case.cpp
$(AG_DIR)Plateau.o : $(AG_DIR)Plateau.cpp $(AG_DIR)Constantes.hpp $(AG_DIR)Pion.hpp $(AG_DIR)Jeu.hpp $(AG_DIR)Case.hpp $(ES_DIR)CaseEchelleSerpent.hpp $(ES_DIR)EchelleSerpent.hpp
	g++ -std=c++11 -Wall -I $(HEADERS_DIR) -c $(AG_DIR)Plateau.cpp
$(AG_DIR)Jeu.o : $(AG_DIR)Jeu.cpp $(AG_DIR)Constantes.hpp $(AG_DIR)Pion.hpp $(AG_DIR)Joueur.hpp
	g++ -std=c++11 -Wall -I $(HEADERS_DIR) -c $(AG_DIR)Jeu.cpp
$(ES_DIR)EchelleSerpent.o : $(ES_DIR)EchelleSerpent.cpp $(AG_DIR)Jeu.hpp
	g++ -std=c++11 -Wall -I $(HEADERS_DIR) -c $(ES_DIR)EchelleSerpent.cpp
$(ES_DIR)ObjetEchelleSerpent.o : $(ES_DIR)ObjetEchelleSerpent.cpp
	g++ -std=c++11 -Wall -I $(HEADERS_DIR) -c $(ES_DIR)ObjetEchelleSerpent.cpp
$(ES_DIR)CaseEchelleSerpent.o :  $(ES_DIR)CaseEchelleSerpent.cpp  $(AG_DIR)Constantes.hpp $(AG_DIR)Case.hpp $(ES_DIR)ObjetEchelleSerpent.hpp $(ES_DIR)EchelleSerpent.hpp
	g++ -std=c++11 -Wall -I $(HEADERS_DIR) -c  $(ES_DIR)CaseEchelleSerpent.cpp
$(AG_DIR)main.o : $(AG_DIR)main.cpp $(AG_DIR)Constantes.hpp $(AG_DIR)Plateau.hpp $(AG_DIR)Jeu.hpp $(ES_DIR)EchelleSerpent.hpp
	g++ -std=c++11 -Wall -I $(HEADERS_DIR) -c $(AG_DIR)main.cpp

clean :
	rm *.o $(GOALS)
