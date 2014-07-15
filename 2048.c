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

void generate(int tiles[4][4]){
	int i,j,a,b;
	srand(time(NULL));
	i=rand()%4;
	j=rand()%4;
	a=rand()%3;
	if(a==0||a==1){
		b=2;
	}
	if(a==2){
		b=4;
	}
	while(1){
		if(tiles[i][j]==0){
			tiles[i][j]=b;
			break;
		}
	}
}

//the splash  screen shown when the game starts
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
	char *top="�z�w�w�w�s�w�w�w�s�w�w�w�s�w�w�w�{\n";
	char *middle="�u�w�w�w�q�w�w�w�q�w�w�w�q�w�w�w�t\n";
	char *bottom="�|�w�w�w�r�w�w�w�r�w�w�w�r�w�w�w�}\n";
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
		case 0:{
			//up
			int i;
			int j;
			//���X�� 
			for(i = 0; i < 4 ; i++){
				for(j = 0; j < 3; j++){
					if(tiles[i][j] == tiles[i][j+1]){
						tiles[i][j]++;
						tiles[i][j+1] = 0;
					}
				}
			}
			//����
			for(i = 0; i < 4; i++){
				int buf[4] = {0,0,0,0};
				int count = 0;
				for(j = 0; j < 4; j++){
					if(tiles[i][j] != 0){
						buf[count] = tiles[i][j];
						count++;
					}
				}
				for(j = 0; j < 4; j++){
					tiles[i][j] = buf[j];
				}
			} 
			break;
		}
		case 1:{
			//down
			int i;
			int j;
			//���X�� 
			for(i = 0; i < 4 ; i++){
				for(j = 3; j > 0; j--){
					if(tiles[i][j] == tiles[i][j-1]){
						tiles[i][j]++;
						tiles[i][j-1] = 0;
					}
				}
			}
			//����
			for(i = 0; i < 4; i++){
				int buf[4] = {0,0,0,0};
				int count = 0;
				for(j = 3; j >= 0; j--){
					if(tiles[i][j] != 0){
						buf[count] = tiles[i][j];
						count++;
					}
				}
				for(j = 3; j >= 0; j--){
					tiles[i][j] = buf[3-j];
				}
			} 
			break;
		}
		case 2:{
			//left
			int i;
			int j;
			//���X�� 
			for(i = 0; i < 4 ; i++){
				for(j = 0; j < 3; j++){
					if(tiles[j][i] == tiles[j+1][i]){
						tiles[j][i]++;
						tiles[j+1][i] = 0;
					}
				}
			}
			//����
			for(i = 0; i < 4; i++){
				int buf[4] = {0,0,0,0};
				int count = 0;
				for(j = 0; j < 4; j++){
					if(tiles[j][i] != 0){
						buf[count] = tiles[j][i];
						count++;
					}
				}
				for(j = 0; j < 4; j++){
					tiles[j][i] = buf[j];
				}
			} 
			break;
		}
		case 3:{
			//right
			int i;
			int j;
			//���X�� 
			for(i = 0; i < 4 ; i++){
				for(j = 3; j > 0; j--){
					if(tiles[j][i] == tiles[j-1][i]){
						tiles[j][i]++;
						tiles[j-1][i] = 0;
					}
				}
			}
			//����
			for(i = 0; i < 4; i++){
				int buf[4] = {0,0,0,0};
				int count = 0;
				for(j = 3; j >= 0; j--){
					if(tiles[j][i] != 0){
						buf[count] = tiles[j][i];
						count++;
					}
				}
				for(j = 3; j >= 0; j--){
					tiles[j][i] = buf[3-j];
				}
			} 
			break;
		}
	}
}

int isfull(int tiles[4][4]){
	int i=0;
	int j=0;
	
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(tiles[i][j]==0)
				return 0;
		}
	}
		
	//���P�_� 
	for(i=0;i<4;i++)
	{
		for(j=0;j<3;j++)
		{
			if(tiles[j][i]==tiles[j+1][i])
				return 0;
		}
	}
	
	//�A�P�_���� 
	for(i=0;i<4;i++)
	{
		for(j=0;j<3;j++)
		{
			if(tiles[i][j]==tiles[i][j+1])
				return 0;
		}
	}
}
int achieve_2048(int tiles[4][4])
{	int i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(tiles[i][j]==11)
			return 1;
		}
	}
	return 0;
}
int main(){
	int tiles[4][4]={0};
	int steps=0;
	char input;
	newGame(tiles, &steps);
	splashScreen();
	scanf("%c", &input);

	refresh(tiles, steps);
	generate(tiles);
	generate(tiles);
		

	refresh(tiles, steps);
	
	while(1){

		input=getch();
		if(input==3)break; //program ends when ctrl+c is pressed
		else if(input==11||input==12||input==13||input==14)move(tiles,input-11);
		if(achieve_2048)gameOver(1,steps);
		if(!isfull(tiles))gameOver(0,steps);
		generate(tiles);
		steps++;
		refresh(tiles,steps);
		//Inputs: arrows, enter, q, ctrl+c, ....
	}
	
	return 0;
}
