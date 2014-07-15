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
	a=rand()%3;
	if(a==0||a==1){
		b=1;
	}
	if(a==2){
		b=2;
	}
	while(1){
		i=rand()%4;
		j=rand()%4;
		if(tiles[i][j]==0){
			tiles[i][j]=b;
			break;
		}
	}
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
	int color=RED+GREEN+BLUE;
	clear();
	switch(status){
		case 0:{
			colorPrint(color, "ùæùùùùùù   ùæùùùè      ùæùè  ùæùè    ùæùùùùùù\n");
			colorPrint(color, "ùø         ùø  ùø      ùøùø  ùøùø    ùø      \n");
			colorPrint(color, "ùø        ùø    ùø    ùø  ùøùø  ùø   ùéùùùùùù\n");
			colorPrint(color, "ùø    ùç  ùéùùùùùë    ùø  ùìùî  ùø   ùø      \n");
			colorPrint(color, "ùø    ùø ùø      ùø  ùø          ùø  ùø      \n");
			colorPrint(color, "ùìùùùùùí ùø      ùø  ùø          ùø  ùìùùùùùù\n");
			colorPrint(color, "                                             \n");
			colorPrint(color, "¢¨¢i¢i¢i¢©  ¢i        ¢i   ¢i¢i¢i¢i   ¢i¢i¢i¢©\n");
			colorPrint(color, "¢i      ¢i   ¢i      ¢i    ¢i         ¢i    ¢i\n");
			colorPrint(color, "¢i      ¢i    ¢i    ¢i     ¢i         ¢i    ¢i\n");
			colorPrint(color, "¢i      ¢i     ¢i  ¢i      ¢i¢i¢i¢i   ¢i¢i¢i¢«\n");
			colorPrint(color, "¢i      ¢i      ¢n ¢n      ¢i         ¢i  ¢©  \n");
			colorPrint(color, "¢ª¢i¢i¢i¢«      ¢ª¢«       ¢i¢i¢i¢i   ¢i  ¢i¢©\n");
			break;}
		case 1:{

			colorPrint(color, "¢¨¢i¢i¢©  ¢i    ¢i ¢¨¢i¢i¢i  ¢¨¢i¢i¢i ¢¨¢i¢i¢i ¢¨¢i¢i¢© ¢¨¢i¢i¢©\n");
			colorPrint(color, "¢i        ¢i    ¢i ¢i        ¢i       ¢i       ¢i       ¢i      \n");
			colorPrint(color, "¢i¢i¢i¢i  ¢i    ¢i ¢i        ¢i       ¢i¢i¢i¢i ¢i¢i¢i¢i ¢i¢i¢i¢i\n");
			colorPrint(color, "      ¢i  ¢i    ¢i ¢i        ¢i       ¢i             ¢i       ¢i\n");
			colorPrint(color, "¢ª¢i¢i¢«  ¢ª¢i¢i¢« ¢ª¢i¢i¢i  ¢ª¢i¢i¢i ¢ª¢i¢i¢i ¢ª¢i¢i¢« ¢ª¢i¢i¢«\n");
			colorPrint(color, "                                                                \n");
			colorPrint(color, "                                    ¡¸¡¹¡¸¡¹¡¸¡¹¡¸¡¹¡¸¡¹¡¸¡¹¡¸¡¹¡¸\n");
			colorPrint(color, "                                          ¡¹¡¸¡¹¡¸¡¹¡¸¡¹¡¸¡¹¡¸¡¹¡¸\n");
			
			break;}

	}
	colorPrint((BLUE+GREEN+RED+BRIGHT), "\nPress enter to start a new game!!\n");
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
	int colors[]={((RED+BLUE+GREEN+BRIGHT)*16), ((GREEN+RED+BRIGHT)*16), ((GREEN+BRIGHT)*16), ((GREEN+BLUE+BRIGHT)*16), ((BLUE+BRIGHT)*16+15), ((GREEN)*16+15), ((GREEN+BLUE)*16+15), ((GREEN+RED)*16+15), ((BLUE+RED)*16+15), ((RED+BLUE+BRIGHT)*16), ((RED+BRIGHT)*16), ((RED)*16+15)};
	colorPrint(colors[num], nums[num]);
}

