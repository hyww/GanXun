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
	char line1[]="�~�����~����  �~���~����\n";
	char line2[]="    ����  ���~������  ��\n";
	char line3[]="�~������  ����  ��������\n";
	char line4[]="��    ��  ����������  ��\n";
	char line5[]="������������    ��������\n";
	
	clear();
	colorPrint((RED+GREEN+BRIGHT), line1);
	colorPrint((RED+BRIGHT), line2);
	colorPrint((RED+BLUE+BRIGHT), line3);
	colorPrint((BLUE+BRIGHT), line4);
	colorPrint((BLUE+GREEN+BRIGHT), line5);
	colorPrint((BLUE+GREEN+RED+BRIGHT), "\nPress enter to start!!\n");
}

void printNum(int num){
	char *nums[]={"   2   ", "   4   ", "   8   ", "  1 6  ", "  3 2  ", "  6 4  ", "  128  ", "  256  ", "  512  ", "1 0 2 4", "2 0 4 8"};
	//int colors[]={(), (), (), (), (), (), (), (), (), ()};
	int colors=BLUE+GREEN+RED+BRIGHT;
	colorPrint(colors, nums[num]);
}

int main(){

	return 0;
}