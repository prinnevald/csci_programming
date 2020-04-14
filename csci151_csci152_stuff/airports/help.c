#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
 char name[20],city[20], terminals[10];
 int timeZone, numberOfTerminals;
}airport;

typedef struct {
 char airline[3];
 int number, from, to, hour, minute, duration;
}flight;

void departures (const char airportName[], const char airportCity[],const airport airportData[],const flight flightSched[])
{ printf("Flight Departure - %s %s airport. \n", airportCity, airportName);
  printf("Time\t");
  printf("Flight\t   ");
  printf("Destination\n");
}

int main (){
 setvbuf (stdout, NULL,_IONBF,0);
 airport airportList[100];
 flight flightList[100];
FILE*file1=fopen("airports.txt", "r");
FILE*file2=fopen("schedule.txt", "r");
int ai=0;
while(!feof(file1)){ //Moscow +3 Sheremetevo A B C D E F
 fscanf(file1, "%s %i %s", airportList[ai].city, &airportList[ai].timeZone, airportList[ai].name);
 int r=0;

 do{char c=fgetc(file1);
  if(feof(file1)) break;
  if (c==' '){continue;}
  if (c=='\n'){break; }
  airportList[ai].terminals[r]=c; r++;
 }while(!feof(file1)); airportList[ai].numberOfTerminals=r;
 printf("%s %i %s %s %i\n", airportList[ai].city, airportList[ai].timeZone, airportList[ai].name, airportList[ai].terminals, airportList[ai].numberOfTerminals);
ai++;
}
fclose(file1);
fclose(file2);
}
