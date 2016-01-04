GOALS = test
HEADERS_DIR = .
ES_DIR = ../jeux/EchelleSerpent/
all : $(GOALS)

test : Pion.o Joueur.o Case.o Plateau.o Jeu.o CaseNormale.o $(ES_DIR)EchelleSerpent.o $(ES_DIR)ObjetEchelleSerpent.o $(ES_DIR)CaseEchelleSerpent.o test.o
	g++ -std=c++11 -o test Pion.o Joueur.o Case.o Plateau.o Jeu.o CaseNormale.o EchelleSerpent.o ObjetEchelleSerpent.o CaseEchelleSerpent.o test.o
Pion.o : Pion.cpp Case.hpp
	g++ -std=c++11 -Wall -I $(HEADERS_DIR) -c Pion.cpp
Joueur.o : Joueur.cpp Pion.hpp
	g++ -std=c++11 -Wall -I $(HEADERS_DIR) -c Joueur.cpp
Case.o : Case.cpp Pion.hpp Constantes.hpp
	g++ -std=c++11 -Wall -I $(HEADERS_DIR) -c Case.cpp
Plateau.o : Plateau.cpp Case.hpp
	g++ -std=c++11 -Wall -I $(HEADERS_DIR) -c Plateau.cpp
Jeu.o : Jeu.cpp Pion.hpp Joueur.hpp Plateau.hpp
	g++ -std=c++11 -Wall -I $(HEADERS_DIR) -c Jeu.cpp
CaseNormale.o : CaseNormale.cpp Case.hpp
	g++ -std=c++11 -Wall -I $(HEADERS_DIR) -c CaseNormale.cpp
$(ES_DIR)EchelleSerpent.o : $(ES_DIR)EchelleSerpent.cpp Jeu.hpp
	g++ -std=c++11 -Wall -I $(HEADERS_DIR) -c $(ES_DIR)EchelleSerpent.cpp
$(ES_DIR)ObjetEchelleSerpent.o : $(ES_DIR)ObjetEchelleSerpent.cpp Case.hpp
	g++ -std=c++11 -Wall -I $(HEADERS_DIR) -c $(ES_DIR)ObjetEchelleSerpent.cpp
$(ES_DIR)CaseEchelleSerpent.o :  $(ES_DIR)CaseEchelleSerpent.cpp  Case.hpp $(ES_DIR)ObjetEchelleSerpent.hpp $(ES_DIR)EchelleSerpent.hpp Constantes.hpp
	g++ -std=c++11 -Wall -I $(HEADERS_DIR) -c  $(ES_DIR)CaseEchelleSerpent.cpp
test.o : test.cpp Constantes.hpp Pion.hpp Case.hpp CaseNormale.hpp $(ES_DIR)ObjetEchelleSerpent.hpp $(ES_DIR)CaseEchelleSerpent.hpp
	g++ -std=c++11 -Wall -I $(HEADERS_DIR) -c test.cpp

clean :
	rm *.o $(GOALS)