//print out current status
void refresh(int tiles[4][4], int steps){
	char *top="¢z¢w¢w¢w¢s¢w¢w¢w¢s¢w¢w¢w¢s¢w¢w¢w¢{\n";
	char *middle="¢u¢w¢w¢w¢q¢w¢w¢w¢q¢w¢w¢w¢q¢w¢w¢w¢t\n";
	char *bottom="¢|¢w¢w¢w¢r¢w¢w¢w¢r¢w¢w¢w¢r¢w¢w¢w¢}\n";
	int lineColor=(RED+BLUE+GREEN);
	int i, j, k;
	int backColor[]={((RED+BLUE+GREEN+BRIGHT)*16), ((GREEN+RED+BRIGHT)*16), ((GREEN+BRIGHT)*16), ((GREEN+BLUE+BRIGHT)*16), ((BLUE+BRIGHT)*16+15), ((GREEN)*16), ((GREEN+BLUE)*16), ((GREEN+RED)*16), ((BLUE+RED)*16+15), ((RED+BLUE+BRIGHT)*16), ((RED+BRIGHT)*16), ((RED)*16+15)};
	
	clear();
	colorPrint(lineColor, top);
	
	for(k=0;k<4;k++){
		for(j=0;j<3;j++){
			colorPrint(lineColor, "|");
			for(i=0;i<4;i++){
				if(j!=1)colorPrint(backColor[tiles[i][k]], "       ");
				else printNum(tiles[i][k]);
				colorPrint(lineColor, "|");
			}
			printf("\n");
		}
		if(k!=3)colorPrint(lineColor, middle);
	}
	colorPrint(lineColor, bottom);
	printf("NUMBER OF STEPS: %d" ,steps);
	
	//print steps
	
}

