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

	int indexfindap = 0;
	int secloop = 0;

	for(indexfindap; strcmp(airportCity, airportData[indexfindap].city); indexfindap++);

	//there we need to implement the changing size of the print, but how...
	int size;
	for(size = 0; flightSched[size].airline[0] != '\0' ; size++);

	for(secloop; secloop < size; secloop++){
		if(indexfindap == flightSched[secloop].from){

			if(flightSched[secloop].hour/10 == 0){
				printf("0%i:",flightSched[secloop].hour);
			} else {
				printf("%i:",flightSched[secloop].hour);
			}

			if(flightSched[secloop].minute/10 == 0){
				printf("0%i\t",flightSched[secloop].minute);
			} else {
				printf("%i\t",flightSched[secloop].minute);
			}

			printf("%s%i\t\t", flightSched[secloop].airline, flightSched[secloop].number);
	
			printf("%s-%s", airportData[flightSched[secloop].to].city, airportData[flightSched[secloop].to].name);

			printf("\n");
		}
	}

}

int main(){

	//opening files

	FILE *airpts;
	airpts = fopen("airports.txt", "r");
	if (airpts == NULL) {
		printf("Problem opening file.");
		return 1;
	}

	FILE *sched;
	sched = fopen("schedule.txt", "r");
	if (sched == NULL) {
		printf("Problem opening file.");
		return 1;
	}

	//reading the info into arrays

	airport airportList[30];
	flight flightList[30];
	int lines = 0;
	
	printf("=====================================\n");

	int apcount = 0;

	for(apcount = 0; !feof(airpts); apcount++){

		int termcount = 0;
		char plus;
		char temp;

		fscanf(airpts, "%s ", airportList[apcount].city);	//reading city name
		printf("%s ", airportList[apcount].city); 

		plus = getc(airpts);	//getting the '+' out of the way

		if (plus != '+'){
			airportList[apcount].timeZone = plus - '0';	//converting char into int
		} else {
			airportList[apcount].timeZone = getc(airpts) - '0';
		} 
		
		printf("%i ", airportList[apcount].timeZone);

		fscanf(airpts, "%s ", airportList[apcount].name);	//reading the ap name

		printf("%s ", airportList[apcount].name);

		while(((temp = getc(airpts)) != '\n') && !feof(airpts)){	//getting terminals
			if((temp != 32) && (temp != '\0')){
				airportList[apcount].terminals[termcount] = temp;
				printf("%c ", airportList[apcount].terminals[termcount]);
				termcount++;
			}
		}

		airportList[apcount].numberOfTerminals = termcount;	//num of terminals
		printf("Amount: %i\n", airportList[apcount].numberOfTerminals);
		lines++;
	} 

	int flycount = 0;
	char placeholder[30];
	printf("=====================================\n");

	do{
		fscanf(sched, "%s ", flightList[flycount].airline);	//reading the airline name
		printf("%s ", flightList[flycount].airline);

		//char num[10];
		fscanf(sched, "%i ", &flightList[flycount].number);	//reading the airline number
		//flightList[flycount].number = atoi(num);
		printf("%i ", flightList[flycount].number);

		char tempfrom[30];
		fscanf(sched, "%s ", tempfrom);
		flightList[flycount].from = 0;
		int index = 0;
		for(index = 0; strcmp(tempfrom, airportList[index].city) != 0; index++){
			if(airportList[index].timeZone == '\0'){
				flightList[flycount].from = '\0';
				break;
			} else {			
				flightList[flycount].from +=1;
			}
		}
		printf("%i ", flightList[flycount].from);		

		fscanf(sched, "%s ", placeholder);	//gettig rid of from airport name
		printf("%s ", placeholder);

		getc(sched);	//getting '-'

		char tempto[30];
		fscanf(sched, "%s ", tempto);
		flightList[flycount].to = 0;
		
		for(index = 0; strcmp(tempto, airportList[index].city) != 0; index++){
			if(airportList[index].timeZone == '\0'){
				flightList[flycount].to = '\0';
				break;
			} else {			
				flightList[flycount].to +=1;
			}
		}
		printf("%i ", flightList[flycount].to);

		fscanf(sched, "%s ", placeholder);	//gettig rid of to airport name
		printf("%s ", placeholder);

		int time;
		//char timenum[10];
		fscanf(sched, "%i", &time);	//reading the airline name
		//time = atoi(timenum);

		flightList[flycount].hour = time/100;
		flightList[flycount].minute = time%100;

		printf("%i ", flightList[flycount].hour);
		printf("%i\n", flightList[flycount].minute);

		//char duranum[10];
		fscanf(sched, "%i ", &flightList[flycount].duration);	//reading the airline name

		flycount++;

	}while(!feof(sched));

	//FINALLY GODDAMN PRINTING STUFFS

	printf("=====================================\n");

	int printer = 0;

	while(printer < lines){
		departures(airportList[printer].name, airportList[printer].city, airportList, flightList);
		printer++;
	}

return 0;
}
