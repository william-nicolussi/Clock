#ifndef DATA_H	/*Guarda di non definirla di nuovo*/
#define DATA_H

#include <ctime>

class DataOra{	
	public:
		time_t tempoIniz;
		tm* now;				//variabili per ottenere il tempo
		DataOra();				//costruttore
		int getSecond();		//restutuisce secondi 0-59
		int getMinute();		//restituisce minuti 0-59
		int getHour();			//restituisce ore 0-23
		int getDay();			//restituisce giorno del mese 1-31
		int getMonth();			//restituisce mese 0-11
		int getYear();			//restituisce anno
		int daysSinceSunday();	//restituisce numero giorni dalla domenica 0-6
		int daysSinceJanuary1();//restutuisce numero giorni dall'1 gennaio
		
	private:
		void setNow();	//Ricava valori attuali
};

#endif
