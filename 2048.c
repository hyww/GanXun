#include <stdio.h>
#include <stdlib.h> 
#include <Windows.h>
#include <time.h>
#include <conio.h>

#define RED 4
#define GREEN 2
#define BLUE 1
#define BRIGHT 8

//clear the terminal output
void clear(){
	system("cls");
}

//suspend for ms/1000 seconds. may be useless if we're not going to create animations
void wait(int ms){
	clock_t startTime;
	startTime=clock();
	while((double)(clock()-startTime)<ms);
}

//print string with colors
void colorPrint(int color, char *str){
	HANDLE hConsole = GetStdHandle ( STD_OUTPUT_HANDLE );
	SetConsoleTextAttribute ( hConsole, color );
	printf("%s", str);
	SetConsoleTextAttribute ( hConsole, (RED+GREEN+BLUE));
}

//the splash  screen shown when the game starts
void splashScreen(){
	char line1[]="¢~ùù¢¡¢~ùù¢¡  ¢~¢¡¢~ùù¢¡\n";
	char line2[]="    ùøùø  ùø¢~¢£ùøùø  ùø\n";
	char line3[]="¢~ùù¢£ùø  ùøùø  ùøùàùù¢¡\n";
	char line4[]="ùø    ùø  ùø¢¢ùùùáùø  ùø\n";
	char line5[]="¢¢ùù¢£¢¢ùù¢£    ¢£¢¢ùù¢£\n";
	
	clear();
	colorPrint((RED+GREEN+BRIGHT), line1);
	colorPrint((RED+BRIGHT), line2);
	colorPrint((RED+BLUE+BRIGHT), line3);
	colorPrint((BLUE+BRIGHT), line4);
	colorPrint((BLUE+GREEN+BRIGHT), line5);
	colorPrint((BLUE+GREEN+RED+BRIGHT), "\nPress enter to start!!\n");
}

//just like splashScreen(), but displays when you lose XD
void gameOver(int status, int steps){
	switch(status){
		case 0:
			//fail
			break;
		case 1:
			//success
			break;
	}
}

void newGame(int tiles[4][4], int *steps){
	int i,j;
	for(i=0;i<=3;i++){
		for(j=0;j<=3;j++){
			tiles[i][j]=0;
		}
	}
	*steps=0;
}

//in the program we use 1, 2, 3... instead of 2, 4, 8...
void printNum(int num){
	char *nums[]={"       ", "   2   ", "   4   ", "   8   ", "  1 6  ", "  3 2  ", "  6 4  ", "  128  ", "  256  ", "  512  ", "1 0 2 4", "2 0 4 8"};
	//int colors[]={(), (), (), (), (), (), (), (), (), (), ()};
	int colors=BLUE+GREEN+RED+BRIGHT;
	colorPrint(colors, nums[num]);
}

//print out current status
void refresh(int tiles[4][4], int steps){
	char *top="¢z¢w¢w¢w¢s¢w¢w¢w¢s¢w¢w¢w¢s¢w¢w¢w¢{\n";
	char *middle="¢u¢w¢w¢w¢q¢w¢w¢w¢q¢w¢w¢w¢q¢w¢w¢w¢t\n";
	char *bottom="¢|¢w¢w¢w¢r¢w¢w¢w¢r¢w¢w¢w¢r¢w¢w¢w¢}\n";
	int lineColor=(RED+BLUE+GREEN);
	int i, j, k;
	//int backColor[]={(), (), (), (), (), (), (), (), (), (), ()};  should be the same as colors in printNum()
	int backColor=0;
	
	clear();
	colorPrint(lineColor, top);
	
	for(k=0;k<4;k++){
		for(j=0;j<3;j++){
			colorPrint(lineColor, "|");
			for(i=0;i<4;i++){
				if(j!=1)colorPrint(backColor, "       ");
				else printNum(tiles[i][j]);
				colorPrint(lineColor, "|");
			}
			printf("\n");
		}
		if(k!=3)colorPrint(lineColor, middle);
	}
	colorPrint(lineColor, bottom);
	printf("%d" ,steps);
	
	//print steps
	
}

//change the status of tiles by moving in different directions
void move(int tiles[4][4], int direction){
	switch(direction){
		case 0:
			//up
			break;
		case 1:
			//down
			break;
		case 2:
			//left
			break;
		case 3:
			//right
			break;
	}
}

int isfull(int tiles[4][4]){
	
}

int main(){
	int tiles[4][4]={0};
	int steps=0;
	char input;
	
	splashScreen();
	scanf("%c", &input);
	refresh(tiles, steps);
	
	while(1){
		input=getch();
		if(input==3)break; //program ends when ctrl+c is pressed
		
		//Inputs: arrows, enter, q, ctrl+c, ....
	}
	
	return 0;
}
