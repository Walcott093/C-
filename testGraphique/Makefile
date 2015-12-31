GOALS = sfml-app
HEADERS_DIR = .
all : $(GOALS)

sfml-app : All_In_One.o
	g++ -o sfml-app All_In_One.o -lsfml-graphics -lsfml-window -lsfml-system
All_In_One.o : All_In_One.cpp
	g++ -Wall -I $(HEADERS_DIR) -std=c++11 -c All_In_One.cpp

clean :
	rm *.o $(GOALS)
