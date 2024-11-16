#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define screenhight 29
#define screenwidth 118
#define gamescreen 98
#define holesize 7

COORD coord = {X: 0, Y: 0};

using namespace std;

int birdpos = 8;
int pipepos[3];
int gappos[3];
int pipestat[3];
int score = 0;

void gotoxy (int x, int y){

    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void drawborder (){

	for(int i=0; i<screenwidth; i++){
		gotoxy(i,0); cout<<"-";
		gotoxy(i,screenhight); cout<<"-";
	}
	
	for(int i=0; i<screenhight; i++){
		gotoxy(0,i); cout<<"|";
		gotoxy(screenwidth,i); cout<<"|";
	}
	for(int i=0; i<screenhight; i++){
		gotoxy(gamescreen,i); cout<<"|";
	}
}

void drawbird(){
	
	char bird[3][9] = {

	{' ', '/','/','/',' ',' ',' ',' ',' '},
	{' ', '/','/','/','/',' ',' ',' ',' '},
	{'<', '/','/','/','/','/','=','<','>'}

	};

	for (int a = 0; a < 3; a++){
		for (int b = 0; b < 9; b++){

			gotoxy(b + 10, a + birdpos); cout<<bird[a][b] <<" ";
		}
		cout<<endl;
	}
}

void erasebird(){
	for(int i=0; i<3; i++){
		for(int j=0; j<9; j++){
			gotoxy(j+10,i+birdpos); cout<<" ";
		}
	}
}

void genpipe(int index){
	gappos[index] = 3 + rand() % 14;
}

void drawpipe(int index){
	if (pipestat[index] == 1){
		for (int a = 0; a < gappos[index]; a++){
			gotoxy (gamescreen - pipepos[index], a+1); cout<<"====";
		}
		for (int b = gappos[index]+holesize; b < screenhight - 1; b++){
			gotoxy (gamescreen - pipepos[index], b+1); cout<<"====";
		}
	}
}

void erasepipe(int index){
	if (pipestat[index] == 1){
		for (int a = 0; a < gappos[index]; a++){
			gotoxy (gamescreen - pipepos[index], a+1); cout<<"    ";
		}
		for (int b = gappos[index]+holesize; b < screenhight - 1; b++){
			gotoxy (gamescreen - pipepos[index], b+1); cout<<"    ";
		}
	}
}
int collapse (){
	if (pipepos[0] >= 80){
		if (birdpos < gappos [0] || birdpos > gappos[0] + holesize){
			
			return 1;
		}
	}
	return 0;
}

void updatescore(){
	
	gotoxy (gamescreen + 7, 11); cout<<"Score: " <<score;
}

void storyplay(){
	
	system("cls");
	
	cout<<"sorry, this part of game will deploy as soon as possible, \n\ncuz the developer might be busy as hell right now"<<endl;
	getch();
}

void gameover(){
	
	system ("cls");
	system ("color C0");
	
	gotoxy(15,7);  cout<<" ___________ __________ ____________ _______      _______ __       __ _______ _________";
	gotoxy(15,8);  cout<<"|           |          |            |       |    |       |  |     |  |       |         |";
	gotoxy(15,9);  cout<<"|    _______|    __    |   _    _   |   ____|    |   _   |  |     |  |   ____|   ___   |";
	gotoxy(15,10); cout<<"|   |       |   |  |   |  | |  | |  |  |         |  | |  |  |     |  |  |    |  |   |  |";
	gotoxy(15,11); cout<<"|   |    ___|   |__|   |  | |  | |  |  |____     |  | |  |  |_   _|  |  |____|  |___|  |_";
	gotoxy(15,12); cout<<"|   |___|   |    __    |  | |__| |  |   ____|    |  |_|  |_   | |   _|   ____|   _____   |";
	gotoxy(15,13); cout<<"|           |   |  |   |  |      |  |  |____     |       | |  |_|  | |  |____|  |     |  |";
	gotoxy(15,14); cout<<"|___________|___|  |___|__|      |__|_______|    |_______| |_______| |_______|__|     |__|";
	
	gotoxy(15,18); cout<<"=========================================================================================";
	gotoxy(15,19); cout<<"                          PRESS ANY KEY TO RETRY THE GAME                                ";
    gotoxy(15,20); cout<<"=========================================================================================";
	
	getch();	
}

void play(){
	
	birdpos = 8;
	pipestat[0] = 1;
	pipestat[1] = 0;
	pipepos[0]= pipepos[1] = 4;
	score = 0;
	
	system ("cls");
	system ("color E0");
	drawborder();
	genpipe(0);
	updatescore();
	
	gotoxy (gamescreen + 7, 4); cout<<"Welcome";//pas
	gotoxy (gamescreen + 3, 6); cout<<"To Flappy Bird";
	gotoxy (gamescreen + 3, 8); cout<<"---------------";
	
	gotoxy (gamescreen + 7, 13); cout<<"------ ";
	
	gotoxy (gamescreen + 7, 17); cout<<"Control";
	gotoxy (gamescreen + 7, 19); cout<<"-------";
	gotoxy (gamescreen + 3, 22); cout<<"Spacebar = Jump";

	gotoxy (38, 15); cout<<"PRESS ANY KEY TO START";
	getch();
	gotoxy (38, 15); cout<<"                      ";
	
	while (1){
		
		if (kbhit()){
			
		int hit = getch();
			if (hit == 32){
				if (birdpos > 3){
					
					birdpos -= 3;
				}
			}
			
			if (hit == 27){
			
				break;
			}
		}
		
		drawbird();
		drawpipe(0);
		drawpipe(1);
		
			if (collapse() == 1){
				gameover();
				return;
			}
		Sleep (100);
		
		erasebird();
		erasepipe(0);
		erasepipe(1);
		
		birdpos += 1;
		
			if (birdpos > screenhight - 1){
				
				gameover();
				return;
			}
		
		if( pipestat[0] == 1 )
			pipepos[0] += 2;
		
		if( pipestat[1] == 1 )
			pipepos[1] += 2;
		
		if( pipepos[0] >= 67 && pipepos[0] < 69 ){
			pipestat[1] = 1;
			pipepos[1] = 4;
			genpipe(1);
		}
		if( pipepos[0] > 95 ){
			
			score++;
			updatescore();
			
			pipestat[1] = 0;
			pipepos[0] = pipepos[1];
			gappos[0] = gappos[1];
		}
	}
}
		
void intruction(){
	
	system ("cls");
	system ("color AF");
	
	gotoxy (10, 1); cout<<" ___________ __         _________ _________ ________ __     __      _______ _ _________   _______";
	gotoxy (10, 2); cout<<"|           |  |       |         |         |        |  |   |  |    |       | |         | |       |";
	gotoxy (10, 3); cout<<"|   ________|  |       |   ___   |   ___   |   __   |  |   |  |    |   _   | |   ___   | |       |";
	gotoxy (10, 4); cout<<"|  |________   |       |  |   |  |  |   |  |  |  |  |  |___|  |    |  |_|  | |  |   |  | |   _   |" ;
	gotoxy (10, 5); cout<<"|           |  |       |  |___|  |  |___|  |  |__|  |         |    |   _   | |  |___|  |_|  | |  | ";
	gotoxy (10, 6); cout<<"|   ________|  |       |   ___   |   ______|   _____|______   |    |  | |  | |   _____   |  | |  | ";
	gotoxy (10, 7); cout<<"|  |        |  |_______|  |   |  |  |      |  |            |  |    |  |_|  | |  |     |  |  |_|  | ";
	gotoxy (10, 8); cout<<"|  |        |          |  |   |  |  |      |  |      ______|  |    |      /| |  |     |  |      / ";
	gotoxy (10, 9); cout<<"|__|        |__________|__|   |__|__|      |__|     |_________|    |____ / |_|__|     |__|_____/ ";
	
	gotoxy (10, 12); cout<<"==================================================================================================";
	gotoxy (10, 13); cout<<"                          Pay Attention Please To The Inttruction                                 ";
	gotoxy (10, 14); cout<<"==================================================================================================";
	
	gotoxy (10, 16); cout<<"                   1. If you Wanna Play The Game, Just Click On (1 = play)";
	gotoxy (10, 17); cout<<"                   2. Just Click On Space Bar To Start the Game";
	gotoxy (10, 18); cout<<"                   3. Just Click On Space Bar To Make  Bird Jump ";
	gotoxy (10, 19); cout<<"                   4. You Can See The Score, Beside The Game Frame";
	gotoxy (10, 20); cout<<"                   5. If Hit The Pipe, The Game Gonna Be Over";

	gotoxy (10, 23); cout<<"==================================================================================================";
	gotoxy (10, 24); cout<<"                                CLICK ANYKEY TO GET BACK ";
	gotoxy (10, 25); cout<<"==================================================================================================";
	
	getch();

}

int main ()	{
	
	char option;

	do{
	
	system ("cls");
	system ("color B0");
	
	gotoxy (10, 1); cout<<" ___________ __         _________ _________ ________ __     __      _______ _ _________   _______";
	gotoxy (10, 2); cout<<"|           |  |       |         |         |        |  |   |  |    |       | |         | |       |";
	gotoxy (10, 3); cout<<"|   ________|  |       |   ___   |   ___   |   __   |  |   |  |    |   _   | |   ___   | |       |";
	gotoxy (10, 4); cout<<"|  |________   |       |  |   |  |  |   |  |  |  |  |  |___|  |    |  |_|  | |  |   |  | |   _   |" ;
	gotoxy (10, 5); cout<<"|           |  |       |  |___|  |  |___|  |  |__|  |         |    |   _   | |  |___|  |_|  | |  | ";
	gotoxy (10, 6); cout<<"|   ________|  |       |   ___   |   ______|   _____|______   |    |  | |  | |   _____   |  | |  | ";
	gotoxy (10, 7); cout<<"|  |        |  |_______|  |   |  |  |      |  |            |  |    |  |_|  | |  |     |  |  |_|  | ";
	gotoxy (10, 8); cout<<"|  |        |          |  |   |  |  |      |  |      ______|  |    |      /| |  |     |  |      / ";
	gotoxy (10, 9); cout<<"|__|        |__________|__|   |__|__|      |__|     |_________|    |____ / |_|__|     |__|_____/ ";
	

	gotoxy (10, 11);cout<<"===================================================================================================";
	gotoxy (10, 12);cout<<"                                 Welcome To The Game, Enjoy The Game                               ";
	gotoxy (10, 13);cout<<"                                           Made By Anwar                                           " ;
	gotoxy (10, 14);cout<<"===================================================================================================";
	
	gotoxy (10, 16);cout<<"                                          1. Quick Play";
	gotoxy (10, 17);cout<<"                                          2. Story Play";
	gotoxy (10, 18);cout<<"                                          3. Intruction";
	gotoxy (10, 19);cout<<"                                          4. Quit" ;
	
	gotoxy (10, 22);cout<<"===================================================================================================";
	gotoxy (10, 23);cout<<"                                    SELECT THE OPTION TO CONTINUE                                  ";
	gotoxy (10, 24);cout<<"===================================================================================================";
	
	option = getche();
	
		if (option == '1'){
	
			play();
		}
		if (option == '2'){
			
			storyplay();
		}
		if (option == '3') {
	
			intruction();
		}
		if (option == '4') {
			
			break;
		}

	} while (option == '1' || option == '3');
	
}

