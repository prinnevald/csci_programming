/*
	Hello, my dear friend!

	You have gotten into a big trouble, you will NEVER win in the game below. (and also understand the code)

	Good Luck!

	made by: Danny 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int island ( int he, int wi, char vis[he][wi], char map[he][wi], int cy, int cx, int guesses[]){  //island reveal
		
		if(cy>=0 && cx>=0 && cy<he && cx<wi){

			if ((vis [cy][cx] == 0 || vis[cy][cx] ==  3)  && map[cy][cx] != '*'){

			vis[cy][cx] = 1;
			guesses[0]++;
			
			if((vis[cy-1][cx] == 0 || vis[cy-1][cx] == 3) && map[cy-1][cx] == '.'){
			island(he, wi, vis, map, cy-1, cx, guesses);
			} else if ((vis[cy-1][cx] == 0 || vis[cy-1][cx] ==  3) && (cy-1>=0 && cx>=0 && cy-1<he && cx<wi)) {vis[cy-1][cx] = 1;guesses[0] ++;}

			if((vis[cy][cx-1] == 0 ||vis[cy][cx-1] ==  3) && map[cy][cx-1] == '.'){
			island(he, wi, vis, map, cy, cx-1, guesses);
			} else if ((vis[cy][cx-1] == 0 || vis[cy][cx-1] ==  3) && (cy>=0 && cx-1>=0 && cy<he && cx-1<wi)) {vis[cy][cx-1] = 1;guesses[0] ++;}

			if((vis[cy][cx+1] == 0 || vis[cy][cx+1] ==  3) && map[cy][cx+1] == '.'){
			island(he, wi, vis, map, cy, cx+1, guesses);
			} else if ((vis[cy][cx+1] == 0 || vis[cy][cx+1] ==  3) && (cy>=0 && cx+1>=0 && cy<he && cx+1<wi)) {vis[cy][cx+1] = 1;guesses[0] ++;}

			if((vis[cy+1][cx] == 0 || vis[cy+1][cx] ==  3) && map[cy+1][cx] == '.'){
			island(he, wi, vis, map, cy+1, cx, guesses);
			} else if ((vis[cy+1][cx] == 0 || vis[cy+1][cx] ==  3) && (cy+1>=0 && cx>=0 && cy+1<he && cx<wi)) {vis[cy+1][cx] = 1;guesses[0] ++;}

			if((vis[cy-1][cx-1] == 0 || vis[cy-1][cx-1] ==  3) && map[cy-1][cx-1] == '.'){
			island(he, wi, vis, map, cy-1, cx-1, guesses);
			} else if ((vis[cy-1][cx-1] == 0 || vis[cy-1][cx-1] ==  3) && (cy-1>=0 && cx-1>=0 && cy-1<he && cx-1<wi)) {vis[cy-1][cx-1] = 1;guesses[0] ++;}

			if((vis[cy+1][cx-1] == 0 || vis[cy+1][cx-1] ==  3) && map[cy+1][cx-1] == '.'){
			island(he, wi, vis, map, cy+1, cx-1, guesses);
			} else if ((vis[cy+1][cx-1] == 0 || vis[cy+1][cx-1] ==  3) && (cy+1>=0 && cx-1>=0 && cy+1<he && cx-1<wi)) {vis[cy+1][cx-1] = 1;guesses[0] ++;}

			if((vis[cy-1][cx+1] == 0 || vis[cy-1][cx+1] ==  3) && map[cy-1][cx+1] == '.'){
			island(he, wi, vis, map, cy-1, cx+1, guesses);
			} else if ((vis[cy-1][cx+1] == 0 || vis[cy-1][cx+1] ==  3) && (cy-1>=0 && cx+1>=0 && cy-1<he && cx+1<wi)) {vis[cy-1][cx+1] = 1;guesses[0] ++;}

			if((vis[cy+1][cx+1] == 0 || vis[cy+1][cx+1] ==  3) && map[cy+1][cx+1] == '.'){
			island(he, wi, vis, map, cy+1, cx+1, guesses);
			} else if ((vis[cy+1][cx+1] == 0 || vis[cy+1][cx+1] ==  3) && (cy+1>=0 && cx+1>=0 && cy+1<he && cx+1<wi)) {vis[cy+1][cx+1] = 1;guesses[0] ++;}
					
				}
			}
			
}

int main(){

srand(time(NULL));

int a, b, he, wi;
int mines, i=0, minerow, minecol;    //THE MENU WILL BE THERE (or not)

char flag, lol;

printf("Welcome to the Danny's Mindsweeper alpha version!\nHave fun!\n");   //scanning info for the game from the user

printf("Enter height of the map:\n");

scanf("%i", &he);

printf("Enter width of the map:\n");

scanf("%i", &wi);

printf("Enter the amount of mines on the map:\n");

scanf("\n%i", &mines);

char map[he][wi], f[he][wi];

char vis[he][wi]; //visibility struct activation

for(a=0; a<he; a++){		//creating empty map
	for(b=0; b<wi; b++){
	map[a][b] = '.';
	}
}


while(i<mines){

	minerow = rand()%he;
	minecol = rand()%wi;
	
	if(map[minerow][minecol] != '*'){
		map[minerow][minecol] = '*';
		i++;
	}
	
}


for(a=0; a<=(he-1); a++){		//checking neighbours of the mine
	for(b=0; b<=(wi-1); b++){
	if(map[a][b] == '*'){
		if((a-1)>=0 && (b-1)>=0){
			if(map[a-1][b-1] == '.'){
			map[a-1][b-1] = '1';
			}else if (map[a-1][b-1] != '*'){
			map[a-1][b-1] == map[a-1][b-1] + 1;}
 		}
		if((a-1)>=0){
			if(map[a-1][b] == '.'){
			map[a-1][b] = '1';
			}else if (map[a-1][b] != '*'){
			map[a-1][b] = map[a-1][b] + 1;}
 		}
		if((a-1)>=0 && (b+1)<=(wi-1)){
			if(map[a-1][b+1] == '.'){
			map[a-1][b+1] = '1';
			}else if(map[a-1][b+1] != '*'){
			map[a-1][b+1] = map[a-1][b+1] + 1;}
 		}
		if((b-1)>=0){
			if(map[a][b-1] == '.'){
			map[a][b-1] = '1';
			}else if(map[a][b-1] != '*'){
			map[a][b-1] = map[a][b-1] + 1;}
 		}
		if((b+1)<=(wi-1)){
			if(map[a][b+1] == '.'){
			map[a][b+1] = '1';
			}else if (map[a][b+1] != '*'){
			map[a][b+1] = map[a][b+1] + 1;}
 		}
		if((a+1)<=(he-1) && (b-1)>=0){
			if(map[a+1][b-1] == '.'){
			map[a+1][b-1] = '1';
			}else if (map[a+1][b-1] != '*'){
			map[a+1][b-1] = map[a+1][b-1] + 1;}
 		}
		if((a+1)<=(he-1)){
			if(map[a+1][b] == '.'){
			map[a+1][b] = '1';
			}else if (map[a+1][b] != '*'){
			map[a+1][b] = map[a+1][b] + 1;
 		}
		if((a+1)<=(he-1) && (b+1)<=(wi-1)){
			if(map[a+1][b+1] == '.'){
			map[a+1][b+1] = '1';
			}else if (map[a+1][b+1] != '*'){
			map[a+1][b+1] = map[a+1][b+1] + 1;}
 		}}
	}}
}

for(a=0; a<=(he-1); a++){		//setting visibility
	for(b=0; b<=(wi-1); b++){
	vis[a][b] = 0;
	}
}

int cy, cx, guesses[1], p;

guesses[0]=0;

while(1){    //game process

for(p=1;p<wi+1;p++){
if(p>=10){
printf("%i", p/10);}else{printf(" ");}
}

printf("\n");

for(p=1;p<wi+1;p++){
printf("%i", p%10);
}

printf("\n");

for(p=1;p<wi+1;p++){
printf("~");
}

printf("\n");


for(a=0; a<=(he-1); a++){		//printing mined map
	for(b=0; b<=(wi-1); b++){
	if  (vis[a][b] == 0){
	printf("#");
	}else if (vis[a][b] == 3){ 
	printf("F"); } else{
	printf("%c", map[a][b]);
	}
	}
	printf(" | %i", a+1);
	printf("\n");
}

scanf("%c", &lol);

printf("<d>ig of <f>lag?\n");

scanf("%c", &flag);

do{
printf("Enter row:\n");

scanf("%i", &cy);

cy = cy-1;

}while(cy > (he-1));

do{

printf("Enter column:\n");

scanf("%i", &cx);

cx = cx-1;

}while(cx > (wi-1));

if (flag == 'f'){
if (vis[cy][cx] == 3){vis[cy][cx] = f[cy][cx];} else {f[cy][cx] =  vis[cy][cx]; vis[cy][cx] = 3;}
 } else if (flag != 'f') {

if(map[cy][cx] == '*'){
	printf("BOOOOOM!\n");
	
	for(a=0; a<=(he-1); a++){		//printing mined map while lost;
	for(b=0; b<=(wi-1); b++){

	printf("%c", map[a][b]);
	
	}

	printf("\n");
	}  break;


} else if (map[cy][cx] == '.'){

island( he, wi, vis, map, cy, cx, guesses);

}else if (vis[cy][cx] == 0 || vis[cy][cx] == 3){
vis[cy][cx] = 1;
guesses[0]++;  
}

}

//printf("G: %i\n", guesses[0]);

if (guesses[0] == ((he) * (wi) - mines)){   //win condition
	printf("YOU WON (really!?)\n");

	for(a=0; a<=(he-1); a++){		//printing mined map while won;
	for(b=0; b<=(wi-1); b++){

	printf("%c", map[a][b]);
	
	}

	printf("\n");
	}  
	break;}

}

return 0;
}

