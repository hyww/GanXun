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


int main(){

	return 0;
}