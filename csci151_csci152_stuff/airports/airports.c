#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
	char name[30];
	char city[30];
	int timeZone;
	int numberOfTerminals;
	char terminals[10];	
} airport;

typedef struct {
	char airline[3];
	int number;
	int from;
	int to;
	int hour;
	int minute;
	int duration;
} flight;

void departures(const char airportName[], const char airportCity[], const airport airportData[], const flight flightSched[]){

	printf("Flight Departure - %s %s airport\n", airportCity, airportName);
	printf("Time\tFlight\t\t\tDestination\n");	

	int loop1 = 0, loop2 = 0, lines = 0;	

	while(flightSched[lines].duration != '\0')	lines++;
	while(strcmp(airportCity, airportData[loop1].city))	loop1++;
	//printf("lines %i\n", lines);

	while(loop2 < lines){
		if(flightSched[loop2].from == loop1){

			if(flightSched[loop2].hour/10 == 0){
				printf("0%i:",flightSched[loop2].hour);
			} else {
				printf("%i:",flightSched[loop2].hour);
			}

			if(flightSched[loop2].minute/10 == 0){
				printf("0%i\t",flightSched[loop2].minute);
			} else {
				printf("%i\t",flightSched[loop2].minute);
			}

			printf("%s", flightSched[loop2].airline);
			printf("%i\t\t",flightSched[loop2].number);
	
			printf("%s-%s\n", airportData[flightSched[loop2].to].city, airportData[flightSched[loop2].to].name);

		}

		loop2++;
	}
}

int main(){

	airport ap[30];
	flight fly[30];
	int printlines = 0;
	int iter;

	FILE *air;	//file opening 
	air = fopen("airports.txt", "r");
	FILE *table;
	table = fopen("schedule.txt", "r");
	if(table == NULL || air == NULL){
		printf("problem with file");
		return 1;
	}

	for(iter = 0; !feof(air); iter++){
		fscanf(air, "%s ", ap[iter].city);		//scanning city
	
		char zone[3];
		fscanf(air, "%s ", zone);		

		if(zone[0] == 43 || zone[0] == 45){		//43 -> plus
			ap[iter].timeZone = zone[1] - 48;	//48 -> zero
		} else {
			ap[iter].timeZone = zone[0] - 48;
		}

		fscanf(air, "%s ", ap[iter].name);
		
		char term;
		int terminals = 0;
		while((term = getc(air)) != '\n' && !feof(air)){	//getting the terminals and counting them
			if(!feof(air) && term != ' '){
				ap[iter].terminals[terminals] = term;
				terminals += 1;
			}
		}
		ap[iter].terminals[terminals] = '\0';
		ap[iter].numberOfTerminals = terminals;
		printlines += 1;
		
		//printf("%s %i %s %s %i\n", ap[iter].city, ap[iter].timeZone, ap[iter].name, ap[iter].terminals, ap[iter].numberOfTerminals);
	}

	for( int tester = 0; tester < 30; tester++)	fly[tester].duration = '\0';

	iter = 0;

	do{
	

		char temporaryfrom[30];
		char temporaryto[30];
		char trashbin[30];
		char secbin[30];
		int val = 0;
		int time;
		fly[iter].to = 0;
		fly[iter].from = 0;

		fscanf(table, "%s %i %s %s - %s %s %i %i", fly[iter].airline, &fly[iter].number, temporaryfrom, trashbin, temporaryto, secbin, &time, &fly[iter].duration);

		while(strcmp(ap[val].city, temporaryfrom) != 0){
			if(ap[val].name[0] != '\0'){
				fly[iter].from++;
			} else {
				fly[iter].from = -1;
				break;
			}
			val++;
		}
		//printf("%i ", fly[iter].from);

		val = 0;

		while(strcmp(ap[val].city, temporaryto) != 0){
			if(ap[val].name[0] != '\0'){
				fly[iter].to++;
			} else {
				fly[iter].to = -1;
				break;
			}
			val++;
		}		
		//printf("%i ", fly[iter].to);

		fly[iter].hour = time/100;
		fly[iter].minute = time%100;

 

		iter++;
	}while(!feof(table));

	//for(int test = 0; test < 25; test++) 
	//printf("%s %i   %i %i\t %i\n", fly[test].airline, fly[test].number, fly[test].from, fly[test].to, fly[test].duration); 

	for(int line = 0; line < printlines; line++){
		departures(ap[line].name, ap[line].city, ap, fly);
	}

return 0;
}