//change the status of tiles by moving in different directions
int move(int tiles[4][4], int direction){
	int moved=0;
	switch(direction){
		case 0:{
			//up
			int i;
			int j;
			int k;
			for(i = 0; i < 4; i++){
				for(j = 0; j < 4; j++){
					if(tiles[i][j] == 0){
						k=j+1;
						while(k<4){
							if(tiles[i][k]){
								moved=1;
								tiles[i][j]=tiles[i][k];
								tiles[i][k]=0;
								break;
							}
							k++;
						}
					}
				}
			} 
			//¥ý¦X¨Ö 
			for(i = 0; i < 4 ; i++){
				for(j = 0; j < 3; j++){
					if(tiles[i][j] == tiles[i][j+1]&&tiles[i][j]!=0){
						tiles[i][j]++;
						tiles[i][j+1] = 0;
						moved=1;
					}
				}
			}
			//²¾°Ê
			for(i = 0; i < 4; i++){
				for(j = 0; j < 4; j++){
					if(tiles[i][j] == 0){
						k=j+1;
						while(k<4){
							if(tiles[i][k]){
								moved=1;
								tiles[i][j]=tiles[i][k];
								tiles[i][k]=0;
								break;
							}
							k++;
						}
					}
				}
			} 
			break;
		}
		case 1:{
			//down
			int i;
			int j, k;
			for(i = 0; i < 4; i++){
				for(j = 0; j < 4; j++){
					if(tiles[i][3-j] == 0){
						k=j+1;
						while(k<4){
							if(tiles[i][3-k]){
								moved=1;
								tiles[i][3-j]=tiles[i][3-k];
								tiles[i][3-k]=0;
								break;
							}
							k++;
						}
					}
				}
			} 
			//¥ý¦X¨Ö 
			for(i = 0; i < 4 ; i++){
				for(j = 3; j > 0; j--){
					if(tiles[i][j] == tiles[i][j-1]&&tiles[i][j]!=0){
						tiles[i][j]++;
						tiles[i][j-1] = 0;
					}
				}
			}
			//²¾°Ê
			for(i = 0; i < 4; i++){
				for(j = 0; j < 4; j++){
					if(tiles[i][3-j] == 0){
						k=j+1;
						while(k<4){
							if(tiles[i][3-k]){
								moved=1;
								tiles[i][3-j]=tiles[i][3-k];
								tiles[i][3-k]=0;
								break;
							}
							k++;
						}
					}
				}
			} 
			break;
		}
		case 2:{
			//left
			int i;
			int j, k;
			for(i = 0; i < 4; i++){
				for(j = 0; j < 4; j++){
					if(tiles[j][i] == 0){
						k=j+1;
						while(k<4){
							if(tiles[k][i]){
								moved=1;
								tiles[j][i]=tiles[k][i];
								tiles[k][i]=0;
								break;
							}
							k++;
						}
					}
				}
			}  
			//¥ý¦X¨Ö 
			for(i = 0; i < 4 ; i++){
				for(j = 0; j < 3; j++){
					if(tiles[j][i] == tiles[j+1][i]&&tiles[j][i]!=0){
						tiles[j][i]++;
						tiles[j+1][i] = 0;
					}
				}
			}
			//²¾°Ê
			for(i = 0; i < 4; i++){
				for(j = 0; j < 4; j++){
					if(tiles[j][i] == 0){
						k=j+1;
						while(k<4){
							if(tiles[k][i]){
								moved=1;
								tiles[j][i]=tiles[k][i];
								tiles[k][i]=0;
								break;
							}
							k++;
						}
					}
				}
			}  
			break;
		}
		case 3:{
			//right
			int i;
			int j, k;
			for(i = 0; i < 4; i++){
				for(j = 0; j < 4; j++){
					if(tiles[3-j][i] == 0){
						k=j+1;
						while(k<4){
							if(tiles[3-k][i]){
								moved=1;
								tiles[3-j][i]=tiles[3-k][i];
								tiles[3-k][i]=0;
								break;
							}
							k++;
						}
					}
				}
			}  
			//¥ý¦X¨Ö 
			for(i = 0; i < 4 ; i++){
				for(j = 3; j > 0; j--){
					if(tiles[j][i] == tiles[j-1][i]&&tiles[j][i]!=0){
						tiles[j][i]++;
						tiles[j-1][i] = 0;
					}
				}
			}
			//²¾°Ê
			for(i = 0; i < 4; i++){
				for(j = 0; j < 4; j++){
					if(tiles[3-j][i] == 0){
						k=j+1;
						while(k<4){
							if(tiles[3-k][i]){
								moved=1;
								tiles[3-j][i]=tiles[3-k][i];
								tiles[3-k][i]=0;
								break;
							}
							k++;
						}
					}
				}
			}  
			break;
		}
	}
	return moved;
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
		
	//¥ý§PÂ_¾îªº 
	for(i=0;i<4;i++)
	{
		for(j=0;j<3;j++)
		{
			if(tiles[j][i]==tiles[j+1][i])
				return 0;
		}
	}
	
	//¦A§PÂ_ª½ªº 
	for(i=0;i<4;i++)
	{
		for(j=0;j<3;j++)
		{
			if(tiles[i][j]==tiles[i][j+1])
				return 0;
		}
	}
	return 1;
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
	int moved=0;
	char input;
	/*int i;
	for(i=0;i<13;i++){
		printNum(i);
	}*/
	newGame(tiles, &steps);
	splashScreen();
	scanf("%c", &input);


	generate(tiles);
	generate(tiles);
		

	refresh(tiles, steps);
	
	while(1){

		input=getch();
		if(input==3)break; //program ends when ctrl+c is pressed

		switch(input)
		{
			case 'w':
				moved=move(tiles,0);
			break;

			case 's':
				moved=move(tiles,1);
			break;

			case 'a':
				moved=move(tiles,2);
			break;

			case 'd':
				moved=move(tiles,3);
			break;

			default:
				continue;
		}		
		
		if(achieve_2048(tiles)){
			gameOver(1,steps);
			scanf("%c", &input);
			newGame(tiles, &steps);
			generate(tiles);
			generate(tiles);
		}
		else if(isfull(tiles)){
			gameOver(0,steps);
			scanf("%c", &input);
			newGame(tiles, &steps);
			generate(tiles);
			generate(tiles);
		}
		else if(moved){
			moved=0;
			generate(tiles);
  			steps++;
		}
		refresh(tiles,steps);
		//Inputs: arrows, enter, q, ctrl+c, ....
	}
	
	
	return 0;
}
