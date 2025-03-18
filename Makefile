CC = gcc
CPP = g++
NOME_EXE = orologio
PARAM_AGGIUNTIVI = DataOra.cpp
PARAM_SFML = -lsfml-graphics -lsfml-window -lsfml-system

#all + nome eseguibile
all: start

#rimuovi questi file col comando clean
clean:
	rm *.exe

#tutte le volte che richiamo start esegue questo
start:
	$(CPP) -Wall -o $(NOME_EXE) orologio.cpp $(PARAM_AGGIUNTIVI) $(PARAM_SFML)