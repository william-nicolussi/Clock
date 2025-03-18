#include "DataOra.h"

DataOra::DataOra(){
	setNow();
}

int DataOra::getSecond(){
	setNow();
	return now->tm_sec;
}
int DataOra::getMinute(){
	setNow();
	return now->tm_min;
}
int DataOra::getHour(){
	setNow();
	return now->tm_hour;
}
int DataOra::getDay(){
	setNow();
	return now->tm_mday;
}
int DataOra::getMonth(){
	setNow();
	return now->tm_mon+1;
}
int DataOra::getYear(){
	setNow();
	return now->tm_year+1900;
}
int DataOra::daysSinceSunday(){
	setNow();
	return now->tm_wday;
}
int DataOra::daysSinceJanuary1(){
	setNow();
	return now->tm_yday;
}

void DataOra::setNow(){
	//---Ottieni il tempo---
	tempoIniz = time(0);
	now = localtime(&tempoIniz);
}