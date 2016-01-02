GOALS = test
HEADERS_DIR = .
all : $(GOALS)

test : Pion.o Case.o CaseNormale.o ../jeux/EchelleSerpent/CaseEchelleSerpent.o test.o
	g++ -std=c++11 -o test Pion.o Case.o CaseNormale.o CaseEchelleSerpent.o test.o
Pion.o : Pion.cpp Case.hpp
	g++ -std=c++11 -Wall -I $(HEADERS_DIR) -c Pion.cpp
Case.o : Case.cpp Pion.hpp Constantes.hpp
	g++ -std=c++11 -Wall -I $(HEADERS_DIR) -c Case.cpp
CaseNormale.o : CaseNormale.cpp Case.hpp
	g++ -std=c++11 -Wall -I $(HEADERS_DIR) -c CaseNormale.cpp
 ../jeux/EchelleSerpent/CaseEchelleSerpent.o :  ../jeux/EchelleSerpent/CaseEchelleSerpent.cpp  Case.hpp
	g++ -std=c++11 -Wall -I $(HEADERS_DIR) -c  ../jeux/EchelleSerpent/CaseEchelleSerpent.cpp
test.o : test.cpp Constantes.hpp Pion.hpp Case.hpp CaseNormale.hpp ../jeux/EchelleSerpent/CaseEchelleSerpent.hpp
	g++ -std=c++11 -Wall -I $(HEADERS_DIR) -c test.cpp

clean :
	rm *.o $(GOALS)
