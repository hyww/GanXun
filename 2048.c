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


int main(){

	return 0;
}