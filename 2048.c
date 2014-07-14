#include <stdio.h>
#include <stdlib.h> 
#include <Windows.h>
#include <time.h>
#include <conio.h>

#define RED 4
#define GREEN 2
#define BLUE 1
#define BRIGHT 8


void clear(){
	system("cls");
}

void wait(int ms){
	clock_t startTime;
	startTime=clock();
	while((double)(clock()-startTime)<ms);
}


void colorPrint(int color, char *str){
	HANDLE hConsole = GetStdHandle ( STD_OUTPUT_HANDLE );
	SetConsoleTextAttribute ( hConsole, color );
	printf("%s", str);
	SetConsoleTextAttribute ( hConsole, (RED+GREEN+BLUE));
}

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

void gameOver(){

}


void printNum(int num){
	char *nums[]={"   2   ", "   4   ", "   8   ", "  1 6  ", "  3 2  ", "  6 4  ", "  128  ", "  256  ", "  512  ", "1 0 2 4", "2 0 4 8"};
	//int colors[]={(), (), (), (), (), (), (), (), (), ()};
	int colors=BLUE+GREEN+RED+BRIGHT;
	colorPrint(colors, nums[num]);
}

void refresh(int tiles[4][4]){
	char *top="¢z¢w¢w¢w¢s¢w¢w¢w¢s¢w¢w¢w¢s¢w¢w¢w¢{\n";
	char *middle="¢u¢w¢w¢w¢q¢w¢w¢w¢q¢w¢w¢w¢q¢w¢w¢w¢t\n";
	char *bottom="¢|¢w¢w¢w¢r¢w¢w¢w¢r¢w¢w¢w¢r¢w¢w¢w¢}\n";
	int lineColor=(RED+BLUE+GREEN);
	int i, j, k;
	//int backColor[]={(), (), (), (), (), (), (), (), (), ()};  should be the same as colors in printNum()
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
	
}

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

int main(){
	int tiles[4][4]={0};
	char input;
	
	splashScreen();
	scanf("%c", &input);
	refresh(tiles);
	
	while(1){
		input=getch();
		if(con==3)break; //program ends when ctrl+c is pressed
		
		//Inputs: arrows, enter, q, ctrl+c, ....
	}
	
	return 0;
}