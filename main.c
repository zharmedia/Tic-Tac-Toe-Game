/*
	POLITEKNIK NEGERI BANDUNG
	D4 Teknik Informatika - 1A
	Developer		: 
		- Difa Mochammad Fadillah (201524004) 
		- Muhammad Azhar Alauddin (201524013)
	Program			: Tic Tac Toe
	Compiler		: DevC++
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>

#define KEYBOARD_TAB 9
#define KEYBOARD_ENTER 13
#define KEYBOARD_ESCAPE 27
#define KEYBOARD_BACKSPACE 8
#define KEYBOARD_F1 59
#define KEYBOARD_HOME 71

/* Declaration */																										  

char matrix[8][8]; 														// Frame Board Game							 			    

void introduction();													// Header Start Program								

void mainMenu();														// Main Menu Program									 
void help();															// Menu help											 					
void chooseColorTheme();												// Menu ChooseColorTheme								
void showColorTheme();													// Menu ShowColorTheme 								
void credit();															// Menu Credit											
int saveHighscore();													// Menu highScore  save
int readHighscore();													// Menu highScore  read

void init_matrix(int);													// Initialize Matrix								

void disp_matrix_3X3();													// Board Program 3X3									   
void disp_matrix_5X5();													// Board Program 5X5									 
void disp_matrix_7X7();													// Board Program 7X7									

void player1_move();													// Player1 Move Program									 
void player2_move();													// Player2 Move Program									  

char check_3X3();														// CheckWin 3X3											   
char check_5X5();														// CheckWin 5X5											
char check_7X7();														// CheckWin 7X7											 

void computer_move_1_3X3();												// Computer Move Program 3X3 easy level		
void computer_move_2_3X3();												// Computer Move Program 3X3 normal level	
void computer_move_3_3X3();												// Computer Move Program 3X3 hard level	
				 
void computer_move_1_5X5();												// Computer Move Program 5X5 easy level
void computer_move_2_5X5();												// Computer Move Program 5X5 normal level	
void computer_move_3_5X5();												// Computer Move Program 5X5 hard level
						   
void computer_move_1_7X7();												// Computer Move Program 7X7 easy level
void computer_move_2_7X7();												// Computer Move Program 7X7 normal level
void computer_move_3_7X7();												// Computer Move Program 7X7 hard level

void menuStart();														// Sumarizing Menu Start in Function Main
void menuHelp();														// Sumarizing Menu Help in Function Main
void menuColor();														// Sumarizing Menu Color Theme in Function Main
void menuCredit();														// Sumarizing Menu Credit in Function Main
void menuHighscore();													// Sumarizing Menu Highscore in Function Main
void menuExit();														// Sumarizing Menu Exit in Function Main

typedef struct data{
	int grid;
	char namePlayer[255];
	int levelComputer;
	char time[100];
};
	struct data dataPemain;

int against, player, chooseLanguage;
char p1[8], p2[8];
char done, kodeWarna[1];


/*******************************************************************
 MAIN FUNCTION (PROGRAM UTAMA YANG MENJALANKAN DARI AWAL HINGGA AKHIR)
 ********************************************************************/
 
int main() {
    int choiceMainMenu;
    
    // Main Menu
	menu:
	done = ' '; 												// Untuk main lagi
	player=1;													// Untuk main lagi
    mainMenu();
    scanf("%d",&choiceMainMenu);
    
    // Start Program
    if(choiceMainMenu==1){
    	menuStart();
    	while(true){
    		fflush(stdin);
    		char input = getch();
    		if((int) input == KEYBOARD_F1) goto menu;
		}
	}
    // help Program
	else if(choiceMainMenu==2){
		menuHelp();
		while(true){
			fflush(stdin);
			char input = getch();
			if((int) input == KEYBOARD_HOME) goto menu;
		}
	}
	
	// ColorTheme Program
	else if(choiceMainMenu==3){
		menuColor();
		while(true){
			fflush(stdin);
			char input = getch();
			if((int) input == KEYBOARD_ESCAPE) goto menu;
		}
	}
	
	// Credit Program
	else if(choiceMainMenu==4){
		menuCredit();
		while(true){
			fflush(stdin);
			char input = getch();
			if((int) input == KEYBOARD_TAB) goto menu;
		}
	}
	
	// Highscore Game
	else if(choiceMainMenu==5){
		menuHighscore();
		while(true){
			fflush(stdin);
			char input = getch();
			if((int) input == KEYBOARD_ENTER) goto menu;
		}
	}
	
	// Exit Program
	else if(choiceMainMenu==6){
		menuExit();
		while(true){
			fflush(stdin);
			char input = getch();
			if((int) input == KEYBOARD_BACKSPACE) goto menu;
		}
		exit(0);
	}
	
	else {
		goto menu;
	}
	
    return 0;
}

/*******************************************************************
PROCEDURE TO SUMMARIZE START IN MAIN MENU
 ********************************************************************/
 
void menuStart(){
	// Input Board Game
    	do{
    		system("cls");
			introduction();
	    	printf("  Board Game\n");
	    	printf("  Press 3 and Enter for [3X3]\n");
			printf("  Press 5 and Enter for [5X5]\n");
			printf("  Press 7 and Enter for [7X7]\n\n");
			printf("  Choose one : ");
			scanf("%d",&dataPemain.grid);
		}while(dataPemain.grid != 3 && dataPemain.grid != 5 && dataPemain.grid != 7);
    	
	// Input Opponent
		do{
			system("cls");
    		introduction();
			printf("  Whom do you wanna play?\n");
			printf("  Press 1 and Enter for playing with computer\n");
			printf("  Press 2 and Enter for playing with player2\n\n");
			printf("  Choose one : ");
			scanf("%d",&against);	
		}while(against != 1 && against != 2);
		
	// Input Name and Symbol
		system("cls");
    	introduction();
		if(against==1){
			printf("  [Max 8 Character]\n  Enter player's name : ");
			scanf("%s",dataPemain.namePlayer);
			printf("  %s's symbol is 'X'",dataPemain.namePlayer);
			
			printf("\n\n  Computer's symbol is 'O'");
			sleep(2);
		}
		else if(against==2){
			printf("  [Max 8 Character]\n  Enter player1's name : ");
			scanf("%s",p1);
			printf("  %s's symbol is 'X'",p1);
			
			printf("\n\n  [Max 8 Character]\n  Enter player2's name : ");
			scanf("%s",p2);
			printf("  %s's symbol is 'O'",p2);
			sleep(1);
		}
		
	// Input level computer
		if(against==1){
			do{
				system("cls");
				introduction();
				printf("  Enter level komputer : \n");
				printf("  [1] Easy\n");
				printf("  [2] Normal\n");
				printf("  [3] Hard\n\n");
				printf("  Choose one : ");
				scanf("%d",&dataPemain.levelComputer);
			}while(dataPemain.levelComputer != 1 && dataPemain.levelComputer != 2 && dataPemain.levelComputer!=3);
		}
		
	// All indices are made empty
		init_matrix(dataPemain.grid);
		
	// Player1 vs Player2 in 3X3
		if((dataPemain.grid==3) && (against==2)){
			system("cls");
    	 	
    	 	do{
    	 		player= (player % 2) ? 1: 2;
    	 		if(player==1){
    	 			disp_matrix_3X3(player,p1);
				 }
				else if(player==2){
					disp_matrix_3X3(player,p2);
				}
				if(player==1)
					player1_move();
				else if(player==2)
					player2_move();
				done = check_3X3();
				player++;
			} while(done==' ');			
			
			if(done=='X'){
				disp_matrix_3X3(player,p2);
				printf("\n\n  %s wins",p1);
			}
			else if(done=='O'){
				disp_matrix_3X3(player,p1);
				printf("\n\n  %s wins",p2);
			}
			else if(done=='D'){
				disp_matrix_3X3(player,p2);
				printf("\n\n  Draw");
			}
		}
		
	// Player1 vs Player2 in 5X5
		else if((dataPemain.grid==5) && (against==2)){
			system("cls");
    	 	
    	 	do{
    	 		player= (player % 2) ? 1: 2;
    	 		if(player==1){
    	 			disp_matrix_5X5(player,p1);
				 }
				else if(player==2){
					disp_matrix_5X5(player,p2);
				}
				if(player==1)
					player1_move();
				else if(player==2)
					player2_move();
				done = check_5X5();
				player++;
			} while(done==' ');			
			
			if(done=='X'){
				disp_matrix_5X5(player,p2);
				printf("\n\n  %s wins",p1);
			}
			else if(done=='O'){
				disp_matrix_5X5(player,p1);
				printf("\n\n  %s wins",p2);
			}
			else if(done=='D'){
				disp_matrix_5X5(player,p2);
				printf("\n\n  Draw");
			}
		}
		
	// Player1 vs Player2 in 7X7
		else if((dataPemain.grid==7) && (against==2)){
			system("cls");
    	 	
    	 	do{
    	 		player= (player % 2) ? 1: 2;
    	 		if(player==1){
    	 			disp_matrix_7X7(player,p1);
				 }
				else if(player==2){
					disp_matrix_7X7(player,p2);
				}
				if(player==1)
					player1_move();
				else if(player==2)
					player2_move();
				done = check_7X7();
				player++;
			} while(done==' ');			
			
			if(done=='X'){
				disp_matrix_7X7(player,p2);
				printf("\n\n  %s wins",p1);
			}
			else if(done=='O'){
				disp_matrix_7X7(player,p1);
				printf("\n\n  %s wins",p2);
			}
			else if(done=='D'){
				disp_matrix_7X7(player,p2);
				printf("\n\n  Draw");
			}
		}
		
	// Player1 vs Computer in 3X3 Easy Level
		else if((dataPemain.grid==3) && (against==1) && (dataPemain.levelComputer==1)){
			system("cls");
			
			do{
				disp_matrix_3X3(player,dataPemain.namePlayer);
				
				player1_move();
				computer_move_1_3X3();

				done = check_3X3();
			}while(done==' ');	
					
			if(done=='X'){
				disp_matrix_3X3(player,dataPemain.namePlayer);
				printf("\n  %s wins",dataPemain.namePlayer);
				saveHighscore();
			}
			else if(done=='O'){
				disp_matrix_3X3(player,dataPemain.namePlayer);
				printf("\n  Computer wins");
			}
			else if(done=='D'){
				disp_matrix_3X3(player,dataPemain.namePlayer);
				printf("\n  Draw");
			}
		}
		
	// Player1 vs Computer in 3X3 Normal Level
		else if((dataPemain.grid==3) && (against==1) && (dataPemain.levelComputer==2)){
			system("cls");
			
			do{
				disp_matrix_3X3(player,dataPemain.namePlayer);
				
				player1_move();
				computer_move_2_3X3();

				done = check_3X3();
			}while(done==' ');	
					
			if(done=='X'){
				disp_matrix_3X3(player,dataPemain.namePlayer);
				printf("\n  %s wins",dataPemain.namePlayer);
				saveHighscore();
			}
			else if(done=='O'){
				disp_matrix_3X3(player,dataPemain.namePlayer);
				printf("\n  Computer wins");
			}
			else if(done=='D'){
				disp_matrix_3X3(player,dataPemain.namePlayer);
				printf("\n  Draw");
			}
		}
		
	// Player1 vs Computer in 3X3 Hard Level
		else if((dataPemain.grid==3) && (against==1) && (dataPemain.levelComputer==3)){
			system("cls");
			
			do{
				disp_matrix_3X3(player,dataPemain.namePlayer);
				
				player1_move();
				computer_move_3_3X3();

				done = check_3X3();
			}while(done==' ');	
					
			if(done=='X'){
				disp_matrix_3X3(player,dataPemain.namePlayer);
				printf("\n  %s wins",dataPemain.namePlayer);
				saveHighscore();
			}
			else if(done=='O'){
				disp_matrix_3X3(player,dataPemain.namePlayer);
				printf("\n  Computer wins");
			}
			else if(done=='D'){
				disp_matrix_3X3(player,dataPemain.namePlayer);
				printf("\n  Draw");
			}
		}
		
	// Player1 vs Computer in 5X5 Easy Level
		else if((dataPemain.grid==5) && (against==1) && (dataPemain.levelComputer==1)){
			system("cls");
			
			do{
				disp_matrix_5X5(player,dataPemain.namePlayer);
				
				player1_move();
				computer_move_1_5X5();

				done = check_5X5();
			}while(done==' ');			
			
			if(done=='X'){
				disp_matrix_5X5(player,dataPemain.namePlayer);
				printf("\n  %s wins",dataPemain.namePlayer);
				saveHighscore();
			}
			else if(done=='O'){
				disp_matrix_5X5(player,dataPemain.namePlayer);
				printf("\n  Computer wins");
			}
			else if(done=='D'){
				disp_matrix_3X3(player,dataPemain.namePlayer);
				printf("\n  Draw");
			}
		}
		
	// Player1 vs Computer in 5X5 Normal Level
		else if((dataPemain.grid==5) && (against==1) && (dataPemain.levelComputer==2)){
			system("cls");
			
			do{
				disp_matrix_5X5(player,dataPemain.namePlayer);
				
				player1_move();
				computer_move_2_5X5();

				done = check_5X5();
			}while(done==' ');			
			
			if(done=='X'){
				disp_matrix_5X5(player,dataPemain.namePlayer);
				printf("\n  %s wins",dataPemain.namePlayer);
				saveHighscore();
			}
			else if(done=='O'){
				disp_matrix_5X5(player,dataPemain.namePlayer);
				printf("\n  Computer wins");
			}
			else if(done=='D'){
				disp_matrix_3X3(player,dataPemain.namePlayer);
				printf("\n  Draw");
			}
		}
		
	// Player1 vs Computer in 5X5 Hard Level
		else if((dataPemain.grid==5) && (against==1) && (dataPemain.levelComputer==3)){
			system("cls");
			
			do{
				disp_matrix_5X5(player,dataPemain.namePlayer);
				
				player1_move();
				computer_move_3_5X5();

				done = check_5X5();
			}while(done==' ');			
			
			if(done=='X'){
				disp_matrix_5X5(player,dataPemain.namePlayer);
				printf("\n  %s wins",dataPemain.namePlayer);
				saveHighscore();
			}
			else if(done=='O'){
				disp_matrix_5X5(player,dataPemain.namePlayer);
				printf("\n  Computer wins");
			}
			else if(done=='D'){
				disp_matrix_3X3(player,dataPemain.namePlayer);
				printf("\n  Draw");
			}
		}
		
	// Player1 vs Computer in 7X7 Easly Level
		else if((dataPemain.grid==7) && (against==1) && (dataPemain.levelComputer==1)){
			system("cls");
			
			do{
				disp_matrix_7X7(player,dataPemain.namePlayer);
				
				player1_move();
				computer_move_1_7X7();

				done = check_7X7();
			}while(done==' ');			
			
			if(done=='X'){
				disp_matrix_7X7(player,dataPemain.namePlayer);
				printf("\n  %s wins",dataPemain.namePlayer);
				saveHighscore();
			}
			else if(done=='O'){
				disp_matrix_7X7(player,dataPemain.namePlayer);
				printf("\n  Computer wins");
			}
			else if(done=='D'){
				disp_matrix_7X7(player,dataPemain.namePlayer);
				printf("\n  Draw");
			}
		}
		
	// Player1 vs Computer in 7X7 Normal Level
		else if((dataPemain.grid==7) && (against==1) && (dataPemain.levelComputer==2)){
			system("cls");
			
			do{
				disp_matrix_7X7(player,dataPemain.namePlayer);
				
				player1_move();
				computer_move_2_7X7();

				done = check_7X7();
			}while(done==' ');			
			
			if(done=='X'){
				disp_matrix_7X7(player,dataPemain.namePlayer);
				printf("\n  %s wins",dataPemain.namePlayer);
				saveHighscore();
			}
			else if(done=='O'){
				disp_matrix_7X7(player,dataPemain.namePlayer);
				printf("\n  Computer wins");
			}
			else if(done=='D'){
				disp_matrix_7X7(player,dataPemain.namePlayer);
				printf("\n  Draw");
			}
		}
		
	// Player1 vs Computer in 7X7 Hard Level
		else if((dataPemain.grid==7) && (against==1) && (dataPemain.levelComputer==3)){
			system("cls");
			
			do{
				disp_matrix_7X7(player,dataPemain.namePlayer);
				
				player1_move();
				computer_move_3_7X7();

				done = check_7X7();
			}while(done==' ');			
			
			if(done=='X'){
				disp_matrix_7X7(player,dataPemain.namePlayer);
				printf("\n  %s wins",dataPemain.namePlayer);
				saveHighscore();
			}
			else if(done=='O'){
				disp_matrix_7X7(player,dataPemain.namePlayer);
				printf("\n  Computer wins");
			}
			else if(done=='D'){
				disp_matrix_7X7(player,dataPemain.namePlayer);
				printf("\n  Draw");
			}
		}
	printf("\n\n\n  Press F1 on your keyboard to main menu");
}

/*******************************************************************
PROCEDURE TO SUMMARIZE HELP IN MAIN MENU
 ********************************************************************/
 
void menuHelp(){
	do{
		system("cls");
		printf("\n\n    ================================\n");
		printf("\n\t   Help Tic Tac Toe \n\n");
		printf("    ================================\n\n");
		printf("\t    [1] Indonesian\n\t    [2] English\n\n");
		printf("             Choose one : ");
		scanf("%d",&chooseLanguage);
		help(chooseLanguage);
		if((chooseLanguage < 1) || (chooseLanguage > 2)){
			system("cls");
		}
	}while(chooseLanguage != 1 && chooseLanguage != 2);	
	printf("\n\n\n  Press HOME on your keyboard to main menu");
}

/*******************************************************************
PROCEDURE TO SUMMARIZE COLOR IN MAIN MENU
 ********************************************************************/
 
void menuColor(){
	chooseColorTheme();
	scanf("%s",&kodeWarna);
	showColorTheme(kodeWarna);
	printf("\n\n\n  Press ESCAPE on your keyboard to main menu");
}

/*******************************************************************
PROCEDURE TO SUMMARIZE CREDIT IN MAIN MENU
 ********************************************************************/
 
void menuCredit(){
	credit();
	printf("\n\n\n  Press TAB on your keyboard to main menu");
}

/*******************************************************************
PROCEDURE TO SUMMARIZE HIGHSCORE IN MAIN MENU
 ********************************************************************/
 
void menuHighscore(){
	system("cls");
	readHighscore();
	printf("\n\n\n  Press ENTER on your keyboard to main menu");
}

/*******************************************************************
PROCEDURE TO SUMMARIZE EXIT IN MAIN MENU
 ********************************************************************/
 
void menuExit(){
	system("cls");
	printf("\n  Press BACKSPACE on your keyboard to main menu\n");
}

/*******************************************************************
PROCEDURE TO MAKE A MAIN MENU 
 ********************************************************************/
 
void mainMenu(){
		system("cls");
		printf("\n\n\t================================\n");
		printf("\n\t\t  MAIN MENU\n\n");
		printf(" \t================================\n\n");
		printf("                 [1] Start     \n");
		printf("                 [2] Help     \n");
		printf("                 [3] Color Theme     \n");
		printf("                 [4] Credit     \n");
		printf("                 [5] Highscore     \n");
		printf("                 [6] Exit     \n\n");
		printf("                Choose one : ");
}
 
/*******************************************************************
PROCEDURE TO MAKE A HELP #2
 ********************************************************************/
 
void help(int chooseLanguage){
	if(chooseLanguage==1){
		system("cls");
		char temp[255];
		FILE*pFile;
		
		if((pFile = fopen("Help in Indonesian.txt","r")) == NULL)
			printf("\n\n   Error! File Tidak Ada..");
			
		while(fgets(temp,sizeof(temp),pFile))
			printf("%s",temp);
	
		fclose(pFile);
	}
	else if(chooseLanguage==2){
		system("cls");
		char temp[255];
		FILE*pFile;
		
		if((pFile = fopen("Help in English.txt","r")) == NULL)
			printf("\n\n   Error! File Tidak Ada..");
		
		while(fgets(temp,sizeof(temp),pFile))
			printf("%s",temp);
			
		fclose(pFile);
	}
}

/*******************************************************************
PROCEDURE TO SHOW A COLORTHEME #3
 ********************************************************************/
 
void showColorTheme(char kodeWarna[]){
	//Black
 		if(kodeWarna[0] == '0' && kodeWarna[1] == 'A') system("color 0A");
 		if(kodeWarna[0] == '0' && kodeWarna[1] == 'B') system("color 0B");
 		if(kodeWarna[0] == '0' && kodeWarna[1] == 'C') system("color 0C");
 		if(kodeWarna[0] == '0' && kodeWarna[1] == 'D') system("color 0D");
 		if(kodeWarna[0] == '0' && kodeWarna[1] == 'E') system("color 0E");
 		if(kodeWarna[0] == '0' && kodeWarna[1] == 'F') system("color 0F");
 	//Blue
 		if(kodeWarna[0] == '1' && kodeWarna[1] == 'A') system("color 1A");
 		if(kodeWarna[0] == '1' && kodeWarna[1] == 'B') system("color 1B");
 		if(kodeWarna[0] == '1' && kodeWarna[1] == 'C') system("color 1C");
 		if(kodeWarna[0] == '1' && kodeWarna[1] == 'D') system("color 1D");
 		if(kodeWarna[0] == '1' && kodeWarna[1] == 'E') system("color 1E");
 		if(kodeWarna[0] == '1' && kodeWarna[1] == 'F') system("color 1F");
 	//Green
 		if(kodeWarna[0] == '2' && kodeWarna[1] == 'A') system("color 2A");
 		if(kodeWarna[0] == '2' && kodeWarna[1] == 'B') system("color 2B");
 		if(kodeWarna[0] == '2' && kodeWarna[1] == 'C') system("color 2C");
 		if(kodeWarna[0] == '2' && kodeWarna[1] == 'D') system("color 2D");
 		if(kodeWarna[0] == '2' && kodeWarna[1] == 'E') system("color 2E");
 		if(kodeWarna[0] == '2' && kodeWarna[1] == 'F') system("color 2F");
	//Aqua
		if(kodeWarna[0] == '3' && kodeWarna[1] == 'A') system("color 3A");
 		if(kodeWarna[0] == '3' && kodeWarna[1] == 'B') system("color 3B");
 		if(kodeWarna[0] == '3' && kodeWarna[1] == 'C') system("color 3C");
 		if(kodeWarna[0] == '3' && kodeWarna[1] == 'D') system("color 3D");
 		if(kodeWarna[0] == '3' && kodeWarna[1] == 'E') system("color 3E");
 		if(kodeWarna[0] == '3' && kodeWarna[1] == 'F') system("color 3F");
	//Red
		if(kodeWarna[0] == '4' && kodeWarna[1] == 'A') system("color 4A");
 		if(kodeWarna[0] == '4' && kodeWarna[1] == 'B') system("color 4B");
 		if(kodeWarna[0] == '4' && kodeWarna[1] == 'C') system("color 4C");
 		if(kodeWarna[0] == '4' && kodeWarna[1] == 'D') system("color 4D");
 		if(kodeWarna[0] == '4' && kodeWarna[1] == 'E') system("color 4E");
 		if(kodeWarna[0] == '4' && kodeWarna[1] == 'F') system("color 4F");
	//Purple
		if(kodeWarna[0] == '5' && kodeWarna[1] == 'A') system("color 5A");
 		if(kodeWarna[0] == '5' && kodeWarna[1] == 'B') system("color 5B");
 		if(kodeWarna[0] == '5' && kodeWarna[1] == 'C') system("color 5C");
 		if(kodeWarna[0] == '5' && kodeWarna[1] == 'D') system("color 5D");
 		if(kodeWarna[0] == '5' && kodeWarna[1] == 'E') system("color 5E");
 		if(kodeWarna[0] == '5' && kodeWarna[1] == 'F') system("color 5F");
	//Yellow
		if(kodeWarna[0] == '6' && kodeWarna[1] == 'A') system("color 6A");
 		if(kodeWarna[0] == '6' && kodeWarna[1] == 'B') system("color 6B");
 		if(kodeWarna[0] == '6' && kodeWarna[1] == 'C') system("color 6C");
 		if(kodeWarna[0] == '6' && kodeWarna[1] == 'D') system("color 6D");
 		if(kodeWarna[0] == '6' && kodeWarna[1] == 'E') system("color 6E");
 		if(kodeWarna[0] == '6' && kodeWarna[1] == 'F') system("color 6F");
	//White
		if(kodeWarna[0] == '7' && kodeWarna[1] == 'A') system("color 7A");
 		if(kodeWarna[0] == '7' && kodeWarna[1] == 'B') system("color 7B");
 		if(kodeWarna[0] == '7' && kodeWarna[1] == 'C') system("color 7C");
 		if(kodeWarna[0] == '7' && kodeWarna[1] == 'D') system("color 7D");
 		if(kodeWarna[0] == '7' && kodeWarna[1] == 'E') system("color 7E");
 		if(kodeWarna[0] == '7' && kodeWarna[1] == 'F') system("color 7F");
	//Gray
		if(kodeWarna[0] == '8' && kodeWarna[1] == 'A') system("color 8A");
 		if(kodeWarna[0] == '8' && kodeWarna[1] == 'B') system("color 8B");
 		if(kodeWarna[0] == '8' && kodeWarna[1] == 'C') system("color 8C");
 		if(kodeWarna[0] == '8' && kodeWarna[1] == 'D') system("color 8D");
 		if(kodeWarna[0] == '8' && kodeWarna[1] == 'E') system("color 8E");
 		if(kodeWarna[0] == '8' && kodeWarna[1] == 'F') system("color 8F");
	//Light Blue
		if(kodeWarna[0] == '9' && kodeWarna[1] == 'A') system("color 9A");
 		if(kodeWarna[0] == '9' && kodeWarna[1] == 'B') system("color 9B");
 		if(kodeWarna[0] == '9' && kodeWarna[1] == 'C') system("color 9C");
 		if(kodeWarna[0] == '9' && kodeWarna[1] == 'D') system("color 9D");
 		if(kodeWarna[0] == '9' && kodeWarna[1] == 'E') system("color 9E");
 		if(kodeWarna[0] == '9' && kodeWarna[1] == 'F') system("color 9F");
 }
 
/*******************************************************************
PROCEDURE TO CHOOSE A COLORTHEME #3
 ********************************************************************/
 
void chooseColorTheme(){
	system("cls");
	char temp[255];
	FILE*pFile;
		
	pFile = fopen("ColorTheme.txt","r");
	while(fgets(temp,sizeof(temp),pFile))
		printf("%s",temp);
	fclose(pFile);
}

/*******************************************************************
PROCEDURE TO SHOW CREDITS #4
********************************************************************/

void credit(){
		system("cls");
		char temp[255];
		FILE*pFile;
		
		pFile = fopen("Credit.txt","r");
		while(fgets(temp,sizeof(temp),pFile))
			printf("%s",temp);
		fclose(pFile);
}

/*******************************************************************
FUNCTION TO SAVE HIGHSCORE #5  Credit : Rangga Yudha Yudistira
********************************************************************/

struct highscore{
		int grid;
		char namePlayer[255];
		int levelComputer;
		char time[100];
}Record;

int saveHighscore(){
    FILE* pFile = 0;
    struct highscore Record;
    time_t _time;
    
    time (&_time);
    struct tm *tmi;
	tmi = localtime (&_time);
    strftime (Record.time,100,"%d %b %Y %H:%M",tmi);
        
    Record.grid = dataPemain.grid;
    Record.levelComputer = dataPemain.levelComputer;
    strcpy(Record.namePlayer, dataPemain.namePlayer);

    fopen_s(&pFile,"Highscore.dat","ab+"); // append and update binary, can be read
    if(!pFile)
    return 1; //fopen error

    fwrite(&Record,sizeof(Record),1,pFile);
    fclose(pFile);
        
    return 0;
}
/*******************************************************************
PROCEDURE TO READ HIGHSCORE #5 Credit : Rangga Yudha Yudistira
********************************************************************/

int readHighscore(){  //
	FILE* pFile = 0;
        int i = 1;
        pFile = fopen("Highscore.dat","ab+"); // append and update binary, can be read
        if(!pFile)
            return 1; //fopen error
        printf("\n\n\t===============================================\n");
		printf("\n\t\t       Riwayat Permainan\n\n");
		printf(" \t===============================================\n\n");
        printf( "  \xDA\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF\n" );
        printf( "  \xB3%-2s\xB3%-20s\xB3%-5s\xB3%-15s\xB3%-15s\xB3\n", "No", "Time", "Size", "Difficulty", "Winner" );
        printf( "  \xC3\xC4\xC4\xC5\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xB4\n" );
		do{
            fseek(pFile,(-i)*sizeof(Record),SEEK_END);
            fread(&Record,sizeof(Record),1,pFile);
            if(!feof(pFile) && i <= 18){
                strncpy(Record.namePlayer, Record.namePlayer, 15);
                printf("  \xB3%-2d\xB3%-20s\xB3%-5d\xB3%-15d\xB3%-15s\xB3\n", i++, Record.time, Record.grid, Record.levelComputer, Record.namePlayer);
            }
        }while(!feof(pFile) && i <= 18);
        printf( "  \xC0\xC4\xC4\xC1\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9" );
        
        fclose(pFile);

        return 0;
}

/*******************************************************************
PROCEDURE TO SHOW INTRODUCTION GAME
 ********************************************************************/
 
 void introduction(){
 		printf("\n\t\t*** TIC TAC TOE GAME ***\n\n\n");
    	printf("  ## Halo! Selamat datang di game ini\n");
    	printf("  ## Berikut ada beberapa hal yang harus anda penuhi\n\n");
 }

/*******************************************************************
PROCEDURE FOR INITIALIZATION
 ********************************************************************/
 
 void init_matrix(int n){
 	int i,j;
 	for(i=0;i<n;i++){
 		for(j=0;j<n;j++){
 			matrix[i][j]=' ';
		 }
	 }
 }
/*******************************************************************
PROCEDURE FOR PLAYER1 MOVE
 ********************************************************************/
 
void player1_move (){
	int x,y;
	int waktuAwal=clock();
	int sec = 10;
	
	printf("\n  Enter x and y co-ordinates of your move: ");
	scanf("%d %d",&x,&y);															//Input player 1 dengan koordinat x dan y

	int waktuAkhir=clock();
	
	if(waktuAkhir-waktuAwal>=10000){
		return;
	}
	
	if(matrix[--x][--y]!=' '){
		printf("  Invalid Move, try again \n");
		player1_move();
	}
	else {
		matrix[x][y]='X';
	}
}

/*******************************************************************
PROCEDURE FOR PLAYER2 MOVE
 ********************************************************************/
 
 void player2_move(){
 	int x,y;
 	int waktuAwal=clock();
 	 
 	printf("\n  Enter x and y co-ordinates of your move: ");
 	scanf("%d %d",&x,&y);																//Input player 2 dengan koordinat x dan y
 	int waktuAkhir=clock();
 	
 	if(waktuAkhir-waktuAwal>=10000){
		return;
	}
	
 	if(matrix[--x][--y]!=' '){
 		printf("  Invalid Move, try again \n");
 		player2_move();
	 }
	 else {
	 	matrix[x][y]='O';
	 }
 }
 
/*******************************************************************
PROCEDURE TO DISPLAY MATRIS 3X3
 ********************************************************************/
 
void disp_matrix_3X3 (int player, char namePlayer[]){
	system("cls");
	printf("\n  Player1(X)\n");
	printf("  Player2/Computer(O)\n\n");
	printf("  %s as player %d",namePlayer,player);
    printf("\n  Player%d's turn \n\n",player);
	
	int i;
	
	printf("      1   2   3\n");
	printf("    \xDA\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xBF\n");
	printf("  1 \xB3 %c \xB3 %c \xB3 %c \xB3\n",matrix[0][0],matrix[0][1],matrix[0][2]);
	printf("    \xC3\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xB4\n");
	printf("  2 \xB3 %c \xB3 %c \xB3 %c \xB3\n",matrix[1][0],matrix[1][1],matrix[1][2]);
	printf("    \xC3\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xB4\n");
	printf("  3 \xB3 %c \xB3 %c \xB3 %c \xB3\n",matrix[2][0],matrix[2][1],matrix[2][2]);
	printf("    \xC0\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xD9\n");
}

/*******************************************************************
PROCEDURE FOR COMPUTER MOVE 3X3 WITH 'O' EASY LEVEL
 ********************************************************************/

void computer_move_1_3X3(){
	int i,j;
	
    //row checking jika 2 berturut-turut
		
		// Jika isi dari array index ke-1 dan ke-2 adalah 'O' atau 'X', maka array index ke-3 isi 'O'
	for(i=0;i<3;i++){
		if((matrix[i][0]=='O'&& matrix[i][1]=='O')||(matrix[i][0]=='X'&& matrix[i][1]=='X')){									
			if(matrix[i][2]==' '){
				matrix[i][2]='O';
				return;
			}
		}
	}

		// Jika isi dari array index ke-1 dan ke-3 adalah 'O' atau 'X', maka array index ke-2 isi 'O'
	for(i=0;i<3;i++){
		if((matrix[i][0]=='O'&& matrix[i][2]=='O')||(matrix[i][0]=='X'&& matrix[i][2]=='X')){									
			if(matrix[i][1]==' '){
				matrix[i][1]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-2 dan ke-3 adalah 'O' atau 'X', maka array index ke-1 isi 'O'
	for(i=0;i<3;i++){
		if((matrix[i][1]=='O'&& matrix[i][2]=='O')||(matrix[i][1]=='X'&& matrix[i][2]=='X')){									
			if(matrix[i][0]==' '){
				matrix[i][0]='O';
				return;
			}
		}
	}

	//column checking jika 2 berturut-turut

		// Jika isi dari array index ke-1 dan ke-2 adalah 'O' atau 'X', maka array index ke-3 isi 'O'
	for(i=0;i<3;i++){
		if((matrix[0][i]=='O'&& matrix[1][i]=='O')||(matrix[0][i]=='X'&& matrix[1][i]=='X')){									
			if(matrix[2][i]==' '){
				matrix[2][i]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-1 dan ke-3 adalah 'O' atau 'X', maka array index ke-2 isi 'O'
	for(i=0;i<3;i++){
		if((matrix[0][i]=='O'&& matrix[2][i]=='O')||(matrix[0][i]=='X'&& matrix[2][i]=='X')){								
			if(matrix[1][i]==' '){
				matrix[1][i]='O';
				return;
			}
		}
	}

		// Jika isi dari array index ke-2 dan ke-3 adalah 'O' atau 'X', maka array index ke-1 isi 'O'
	for(i=0;i<3;i++){
		if((matrix[2][i]=='O'&& matrix[1][i]=='O')||(matrix[2][i]=='X'&& matrix[1][i]=='X')){									
			if(matrix[0][i]==' '){
				matrix[0][i]='O';
				return;
			}
		}
	}

	//diagonal checking jika 2 berturut-turut
	
		// Kiri ke Kanan
		// warna orange sesuai dengan tracing
	if((matrix[0][0]=='O'&&matrix[1][1]=='O')||(matrix[0][0]=='X'&&matrix[1][1]=='X')){										
		if(matrix[2][2]==' '){
				matrix[2][2]='O';
				return;
		}
	}

	if((matrix[0][0]=='O'&&matrix[2][2]=='O')||(matrix[0][0]=='X'&&matrix[2][2]=='X')){
		if(matrix[1][1]==' '){
				matrix[1][1]='O';
				return;
			}
	}

	if((matrix[1][1]=='O'&&matrix[2][2]=='O')||(matrix[1][1]=='X'&&matrix[2][2]=='X')){										
		if(matrix[0][0]==' '){
				matrix[0][0]='O';
				return;
			}
	}
	
		// Kanan ke Kiri
		// warna hijau sesuai dengan tracing
	if((matrix[0][2]=='O'&&matrix[1][1]=='O')||(matrix[0][2]=='X'&&matrix[1][1]=='X')){					
		if(matrix[2][0]==' '){
				matrix[2][0]='O';
				return;
			}
	}
	
	if((matrix[0][2]=='O'&&matrix[2][0]=='O')||(matrix[0][2]=='X'&&matrix[2][0]=='X')){										
		if(matrix[1][1]==' '){
				matrix[1][1]='O';
				return;
			}
	}

	if((matrix[1][1]=='O'&&matrix[2][0]=='O')||(matrix[1][1]=='X'&&matrix[2][0]=='X')){										
		if(matrix[0][2]==' '){
				matrix[0][2]='O';
				return;
			}
	}

		// Finalisasi dengan mengisi sekitar 'X'
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(matrix[i][j]=='X'){
				if(matrix[i][--j]==' '){
					matrix[i][j]='O';
					return;
				}
				else if(matrix[i][++j]==' '){
					matrix[i][j]='O';
					return;
				}
				else if(matrix[++i][j]==' '){
					matrix[i][j]='O';
					return;
				}
				else if(matrix[--i][j]==' '){
					matrix[i][j]='O';
					return;
				}
			}
		}
	}
	
		// Finalisasi dengan mengisi yang masih kosong	
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(matrix[i][j] = ' '){
				matrix[i][j]='O';
				return;
			}
		}
	}
}

/*******************************************************************
PROCEDURE FOR COMPUTER MOVE 3X3 WITH 'O' NORMAL LEVEL
 ********************************************************************/

void computer_move_2_3X3(){
	int i,j;
	
    //row checking jika 2 berturut-turut
		
		// Jika isi dari array index ke-1 dan ke-2 adalah 'O' atau 'X', maka array index ke-3 isi 'O'
	for(i=0;i<3;i++){
		if((matrix[i][0]=='O'&& matrix[i][1]=='O')||(matrix[i][0]=='X'&& matrix[i][1]=='X')){									
			if(matrix[i][2]==' '){
				matrix[i][2]='O';
				return;
			}
		}
	}

		// Jika isi dari array index ke-1 dan ke-3 adalah 'O' atau 'X', maka array index ke-2 isi 'O'
	for(i=0;i<3;i++){
		if((matrix[i][0]=='O'&& matrix[i][2]=='O')||(matrix[i][0]=='X'&& matrix[i][2]=='X')){									
			if(matrix[i][1]==' '){
				matrix[i][1]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-2 dan ke-3 adalah 'O' atau 'X', maka array index ke-1 isi 'O'
	for(i=0;i<3;i++){
		if((matrix[i][1]=='O'&& matrix[i][2]=='O')||(matrix[i][1]=='X'&& matrix[i][2]=='X')){									
			if(matrix[i][0]==' '){
				matrix[i][0]='O';
				return;
			}
		}
	}

	//column checking jika 2 berturut-turut

		// Jika isi dari array index ke-1 dan ke-2 adalah 'O' atau 'X', maka array index ke-3 isi 'O'
	for(i=0;i<3;i++){
		if((matrix[0][i]=='O'&& matrix[1][i]=='O')||(matrix[0][i]=='X'&& matrix[1][i]=='X')){									
			if(matrix[2][i]==' '){
				matrix[2][i]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-1 dan ke-3 adalah 'O' atau 'X', maka array index ke-2 isi 'O'
	for(i=0;i<3;i++){
		if((matrix[0][i]=='O'&& matrix[2][i]=='O')||(matrix[0][i]=='X'&& matrix[2][i]=='X')){								
			if(matrix[1][i]==' '){
				matrix[1][i]='O';
				return;
			}
		}
	}

		// Jika isi dari array index ke-2 dan ke-3 adalah 'O' atau 'X', maka array index ke-1 isi 'O'
	for(i=0;i<3;i++){
		if((matrix[2][i]=='O'&& matrix[1][i]=='O')||(matrix[2][i]=='X'&& matrix[1][i]=='X')){									
			if(matrix[0][i]==' '){
				matrix[0][i]='O';
				return;
			}
		}
	}

	//diagonal checking jika 2 berturut-turut
	
		// Kiri ke Kanan
		// warna orange sesuai dengan tracing
	if((matrix[0][0]=='O'&&matrix[1][1]=='O')||(matrix[0][0]=='X'&&matrix[1][1]=='X')){										
		if(matrix[2][2]==' '){
				matrix[2][2]='O';
				return;
		}
	}

	if((matrix[0][0]=='O'&&matrix[2][2]=='O')||(matrix[0][0]=='X'&&matrix[2][2]=='X')){
		if(matrix[1][1]==' '){
				matrix[1][1]='O';
				return;
			}
	}

	if((matrix[1][1]=='O'&&matrix[2][2]=='O')||(matrix[1][1]=='X'&&matrix[2][2]=='X')){										
		if(matrix[0][0]==' '){
				matrix[0][0]='O';
				return;
			}
	}
	
		// Kanan ke Kiri
		// warna hijau sesuai dengan tracing
	if((matrix[0][2]=='O'&&matrix[1][1]=='O')||(matrix[0][2]=='X'&&matrix[1][1]=='X')){					
		if(matrix[2][0]==' '){
				matrix[2][0]='O';
				return;
			}
	}
	
	if((matrix[0][2]=='O'&&matrix[2][0]=='O')||(matrix[0][2]=='X'&&matrix[2][0]=='X')){										
		if(matrix[1][1]==' '){
				matrix[1][1]='O';
				return;
			}
	}

	if((matrix[1][1]=='O'&&matrix[2][0]=='O')||(matrix[1][1]=='X'&&matrix[2][0]=='X')){										
		if(matrix[0][2]==' '){
				matrix[0][2]='O';
				return;
			}
	}

	// teknik blocking untuk pergerakan ke-1

		// Jika tengah (1,1) kosong, maka isi tengah (1,1)
	if(matrix[1][1]==' '){
		matrix[1][1]='O';	
		return;														
	}
		
		// Jika tengah sudah terisi dengan tanda 'O', maka
	if (matrix [1][1] == 'O') {
		if (matrix [0][0] == 'X') {  // Jika ujung kiri atas diisi, maka isi ujung kanan bawah
			if (matrix [2][2] == ' ') {
				matrix [2][2] = 'O';
				return;
			}
		}
		if (matrix [2][2] == 'X') {  // Jika ujung kanan bawah diisi maka isi ujung kiri atas
			if (matrix [0][0] == ' '){
				matrix [0][0] = 'O';
				return;
			}	
		}
		if (matrix [0][2] == 'X') {  // Jika ujung kanan atas diisi maka isi ujung kiri bawah
			if (matrix [2][0] == ' ') {
				matrix [2][0] = 'O';
				return;
			}
		}
		if (matrix [2][0] == 'X') {  // Jika ujung kiri bawah diisi maka isi ujung kanan atas
			if (matrix [0][2] == ' ') {
				matrix [0][2] = 'O';
				return;
			}	
		}
	}
	
		// Jika tengah sudah terisi dengan tanda 'X'
	if(matrix[1][1] == 'X'){
		if(matrix[0][0] == ' '){
			matrix[0][0] ='O';
			return;
		}
	}

		// Finalisasi dengan mengisi di sekitar 'X'
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(matrix[i][j]=='X'){
				if(matrix[i][--j]==' '){
					matrix[i][j]='O';
					return;
				}
				else if(matrix[i][++j]==' '){
					matrix[i][j]='O';
					return;
				}
				else if(matrix[++i][j]==' '){
					matrix[i][j]='O';
					return;
				}
				else if(matrix[--i][j]==' '){
					matrix[i][j]='O';
					return;
				}
			}
		}
	}
	
		// Finalisasi dengan mengisi yang masih kosong	
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(matrix[i][j] = ' '){
				matrix[i][j]='O';
				return;
			}
		}
	}	
}

/*******************************************************************
PROCEDURE FOR COMPUTER MOVE 3X3 WITH 'O' HARD LEVEL
 ********************************************************************/
 
 void computer_move_3_3X3(){
	int i,j;
	
    //row checking jika 2 berturut-turut
		
		// Jika isi dari array index ke-1 dan ke-2 adalah 'O' atau 'X', maka array index ke-3 isi 'O'
	for(i=0;i<3;i++){
		if((matrix[i][0]=='O'&& matrix[i][1]=='O')||(matrix[i][0]=='X'&& matrix[i][1]=='X')){									
			if(matrix[i][2]==' '){
				matrix[i][2]='O';
				return;
			}
		}
	}

		// Jika isi dari array index ke-1 dan ke-3 adalah 'O' atau 'X', maka array index ke-2 isi 'O'
	for(i=0;i<3;i++){
		if((matrix[i][0]=='O'&& matrix[i][2]=='O')||(matrix[i][0]=='X'&& matrix[i][2]=='X')){									
			if(matrix[i][1]==' '){
				matrix[i][1]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-2 dan ke-3 adalah 'O' atau 'X', maka array index ke-1 isi 'O'
	for(i=0;i<3;i++){
		if((matrix[i][1]=='O'&& matrix[i][2]=='O')||(matrix[i][1]=='X'&& matrix[i][2]=='X')){									
			if(matrix[i][0]==' '){
				matrix[i][0]='O';
				return;
			}
		}
	}

	//column checking jika 2 berturut-turut

		// Jika isi dari array index ke-1 dan ke-2 adalah 'O' atau 'X', maka array index ke-3 isi 'O'
	for(i=0;i<3;i++){
		if((matrix[0][i]=='O'&& matrix[1][i]=='O')||(matrix[0][i]=='X'&& matrix[1][i]=='X')){									
			if(matrix[2][i]==' '){
				matrix[2][i]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-1 dan ke-3 adalah 'O' atau 'X', maka array index ke-2 isi 'O'
	for(i=0;i<3;i++){
		if((matrix[0][i]=='O'&& matrix[2][i]=='O')||(matrix[0][i]=='X'&& matrix[2][i]=='X')){								
			if(matrix[1][i]==' '){
				matrix[1][i]='O';
				return;
			}
		}
	}

		// Jika isi dari array index ke-2 dan ke-3 adalah 'O' atau 'X', maka array index ke-1 isi 'O'
	for(i=0;i<3;i++){
		if((matrix[2][i]=='O'&& matrix[1][i]=='O')||(matrix[2][i]=='X'&& matrix[1][i]=='X')){									
			if(matrix[0][i]==' '){
				matrix[0][i]='O';
				return;
			}
		}
	}

	//diagonal checking jika 2 berturut-turut
	
		// Kiri ke Kanan
		// warna orange sesuai dengan tracing
	if((matrix[0][0]=='O'&&matrix[1][1]=='O')||(matrix[0][0]=='X'&&matrix[1][1]=='X')){										
		if(matrix[2][2]==' '){
				matrix[2][2]='O';
				return;
		}
	}

	if((matrix[0][0]=='O'&&matrix[2][2]=='O')||(matrix[0][0]=='X'&&matrix[2][2]=='X')){
		if(matrix[1][1]==' '){
				matrix[1][1]='O';
				return;
			}
	}

	if((matrix[1][1]=='O'&&matrix[2][2]=='O')||(matrix[1][1]=='X'&&matrix[2][2]=='X')){										
		if(matrix[0][0]==' '){
				matrix[0][0]='O';
				return;
			}
	}
	
		// Kanan ke Kiri
		// warna hijau sesuai dengan tracing
	if((matrix[0][2]=='O'&&matrix[1][1]=='O')||(matrix[0][2]=='X'&&matrix[1][1]=='X')){					
		if(matrix[2][0]==' '){
				matrix[2][0]='O';
				return;
			}
	}
	
	if((matrix[0][2]=='O'&&matrix[2][0]=='O')||(matrix[0][2]=='X'&&matrix[2][0]=='X')){										
		if(matrix[1][1]==' '){
				matrix[1][1]='O';
				return;
			}
	}

	if((matrix[1][1]=='O'&&matrix[2][0]=='O')||(matrix[1][1]=='X'&&matrix[2][0]=='X')){										
		if(matrix[0][2]==' '){
				matrix[0][2]='O';
				return;
			}
	}

	// teknik blocking untuk pergerakan ke-1

		// Jika tengah (1,1) kosong, maka isi tengah (1,1)
	if(matrix[1][1]==' '){
		matrix[1][1]='O';	
		return;														
	}
		
		// Jika tengah sudah terisi dengan tanda 'O', maka
	if (matrix [1][1] == 'O') {
		if (matrix [0][0] == 'X') {  // Jika ujung kiri atas diisi, maka isi ujung kanan bawah
			if (matrix [2][2] == ' ') {
				matrix [2][2] = 'O';
				return;
			}
		}
		if (matrix [2][2] == 'X') {  // Jika ujung kanan bawah diisi maka isi ujung kiri atas
			if (matrix [0][0] == ' '){
				matrix [0][0] = 'O';
				return;
			}	
		}
		if (matrix [0][2] == 'X') {  // Jika ujung kanan atas diisi maka isi ujung kiri bawah
			if (matrix [2][0] == ' ') {
				matrix [2][0] = 'O';
				return;
			}
		}
		if (matrix [2][0] == 'X') {  // Jika ujung kiri bawah diisi maka isi ujung kanan atas
			if (matrix [0][2] == ' ') {
				matrix [0][2] = 'O';
				return;
			}	
		}
	}
	
		// Jika tengah sudah terisi dengan tanda 'X'
	if(matrix[1][1] == 'X'){
		if(matrix[0][0] == ' '){
			matrix[0][0] ='O';
			return;
		}
	}

	// teknik blocking untuk pergerakan ke-2
	
		// Draw 1 (dalam kondisi tengah sudah terisi dengan tanda 'O')
	if((matrix[0][0] == 'X' && matrix[2][2] == 'X') || (matrix[0][2] == 'X' && matrix[2][0] == 'X')){
		if(matrix[0][1] == ' '){
			matrix[0][1] = 'O';
			return;
		}
	}
		// Draw 2 
	if(matrix[1][1] == 'X' && matrix[2][2] == 'X'){
		if(matrix[0][2] == ' '){
			matrix[0][2] = 'O';
		}
	}
		// Finalisasi dengan mengisi di sekitar 'X'
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(matrix[i][j]=='X'){
				if(matrix[i][--j]==' '){
					matrix[i][j]='O';
					return;
				}
				else if(matrix[i][++j]==' '){
					matrix[i][j]='O';
					return;
				}
				else if(matrix[++i][j]==' '){
					matrix[i][j]='O';
					return;
				}
				else if(matrix[--i][j]==' '){
					matrix[i][j]='O';
					return;
				}
			}
		}
	}
		// Finalisasi dengan mengisi yang masih kosong	
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(matrix[i][j] = ' '){
				matrix[i][j]='O';
				return;
			}
		}
	}
}

/*******************************************************************
FUNCTION TO CHECK WIN 3X3
 ********************************************************************/
 
 char check_3X3(){
	int i,j;
	
	// row checking
	for(i=0;i<3;i++){
		if((matrix[i][0]==matrix[i][1]) && (matrix[i][0]==matrix[i][2])){
			return matrix[i][0];
		}
	}
	
	// column checking
	for(i=0;i<3;i++){
		if((matrix[0][i]==matrix[1][i]) && (matrix[0][i]==matrix[2][i])){
			return matrix[0][i];
		}
	}
	
	// diagonal checking
	if((matrix[0][0]==matrix[1][1]) && (matrix[1][1]==matrix[2][2])){
		return matrix[0][0];
	}
	if((matrix[0][2]==matrix[1][1]) && (matrix[0][2]==matrix[2][0])){
		return matrix[0][2];
	}
	
	// If empty
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(matrix[i][j]==' '){
				return ' ';
			}
		}
	}
	
	// Draw
	return 'D';																						
}

/*******************************************************************
PROCEDURE TO DISPLAY MATRIS 5X5
 ********************************************************************/
 
 void disp_matrix_5X5 (int player, char namePlayer[]){
 	system("cls");
    printf("\n  Player1(X)\n");
	printf("  Player2/Computer(O)\n\n");
	printf("  %s as player %d",namePlayer,player);
    printf("\n  Player%d's turn \n\n",player);
 	
 	int i;
 	
 	printf("  (x,y)  1   2   3   4   5\n");
 	printf("       \xDA\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xBF\n");
	printf("     1 \xB3 %c \xB3 %c \xB3 %c \xB3 %c \xB3 %c \xB3\n",matrix[0][0],matrix[0][1],matrix[0][2],matrix[0][3],matrix[0][4]);
	printf("       \xC3\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xB4\n");
	printf("     2 \xB3 %c \xB3 %c \xB3 %c \xB3 %c \xB3 %c \xB3\n",matrix[1][0],matrix[1][1],matrix[1][2],matrix[1][3],matrix[1][4]);
	printf("       \xC3\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xB4\n");
	printf("     3 \xB3 %c \xB3 %c \xB3 %c \xB3 %c \xB3 %c \xB3\n",matrix[2][0],matrix[2][1],matrix[2][2],matrix[2][3],matrix[2][4]);
	printf("       \xC3\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xB4\n");
	printf("     4 \xB3 %c \xB3 %c \xB3 %c \xB3 %c \xB3 %c \xB3\n",matrix[3][0],matrix[3][1],matrix[3][2],matrix[3][3],matrix[3][4]);
	printf("       \xC3\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xB4\n");
	printf("     5 \xB3 %c \xB3 %c \xB3 %c \xB3 %c \xB3 %c \xB3\n",matrix[4][0],matrix[4][1],matrix[4][2],matrix[4][3],matrix[4][4]);
	printf("       \xC0\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xD9\n");
	
 }

/*******************************************************************
PROCEDURE FOR COMPUTER MOVE 5X5 WITH 'O' EASY LEVEL
 ********************************************************************/
 
 void computer_move_1_5X5(){
	int i,j;
	
		// Finalisasi dengan mengisi random di sekitar 'X' yang sudah ada
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			if(matrix[i][j]=='X'){
				if(matrix[i][--j]==' '){
					matrix[i][j]='O';
					return;
				}
				else if(matrix[i][++j]==' '){
					matrix[i][j]='O';
					return;
				}
				else if(matrix[++i][j]==' '){
					matrix[i][j]='O';
					return;
				}
				else if(matrix[--i][j]==' '){
					matrix[i][j]='O';
					return;
				}
			}
		}
	}
}

 /*******************************************************************
PROCEDURE FOR COMPUTER MOVE 5X5 WITH 'O' NORMAL LEVEL
 ********************************************************************/
 
 void computer_move_2_5X5(){
	int i,j;
	
	//row checking jika 3 berturut-turut

		// Jika isi dari array index ke-1, ke-2 dan ke-3 adalah 'O' atau 'X', maka array index ke-4 atau ke-5 isi 'O'
	for(i=0;i<5;i++){
		if(((matrix[i][0] && matrix[i][1]) && (matrix[i][1] && matrix[i][2]) && matrix[i][0] != ' ')){									
			if(matrix[i][3]==' '){
				matrix[i][3]='O';
				return;
			}
			else if(matrix[i][4]==' '){
				matrix[i][4]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-2, ke-3 dan ke-4 adalah 'O' atau 'X', maka array index ke-1 atau ke-5 isi 'O'
	for(i=0;i<5;i++){
		if(((matrix[i][1] && matrix[i][2]) && (matrix[i][2] && matrix[i][3]) && matrix[i][1] != ' ')){									
			if(matrix[i][0]==' '){
				matrix[i][0]='O';
				return;
			}
			else if(matrix[i][4]==' '){
				matrix[i][4]='O';
				return;
			}
		}
	}
	
			// Jika isi dari array index ke-3, ke-4 dan ke-5 adalah 'O' atau 'X', maka array index ke-2 isi 'O'
	for(i=0;i<5;i++){
		if(((matrix[i][2] && matrix[i][3]) && (matrix[i][3] && matrix[i][4]) && matrix[i][2] != ' ')){									
			if(matrix[i][1]==' '){
				matrix[i][1]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-1, ke-2 dan ke-4 adalah 'O' atau 'X', maka array index ke-3 atau ke-5 isi 'O'
	for(i=0;i<5;i++){
		if(((matrix[i][0] && matrix[i][1]) && (matrix[i][1] && matrix[i][3])) && matrix[i][0] != ' '){									
			if(matrix[i][2]==' '){
				matrix[i][2]='O';
				return;
			}
			else if(matrix[i][4]==' '){
				matrix[i][4]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-2, ke-4 dan ke-5 adalah 'O' atau 'X', maka array index ke-1 atau ke-3 isi 'O'
	for(i=0;i<5;i++){
		if(((matrix[i][1] && matrix[i][3]) && (matrix[i][3] && matrix[i][4])) && matrix[i][1] != ' '){									
			if(matrix[i][2]==' '){
				matrix[i][2]='O';
				return;
			}
			else if(matrix[i][0]==' '){
				matrix[i][0]='O';
				return;
			}
		}
	}

		// Jika isi dari array index ke-1, ke-3 dan ke-4 adalah 'O' atau 'X', maka array index ke-2 atau ke-5 isi 'O'
	for(i=0;i<5;i++){
		if(((matrix[i][0] && matrix[i][2]) && (matrix[i][2] && matrix[i][3])) && matrix[i][0] != ' '){									
			if(matrix[i][1]==' '){
				matrix[i][1]='O';
				return;
			}
			else if(matrix[i][4]==' '){
				matrix[i][4]='O';
				return;
			}
		}
	}

		// Jika isi dari array index ke-1, ke-3 dan ke-5 adalah 'O' atau 'X', maka array index ke-2 atau ke-4 isi 'O'
	for(i=0;i<5;i++){
		if(((matrix[i][0] && matrix[i][2]) && (matrix[i][2] && matrix[i][4])) && matrix[i][0] != ' '){									
			if(matrix[i][1]==' '){
				matrix[i][1]='O';
				return;
			}
			else if(matrix[i][3]==' '){
				matrix[i][3]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-2, ke-3 dan ke-5 adalah 'O' atau 'X', maka array index ke-1 atau ke-4 isi 'O'
	for(i=0;i<5;i++){
		if(((matrix[i][1] && matrix[i][2]) && (matrix[i][2] && matrix[i][4])) && matrix[i][0] != ' '){									
			if(matrix[i][3]==' '){
				matrix[i][3]='O';
				return;
			}
			else if(matrix[i][0]==' '){
				matrix[i][0]='O';
				return;
			}
		}
	}
	
	//column checking jika 3 berturut-turut
	
		// Jika isi dari array index ke-1, ke-2 dan ke-3 adalah 'O' atau 'X', maka array index ke-4 atau ke-5 isi 'O'
	for(i=0;i<5;i++){
		if(((matrix[0][i] && matrix[1][i]) && (matrix[1][i] && matrix[2][i]) && matrix[0][i] != ' ')){									
			if(matrix[3][i]==' '){
				matrix[3][i]='O';
				return;
			}
			else if(matrix[4][i]==' '){
				matrix[4][i]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-2, ke-3 dan ke-4 adalah 'O' atau 'X', maka array index ke-1 atau ke-5 isi 'O'
	for(i=0;i<5;i++){
		if(((matrix[1][i] && matrix[2][i]) && (matrix[2][i] && matrix[3][i]) && matrix[1][i] != ' ')){									
			if(matrix[0][i]==' '){
				matrix[0][i]='O';
				return;
			}
			else if(matrix[4][i]==' '){
				matrix[4][i]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-3, ke-4 dan ke-5 adalah 'O' atau 'X', maka array index ke-1 atau ke-2 isi 'O'
	for(i=0;i<5;i++){
		if(((matrix[2][i] && matrix[3][i]) && (matrix[3][i] && matrix[4][i]) && matrix[2][i] != ' ')){									
			if(matrix[1][i]==' '){
				matrix[1][i]='O';
				return;
			}
			else if(matrix[0][i]==' '){
				matrix[0][i]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-1, ke-3 dan ke-4 adalah 'O' atau 'X', maka array index ke-2 atau ke-5 isi 'O'
	for(i=0;i<5;i++){
		if(((matrix[0][i] && matrix[2][i]) && (matrix[2][i] && matrix[3][i]) && matrix[0][i] != ' ')){									
			if(matrix[1][i]==' '){
				matrix[1][i]='O';
				return;
			}
			else if(matrix[4][i]==' '){
				matrix[4][i]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-1, ke-3 dan ke-5 adalah 'O' atau 'X', maka array index ke-2 atau ke-4 isi 'O'
	for(i=0;i<5;i++){
		if(((matrix[0][i] && matrix[2][i]) && (matrix[2][i] && matrix[4][i]) && matrix[0][i] != ' ')){									
			if(matrix[1][i]==' '){
				matrix[1][i]='O';
				return;
			}
			else if(matrix[3][i]==' '){
				matrix[3][i]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-1, ke-2 dan ke-4 adalah 'O' atau 'X', maka array index ke-3 atau ke-5 isi 'O'
	for(i=0;i<5;i++){
		if(((matrix[0][i] && matrix[1][i]) && (matrix[1][i] && matrix[3][i]) && matrix[0][i] != ' ')){									
			if(matrix[2][i]==' '){
				matrix[2][i]='O';
				return;
			}
			else if(matrix[4][i]==' '){
				matrix[4][i]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-2, ke-4 dan ke-5 adalah 'O' atau 'X', maka array index ke-1 atau ke-3 isi 'O'
	for(i=0;i<5;i++){
		if(((matrix[1][i] && matrix[3][i]) && (matrix[3][i] && matrix[4][i]) && matrix[1][i] != ' ')){									
			if(matrix[2][i]==' '){
				matrix[2][i]='O';
				return;
			}
			else if(matrix[1][i]==' '){
				matrix[1][i]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-2, ke-3 dan ke-5 adalah 'O' atau 'X', maka array index ke-1 atau ke-4 isi 'O'
	for(i=0;i<5;i++){
		if(((matrix[1][i] && matrix[2][i]) && (matrix[2][i] && matrix[4][i]) && matrix[1][i] != ' ')){									
			if(matrix[3][i]==' '){
				matrix[3][i]='O';
				return;
			}
			else if(matrix[1][i]==' '){
				matrix[1][i]='O';
				return;
			}
		}
	}
	
	// Diagonal Checking jika 3 berturut-turut
		// kiri ke kanan
		// warna pink
	if(((matrix[1][0]==matrix[2][1]) && (matrix[2][1]==matrix[3][2])) && matrix[1][0] != ' '){
		if(matrix[4][3]==' '){
			matrix[4][3]='O';
			return;
		}
	}
	
	if(((matrix[2][1]==matrix[3][2]) && (matrix[3][2]==matrix[4][3])) && matrix[2][1] != ' '){
		if(matrix[1][0]==' '){
			matrix[1][0]='O';
			return;
		}
	}
		//---
	if(((matrix[0][1]==matrix[1][2]) && (matrix[1][2]==matrix[2][3])) && matrix[0][1] != ' '){
		if(matrix[3][4]==' '){
			matrix[3][4]='O';
			return;
		}
	}
	
	if(((matrix[1][2]==matrix[2][3]) && (matrix[2][3]==matrix[3][4])) && matrix[1][2] != ' '){
		if(matrix[0][1]==' '){
			matrix[0][1]='O';
			return;
		}
	}
	
		// warna orange
	if(((matrix[0][0]==matrix[1][1]) && (matrix[1][1]==matrix[2][2])) && matrix[0][0] != ' '){
		if(matrix[3][3]==' '){
			matrix[3][3]='O';
			return;
		}
	}
	
	if(((matrix[1][1]==matrix[2][2]) && (matrix[2][2]==matrix[3][3])) && matrix[1][1] != ' '){
		if(matrix[0][0]==' '){
			matrix[0][0]='O';
			return;
		}
		else if(matrix[4][4]==' '){
			matrix[4][4]='O';
			return;
		}
	}
	
	if(((matrix[2][2]==matrix[3][3]) && (matrix[3][3]==matrix[4][4])) && matrix[2][2] != ' '){
		if(matrix[1][1]==' '){
			matrix[1][1]='O';
			return;
		}
	}	
	
		// kanan ke kiri
		// warna pink
	if(((matrix[3][0]==matrix[2][1]) && (matrix[2][1]==matrix[1][2])) && matrix[3][0] != ' '){
		if(matrix[0][3]==' '){
			matrix[0][3]='O';
			return;
		}
	}
	
	if(((matrix[2][1]==matrix[1][2]) && (matrix[1][2]==matrix[0][3])) && matrix[2][1] != ' '){
		if(matrix[3][0]==' '){
			matrix[3][0]='O';
			return;
		}
	}
		//---
	if(((matrix[4][1]==matrix[3][2]) && (matrix[3][2]==matrix[2][3])) && matrix[4][1] != ' '){
		if(matrix[1][4]==' '){
			matrix[1][4]='O';
			return;
		}
	}
	
	if(((matrix[3][2]==matrix[2][3]) && (matrix[2][3]==matrix[1][4])) && matrix[3][2] != ' '){
		if(matrix[4][1]==' '){
			matrix[4][1]='O';
			return;
		}
	}
	
		// warna orange
	if(((matrix[4][0]==matrix[3][1]) && (matrix[3][1]==matrix[2][2])) && matrix[4][0] != ' '){
		if(matrix[1][3]==' '){
			matrix[1][3]='O';
			return;
		}
	}
	
	if(((matrix[3][1]==matrix[2][2]) && (matrix[2][2]==matrix[1][3])) && matrix[3][1] != ' '){
		if(matrix[4][0]==' '){
			matrix[4][0]='O';
			return;
		}
		else if(matrix[0][4]==' '){
			matrix[0][4]='O';
			return;
		}
	}
	
	if(((matrix[2][2]==matrix[1][3]) && (matrix[1][3]==matrix[0][4])) && matrix[2][2] != ' '){
		if(matrix[3][1]==' '){
			matrix[3][1]='O';
			return;
		}
	}

		// Finalisasi dengan mengisi random di sekitar 'X' yang sudah ada
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			if(matrix[i][j]=='X'){
				if(matrix[i][--j]==' '){
					matrix[i][j]='O';
					return;
				}
				else if(matrix[i][++j]==' '){
					matrix[i][j]='O';
					return;
				}
				else if(matrix[++i][j]==' '){
					matrix[i][j]='O';
					return;
				}
				else if(matrix[--i][j]==' '){
					matrix[i][j]='O';
					return;
				}
			}
		}
	}
		// Finalisasi dengan mengisi yang masih kosong	
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			if(matrix[i][j] = ' '){
				matrix[i][j]='O';
				return;
			}
		}
	}
}

/*******************************************************************
PROCEDURE FOR COMPUTER MOVE 5X5 WITH 'O' HARD LEVEL
 ********************************************************************/
 
 void computer_move_3_5X5(){
	int i,j;
	
	//row checking jika 3 berturut-turut

		// Jika isi dari array index ke-1, ke-2 dan ke-3 adalah 'O' atau 'X', maka array index ke-4 atau ke-5 isi 'O'
	for(i=0;i<5;i++){
		if(((matrix[i][0] && matrix[i][1]) && (matrix[i][1] && matrix[i][2]) && matrix[i][0] != ' ')){									
			if(matrix[i][3]==' '){
				matrix[i][3]='O';
				return;
			}
			else if(matrix[i][4]==' '){
				matrix[i][4]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-2, ke-3 dan ke-4 adalah 'O' atau 'X', maka array index ke-1 atau ke-5 isi 'O'
	for(i=0;i<5;i++){
		if(((matrix[i][1] && matrix[i][2]) && (matrix[i][2] && matrix[i][3]) && matrix[i][1] != ' ')){									
			if(matrix[i][0]==' '){
				matrix[i][0]='O';
				return;
			}
			else if(matrix[i][4]==' '){
				matrix[i][4]='O';
				return;
			}
		}
	}
	
			// Jika isi dari array index ke-3, ke-4 dan ke-5 adalah 'O' atau 'X', maka array index ke-2 isi 'O'
	for(i=0;i<5;i++){
		if(((matrix[i][2] && matrix[i][3]) && (matrix[i][3] && matrix[i][4]) && matrix[i][2] != ' ')){									
			if(matrix[i][1]==' '){
				matrix[i][1]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-1, ke-2 dan ke-4 adalah 'O' atau 'X', maka array index ke-3 atau ke-5 isi 'O'
	for(i=0;i<5;i++){
		if(((matrix[i][0] && matrix[i][1]) && (matrix[i][1] && matrix[i][3])) && matrix[i][0] != ' '){									
			if(matrix[i][2]==' '){
				matrix[i][2]='O';
				return;
			}
			else if(matrix[i][4]==' '){
				matrix[i][4]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-2, ke-4 dan ke-5 adalah 'O' atau 'X', maka array index ke-1 atau ke-3 isi 'O'
	for(i=0;i<5;i++){
		if(((matrix[i][1] && matrix[i][3]) && (matrix[i][3] && matrix[i][4])) && matrix[i][1] != ' '){									
			if(matrix[i][2]==' '){
				matrix[i][2]='O';
				return;
			}
			else if(matrix[i][0]==' '){
				matrix[i][0]='O';
				return;
			}
		}
	}

		// Jika isi dari array index ke-1, ke-3 dan ke-4 adalah 'O' atau 'X', maka array index ke-2 atau ke-5 isi 'O'
	for(i=0;i<5;i++){
		if(((matrix[i][0] && matrix[i][2]) && (matrix[i][2] && matrix[i][3])) && matrix[i][0] != ' '){									
			if(matrix[i][1]==' '){
				matrix[i][1]='O';
				return;
			}
			else if(matrix[i][4]==' '){
				matrix[i][4]='O';
				return;
			}
		}
	}

		// Jika isi dari array index ke-1, ke-3 dan ke-5 adalah 'O' atau 'X', maka array index ke-2 atau ke-4 isi 'O'
	for(i=0;i<5;i++){
		if(((matrix[i][0] && matrix[i][2]) && (matrix[i][2] && matrix[i][4])) && matrix[i][0] != ' '){									
			if(matrix[i][1]==' '){
				matrix[i][1]='O';
				return;
			}
			else if(matrix[i][3]==' '){
				matrix[i][3]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-2, ke-3 dan ke-5 adalah 'O' atau 'X', maka array index ke-1 atau ke-4 isi 'O'
	for(i=0;i<5;i++){
		if(((matrix[i][1] && matrix[i][2]) && (matrix[i][2] && matrix[i][4])) && matrix[i][0] != ' '){									
			if(matrix[i][3]==' '){
				matrix[i][3]='O';
				return;
			}
			else if(matrix[i][0]==' '){
				matrix[i][0]='O';
				return;
			}
		}
	}
	
	//column checking jika 3 berturut-turut
	
		// Jika isi dari array index ke-1, ke-2 dan ke-3 adalah 'O' atau 'X', maka array index ke-4 atau ke-5 isi 'O'
	for(i=0;i<5;i++){
		if(((matrix[0][i] && matrix[1][i]) && (matrix[1][i] && matrix[2][i]) && matrix[0][i] != ' ')){									
			if(matrix[3][i]==' '){
				matrix[3][i]='O';
				return;
			}
			else if(matrix[4][i]==' '){
				matrix[4][i]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-2, ke-3 dan ke-4 adalah 'O' atau 'X', maka array index ke-1 atau ke-5 isi 'O'
	for(i=0;i<5;i++){
		if(((matrix[1][i] && matrix[2][i]) && (matrix[2][i] && matrix[3][i]) && matrix[1][i] != ' ')){									
			if(matrix[0][i]==' '){
				matrix[0][i]='O';
				return;
			}
			else if(matrix[4][i]==' '){
				matrix[4][i]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-3, ke-4 dan ke-5 adalah 'O' atau 'X', maka array index ke-1 atau ke-2 isi 'O'
	for(i=0;i<5;i++){
		if(((matrix[2][i] && matrix[3][i]) && (matrix[3][i] && matrix[4][i]) && matrix[2][i] != ' ')){									
			if(matrix[1][i]==' '){
				matrix[1][i]='O';
				return;
			}
			else if(matrix[0][i]==' '){
				matrix[0][i]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-1, ke-3 dan ke-4 adalah 'O' atau 'X', maka array index ke-2 atau ke-5 isi 'O'
	for(i=0;i<5;i++){
		if(((matrix[0][i] && matrix[2][i]) && (matrix[2][i] && matrix[3][i]) && matrix[0][i] != ' ')){									
			if(matrix[1][i]==' '){
				matrix[1][i]='O';
				return;
			}
			else if(matrix[4][i]==' '){
				matrix[4][i]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-1, ke-3 dan ke-5 adalah 'O' atau 'X', maka array index ke-2 atau ke-4 isi 'O'
	for(i=0;i<5;i++){
		if(((matrix[0][i] && matrix[2][i]) && (matrix[2][i] && matrix[4][i]) && matrix[0][i] != ' ')){									
			if(matrix[1][i]==' '){
				matrix[1][i]='O';
				return;
			}
			else if(matrix[3][i]==' '){
				matrix[3][i]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-1, ke-2 dan ke-4 adalah 'O' atau 'X', maka array index ke-3 atau ke-5 isi 'O'
	for(i=0;i<5;i++){
		if(((matrix[0][i] && matrix[1][i]) && (matrix[1][i] && matrix[3][i]) && matrix[0][i] != ' ')){									
			if(matrix[2][i]==' '){
				matrix[2][i]='O';
				return;
			}
			else if(matrix[4][i]==' '){
				matrix[4][i]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-2, ke-4 dan ke-5 adalah 'O' atau 'X', maka array index ke-1 atau ke-3 isi 'O'
	for(i=0;i<5;i++){
		if(((matrix[1][i] && matrix[3][i]) && (matrix[3][i] && matrix[4][i]) && matrix[1][i] != ' ')){									
			if(matrix[2][i]==' '){
				matrix[2][i]='O';
				return;
			}
			else if(matrix[1][i]==' '){
				matrix[1][i]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-2, ke-3 dan ke-5 adalah 'O' atau 'X', maka array index ke-1 atau ke-4 isi 'O'
	for(i=0;i<5;i++){
		if(((matrix[1][i] && matrix[2][i]) && (matrix[2][i] && matrix[4][i]) && matrix[1][i] != ' ')){									
			if(matrix[3][i]==' '){
				matrix[3][i]='O';
				return;
			}
			else if(matrix[1][i]==' '){
				matrix[1][i]='O';
				return;
			}
		}
	}
	
	// Diagonal Checking jika 3 berturut-turut
		// kiri ke kanan
		// warna pink
	if(((matrix[1][0]==matrix[2][1]) && (matrix[2][1]==matrix[3][2])) && matrix[1][0] != ' '){
		if(matrix[4][3]==' '){
			matrix[4][3]='O';
			return;
		}
	}
	
	if(((matrix[2][1]==matrix[3][2]) && (matrix[3][2]==matrix[4][3])) && matrix[2][1] != ' '){
		if(matrix[1][0]==' '){
			matrix[1][0]='O';
			return;
		}
	}
		//---
	if(((matrix[0][1]==matrix[1][2]) && (matrix[1][2]==matrix[2][3])) && matrix[0][1] != ' '){
		if(matrix[3][4]==' '){
			matrix[3][4]='O';
			return;
		}
	}
	
	if(((matrix[1][2]==matrix[2][3]) && (matrix[2][3]==matrix[3][4])) && matrix[1][2] != ' '){
		if(matrix[0][1]==' '){
			matrix[0][1]='O';
			return;
		}
	}
	
		// warna orange
	if(((matrix[0][0]==matrix[1][1]) && (matrix[1][1]==matrix[2][2])) && matrix[0][0] != ' '){
		if(matrix[3][3]==' '){
			matrix[3][3]='O';
			return;
		}
	}
	
	if(((matrix[1][1]==matrix[2][2]) && (matrix[2][2]==matrix[3][3])) && matrix[1][1] != ' '){
		if(matrix[0][0]==' '){
			matrix[0][0]='O';
			return;
		}
		else if(matrix[4][4]==' '){
			matrix[4][4]='O';
			return;
		}
	}
	
	if(((matrix[2][2]==matrix[3][3]) && (matrix[3][3]==matrix[4][4])) && matrix[2][2] != ' '){
		if(matrix[1][1]==' '){
			matrix[1][1]='O';
			return;
		}
	}	
	
		// kanan ke kiri
		// warna pink
	if(((matrix[3][0]==matrix[2][1]) && (matrix[2][1]==matrix[1][2])) && matrix[3][0] != ' '){
		if(matrix[0][3]==' '){
			matrix[0][3]='O';
			return;
		}
	}
	
	if(((matrix[2][1]==matrix[1][2]) && (matrix[1][2]==matrix[0][3])) && matrix[2][1] != ' '){
		if(matrix[3][0]==' '){
			matrix[3][0]='O';
			return;
		}
	}
		//---
	if(((matrix[4][1]==matrix[3][2]) && (matrix[3][2]==matrix[2][3])) && matrix[4][1] != ' '){
		if(matrix[1][4]==' '){
			matrix[1][4]='O';
			return;
		}
	}
	
	if(((matrix[3][2]==matrix[2][3]) && (matrix[2][3]==matrix[1][4])) && matrix[3][2] != ' '){
		if(matrix[4][1]==' '){
			matrix[4][1]='O';
			return;
		}
	}
	
		// warna orange
	if(((matrix[4][0]==matrix[3][1]) && (matrix[3][1]==matrix[2][2])) && matrix[4][0] != ' '){
		if(matrix[1][3]==' '){
			matrix[1][3]='O';
			return;
		}
	}
	
	if(((matrix[3][1]==matrix[2][2]) && (matrix[2][2]==matrix[1][3])) && matrix[3][1] != ' '){
		if(matrix[4][0]==' '){
			matrix[4][0]='O';
			return;
		}
		else if(matrix[0][4]==' '){
			matrix[0][4]='O';
			return;
		}
	}
	
	if(((matrix[2][2]==matrix[1][3]) && (matrix[1][3]==matrix[0][4])) && matrix[2][2] != ' '){
		if(matrix[3][1]==' '){
			matrix[3][1]='O';
			return;
		}
	}
	
	//row checking jika sudah 2 beturut-turut
	
		// Jika isi dari array index ke-1 dan ke-2 adalah 'O' atau 'X', maka array index ke-3 isi 'O'
	for(i=0;i<5;i++){
		if((matrix[i][0]==matrix[i][1]) && (matrix[i][0] != ' ')){
			if(matrix[i][2]==' '){
				matrix[i][2]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-2 dan ke-3 adalah 'O' atau 'X', maka array index ke-1 dan ke-4 isi 'O'
	for(i=0;i<5;i++){
		if((matrix[i][1]==matrix[i][2]) && (matrix[i][1] != ' ')){									
			if(matrix[i][0]==' '){
				matrix[i][0]='O';
				return;
			}
			else if(matrix[i][3]==' '){
				matrix[i][3]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-3 dan ke-4 adalah 'O' atau 'X', maka array index ke-2 dan ke-5 isi 'O'
	for(i=0;i<5;i++){
		if((matrix[i][2]==matrix[i][3]=='X') && (matrix[i][2] != ' ')){									
			if(matrix[i][1]==' '){
				matrix[i][1]='O';
				return;
			}
			else if(matrix[i][4]==' '){
				matrix[i][4]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-4 dan ke-5 adalah 'O' atau 'X', maka array index ke-3 isi 'O'
	for(i=0;i<5;i++){
		if((matrix[i][3]==matrix[i][4]=='X') && (matrix[i][3] != ' ')){									
			if(matrix[i][2]==' '){
				matrix[i][2]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-1 dan ke-3 adalah 'O' atau 'X', maka array index ke-2 isi 'O'
	for(i=0;i<5;i++){
		if((matrix[i][0]==matrix[i][2]) && (matrix[i][0] != ' ')){									
			if(matrix[i][1]==' '){
				matrix[i][1]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-2 dan ke-4 adalah 'O' atau 'X', maka array index ke-3 isi 'O'
	for(i=0;i<5;i++){
		if((matrix[i][1]==matrix[i][3]) && (matrix[i][1] != ' ')){									
			if(matrix[i][2]==' '){
				matrix[i][2]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-3 dan ke-5 adalah 'O' atau 'X', maka array index ke-4 isi 'O'
	for(i=0;i<5;i++){
		if((matrix[i][2]==matrix[i][4]) && (matrix[i][2] != ' ')){									
			if(matrix[i][3]==' '){
				matrix[i][3]='O';
				return;
			}
		}
	}
	
	//column checking jika 2 berturut-turut

		// Jika isi dari array index ke-1 dan ke-2 adalah 'O' atau 'X', maka array index ke-3 isi 'O'
	for(i=0;i<5;i++){
		if((matrix[0][i]==matrix[1][i]) && (matrix[0][i] != ' ')){									
			if(matrix[2][i]==' '){
				matrix[2][i]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-2 dan ke-3 adalah 'O' atau 'X', maka array index ke-1 dan ke-4 isi 'O'
	for(i=0;i<5;i++){
		if((matrix[1][i]==matrix[2][i]) && (matrix[1][i] != ' ')){									
			if(matrix[0][i]==' '){
				matrix[0][i]='O';
				return;
			}
			else if(matrix[3][i]==' '){
				matrix[3][i]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-3 dan ke-4 adalah 'O' atau 'X', maka array index ke-2 dan ke-5 isi 'O'
	for(i=0;i<5;i++){
		if((matrix[2][i]==matrix[3][i]) && (matrix[2][i] != ' ')){									
			if(matrix[1][i]==' '){
				matrix[1][i]='O';
				return;
			}
			else if(matrix[4][i]==' '){
				matrix[4][i]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-4 dan ke-5 adalah 'O' atau 'X', maka array index ke-3 dan ke-6 isi 'O'
	for(i=0;i<5;i++){
		if((matrix[3][i]==matrix[4][i]) && (matrix[3][i] != ' ')){									
			if(matrix[2][i]==' '){
				matrix[2][i]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-1 dan ke-3 adalah 'O' atau 'X', maka array index ke-2 isi 'O'
	for(i=0;i<5;i++){
		if((matrix[0][i]==matrix[2][i]) && (matrix[0][i] != ' ')){									
			if(matrix[1][i]==' '){
				matrix[1][i]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-2 dan ke-4 adalah 'O' atau 'X', maka array index ke-3 isi 'O'
	for(i=0;i<5;i++){
		if((matrix[1][i]==matrix[3][i]) && (matrix[1][i] != ' ')){									
			if(matrix[2][i]==' '){
				matrix[2][i]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-3 dan ke-5 adalah 'O' atau 'X', maka array index ke-4 isi 'O'
	for(i=0;i<5;i++){
		if((matrix[2][i]==matrix[4][i]) && (matrix[2][i] != ' ')){									
			if(matrix[3][i]==' '){
				matrix[3][i]='O';
				return;
			}
		}
	}

	// diagonal checking jika 2 berturut-turut
	
		// kiri ke kanan
		// warna pink sesuai tracing
	if(((matrix[1][0]==matrix[2][1]) && matrix[1][0] != ' ')){
		if(matrix[3][2]==' '){
			matrix[3][2]='O';
			return;
		}
	}		
	
	if(((matrix[2][1]==matrix[3][2]) && matrix[2][1] != ' ')){
		if(matrix[1][0]==' '){
			matrix[1][0]='O';
			return;
		}
		else if(matrix[4][3]==' '){
			matrix[4][3]='O';
			return;
		}
	}
	
	if(((matrix[3][2]==matrix[4][3]) && matrix[3][2] != ' ')){
		if(matrix[2][1]==' '){
			matrix[2][1]='O';
			return;
		}
	}
	
		// -----	
	if(((matrix[0][1]==matrix[1][2]) && matrix[0][1] != ' ')){
		if(matrix[2][3]==' '){
			matrix[2][3]='O';
			return;
		}
	}		
	
	if(((matrix[1][2]==matrix[2][3]) && matrix[1][2] != ' ')){
		if(matrix[0][1]==' '){
			matrix[0][1]='O';
			return;
		}
		else if(matrix[3][4]==' '){
			matrix[3][4]='O';
			return;
		}
	}
	
	if(((matrix[2][3]==matrix[3][4]) && matrix[2][3] != ' ')){
		if(matrix[1][2]==' '){
			matrix[1][2]='O';
			return;
		}
	}	
	
		// warna biru sesuai tracing
	if(((matrix[0][0]==matrix[1][1]) && matrix[0][0] != ' ')){
		if(matrix[2][2]==' '){
			matrix[2][2]='O';
			return;
		}
	}	
	
	if(((matrix[1][1]==matrix[2][2]) && matrix[1][1] != ' ')){
		if(matrix[0][0]==' '){
			matrix[0][0]='O';
			return;
		}
		else if(matrix[3][3]==' '){
			matrix[3][3]='O';
			return;
		}
	}
	
	if(((matrix[2][2]==matrix[3][3]) && matrix[2][2] != ' ')){
		if(matrix[1][1]==' '){
			matrix[1][1]='O';
			return;
		}
		else if(matrix[4][4]==' '){
			matrix[4][4]='O';
			return;
		}
	}
	
	if(((matrix[3][3]==matrix[4][4]) && matrix[3][3] != ' ')){
		if(matrix[2][2]==' '){
			matrix[2][2]='O';
			return;
		}
	}
	
		// kanan ke kiri
		// warna pink sesuai tracing
	if(((matrix[3][0]==matrix[2][1]) && matrix[3][0] != ' ')){
		if(matrix[1][2]==' '){
			matrix[1][2]='O';
			return;
		}
	}		
	
	if(((matrix[2][1]==matrix[1][2]) && matrix[2][1] != ' ')){
		if(matrix[0][3]==' '){
			matrix[0][3]='O';
			return;
		}
		else if(matrix[3][0]==' '){
			matrix[3][0]='O';
			return;
		}
	}
	
	if(((matrix[1][2]==matrix[0][3]) && matrix[1][2] != ' ')){
		if(matrix[2][1]==' '){
			matrix[2][1]='O';
			return;
		}
	}
	
		// -----	
	if(((matrix[4][1]==matrix[3][2]) && matrix[4][1] != ' ')){
		if(matrix[2][3]==' '){
			matrix[2][3]='O';
			return;
		}
	}		
	
	if(((matrix[3][2]==matrix[2][3]) && matrix[3][2] != ' ')){
		if(matrix[4][1]==' '){
			matrix[4][1]='O';
			return;
		}
		else if(matrix[1][4]==' '){
			matrix[1][4]='O';
			return;
		}
	}
	
	if(((matrix[2][3]==matrix[1][4]) && matrix[2][3] != ' ')){
		if(matrix[3][2]==' '){
			matrix[3][2]='O';
			return;
		}
	}	
	
		// warna biru sesuai tracing
	if(((matrix[4][0]==matrix[3][1]) && matrix[4][0] != ' ')){
		if(matrix[2][2]==' '){
			matrix[2][2]='O';
			return;
		}
	}	
	
	if(((matrix[3][1]==matrix[2][2]) && matrix[3][1] != ' ')){
		if(matrix[4][0]==' '){
			matrix[4][0]='O';
			return;
		}
		else if(matrix[1][3]==' '){
			matrix[1][3]='O';
			return;
		}
	}
	
	if(((matrix[2][2]==matrix[1][3]) && matrix[2][2] != ' ')){
		if(matrix[3][1]==' '){
			matrix[3][1]='O';
			return;
		}
		else if(matrix[0][4]==' '){
			matrix[0][4]='O';
			return;
		}
	}
	
	if(((matrix[1][3]==matrix[0][4]) && matrix[1][3] != ' ')){
		if(matrix[2][2]==' '){
			matrix[2][2]='O';
			return;
		}
	}

		// Finalisasi dengan mengisi random di sekitar 'X' yang sudah ada
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			if(matrix[i][j]=='X'){
				if(matrix[i][--j]==' '){
					matrix[i][j]='O';
					return;
				}
				else if(matrix[i][++j]==' '){
					matrix[i][j]='O';
					return;
				}
				else if(matrix[++i][j]==' '){
					matrix[i][j]='O';
					return;
				}
				else if(matrix[--i][j]==' '){
					matrix[i][j]='O';
					return;
				}
			}
		}
	}
		// Finalisasi dengan mengisi yang masih kosong	
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			if(matrix[i][j] = ' '){
				matrix[i][j]='O';
				return;
			}
		}
	}
}
 
/*******************************************************************
FUNCTION TO CHECK WIN 5X5
 ********************************************************************/
 
 char check_5X5(){
	int i,j;
	
		// row checking jika 4 berturut-turut
	for(i=0;i<5;i++){ 
		if((matrix[i][0]==matrix[i][1]) && (matrix[i][1]==matrix[i][2]) && (matrix[i][2]==matrix[i][3]) && (matrix[i][0] != ' ')){
			return matrix[i][0];
		}
	}
	
	for(i=0;i<5;i++){
		if((matrix[i][1]==matrix[i][2]) && (matrix[i][2]==matrix[i][3]) && (matrix[i][3]==matrix[i][4]) && (matrix[i][1] != ' ')){
			return matrix[i][1];
		}
	}
	
		// column checking
	for(i=0;i<5;i++){
		if((matrix[0][i]==matrix[1][i]) && (matrix[0][i]==matrix[2][i]) && (matrix[0][i]==matrix[3][i]) && (matrix[0][i] != ' ')){
			return matrix[0][i];
		}
	}
	
	for(i=0;i<5;i++){
		if((matrix[1][i]==matrix[2][i]) && (matrix[2][i]==matrix[3][i]) && (matrix[3][i]==matrix[4][i]) && (matrix[1][i] != ' ')){
			return matrix[1][i];
		}
	}
	
		// diagonal checking jika 4 berturut-turut
		// kiri ke kanan
	if((matrix[0][0]==matrix[1][1]) && (matrix[0][0]==matrix[2][2]) && (matrix[0][0]==matrix[3][3]) && (matrix[0][0] != ' ')){
		return matrix[0][0];
	}
	if((matrix[1][1]==matrix[2][2]) && (matrix[2][2]==matrix[3][3]) && (matrix[3][3]==matrix[4][4]) && (matrix[1][1] != ' ')){
		return matrix[1][1];
	}
	if((matrix[0][1]==matrix[1][2]) && (matrix[1][2]==matrix[2][3]) && (matrix[2][3]==matrix[3][4]) && (matrix[0][1] != ' ')){
		return matrix[0][1];
	}
	if((matrix[1][0]==matrix[2][1]) && (matrix[2][1]==matrix[3][2]) && (matrix[3][2]==matrix[4][3]) && (matrix[1][0] != ' ')){
		return matrix[1][0];
	}
	
		// kanan ke kiri
	if((matrix[3][0]==matrix[2][1]) && (matrix[2][1]==matrix[1][2]) && (matrix[1][2]==matrix[0][3]) && (matrix[3][0] != ' ')){
		return matrix[3][0];
	}
	if((matrix[4][0]==matrix[3][1]) && (matrix[3][1]==matrix[2][2]) && (matrix[2][2]==matrix[1][3]) && (matrix[4][0] != ' ')){
		return matrix[4][0];
	}
	if((matrix[3][1]==matrix[2][2]) && (matrix[2][2]==matrix[1][3]) && (matrix[1][3]==matrix[0][4]) && (matrix[3][1] != ' ')){
		return matrix[3][1];
	}
	if((matrix[4][1]==matrix[3][2]) && (matrix[3][2]==matrix[2][3]) && (matrix[2][3]==matrix[1][4]) && (matrix[4][1] != ' ')){
		return matrix[4][1];
	}
	
		// If empty
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			if(matrix[i][j]==' '){
				return ' ';
			}
		}
	}
	
		// Draw
	return 'D';																						
}

/*******************************************************************
PROCEDURE TO DISPLAY MATRIS 7X7
 ********************************************************************/
 
 void disp_matrix_7X7 (int player,char namePlayer[]){
 	system("cls");
    printf("\n  Player1(X)\n");
	printf("  Player2/Computer(O)\n\n");
	printf("  %s as player %d",namePlayer,player);
    printf("\n  Player%d's turn \n\n",player);
 	
 	int i;
 	
 	printf("  (x,y)  1   2   3   4   5   6   7\n");
 	printf("       \xDA\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xBF\n");
	printf("     1 \xB3 %c \xB3 %c \xB3 %c \xB3 %c \xB3 %c \xB3 %c \xB3 %c \xB3\n",matrix[0][0],matrix[0][1],matrix[0][2],matrix[0][3],matrix[0][4],matrix[0][5],matrix[0][6]);
	printf("       \xC3\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xB4\n");
	printf("     2 \xB3 %c \xB3 %c \xB3 %c \xB3 %c \xB3 %c \xB3 %c \xB3 %c \xB3\n",matrix[1][0],matrix[1][1],matrix[1][2],matrix[1][3],matrix[1][4],matrix[1][5],matrix[1][6]);
	printf("       \xC3\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xB4\n");
	printf("     3 \xB3 %c \xB3 %c \xB3 %c \xB3 %c \xB3 %c \xB3 %c \xB3 %c \xB3\n",matrix[2][0],matrix[2][1],matrix[2][2],matrix[2][3],matrix[2][4],matrix[2][5],matrix[2][6]);
	printf("       \xC3\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xB4\n");
	printf("     4 \xB3 %c \xB3 %c \xB3 %c \xB3 %c \xB3 %c \xB3 %c \xB3 %c \xB3\n",matrix[3][0],matrix[3][1],matrix[3][2],matrix[3][3],matrix[3][4],matrix[3][5],matrix[3][6]);
	printf("       \xC3\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xB4\n");
	printf("     5 \xB3 %c \xB3 %c \xB3 %c \xB3 %c \xB3 %c \xB3 %c \xB3 %c \xB3\n",matrix[4][0],matrix[4][1],matrix[4][2],matrix[4][3],matrix[4][4],matrix[4][5],matrix[4][6]);
	printf("       \xC3\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xB4\n");
	printf("     6 \xB3 %c \xB3 %c \xB3 %c \xB3 %c \xB3 %c \xB3 %c \xB3 %c \xB3\n",matrix[5][0],matrix[5][1],matrix[5][2],matrix[5][3],matrix[5][4],matrix[5][5],matrix[5][6]);
	printf("       \xC3\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xB4\n");
	printf("     7 \xB3 %c \xB3 %c \xB3 %c \xB3 %c \xB3 %c \xB3 %c \xB3 %c \xB3\n",matrix[6][0],matrix[6][1],matrix[6][2],matrix[6][3],matrix[6][4],matrix[6][5],matrix[6][6]);
	printf("       \xC0\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xD9\n");
 }

/*******************************************************************
PROCEDURE FOR COMPUTER MOVE 7X7 WITH 'O' EASY LEVEL
 ********************************************************************/
 
 void computer_move_1_7X7(){
 	int i,j;
 	
 	//row checking jika 4 berturut=turut 
    
    	// Jika isi dari array index ke-1, ke-2, ke-3 dan ke-4 adalah 'O' atau 'X', maka array index ke-5, ke-6, dan ke-7 isi 'O'
	for(i=0;i<7;i++){
		if(((matrix[i][0]==matrix[i][1]) && (matrix[i][1]==matrix[i][2]) && (matrix[i][2]==matrix[i][3])) && matrix[i][0] != ' '){									
			if(matrix[i][4]==' '){
				matrix[i][4]='O';
				return;
			}
			else if(matrix[i][5]==' '){
				matrix[i][5]='O';
				return;
			}
			else if(matrix[i][6]==' '){
				matrix[i][6]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-2, ke-3, ke-4 dan ke-5 adalah 'O' atau 'X', maka array index ke-1, ke-6, dan ke-7 isi 'O'
	for(i=0;i<7;i++){
		if(((matrix[i][1]==matrix[i][2]) && (matrix[i][2]==matrix[i][3]) && (matrix[i][3]==matrix[i][4])) && matrix[i][1] != ' '){									
			if(matrix[i][0]==' '){
				matrix[i][0]='O';
				return;
			}
			else if(matrix[i][5]==' '){
				matrix[i][5]='O';
				return;
			}
			else if(matrix[i][6]==' '){
				matrix[i][6]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-3, ke-4, ke-5 dan ke-6 adalah 'O' atau 'X', maka array index ke-1, ke-2, dan ke-7 isi 'O'
	for(i=0;i<7;i++){
		if(((matrix[i][2]==matrix[i][3]) && (matrix[i][3]==matrix[i][4]) && (matrix[i][4]==matrix[i][5])) && matrix[i][2] != ' '){									
			if(matrix[i][0]==' '){
				matrix[i][0]='O';
				return;
			}
			else if(matrix[i][1]==' '){
				matrix[i][1]='O';
				return;
			}
			else if(matrix[i][6]==' '){
				matrix[i][6]='O';
				return;
			}
		}
	}
		
		// Jika isi dari array index ke-4, ke-5, ke-6 dan ke-7 adalah 'O' atau 'X', maka array index ke-1, ke-2, dan ke-3 isi 'O'
	for(i=0;i<7;i++){
		if(((matrix[i][3]==matrix[i][4]) && (matrix[i][4]==matrix[i][5]) && (matrix[i][5]==matrix[i][6])) && matrix[i][3] != ' '){									
			if(matrix[i][0]==' '){
				matrix[i][0]='O';
				return;
			}
			else if(matrix[i][1]==' '){
				matrix[i][1]='O';
				return;
			}
			else if(matrix[i][2]==' '){
				matrix[i][2]='O';
				return;
			}
		}
	}
	
	// Column Checking jika 4 berturut-turut
	
		// Jika isi dari array index ke-1, ke-2, ke-3 dan ke-4 adalah 'O' atau 'X', maka array index ke-5, ke-6, dan ke-7 isi 'O'
	for(i=0;i<7;i++){
		if(((matrix[0][i]==matrix[1][i]) && (matrix[1][i]==matrix[2][i]) && (matrix[2][i]==matrix[3][i])) && matrix[0][i] != ' '){									
			if(matrix[4][i]==' '){
				matrix[4][i]='O';
				return;
			}
			else if(matrix[5][i]==' '){
				matrix[5][i]='O';
				return;
			}
			else if(matrix[6][i]==' '){
				matrix[6][i]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-2, ke-3, ke-4 dan ke-5 adalah 'O' atau 'X', maka array index ke-1, ke-6, dan ke-7 isi 'O'
	for(i=0;i<7;i++){
		if(((matrix[1][i]==matrix[2][i]) && (matrix[2][i]==matrix[3][i]) && (matrix[3][i]==matrix[4][i])) && matrix[1][i] != ' '){
			if(matrix[0][i]==' '){
				matrix[0][i]='O';
				return;
			}
			else if(matrix[5][i]==' '){
				matrix[5][i]='O';
				return;
			}
			else if(matrix[6][i]==' '){
				matrix[6][i]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-3, ke-4, ke-5 dan ke-6 adalah 'O' atau 'X', maka array index ke-1, ke-2, dan ke-7 isi 'O'
	for(i=0;i<7;i++){
		if(((matrix[2][i]==matrix[3][i]) && (matrix[3][i]==matrix[4][i]) && (matrix[4][i]==matrix[5][i])) && matrix[2][i] != ' '){
			if(matrix[0][i]==' '){
				matrix[0][i]='O';
				return;
			}
			else if(matrix[1][i]==' '){
				matrix[1][i]='O';
				return;
			}
			else if(matrix[6][i]==' '){
				matrix[6][i]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-4, ke-5, ke-6 dan ke-7 adalah 'O' atau 'X', maka array index ke-1, ke-2, dan ke-3 isi 'O'
	for(i=0;i<7;i++){
		if(((matrix[3][i]==matrix[4][i]) && (matrix[4][i]==matrix[5][i]) && (matrix[5][i]==matrix[6][i])) && matrix[3][i] != ' '){
			if(matrix[0][i]==' '){
				matrix[0][i]='O';
				return;
			}
			else if(matrix[1][i]==' '){
				matrix[1][i]='O';
				return;
			}
			else if(matrix[2][i]==' '){
				matrix[2][i]='O';
				return;
			}
		}
	}
	
	// Diagonal Checking jika sudah 4 berturut-turut
		// kanan ke kiri
		// warna merah sesuai dengan tracing
	if(((matrix[4][0]==matrix[3][1]) && (matrix[3][1]==matrix[2][2]) && (matrix[2][2]==matrix[1][3])) && matrix[4][0] != ' '){
		if(matrix[0][4]==' '){
			matrix[0][4]='O';
			return;
		}
	}
	
	if(((matrix[3][1]==matrix[2][2]) && (matrix[2][2]==matrix[1][3]) && (matrix[1][3]==matrix[0][4])) && matrix[3][1] != ' '){
		if(matrix[4][0]==' '){
			matrix[4][0]='O';
			return;
		}
	}
	
	if(((matrix[6][2]==matrix[5][3]) && (matrix[5][3]==matrix[4][4]) && (matrix[4][4]==matrix[3][5])) && matrix[6][2] != ' '){
		if(matrix[2][6]==' '){
			matrix[2][6]='O';
			return;
		}
	}
	
	if(((matrix[5][3]==matrix[4][4]) && (matrix[4][4]==matrix[3][5]) && (matrix[3][5]==matrix[2][6])) && matrix[5][3] != ' '){
		if(matrix[6][2]==' '){
			matrix[6][2]='O';
			return;
		}
	}
		// Warna hijau sesuai dengan tracing
	if(((matrix[5][0]==matrix[4][1]) && (matrix[4][1]==matrix[3][2]) && (matrix[3][2]==matrix[2][3])) && matrix[5][0] != ' '){
		if(matrix[1][4]==' '){
			matrix[1][4]='O';
			return;
		}
		else if(matrix[0][5]==' '){
			matrix[0][5]='O';
			return;
		}
	}
	
	if(((matrix[4][1]==matrix[3][2]) && (matrix[3][2]==matrix[2][3]) && (matrix[2][3]==matrix[1][4])) && matrix[4][1] != ' '){
		if(matrix[0][5]==' '){
			matrix[0][5]='O';
			return;
		}
		else if(matrix[5][0]==' '){
			matrix[5][0]='O';
			return;
		}
	}
	
	if(((matrix[3][2]==matrix[2][3]) && (matrix[2][3]==matrix[1][4]) && (matrix[1][4]==matrix[0][5])) && matrix[3][2] != ' '){
		if(matrix[4][1]==' '){
			matrix[4][1]='O';
			return;
		}
		else if(matrix[5][0]==' '){
			matrix[5][0]='O';
			return;
		}
	}
	
	if(((matrix[6][1]==matrix[5][2]) && (matrix[5][2]==matrix[4][3]) && (matrix[4][3]==matrix[3][4])) && matrix[6][1] != ' '){
		if(matrix[2][5]==' '){
			matrix[2][5]='O';
			return;
		}
		else if(matrix[1][6]==' '){
			matrix[1][6]='O';
			return;
		}
	}
	
	if(((matrix[5][2]==matrix[4][3]) && (matrix[4][3]==matrix[3][4]) && (matrix[3][4]==matrix[2][5])) && matrix[5][2] != ' '){
		if(matrix[1][6]==' '){
			matrix[1][6]='O';
			return;
		}
		else if(matrix[6][1]==' '){
			matrix[6][1]='O';
			return;
		}
	}
	
	if(((matrix[4][3]==matrix[3][4]) && (matrix[3][4]==matrix[2][5]) && (matrix[2][5]==matrix[1][6])) && matrix[4][3] != ' '){
		if(matrix[5][2]==' '){
			matrix[5][2]='O';
			return;
		}
		else if(matrix[6][1]==' '){
			matrix[6][1]='O';
			return;
		}
	}
		// Warna kuning sesuai dengan tracing
	if(((matrix[6][0]==matrix[5][1]) && (matrix[5][1]==matrix[4][2]) && (matrix[4][2]==matrix[3][3])) && matrix[6][0] != ' '){
		if(matrix[2][4]==' '){
			matrix[2][4]='O';
			return;
		}
		else if(matrix[1][5]==' '){
			matrix[1][5]='O';
			return;
		}
		else if(matrix[0][6]==' '){
			matrix[0][6]='O';
			return;
		}
	}
	
	if(((matrix[5][1]==matrix[4][2]) && (matrix[4][2]==matrix[3][3]) && (matrix[3][3]==matrix[2][4])) && matrix[5][1] != ' '){
		if(matrix[1][5]==' '){
			matrix[1][5]='O';
			return;
		}
		else if(matrix[0][6]==' '){
			matrix[0][6]='O';
			return;
		}
		else if(matrix[6][0]==' '){
			matrix[6][0]='O';
			return;
		}
	}
	
	if(((matrix[4][2]==matrix[3][3]) && (matrix[3][3]==matrix[2][4]) && (matrix[2][4]==matrix[1][5])) && matrix[4][2] != ' '){
		if(matrix[5][1]==' '){
			matrix[5][1]='O';
			return;
		}
		else if(matrix[0][6]==' '){
			matrix[0][6]='O';
			return;
		}
		else if(matrix[6][0]==' '){
			matrix[6][0]='O';
			return;
		}
	}	
	
	if(((matrix[3][3]==matrix[2][4]) && (matrix[2][4]==matrix[1][5]) && (matrix[1][5]==matrix[0][6])) && matrix[3][3] != ' '){
		if(matrix[5][1]==' '){
			matrix[5][1]='O';
			return;
		}
		else if(matrix[4][2]==' '){
			matrix[4][2]='O';
			return;
		}
		else if(matrix[6][0]==' '){
			matrix[6][0]='O';
			return;
		}
	}
	
		// kiri ke kanan
		// warna merah sesuai dengan tracing
	if(((matrix[2][0]==matrix[3][1]) && (matrix[3][1]==matrix[4][2]) && (matrix[4][2]==matrix[5][3])) && matrix[2][0] != ' '){
		if(matrix[6][4]==' '){
			matrix[6][4]='O';
			return;
		}
	}
	
	if(((matrix[3][1]==matrix[4][2]) && (matrix[4][2]==matrix[5][3]) && (matrix[5][3]==matrix[6][4])) && matrix[3][1] != ' '){
		if(matrix[2][0]==' '){
			matrix[2][0]='O';
			return;
		}
	}
	
	if(((matrix[0][2]==matrix[1][3]) && (matrix[1][3]==matrix[2][4]) && (matrix[2][4]==matrix[3][5])) && matrix[0][2] != ' '){
		if(matrix[4][6]==' '){
			matrix[4][6]='O';
			return;
		}
	}
	
	if(((matrix[1][3]==matrix[2][4]) && (matrix[2][4]==matrix[3][5]) && (matrix[3][5]==matrix[4][6])) && matrix[1][3] != ' '){
		if(matrix[0][2]==' '){
			matrix[0][2]='O';
			return;
		}
	}
		// Warna hijau sesuai dengan tracing
	if(((matrix[1][0]==matrix[2][1]) && (matrix[2][1]==matrix[3][2]) && (matrix[3][2]==matrix[4][3])) && matrix[1][0] != ' '){
		if(matrix[5][4]==' '){
			matrix[5][4]='O';
			return;
		}
		else if(matrix[6][5]==' '){
			matrix[6][5]='O';
			return;
		}
	}
	
	if(((matrix[2][1]==matrix[3][2]) && (matrix[3][2]==matrix[4][3]) && (matrix[4][3]==matrix[5][4])) && matrix[2][1] != ' '){
		if(matrix[6][5]==' '){
			matrix[6][5]='O';
			return;
		}
		else if(matrix[1][0]==' '){
			matrix[1][0]='O';
			return;
		}
	}
	
	if(((matrix[3][2]==matrix[4][3]) && (matrix[4][3]==matrix[5][4]) && (matrix[5][4]==matrix[6][5])) && matrix[3][2] != ' '){
		if(matrix[2][1]==' '){
			matrix[2][1]='O';
			return;
		}
		else if(matrix[1][0]==' '){
			matrix[1][0]='O';
			return;
		}
	}
	
	if(((matrix[0][1]==matrix[1][2]) && (matrix[1][2]==matrix[2][3]) && (matrix[2][3]==matrix[3][4])) && matrix[0][1] != ' '){
		if(matrix[4][5]==' '){
			matrix[4][5]='O';
			return;
		}
		else if(matrix[5][6]==' '){
			matrix[5][6]='O';
			return;
		}
	}
	
	if(((matrix[1][2]==matrix[2][3]) && (matrix[2][3]==matrix[3][4]) && (matrix[3][4]==matrix[4][5])) && matrix[1][2] != ' '){
		if(matrix[5][6]==' '){
			matrix[5][6]='O';
			return;
		}
		else if(matrix[0][1]==' '){
			matrix[0][1]='O';
			return;
		}
	}
	
	if(((matrix[2][3]==matrix[3][4]) && (matrix[3][4]==matrix[4][5]) && (matrix[4][5]==matrix[5][6])) && matrix[2][3] != ' '){
		if(matrix[1][2]==' '){
			matrix[1][2]='O';
			return;
		}
		else if(matrix[0][1]==' '){
			matrix[0][1]='O';
			return;
		}
	}
		// Warna kuning sesuai dengan tracing
	if(((matrix[0][0]==matrix[1][1]) && (matrix[1][1]==matrix[2][2]) && (matrix[2][2]==matrix[3][3])) && matrix[0][0] != ' '){
		if(matrix[4][4]==' '){
			matrix[4][4]='O';
			return;
		}
		else if(matrix[5][5]==' '){
			matrix[5][5]='O';
			return;
		}
		else if(matrix[6][6]==' '){
			matrix[6][6]='O';
			return;
		}
	}
	
	if(((matrix[1][1]==matrix[2][2]) && (matrix[2][2]==matrix[3][3]) && (matrix[3][3]==matrix[4][4])) && matrix[1][1] != ' '){
		if(matrix[5][5]==' '){
			matrix[5][5]='O';
			return;
		}
		else if(matrix[0][0]==' '){
			matrix[0][0]='O';
			return;
		}
		else if(matrix[6][6]==' '){
			matrix[6][6]='O';
			return;
		}
	}
	
	if(((matrix[2][2]==matrix[3][3]) && (matrix[3][3]==matrix[4][4]) && (matrix[4][4]==matrix[5][5])) && matrix[2][2] != ' '){
		if(matrix[1][1]==' '){
			matrix[1][1]='O';
			return;
		}
		else if(matrix[6][6]==' '){
			matrix[6][6]='O';
			return;
		}
		else if(matrix[0][0]==' '){
			matrix[0][0]='O';
			return;
		}
	}	
	
	if(((matrix[3][3]==matrix[4][4]) && (matrix[4][4]==matrix[5][5]) && (matrix[5][5]==matrix[6][6])) && matrix[3][3] != ' '){
		if(matrix[2][2]==' '){
			matrix[2][2]='O';
			return;
		}
		else if(matrix[1][1]==' '){
			matrix[1][1]='O';
			return;
		}
		else if(matrix[0][0]==' '){
			matrix[0][0]='O';
			return;
		}
	}
	
		// Finalisasi dengan mengisi random di sekitar 'X' yang sudah ada
	for(i=0;i<7;i++){
		for(j=0;j<7;j++){
			if(matrix[i][j]=='X'){

				if(matrix[i][--j]==' '){
					matrix[i][j]='O';
					return;
				}

				else if(matrix[i][++j]==' '){
					matrix[i][j]='O';
					return;
				}
				else if(matrix[++i][j]==' '){
					matrix[i][j]='O';
					return;
				}

				else if(matrix[--i][j]==' '){
					matrix[i][j]='O';
					return;
				}

			}
		}
	}
		// Finalisasi dengan mengisi yang masih kosong	
	for(i=0;i<7;i++){
		for(j=0;j<7;j++){
			if(matrix[i][j] = ' '){
				matrix[i][j]='O';
				return;
			}
		}
	}
 }
 
 /*******************************************************************
PROCEDURE FOR COMPUTER MOVE 7X7 WITH 'O' NORMAL LEVEL
 ********************************************************************/
 
 void computer_move_2_7X7(){
 	int i,j;
 	
 	//row checking jika 4 berturut=turut 
    
    	// Jika isi dari array index ke-1, ke-2, ke-3 dan ke-4 adalah 'O' atau 'X', maka array index ke-5, ke-6, dan ke-7 isi 'O'
	for(i=0;i<7;i++){
		if(((matrix[i][0]==matrix[i][1]) && (matrix[i][1]==matrix[i][2]) && (matrix[i][2]==matrix[i][3])) && matrix[i][0] != ' '){									
			if(matrix[i][4]==' '){
				matrix[i][4]='O';
				return;
			}
			else if(matrix[i][5]==' '){
				matrix[i][5]='O';
				return;
			}
			else if(matrix[i][6]==' '){
				matrix[i][6]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-2, ke-3, ke-4 dan ke-5 adalah 'O' atau 'X', maka array index ke-1, ke-6, dan ke-7 isi 'O'
	for(i=0;i<7;i++){
		if(((matrix[i][1]==matrix[i][2]) && (matrix[i][2]==matrix[i][3]) && (matrix[i][3]==matrix[i][4])) && matrix[i][1] != ' '){									
			if(matrix[i][0]==' '){
				matrix[i][0]='O';
				return;
			}
			else if(matrix[i][5]==' '){
				matrix[i][5]='O';
				return;
			}
			else if(matrix[i][6]==' '){
				matrix[i][6]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-3, ke-4, ke-5 dan ke-6 adalah 'O' atau 'X', maka array index ke-1, ke-2, dan ke-7 isi 'O'
	for(i=0;i<7;i++){
		if(((matrix[i][2]==matrix[i][3]) && (matrix[i][3]==matrix[i][4]) && (matrix[i][4]==matrix[i][5])) && matrix[i][2] != ' '){									
			if(matrix[i][0]==' '){
				matrix[i][0]='O';
				return;
			}
			else if(matrix[i][1]==' '){
				matrix[i][1]='O';
				return;
			}
			else if(matrix[i][6]==' '){
				matrix[i][6]='O';
				return;
			}
		}
	}
		
		// Jika isi dari array index ke-4, ke-5, ke-6 dan ke-7 adalah 'O' atau 'X', maka array index ke-1, ke-2, dan ke-3 isi 'O'
	for(i=0;i<7;i++){
		if(((matrix[i][3]==matrix[i][4]) && (matrix[i][4]==matrix[i][5]) && (matrix[i][5]==matrix[i][6])) && matrix[i][3] != ' '){									
			if(matrix[i][0]==' '){
				matrix[i][0]='O';
				return;
			}
			else if(matrix[i][1]==' '){
				matrix[i][1]='O';
				return;
			}
			else if(matrix[i][2]==' '){
				matrix[i][2]='O';
				return;
			}
		}
	}
	
	// Column Checking jika 4 berturut-turut
	
		// Jika isi dari array index ke-1, ke-2, ke-3 dan ke-4 adalah 'O' atau 'X', maka array index ke-5, ke-6, dan ke-7 isi 'O'
	for(i=0;i<7;i++){
		if(((matrix[0][i]==matrix[1][i]) && (matrix[1][i]==matrix[2][i]) && (matrix[2][i]==matrix[3][i])) && matrix[0][i] != ' '){									
			if(matrix[4][i]==' '){
				matrix[4][i]='O';
				return;
			}
			else if(matrix[5][i]==' '){
				matrix[5][i]='O';
				return;
			}
			else if(matrix[6][i]==' '){
				matrix[6][i]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-2, ke-3, ke-4 dan ke-5 adalah 'O' atau 'X', maka array index ke-1, ke-6, dan ke-7 isi 'O'
	for(i=0;i<7;i++){
		if(((matrix[1][i]==matrix[2][i]) && (matrix[2][i]==matrix[3][i]) && (matrix[3][i]==matrix[4][i])) && matrix[1][i] != ' '){
			if(matrix[0][i]==' '){
				matrix[0][i]='O';
				return;
			}
			else if(matrix[5][i]==' '){
				matrix[5][i]='O';
				return;
			}
			else if(matrix[6][i]==' '){
				matrix[6][i]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-3, ke-4, ke-5 dan ke-6 adalah 'O' atau 'X', maka array index ke-1, ke-2, dan ke-7 isi 'O'
	for(i=0;i<7;i++){
		if(((matrix[2][i]==matrix[3][i]) && (matrix[3][i]==matrix[4][i]) && (matrix[4][i]==matrix[5][i])) && matrix[2][i] != ' '){
			if(matrix[0][i]==' '){
				matrix[0][i]='O';
				return;
			}
			else if(matrix[1][i]==' '){
				matrix[1][i]='O';
				return;
			}
			else if(matrix[6][i]==' '){
				matrix[6][i]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-4, ke-5, ke-6 dan ke-7 adalah 'O' atau 'X', maka array index ke-1, ke-2, dan ke-3 isi 'O'
	for(i=0;i<7;i++){
		if(((matrix[3][i]==matrix[4][i]) && (matrix[4][i]==matrix[5][i]) && (matrix[5][i]==matrix[6][i])) && matrix[3][i] != ' '){
			if(matrix[0][i]==' '){
				matrix[0][i]='O';
				return;
			}
			else if(matrix[1][i]==' '){
				matrix[1][i]='O';
				return;
			}
			else if(matrix[2][i]==' '){
				matrix[2][i]='O';
				return;
			}
		}
	}
	
	// Diagonal Checking jika sudah 4 berturut-turut
		// kanan ke kiri
		// warna merah sesuai dengan tracing
	if(((matrix[4][0]==matrix[3][1]) && (matrix[3][1]==matrix[2][2]) && (matrix[2][2]==matrix[1][3])) && matrix[4][0] != ' '){
		if(matrix[0][4]==' '){
			matrix[0][4]='O';
			return;
		}
	}
	
	if(((matrix[3][1]==matrix[2][2]) && (matrix[2][2]==matrix[1][3]) && (matrix[1][3]==matrix[0][4])) && matrix[3][1] != ' '){
		if(matrix[4][0]==' '){
			matrix[4][0]='O';
			return;
		}
	}
	
	if(((matrix[6][2]==matrix[5][3]) && (matrix[5][3]==matrix[4][4]) && (matrix[4][4]==matrix[3][5])) && matrix[6][2] != ' '){
		if(matrix[2][6]==' '){
			matrix[2][6]='O';
			return;
		}
	}
	
	if(((matrix[5][3]==matrix[4][4]) && (matrix[4][4]==matrix[3][5]) && (matrix[3][5]==matrix[2][6])) && matrix[5][3] != ' '){
		if(matrix[6][2]==' '){
			matrix[6][2]='O';
			return;
		}
	}
		// Warna hijau sesuai dengan tracing
	if(((matrix[5][0]==matrix[4][1]) && (matrix[4][1]==matrix[3][2]) && (matrix[3][2]==matrix[2][3])) && matrix[5][0] != ' '){
		if(matrix[1][4]==' '){
			matrix[1][4]='O';
			return;
		}
		else if(matrix[0][5]==' '){
			matrix[0][5]='O';
			return;
		}
	}
	
	if(((matrix[4][1]==matrix[3][2]) && (matrix[3][2]==matrix[2][3]) && (matrix[2][3]==matrix[1][4])) && matrix[4][1] != ' '){
		if(matrix[0][5]==' '){
			matrix[0][5]='O';
			return;
		}
		else if(matrix[5][0]==' '){
			matrix[5][0]='O';
			return;
		}
	}
	
	if(((matrix[3][2]==matrix[2][3]) && (matrix[2][3]==matrix[1][4]) && (matrix[1][4]==matrix[0][5])) && matrix[3][2] != ' '){
		if(matrix[4][1]==' '){
			matrix[4][1]='O';
			return;
		}
		else if(matrix[5][0]==' '){
			matrix[5][0]='O';
			return;
		}
	}
	
	if(((matrix[6][1]==matrix[5][2]) && (matrix[5][2]==matrix[4][3]) && (matrix[4][3]==matrix[3][4])) && matrix[6][1] != ' '){
		if(matrix[2][5]==' '){
			matrix[2][5]='O';
			return;
		}
		else if(matrix[1][6]==' '){
			matrix[1][6]='O';
			return;
		}
	}
	
	if(((matrix[5][2]==matrix[4][3]) && (matrix[4][3]==matrix[3][4]) && (matrix[3][4]==matrix[2][5])) && matrix[5][2] != ' '){
		if(matrix[1][6]==' '){
			matrix[1][6]='O';
			return;
		}
		else if(matrix[6][1]==' '){
			matrix[6][1]='O';
			return;
		}
	}
	
	if(((matrix[4][3]==matrix[3][4]) && (matrix[3][4]==matrix[2][5]) && (matrix[2][5]==matrix[1][6])) && matrix[4][3] != ' '){
		if(matrix[5][2]==' '){
			matrix[5][2]='O';
			return;
		}
		else if(matrix[6][1]==' '){
			matrix[6][1]='O';
			return;
		}
	}
		// Warna kuning sesuai dengan tracing
	if(((matrix[6][0]==matrix[5][1]) && (matrix[5][1]==matrix[4][2]) && (matrix[4][2]==matrix[3][3])) && matrix[6][0] != ' '){
		if(matrix[2][4]==' '){
			matrix[2][4]='O';
			return;
		}
		else if(matrix[1][5]==' '){
			matrix[1][5]='O';
			return;
		}
		else if(matrix[0][6]==' '){
			matrix[0][6]='O';
			return;
		}
	}
	
	if(((matrix[5][1]==matrix[4][2]) && (matrix[4][2]==matrix[3][3]) && (matrix[3][3]==matrix[2][4])) && matrix[5][1] != ' '){
		if(matrix[1][5]==' '){
			matrix[1][5]='O';
			return;
		}
		else if(matrix[0][6]==' '){
			matrix[0][6]='O';
			return;
		}
		else if(matrix[6][0]==' '){
			matrix[6][0]='O';
			return;
		}
	}
	
	if(((matrix[4][2]==matrix[3][3]) && (matrix[3][3]==matrix[2][4]) && (matrix[2][4]==matrix[1][5])) && matrix[4][2] != ' '){
		if(matrix[5][1]==' '){
			matrix[5][1]='O';
			return;
		}
		else if(matrix[0][6]==' '){
			matrix[0][6]='O';
			return;
		}
		else if(matrix[6][0]==' '){
			matrix[6][0]='O';
			return;
		}
	}	
	
	if(((matrix[3][3]==matrix[2][4]) && (matrix[2][4]==matrix[1][5]) && (matrix[1][5]==matrix[0][6])) && matrix[3][3] != ' '){
		if(matrix[5][1]==' '){
			matrix[5][1]='O';
			return;
		}
		else if(matrix[4][2]==' '){
			matrix[4][2]='O';
			return;
		}
		else if(matrix[6][0]==' '){
			matrix[6][0]='O';
			return;
		}
	}
	
		// kiri ke kanan
		// warna merah sesuai dengan tracing
	if(((matrix[2][0]==matrix[3][1]) && (matrix[3][1]==matrix[4][2]) && (matrix[4][2]==matrix[5][3])) && matrix[2][0] != ' '){
		if(matrix[6][4]==' '){
			matrix[6][4]='O';
			return;
		}
	}
	
	if(((matrix[3][1]==matrix[4][2]) && (matrix[4][2]==matrix[5][3]) && (matrix[5][3]==matrix[6][4])) && matrix[3][1] != ' '){
		if(matrix[2][0]==' '){
			matrix[2][0]='O';
			return;
		}
	}
	
	if(((matrix[0][2]==matrix[1][3]) && (matrix[1][3]==matrix[2][4]) && (matrix[2][4]==matrix[3][5])) && matrix[0][2] != ' '){
		if(matrix[4][6]==' '){
			matrix[4][6]='O';
			return;
		}
	}
	
	if(((matrix[1][3]==matrix[2][4]) && (matrix[2][4]==matrix[3][5]) && (matrix[3][5]==matrix[4][6])) && matrix[1][3] != ' '){
		if(matrix[0][2]==' '){
			matrix[0][2]='O';
			return;
		}
	}
		// Warna hijau sesuai dengan tracing
	if(((matrix[1][0]==matrix[2][1]) && (matrix[2][1]==matrix[3][2]) && (matrix[3][2]==matrix[4][3])) && matrix[1][0] != ' '){
		if(matrix[5][4]==' '){
			matrix[5][4]='O';
			return;
		}
		else if(matrix[6][5]==' '){
			matrix[6][5]='O';
			return;
		}
	}
	
	if(((matrix[2][1]==matrix[3][2]) && (matrix[3][2]==matrix[4][3]) && (matrix[4][3]==matrix[5][4])) && matrix[2][1] != ' '){
		if(matrix[6][5]==' '){
			matrix[6][5]='O';
			return;
		}
		else if(matrix[1][0]==' '){
			matrix[1][0]='O';
			return;
		}
	}
	
	if(((matrix[3][2]==matrix[4][3]) && (matrix[4][3]==matrix[5][4]) && (matrix[5][4]==matrix[6][5])) && matrix[3][2] != ' '){
		if(matrix[2][1]==' '){
			matrix[2][1]='O';
			return;
		}
		else if(matrix[1][0]==' '){
			matrix[1][0]='O';
			return;
		}
	}
	
	if(((matrix[0][1]==matrix[1][2]) && (matrix[1][2]==matrix[2][3]) && (matrix[2][3]==matrix[3][4])) && matrix[0][1] != ' '){
		if(matrix[4][5]==' '){
			matrix[4][5]='O';
			return;
		}
		else if(matrix[5][6]==' '){
			matrix[5][6]='O';
			return;
		}
	}
	
	if(((matrix[1][2]==matrix[2][3]) && (matrix[2][3]==matrix[3][4]) && (matrix[3][4]==matrix[4][5])) && matrix[1][2] != ' '){
		if(matrix[5][6]==' '){
			matrix[5][6]='O';
			return;
		}
		else if(matrix[0][1]==' '){
			matrix[0][1]='O';
			return;
		}
	}
	
	if(((matrix[2][3]==matrix[3][4]) && (matrix[3][4]==matrix[4][5]) && (matrix[4][5]==matrix[5][6])) && matrix[2][3] != ' '){
		if(matrix[1][2]==' '){
			matrix[1][2]='O';
			return;
		}
		else if(matrix[0][1]==' '){
			matrix[0][1]='O';
			return;
		}
	}
		// Warna kuning sesuai dengan tracing
	if(((matrix[0][0]==matrix[1][1]) && (matrix[1][1]==matrix[2][2]) && (matrix[2][2]==matrix[3][3])) && matrix[0][0] != ' '){
		if(matrix[4][4]==' '){
			matrix[4][4]='O';
			return;
		}
		else if(matrix[5][5]==' '){
			matrix[5][5]='O';
			return;
		}
		else if(matrix[6][6]==' '){
			matrix[6][6]='O';
			return;
		}
	}
	
	if(((matrix[1][1]==matrix[2][2]) && (matrix[2][2]==matrix[3][3]) && (matrix[3][3]==matrix[4][4])) && matrix[1][1] != ' '){
		if(matrix[5][5]==' '){
			matrix[5][5]='O';
			return;
		}
		else if(matrix[0][0]==' '){
			matrix[0][0]='O';
			return;
		}
		else if(matrix[6][6]==' '){
			matrix[6][6]='O';
			return;
		}
	}
	
	if(((matrix[2][2]==matrix[3][3]) && (matrix[3][3]==matrix[4][4]) && (matrix[4][4]==matrix[5][5])) && matrix[2][2] != ' '){
		if(matrix[1][1]==' '){
			matrix[1][1]='O';
			return;
		}
		else if(matrix[6][6]==' '){
			matrix[6][6]='O';
			return;
		}
		else if(matrix[0][0]==' '){
			matrix[0][0]='O';
			return;
		}
	}	
	
	if(((matrix[3][3]==matrix[4][4]) && (matrix[4][4]==matrix[5][5]) && (matrix[5][5]==matrix[6][6])) && matrix[3][3] != ' '){
		if(matrix[2][2]==' '){
			matrix[2][2]='O';
			return;
		}
		else if(matrix[1][1]==' '){
			matrix[1][1]='O';
			return;
		}
		else if(matrix[0][0]==' '){
			matrix[0][0]='O';
			return;
		}
	}
	
	//row checking jika 3 berturut-turut
    
    	// Jika isi dari array index ke-1, ke-2 dan ke-3 adalah 'O' atau 'X', maka array index ke-4 isi 'O'
	for(i=0;i<7;i++){
		if(((matrix[i][0]==matrix[i][1]) && (matrix[i][1]==matrix[i][2])) && matrix[i][0] != ' '){									
			if(matrix[i][3]==' '){
				matrix[i][3]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-2, ke-3 dan ke-4 adalah 'O' atau 'X', maka array index ke-1 dan ke-5 isi 'O'
	for(i=0;i<7;i++){
		if(((matrix[i][1]==matrix[i][2]) && (matrix[i][2]==matrix[i][3])) && matrix[i][1] != ' '){									
			if(matrix[i][0]==' '){
				matrix[i][0]='O';
				return;
			}
			else if(matrix[i][4]==' '){
				matrix[i][4]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-3, ke-4 dan ke-5 adalah 'O' atau 'X', maka array index ke-2 dan ke-6 isi 'O'
	for(i=0;i<7;i++){
		if(((matrix[i][2]==matrix[i][3]) && (matrix[i][3]==matrix[i][4])) && matrix[i][2] != ' '){									
			if(matrix[i][1]==' '){
				matrix[i][1]='O';
				return;
			}
			else if(matrix[i][5]==' '){
				matrix[i][5]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-4, ke-5 dan ke-6 adalah 'O' atau 'X', maka array index ke-3 dan ke-7 isi 'O'
	for(i=0;i<7;i++){
		if(((matrix[i][3]==matrix[i][4]) && (matrix[i][4]==matrix[i][5])) && matrix[i][3] != ' '){									
			if(matrix[i][2]==' '){
				matrix[i][2]='O';
				return;
			}
			else if(matrix[i][6]==' '){
				matrix[i][6]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-5, ke-6 dan ke-7 adalah 'O' atau 'X', maka array index ke-4 isi 'O'
	for(i=0;i<7;i++){
		if(((matrix[i][4]==matrix[i][5]) && (matrix[i][5]==matrix[i][6])) && matrix[i][4] != ' '){									
			if(matrix[i][3]==' '){
				matrix[i][3]='O';
				return;
			}
		}
	}
	
	 //column checking jika 3 berturut-turut
    
    	// Jika isi dari array index ke-1, ke-2 dan ke-3 adalah 'O' atau 'X', maka array index ke-4 isi 'O'
	for(i=0;i<7;i++){
		if(((matrix[0][i]==matrix[1][i]) && (matrix[1][i]==matrix[2][i])) && matrix[0][i] != ' '){									
			if(matrix[3][i]==' '){
				matrix[3][i]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-2, ke-3 dan ke-4 adalah 'O' atau 'X', maka array index ke-1 dan ke-5 isi 'O'
	for(i=0;i<7;i++){
		if(((matrix[1][i]==matrix[2][i]) && (matrix[2][i]==matrix[3][i])) && matrix[1][i] != ' '){									
			if(matrix[0][i]==' '){
				matrix[0][i]='O';
				return;
			}
			else if(matrix[4][i]==' '){
				matrix[4][i]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-3, ke-4 dan ke-5 adalah 'O' atau 'X', maka array index ke-2 dan ke-6 isi 'O'
	for(i=0;i<7;i++){
		if(((matrix[2][i]==matrix[3][i]) && (matrix[3][i]==matrix[4][i])) && matrix[2][i] != ' '){									
			if(matrix[1][i]==' '){
				matrix[1][i]='O';
				return;
			}
			else if(matrix[5][i]==' '){
				matrix[5][i]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-4, ke-5 dan ke-6 adalah 'O' atau 'X', maka array index ke-3 dan ke-7 isi 'O'
	for(i=0;i<7;i++){
		if(((matrix[3][i]==matrix[4][i]) && (matrix[4][i]==matrix[5][i])) && matrix[3][i] != ' '){									
			if(matrix[2][i]==' '){
				matrix[2][i]='O';
				return;
			}
			else if(matrix[6][i]==' '){
				matrix[6][i]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-5, ke-6 dan ke-7 adalah 'O' atau 'X', maka array index ke-3 isi 'O'
	for(i=0;i<7;i++){
		if(((matrix[4][i]==matrix[5][i]) && (matrix[5][i]==matrix[6][i])) && matrix[4][i] != ' '){									
			if(matrix[3][i]==' '){
				matrix[3][i]='O';
				return;
			}
		}
	}
	
	//Diagonal checking jika 3 berturut-turut
    	// kiri ke kanan
    	//Warna pink sesuai tracing
    if(((matrix[2][0]==matrix[3][1]) && (matrix[3][1]==matrix[4][2])) && matrix[2][0] != ' '){
		if(matrix[5][3]==' '){
			matrix[5][3]='O';
			return;
		}
	}
	
	if(((matrix[3][1]==matrix[4][2]) && (matrix[4][2]==matrix[5][3])) && matrix[3][1] != ' '){
		if(matrix[2][0]==' '){
			matrix[2][0]='O';
			return;
		}
		else if(matrix[6][4]==' '){
			matrix[6][4]='O';
			return;
		}
	}
	
	if(((matrix[4][2]==matrix[5][3]) && (matrix[5][3]==matrix[6][4])) && matrix[4][2] != ' '){
		if(matrix[3][1]==' '){
			matrix[3][1]='O';
			return;
		}
	}
		//---
	if(((matrix[0][2]==matrix[1][3]) && (matrix[1][3]==matrix[2][4])) && matrix[0][2] != ' '){
		if(matrix[3][5]==' '){
			matrix[3][5]='O';
			return;
		}
	}
	
	if(((matrix[1][3]==matrix[2][4]) && (matrix[2][4]==matrix[3][5])) && matrix[1][3] != ' '){
		if(matrix[0][2]==' '){
			matrix[0][2]='O';
			return;
		}
		else if(matrix[4][6]==' '){
			matrix[4][6]='O';
			return;
		}
	}
	
	if(((matrix[2][4]==matrix[3][5]) && (matrix[3][5]==matrix[4][6])) && matrix[2][4] != ' '){
		if(matrix[1][3]==' '){
			matrix[1][3]='O';
			return;
		}
	}
	
		// Warna kuning sesuai dengan tracing
	if(((matrix[1][0]==matrix[2][1]) && (matrix[2][1]==matrix[3][2])) && matrix[1][0] != ' '){
		if(matrix[4][3]==' '){
			matrix[4][3]='O';
			return;
		}
	}
	
	if(((matrix[2][1]==matrix[3][2]) && (matrix[3][2]==matrix[4][3])) && matrix[2][1] != ' '){
		if(matrix[1][0]==' '){
			matrix[1][0]='O';
			return;
		}
		else if(matrix[5][4]==' '){
			matrix[5][4]='O';
			return;
		}
	}
	
	if(((matrix[3][2]==matrix[4][3]) && (matrix[4][3]==matrix[5][4])) && matrix[3][2] != ' '){
		if(matrix[2][1]==' '){
			matrix[2][1]='O';
			return;
		}
		else if(matrix[6][5]==' '){
			matrix[6][5]='O';
			return;
		}
	}
	
	if(((matrix[4][3]==matrix[5][4]) && (matrix[5][4]==matrix[6][5])) && matrix[4][3] != ' '){
		if(matrix[3][2]==' '){
			matrix[3][2]='O';
			return;
		}
	}
	
		//---
	if(((matrix[0][1]==matrix[1][2]) && (matrix[1][2]==matrix[2][3])) && matrix[0][1] != ' '){
		if(matrix[3][4]==' '){
			matrix[3][4]='O';
			return;
		}
	}
	
	if(((matrix[1][2]==matrix[2][3]) && (matrix[2][3]==matrix[3][4])) && matrix[1][2] != ' '){
		if(matrix[0][1]==' '){
			matrix[0][1]='O';
			return;
		}
		else if(matrix[4][5]==' '){
			matrix[4][5]='O';
			return;
		}
	}
	
	if(((matrix[2][3]==matrix[3][4]) && (matrix[3][4]==matrix[4][5])) && matrix[2][3] != ' '){
		if(matrix[1][2]==' '){
			matrix[1][2]='O';
			return;
		}
		else if(matrix[5][6]==' '){
			matrix[5][6]='O';
			return;
		}
	}
	
	if(((matrix[3][4]==matrix[4][5]) && (matrix[4][5]==matrix[5][6])) && matrix[2][4] != ' '){
		if(matrix[2][3]==' '){
			matrix[1][2]='O';
			return;
		}
	}
	
		// Warna merah sesuai dengan tracing
	if(((matrix[0][0]==matrix[1][1]) && (matrix[1][1]==matrix[2][2])) && matrix[0][0] != ' '){
		if(matrix[3][3]==' '){
			matrix[3][3]='O';
			return;
		}
	}
	
	if(((matrix[1][1]==matrix[2][2]) && (matrix[2][2]==matrix[3][3])) && matrix[1][1] != ' '){
		if(matrix[0][0]==' '){
			matrix[0][0]='O';
			return;
		}
		else if(matrix[4][4]==' '){
			matrix[4][4]='O';
			return;
		}
	}
	
	if(((matrix[2][2]==matrix[3][3]) && (matrix[3][3]==matrix[4][4])) && matrix[2][2] != ' '){
		if(matrix[1][1]==' '){
			matrix[1][1]='O';
			return;
		}
		else if(matrix[5][5]==' '){
			matrix[5][5]='O';
			return;
		}
	}	
	
	if(((matrix[3][3]==matrix[4][4]) && (matrix[4][4]==matrix[5][5])) && matrix[3][3] != ' '){
		if(matrix[2][2]==' '){
			matrix[2][2]='O';
			return;
		}
		else if(matrix[6][6]==' '){
			matrix[6][6]='O';
			return;
		}
	}
		
	if(((matrix[4][4]==matrix[5][5]) && (matrix[5][5]==matrix[6][6])) && matrix[4][4] != ' '){
		if(matrix[3][3]==' '){
			matrix[3][3]='O';
			return;
		}
	}	
	
   		// kanan ke kiri
    	//Warna pink sesuai tracing
	if(((matrix[4][0]==matrix[3][1]) && (matrix[3][1]==matrix[2][2])) && matrix[4][0] != ' '){
		if(matrix[1][3]==' '){
			matrix[1][3]='O';
			return;
		}
	}
	
	if(((matrix[3][1]==matrix[2][2]) && (matrix[2][2]==matrix[1][3])) && matrix[3][1] != ' '){
		if(matrix[4][0]==' '){
			matrix[4][0]='O';
			return;
		}
		else if(matrix[0][4]==' '){
			matrix[0][4]='O';
			return;
		}
	}
	
	if(((matrix[2][2]==matrix[1][3]) && (matrix[1][3]==matrix[0][4])) && matrix[2][2] != ' '){
		if(matrix[3][1]==' '){
			matrix[3][1]='O';
			return;
		}
	}
		//---
	if(((matrix[6][2]==matrix[5][3]) && (matrix[5][3]==matrix[4][4])) && matrix[6][2] != ' '){
		if(matrix[3][5]==' '){
			matrix[3][5]='O';
			return;
		}
	}
		
	if(((matrix[5][3]==matrix[4][4]) && (matrix[4][4]==matrix[3][5])) && matrix[5][3] != ' '){
		if(matrix[6][2]==' '){
			matrix[6][2]='O';
			return;
		}
		else if(matrix[2][6]==' '){
			matrix[2][6]='O';
			return;
		}
	}
	
	if(((matrix[4][4]==matrix[3][5]) && (matrix[3][5]==matrix[2][6])) && matrix[4][4] != ' '){
		if(matrix[5][3]==' '){
			matrix[5][3]='O';
			return;
		}
	}
	
		// Warna kuning sesuai dengan tracing
	if(((matrix[5][0]==matrix[4][1]) && (matrix[4][1]==matrix[3][2])) && matrix[5][0] != ' '){
		if(matrix[2][3]==' '){
			matrix[2][3]='O';
			return;
		}
	}
	
	if(((matrix[4][1]==matrix[3][2]) && (matrix[3][2]==matrix[2][3])) && matrix[4][1] != ' '){
		if(matrix[5][0]==' '){
			matrix[5][0]='O';
			return;
		}
		else if(matrix[1][4]==' '){
			matrix[1][4]='O';
			return;
		}
	}
	
	if(((matrix[3][2]==matrix[2][3]) && (matrix[2][3]==matrix[1][4])) && matrix[3][2] != ' '){
		if(matrix[4][1]==' '){
			matrix[4][1]='O';
			return;
		}
		else if(matrix[0][5]==' '){
			matrix[0][5]='O';
			return;
		}
	}
	
	if(((matrix[2][3]==matrix[1][4]) && (matrix[1][4]==matrix[0][5])) && matrix[2][3] != ' '){
		if(matrix[3][2]==' '){
			matrix[3][2]='O';
			return;
		}
	}
		//---
	if(((matrix[6][1]==matrix[5][2]) && (matrix[5][2]==matrix[4][3])) && matrix[6][1] != ' '){
		if(matrix[3][4]==' '){
			matrix[3][4]='O';
			return;
		}
	}
	
	if(((matrix[5][2]==matrix[4][3]) && (matrix[4][3]==matrix[3][4])) && matrix[5][2] != ' '){
		if(matrix[6][1]==' '){
			matrix[6][1]='O';
			return;
		}
		else if(matrix[2][5]==' '){
			matrix[2][5]='O';
			return;
		}
	}
	
	if(((matrix[4][3]==matrix[3][4]) && (matrix[3][4]==matrix[2][5])) && matrix[4][3] != ' '){
		if(matrix[5][2]==' '){
			matrix[5][2]='O';
			return;
		}
		else if(matrix[3][4]==' '){
			matrix[3][4]='O';
			return;
		}
	}
	
	if(((matrix[3][4]==matrix[2][5]) && (matrix[2][5]==matrix[1][6])) && matrix[3][4] != ' '){
		if(matrix[4][3]==' '){
			matrix[4][3]='O';
			return;
		}
	}
	
		// Warna merah sesuai dengan tracing
	if(((matrix[6][0]==matrix[5][1]) && (matrix[5][1]==matrix[4][2])) && matrix[6][0] != ' '){
		if(matrix[3][3]==' '){
			matrix[3][3]='O';
			return;
		}
	}
	
	if(((matrix[5][1]==matrix[4][2]) && (matrix[4][2]==matrix[3][3])) && matrix[5][1] != ' '){
		if(matrix[6][0]==' '){
			matrix[6][0]='O';
			return;
		}
		else if(matrix[2][4]==' '){
			matrix[2][4]='O';
			return;
		}
	}
	
	if(((matrix[4][2]==matrix[3][3]) && (matrix[3][3]==matrix[2][4])) && matrix[4][2] != ' '){
		if(matrix[5][1]==' '){
			matrix[5][1]='O';
			return;
		}
		else if(matrix[1][5]==' '){
			matrix[1][5]='O';
			return;
		}
	}	
	
	if(((matrix[3][3]==matrix[2][4]) && (matrix[2][4]==matrix[1][5])) && matrix[3][3] != ' '){
		if(matrix[4][2]==' '){
			matrix[4][2]='O';
			return;
		}
		else if(matrix[0][6]==' '){
			matrix[0][6]='O';
			return;
		}
	}
	
	if(((matrix[2][4]==matrix[1][5]) && (matrix[1][5]==matrix[0][6])) && matrix[2][4] != ' '){
		if(matrix[3][3]==' '){
			matrix[3][3]='O';
			return;
		}
	}
	
		// Finalisasi dengan mengisi random di sekitar 'X' yang sudah ada
	for(i=0;i<7;i++){
		for(j=0;j<7;j++){
			if(matrix[i][j]=='X'){

				if(matrix[i][--j]==' '){
					matrix[i][j]='O';
					return;
				}

				else if(matrix[i][++j]==' '){
					matrix[i][j]='O';
					return;
				}
				else if(matrix[++i][j]==' '){
					matrix[i][j]='O';
					return;
				}

				else if(matrix[--i][j]==' '){
					matrix[i][j]='O';
					return;
				}

			}
		}
	}
		// Finalisasi dengan mengisi yang masih kosong	
	for(i=0;i<7;i++){
		for(j=0;j<7;j++){
			if(matrix[i][j] = ' '){
				matrix[i][j]='O';
				return;
			}
		}
	}
 }
 
/*******************************************************************
PROCEDURE FOR COMPUTER MOVE 7X7 WITH 'O' HARD LEVEL
 ********************************************************************/
 void computer_move_3_7X7(){
 	int i,j;
 	
 	//row checking jika 4 berturut=turut 
    
    	// Jika isi dari array index ke-1, ke-2, ke-3 dan ke-4 adalah 'O' atau 'X', maka array index ke-5, ke-6, dan ke-7 isi 'O'
	for(i=0;i<7;i++){
		if(((matrix[i][0]==matrix[i][1]) && (matrix[i][1]==matrix[i][2]) && (matrix[i][2]==matrix[i][3])) && matrix[i][0] != ' '){									
			if(matrix[i][4]==' '){
				matrix[i][4]='O';
				return;
			}
			else if(matrix[i][5]==' '){
				matrix[i][5]='O';
				return;
			}
			else if(matrix[i][6]==' '){
				matrix[i][6]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-2, ke-3, ke-4 dan ke-5 adalah 'O' atau 'X', maka array index ke-1, ke-6, dan ke-7 isi 'O'
	for(i=0;i<7;i++){
		if(((matrix[i][1]==matrix[i][2]) && (matrix[i][2]==matrix[i][3]) && (matrix[i][3]==matrix[i][4])) && matrix[i][1] != ' '){									
			if(matrix[i][0]==' '){
				matrix[i][0]='O';
				return;
			}
			else if(matrix[i][5]==' '){
				matrix[i][5]='O';
				return;
			}
			else if(matrix[i][6]==' '){
				matrix[i][6]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-3, ke-4, ke-5 dan ke-6 adalah 'O' atau 'X', maka array index ke-1, ke-2, dan ke-7 isi 'O'
	for(i=0;i<7;i++){
		if(((matrix[i][2]==matrix[i][3]) && (matrix[i][3]==matrix[i][4]) && (matrix[i][4]==matrix[i][5])) && matrix[i][2] != ' '){									
			if(matrix[i][0]==' '){
				matrix[i][0]='O';
				return;
			}
			else if(matrix[i][1]==' '){
				matrix[i][1]='O';
				return;
			}
			else if(matrix[i][6]==' '){
				matrix[i][6]='O';
				return;
			}
		}
	}
		
		// Jika isi dari array index ke-4, ke-5, ke-6 dan ke-7 adalah 'O' atau 'X', maka array index ke-1, ke-2, dan ke-3 isi 'O'
	for(i=0;i<7;i++){
		if(((matrix[i][3]==matrix[i][4]) && (matrix[i][4]==matrix[i][5]) && (matrix[i][5]==matrix[i][6])) && matrix[i][3] != ' '){									
			if(matrix[i][0]==' '){
				matrix[i][0]='O';
				return;
			}
			else if(matrix[i][1]==' '){
				matrix[i][1]='O';
				return;
			}
			else if(matrix[i][2]==' '){
				matrix[i][2]='O';
				return;
			}
		}
	}
	
	// Column Checking jika 4 berturut-turut
	
		// Jika isi dari array index ke-1, ke-2, ke-3 dan ke-4 adalah 'O' atau 'X', maka array index ke-5, ke-6, dan ke-7 isi 'O'
	for(i=0;i<7;i++){
		if(((matrix[0][i]==matrix[1][i]) && (matrix[1][i]==matrix[2][i]) && (matrix[2][i]==matrix[3][i])) && matrix[0][i] != ' '){									
			if(matrix[4][i]==' '){
				matrix[4][i]='O';
				return;
			}
			else if(matrix[5][i]==' '){
				matrix[5][i]='O';
				return;
			}
			else if(matrix[6][i]==' '){
				matrix[6][i]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-2, ke-3, ke-4 dan ke-5 adalah 'O' atau 'X', maka array index ke-1, ke-6, dan ke-7 isi 'O'
	for(i=0;i<7;i++){
		if(((matrix[1][i]==matrix[2][i]) && (matrix[2][i]==matrix[3][i]) && (matrix[3][i]==matrix[4][i])) && matrix[1][i] != ' '){
			if(matrix[0][i]==' '){
				matrix[0][i]='O';
				return;
			}
			else if(matrix[5][i]==' '){
				matrix[5][i]='O';
				return;
			}
			else if(matrix[6][i]==' '){
				matrix[6][i]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-3, ke-4, ke-5 dan ke-6 adalah 'O' atau 'X', maka array index ke-1, ke-2, dan ke-7 isi 'O'
	for(i=0;i<7;i++){
		if(((matrix[2][i]==matrix[3][i]) && (matrix[3][i]==matrix[4][i]) && (matrix[4][i]==matrix[5][i])) && matrix[2][i] != ' '){
			if(matrix[0][i]==' '){
				matrix[0][i]='O';
				return;
			}
			else if(matrix[1][i]==' '){
				matrix[1][i]='O';
				return;
			}
			else if(matrix[6][i]==' '){
				matrix[6][i]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-4, ke-5, ke-6 dan ke-7 adalah 'O' atau 'X', maka array index ke-1, ke-2, dan ke-3 isi 'O'
	for(i=0;i<7;i++){
		if(((matrix[3][i]==matrix[4][i]) && (matrix[4][i]==matrix[5][i]) && (matrix[5][i]==matrix[6][i])) && matrix[3][i] != ' '){
			if(matrix[0][i]==' '){
				matrix[0][i]='O';
				return;
			}
			else if(matrix[1][i]==' '){
				matrix[1][i]='O';
				return;
			}
			else if(matrix[2][i]==' '){
				matrix[2][i]='O';
				return;
			}
		}
	}
	
	// Diagonal Checking jika sudah 4 berturut-turut
		// kanan ke kiri
		// warna merah sesuai dengan tracing
	if(((matrix[4][0]==matrix[3][1]) && (matrix[3][1]==matrix[2][2]) && (matrix[2][2]==matrix[1][3])) && matrix[4][0] != ' '){
		if(matrix[0][4]==' '){
			matrix[0][4]='O';
			return;
		}
	}
	
	if(((matrix[3][1]==matrix[2][2]) && (matrix[2][2]==matrix[1][3]) && (matrix[1][3]==matrix[0][4])) && matrix[3][1] != ' '){
		if(matrix[4][0]==' '){
			matrix[4][0]='O';
			return;
		}
	}
	
	if(((matrix[6][2]==matrix[5][3]) && (matrix[5][3]==matrix[4][4]) && (matrix[4][4]==matrix[3][5])) && matrix[6][2] != ' '){
		if(matrix[2][6]==' '){
			matrix[2][6]='O';
			return;
		}
	}
	
	if(((matrix[5][3]==matrix[4][4]) && (matrix[4][4]==matrix[3][5]) && (matrix[3][5]==matrix[2][6])) && matrix[5][3] != ' '){
		if(matrix[6][2]==' '){
			matrix[6][2]='O';
			return;
		}
	}
		// Warna hijau sesuai dengan tracing
	if(((matrix[5][0]==matrix[4][1]) && (matrix[4][1]==matrix[3][2]) && (matrix[3][2]==matrix[2][3])) && matrix[5][0] != ' '){
		if(matrix[1][4]==' '){
			matrix[1][4]='O';
			return;
		}
		else if(matrix[0][5]==' '){
			matrix[0][5]='O';
			return;
		}
	}
	
	if(((matrix[4][1]==matrix[3][2]) && (matrix[3][2]==matrix[2][3]) && (matrix[2][3]==matrix[1][4])) && matrix[4][1] != ' '){
		if(matrix[0][5]==' '){
			matrix[0][5]='O';
			return;
		}
		else if(matrix[5][0]==' '){
			matrix[5][0]='O';
			return;
		}
	}
	
	if(((matrix[3][2]==matrix[2][3]) && (matrix[2][3]==matrix[1][4]) && (matrix[1][4]==matrix[0][5])) && matrix[3][2] != ' '){
		if(matrix[4][1]==' '){
			matrix[4][1]='O';
			return;
		}
		else if(matrix[5][0]==' '){
			matrix[5][0]='O';
			return;
		}
	}
	
	if(((matrix[6][1]==matrix[5][2]) && (matrix[5][2]==matrix[4][3]) && (matrix[4][3]==matrix[3][4])) && matrix[6][1] != ' '){
		if(matrix[2][5]==' '){
			matrix[2][5]='O';
			return;
		}
		else if(matrix[1][6]==' '){
			matrix[1][6]='O';
			return;
		}
	}
	
	if(((matrix[5][2]==matrix[4][3]) && (matrix[4][3]==matrix[3][4]) && (matrix[3][4]==matrix[2][5])) && matrix[5][2] != ' '){
		if(matrix[1][6]==' '){
			matrix[1][6]='O';
			return;
		}
		else if(matrix[6][1]==' '){
			matrix[6][1]='O';
			return;
		}
	}
	
	if(((matrix[4][3]==matrix[3][4]) && (matrix[3][4]==matrix[2][5]) && (matrix[2][5]==matrix[1][6])) && matrix[4][3] != ' '){
		if(matrix[5][2]==' '){
			matrix[5][2]='O';
			return;
		}
		else if(matrix[6][1]==' '){
			matrix[6][1]='O';
			return;
		}
	}
		// Warna kuning sesuai dengan tracing
	if(((matrix[6][0]==matrix[5][1]) && (matrix[5][1]==matrix[4][2]) && (matrix[4][2]==matrix[3][3])) && matrix[6][0] != ' '){
		if(matrix[2][4]==' '){
			matrix[2][4]='O';
			return;
		}
		else if(matrix[1][5]==' '){
			matrix[1][5]='O';
			return;
		}
		else if(matrix[0][6]==' '){
			matrix[0][6]='O';
			return;
		}
	}
	
	if(((matrix[5][1]==matrix[4][2]) && (matrix[4][2]==matrix[3][3]) && (matrix[3][3]==matrix[2][4])) && matrix[5][1] != ' '){
		if(matrix[1][5]==' '){
			matrix[1][5]='O';
			return;
		}
		else if(matrix[0][6]==' '){
			matrix[0][6]='O';
			return;
		}
		else if(matrix[6][0]==' '){
			matrix[6][0]='O';
			return;
		}
	}
	
	if(((matrix[4][2]==matrix[3][3]) && (matrix[3][3]==matrix[2][4]) && (matrix[2][4]==matrix[1][5])) && matrix[4][2] != ' '){
		if(matrix[5][1]==' '){
			matrix[5][1]='O';
			return;
		}
		else if(matrix[0][6]==' '){
			matrix[0][6]='O';
			return;
		}
		else if(matrix[6][0]==' '){
			matrix[6][0]='O';
			return;
		}
	}	
	
	if(((matrix[3][3]==matrix[2][4]) && (matrix[2][4]==matrix[1][5]) && (matrix[1][5]==matrix[0][6])) && matrix[3][3] != ' '){
		if(matrix[5][1]==' '){
			matrix[5][1]='O';
			return;
		}
		else if(matrix[4][2]==' '){
			matrix[4][2]='O';
			return;
		}
		else if(matrix[6][0]==' '){
			matrix[6][0]='O';
			return;
		}
	}
	
		// kiri ke kanan
		// warna merah sesuai dengan tracing
	if(((matrix[2][0]==matrix[3][1]) && (matrix[3][1]==matrix[4][2]) && (matrix[4][2]==matrix[5][3])) && matrix[2][0] != ' '){
		if(matrix[6][4]==' '){
			matrix[6][4]='O';
			return;
		}
	}
	
	if(((matrix[3][1]==matrix[4][2]) && (matrix[4][2]==matrix[5][3]) && (matrix[5][3]==matrix[6][4])) && matrix[3][1] != ' '){
		if(matrix[2][0]==' '){
			matrix[2][0]='O';
			return;
		}
	}
	
	if(((matrix[0][2]==matrix[1][3]) && (matrix[1][3]==matrix[2][4]) && (matrix[2][4]==matrix[3][5])) && matrix[0][2] != ' '){
		if(matrix[4][6]==' '){
			matrix[4][6]='O';
			return;
		}
	}
	
	if(((matrix[1][3]==matrix[2][4]) && (matrix[2][4]==matrix[3][5]) && (matrix[3][5]==matrix[4][6])) && matrix[1][3] != ' '){
		if(matrix[0][2]==' '){
			matrix[0][2]='O';
			return;
		}
	}
		// Warna hijau sesuai dengan tracing
	if(((matrix[1][0]==matrix[2][1]) && (matrix[2][1]==matrix[3][2]) && (matrix[3][2]==matrix[4][3])) && matrix[1][0] != ' '){
		if(matrix[5][4]==' '){
			matrix[5][4]='O';
			return;
		}
		else if(matrix[6][5]==' '){
			matrix[6][5]='O';
			return;
		}
	}
	
	if(((matrix[2][1]==matrix[3][2]) && (matrix[3][2]==matrix[4][3]) && (matrix[4][3]==matrix[5][4])) && matrix[2][1] != ' '){
		if(matrix[6][5]==' '){
			matrix[6][5]='O';
			return;
		}
		else if(matrix[1][0]==' '){
			matrix[1][0]='O';
			return;
		}
	}
	
	if(((matrix[3][2]==matrix[4][3]) && (matrix[4][3]==matrix[5][4]) && (matrix[5][4]==matrix[6][5])) && matrix[3][2] != ' '){
		if(matrix[2][1]==' '){
			matrix[2][1]='O';
			return;
		}
		else if(matrix[1][0]==' '){
			matrix[1][0]='O';
			return;
		}
	}
	
	if(((matrix[0][1]==matrix[1][2]) && (matrix[1][2]==matrix[2][3]) && (matrix[2][3]==matrix[3][4])) && matrix[0][1] != ' '){
		if(matrix[4][5]==' '){
			matrix[4][5]='O';
			return;
		}
		else if(matrix[5][6]==' '){
			matrix[5][6]='O';
			return;
		}
	}
	
	if(((matrix[1][2]==matrix[2][3]) && (matrix[2][3]==matrix[3][4]) && (matrix[3][4]==matrix[4][5])) && matrix[1][2] != ' '){
		if(matrix[5][6]==' '){
			matrix[5][6]='O';
			return;
		}
		else if(matrix[0][1]==' '){
			matrix[0][1]='O';
			return;
		}
	}
	
	if(((matrix[2][3]==matrix[3][4]) && (matrix[3][4]==matrix[4][5]) && (matrix[4][5]==matrix[5][6])) && matrix[2][3] != ' '){
		if(matrix[1][2]==' '){
			matrix[1][2]='O';
			return;
		}
		else if(matrix[0][1]==' '){
			matrix[0][1]='O';
			return;
		}
	}
		// Warna kuning sesuai dengan tracing
	if(((matrix[0][0]==matrix[1][1]) && (matrix[1][1]==matrix[2][2]) && (matrix[2][2]==matrix[3][3])) && matrix[0][0] != ' '){
		if(matrix[4][4]==' '){
			matrix[4][4]='O';
			return;
		}
		else if(matrix[5][5]==' '){
			matrix[5][5]='O';
			return;
		}
		else if(matrix[6][6]==' '){
			matrix[6][6]='O';
			return;
		}
	}
	
	if(((matrix[1][1]==matrix[2][2]) && (matrix[2][2]==matrix[3][3]) && (matrix[3][3]==matrix[4][4])) && matrix[1][1] != ' '){
		if(matrix[5][5]==' '){
			matrix[5][5]='O';
			return;
		}
		else if(matrix[0][0]==' '){
			matrix[0][0]='O';
			return;
		}
		else if(matrix[6][6]==' '){
			matrix[6][6]='O';
			return;
		}
	}
	
	if(((matrix[2][2]==matrix[3][3]) && (matrix[3][3]==matrix[4][4]) && (matrix[4][4]==matrix[5][5])) && matrix[2][2] != ' '){
		if(matrix[1][1]==' '){
			matrix[1][1]='O';
			return;
		}
		else if(matrix[6][6]==' '){
			matrix[6][6]='O';
			return;
		}
		else if(matrix[0][0]==' '){
			matrix[0][0]='O';
			return;
		}
	}	
	
	if(((matrix[3][3]==matrix[4][4]) && (matrix[4][4]==matrix[5][5]) && (matrix[5][5]==matrix[6][6])) && matrix[3][3] != ' '){
		if(matrix[2][2]==' '){
			matrix[2][2]='O';
			return;
		}
		else if(matrix[1][1]==' '){
			matrix[1][1]='O';
			return;
		}
		else if(matrix[0][0]==' '){
			matrix[0][0]='O';
			return;
		}
	}
	
	//row checking jika 3 berturut-turut
    
    	// Jika isi dari array index ke-1, ke-2 dan ke-3 adalah 'O' atau 'X', maka array index ke-4 isi 'O'
	for(i=0;i<7;i++){
		if(((matrix[i][0]==matrix[i][1]) && (matrix[i][1]==matrix[i][2])) && matrix[i][0] != ' '){									
			if(matrix[i][3]==' '){
				matrix[i][3]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-2, ke-3 dan ke-4 adalah 'O' atau 'X', maka array index ke-1 dan ke-5 isi 'O'
	for(i=0;i<7;i++){
		if(((matrix[i][1]==matrix[i][2]) && (matrix[i][2]==matrix[i][3])) && matrix[i][1] != ' '){									
			if(matrix[i][0]==' '){
				matrix[i][0]='O';
				return;
			}
			else if(matrix[i][4]==' '){
				matrix[i][4]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-3, ke-4 dan ke-5 adalah 'O' atau 'X', maka array index ke-2 dan ke-6 isi 'O'
	for(i=0;i<7;i++){
		if(((matrix[i][2]==matrix[i][3]) && (matrix[i][3]==matrix[i][4])) && matrix[i][2] != ' '){									
			if(matrix[i][1]==' '){
				matrix[i][1]='O';
				return;
			}
			else if(matrix[i][5]==' '){
				matrix[i][5]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-4, ke-5 dan ke-6 adalah 'O' atau 'X', maka array index ke-3 dan ke-7 isi 'O'
	for(i=0;i<7;i++){
		if(((matrix[i][3]==matrix[i][4]) && (matrix[i][4]==matrix[i][5])) && matrix[i][3] != ' '){									
			if(matrix[i][2]==' '){
				matrix[i][2]='O';
				return;
			}
			else if(matrix[i][6]==' '){
				matrix[i][6]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-5, ke-6 dan ke-7 adalah 'O' atau 'X', maka array index ke-4 isi 'O'
	for(i=0;i<7;i++){
		if(((matrix[i][4]==matrix[i][5]) && (matrix[i][5]==matrix[i][6])) && matrix[i][4] != ' '){									
			if(matrix[i][3]==' '){
				matrix[i][3]='O';
				return;
			}
		}
	}
	
	 //column checking jika 3 berturut-turut
    
    	// Jika isi dari array index ke-1, ke-2 dan ke-3 adalah 'O' atau 'X', maka array index ke-4 isi 'O'
	for(i=0;i<7;i++){
		if(((matrix[0][i]==matrix[1][i]) && (matrix[1][i]==matrix[2][i])) && matrix[0][i] != ' '){									
			if(matrix[3][i]==' '){
				matrix[3][i]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-2, ke-3 dan ke-4 adalah 'O' atau 'X', maka array index ke-1 dan ke-5 isi 'O'
	for(i=0;i<7;i++){
		if(((matrix[1][i]==matrix[2][i]) && (matrix[2][i]==matrix[3][i])) && matrix[1][i] != ' '){									
			if(matrix[0][i]==' '){
				matrix[0][i]='O';
				return;
			}
			else if(matrix[4][i]==' '){
				matrix[4][i]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-3, ke-4 dan ke-5 adalah 'O' atau 'X', maka array index ke-2 dan ke-6 isi 'O'
	for(i=0;i<7;i++){
		if(((matrix[2][i]==matrix[3][i]) && (matrix[3][i]==matrix[4][i])) && matrix[2][i] != ' '){									
			if(matrix[1][i]==' '){
				matrix[1][i]='O';
				return;
			}
			else if(matrix[5][i]==' '){
				matrix[5][i]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-4, ke-5 dan ke-6 adalah 'O' atau 'X', maka array index ke-3 dan ke-7 isi 'O'
	for(i=0;i<7;i++){
		if(((matrix[3][i]==matrix[4][i]) && (matrix[4][i]==matrix[5][i])) && matrix[3][i] != ' '){									
			if(matrix[2][i]==' '){
				matrix[2][i]='O';
				return;
			}
			else if(matrix[6][i]==' '){
				matrix[6][i]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-5, ke-6 dan ke-7 adalah 'O' atau 'X', maka array index ke-3 isi 'O'
	for(i=0;i<7;i++){
		if(((matrix[4][i]==matrix[5][i]) && (matrix[5][i]==matrix[6][i])) && matrix[4][i] != ' '){									
			if(matrix[3][i]==' '){
				matrix[3][i]='O';
				return;
			}
		}
	}
	
	//Diagonal checking jika 3 berturut-turut
    	// kiri ke kanan
    	//Warna pink sesuai tracing
    if(((matrix[2][0]==matrix[3][1]) && (matrix[3][1]==matrix[4][2])) && matrix[2][0] != ' '){
		if(matrix[5][3]==' '){
			matrix[5][3]='O';
			return;
		}
	}
	
	if(((matrix[3][1]==matrix[4][2]) && (matrix[4][2]==matrix[5][3])) && matrix[3][1] != ' '){
		if(matrix[2][0]==' '){
			matrix[2][0]='O';
			return;
		}
		else if(matrix[6][4]==' '){
			matrix[6][4]='O';
			return;
		}
	}
	
	if(((matrix[4][2]==matrix[5][3]) && (matrix[5][3]==matrix[6][4])) && matrix[4][2] != ' '){
		if(matrix[3][1]==' '){
			matrix[3][1]='O';
			return;
		}
	}
		//---
	if(((matrix[0][2]==matrix[1][3]) && (matrix[1][3]==matrix[2][4])) && matrix[0][2] != ' '){
		if(matrix[3][5]==' '){
			matrix[3][5]='O';
			return;
		}
	}
	
	if(((matrix[1][3]==matrix[2][4]) && (matrix[2][4]==matrix[3][5])) && matrix[1][3] != ' '){
		if(matrix[0][2]==' '){
			matrix[0][2]='O';
			return;
		}
		else if(matrix[4][6]==' '){
			matrix[4][6]='O';
			return;
		}
	}
	
	if(((matrix[2][4]==matrix[3][5]) && (matrix[3][5]==matrix[4][6])) && matrix[2][4] != ' '){
		if(matrix[1][3]==' '){
			matrix[1][3]='O';
			return;
		}
	}
	
		// Warna kuning sesuai dengan tracing
	if(((matrix[1][0]==matrix[2][1]) && (matrix[2][1]==matrix[3][2])) && matrix[1][0] != ' '){
		if(matrix[4][3]==' '){
			matrix[4][3]='O';
			return;
		}
	}
	
	if(((matrix[2][1]==matrix[3][2]) && (matrix[3][2]==matrix[4][3])) && matrix[2][1] != ' '){
		if(matrix[1][0]==' '){
			matrix[1][0]='O';
			return;
		}
		else if(matrix[5][4]==' '){
			matrix[5][4]='O';
			return;
		}
	}
	
	if(((matrix[3][2]==matrix[4][3]) && (matrix[4][3]==matrix[5][4])) && matrix[3][2] != ' '){
		if(matrix[2][1]==' '){
			matrix[2][1]='O';
			return;
		}
		else if(matrix[6][5]==' '){
			matrix[6][5]='O';
			return;
		}
	}
	
	if(((matrix[4][3]==matrix[5][4]) && (matrix[5][4]==matrix[6][5])) && matrix[4][3] != ' '){
		if(matrix[3][2]==' '){
			matrix[3][2]='O';
			return;
		}
	}
	
		//---
	if(((matrix[0][1]==matrix[1][2]) && (matrix[1][2]==matrix[2][3])) && matrix[0][1] != ' '){
		if(matrix[3][4]==' '){
			matrix[3][4]='O';
			return;
		}
	}
	
	if(((matrix[1][2]==matrix[2][3]) && (matrix[2][3]==matrix[3][4])) && matrix[1][2] != ' '){
		if(matrix[0][1]==' '){
			matrix[0][1]='O';
			return;
		}
		else if(matrix[4][5]==' '){
			matrix[4][5]='O';
			return;
		}
	}
	
	if(((matrix[2][3]==matrix[3][4]) && (matrix[3][4]==matrix[4][5])) && matrix[2][3] != ' '){
		if(matrix[1][2]==' '){
			matrix[1][2]='O';
			return;
		}
		else if(matrix[5][6]==' '){
			matrix[5][6]='O';
			return;
		}
	}
	
	if(((matrix[3][4]==matrix[4][5]) && (matrix[4][5]==matrix[5][6])) && matrix[2][4] != ' '){
		if(matrix[2][3]==' '){
			matrix[1][2]='O';
			return;
		}
	}
	
		// Warna merah sesuai dengan tracing
	if(((matrix[0][0]==matrix[1][1]) && (matrix[1][1]==matrix[2][2])) && matrix[0][0] != ' '){
		if(matrix[3][3]==' '){
			matrix[3][3]='O';
			return;
		}
	}
	
	if(((matrix[1][1]==matrix[2][2]) && (matrix[2][2]==matrix[3][3])) && matrix[1][1] != ' '){
		if(matrix[0][0]==' '){
			matrix[0][0]='O';
			return;
		}
		else if(matrix[4][4]==' '){
			matrix[4][4]='O';
			return;
		}
	}
	
	if(((matrix[2][2]==matrix[3][3]) && (matrix[3][3]==matrix[4][4])) && matrix[2][2] != ' '){
		if(matrix[1][1]==' '){
			matrix[1][1]='O';
			return;
		}
		else if(matrix[5][5]==' '){
			matrix[5][5]='O';
			return;
		}
	}	
	
	if(((matrix[3][3]==matrix[4][4]) && (matrix[4][4]==matrix[5][5])) && matrix[3][3] != ' '){
		if(matrix[2][2]==' '){
			matrix[2][2]='O';
			return;
		}
		else if(matrix[6][6]==' '){
			matrix[6][6]='O';
			return;
		}
	}
		
	if(((matrix[4][4]==matrix[5][5]) && (matrix[5][5]==matrix[6][6])) && matrix[4][4] != ' '){
		if(matrix[3][3]==' '){
			matrix[3][3]='O';
			return;
		}
	}	
	
   		// kanan ke kiri
    	//Warna pink sesuai tracing
	if(((matrix[4][0]==matrix[3][1]) && (matrix[3][1]==matrix[2][2])) && matrix[4][0] != ' '){
		if(matrix[1][3]==' '){
			matrix[1][3]='O';
			return;
		}
	}
	
	if(((matrix[3][1]==matrix[2][2]) && (matrix[2][2]==matrix[1][3])) && matrix[3][1] != ' '){
		if(matrix[4][0]==' '){
			matrix[4][0]='O';
			return;
		}
		else if(matrix[0][4]==' '){
			matrix[0][4]='O';
			return;
		}
	}
	
	if(((matrix[2][2]==matrix[1][3]) && (matrix[1][3]==matrix[0][4])) && matrix[2][2] != ' '){
		if(matrix[3][1]==' '){
			matrix[3][1]='O';
			return;
		}
	}
		//---
	if(((matrix[6][2]==matrix[5][3]) && (matrix[5][3]==matrix[4][4])) && matrix[6][2] != ' '){
		if(matrix[3][5]==' '){
			matrix[3][5]='O';
			return;
		}
	}
		
	if(((matrix[5][3]==matrix[4][4]) && (matrix[4][4]==matrix[3][5])) && matrix[5][3] != ' '){
		if(matrix[6][2]==' '){
			matrix[6][2]='O';
			return;
		}
		else if(matrix[2][6]==' '){
			matrix[2][6]='O';
			return;
		}
	}
	
	if(((matrix[4][4]==matrix[3][5]) && (matrix[3][5]==matrix[2][6])) && matrix[4][4] != ' '){
		if(matrix[5][3]==' '){
			matrix[5][3]='O';
			return;
		}
	}
	
		// Warna kuning sesuai dengan tracing
	if(((matrix[5][0]==matrix[4][1]) && (matrix[4][1]==matrix[3][2])) && matrix[5][0] != ' '){
		if(matrix[2][3]==' '){
			matrix[2][3]='O';
			return;
		}
	}
	
	if(((matrix[4][1]==matrix[3][2]) && (matrix[3][2]==matrix[2][3])) && matrix[4][1] != ' '){
		if(matrix[5][0]==' '){
			matrix[5][0]='O';
			return;
		}
		else if(matrix[1][4]==' '){
			matrix[1][4]='O';
			return;
		}
	}
	
	if(((matrix[3][2]==matrix[2][3]) && (matrix[2][3]==matrix[1][4])) && matrix[3][2] != ' '){
		if(matrix[4][1]==' '){
			matrix[4][1]='O';
			return;
		}
		else if(matrix[0][5]==' '){
			matrix[0][5]='O';
			return;
		}
	}
	
	if(((matrix[2][3]==matrix[1][4]) && (matrix[1][4]==matrix[0][5])) && matrix[2][3] != ' '){
		if(matrix[3][2]==' '){
			matrix[3][2]='O';
			return;
		}
	}
		//---
	if(((matrix[6][1]==matrix[5][2]) && (matrix[5][2]==matrix[4][3])) && matrix[6][1] != ' '){
		if(matrix[3][4]==' '){
			matrix[3][4]='O';
			return;
		}
	}
	
	if(((matrix[5][2]==matrix[4][3]) && (matrix[4][3]==matrix[3][4])) && matrix[5][2] != ' '){
		if(matrix[6][1]==' '){
			matrix[6][1]='O';
			return;
		}
		else if(matrix[2][5]==' '){
			matrix[2][5]='O';
			return;
		}
	}
	
	if(((matrix[4][3]==matrix[3][4]) && (matrix[3][4]==matrix[2][5])) && matrix[4][3] != ' '){
		if(matrix[5][2]==' '){
			matrix[5][2]='O';
			return;
		}
		else if(matrix[3][4]==' '){
			matrix[3][4]='O';
			return;
		}
	}
	
	if(((matrix[3][4]==matrix[2][5]) && (matrix[2][5]==matrix[1][6])) && matrix[3][4] != ' '){
		if(matrix[4][3]==' '){
			matrix[4][3]='O';
			return;
		}
	}
	
		// Warna merah sesuai dengan tracing
	if(((matrix[6][0]==matrix[5][1]) && (matrix[5][1]==matrix[4][2])) && matrix[6][0] != ' '){
		if(matrix[3][3]==' '){
			matrix[3][3]='O';
			return;
		}
	}
	
	if(((matrix[5][1]==matrix[4][2]) && (matrix[4][2]==matrix[3][3])) && matrix[5][1] != ' '){
		if(matrix[6][0]==' '){
			matrix[6][0]='O';
			return;
		}
		else if(matrix[2][4]==' '){
			matrix[2][4]='O';
			return;
		}
	}
	
	if(((matrix[4][2]==matrix[3][3]) && (matrix[3][3]==matrix[2][4])) && matrix[4][2] != ' '){
		if(matrix[5][1]==' '){
			matrix[5][1]='O';
			return;
		}
		else if(matrix[1][5]==' '){
			matrix[1][5]='O';
			return;
		}
	}	
	
	if(((matrix[3][3]==matrix[2][4]) && (matrix[2][4]==matrix[1][5])) && matrix[3][3] != ' '){
		if(matrix[4][2]==' '){
			matrix[4][2]='O';
			return;
		}
		else if(matrix[0][6]==' '){
			matrix[0][6]='O';
			return;
		}
	}
	
	if(((matrix[2][4]==matrix[1][5]) && (matrix[1][5]==matrix[0][6])) && matrix[2][4] != ' '){
		if(matrix[3][3]==' '){
			matrix[3][3]='O';
			return;
		}
	}
	
 	//row checking jika 2 berturut-turut
	
		// Jika isi dari array index ke-1 dan ke-2 adalah 'O' atau 'X', maka array index ke-3 isi 'O'
	for(i=0;i<7;i++){
		if((matrix[i][0]==matrix[i][1]) && (matrix[i][0] != ' ')){				
			if(matrix[i][2]==' '){
				matrix[i][2]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-2 dan ke-3 adalah 'O' atau 'X', maka array index ke-1 dan ke-4 isi 'O'
	for(i=0;i<7;i++){
		if((matrix[i][1]==matrix[i][2]) && (matrix[i][1] != ' ')){									
			if(matrix[i][0]==' '){
				matrix[i][0]='O';
				return;
			}
			else if(matrix[i][3]==' '){
				matrix[i][3]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-3 dan ke-4 adalah 'O' atau 'X', maka array index ke-2 dan ke-5 isi 'O'
	for(i=0;i<7;i++){
		if((matrix[i][2]==matrix[i][3]=='X') && (matrix[i][2] != ' ')){									
			if(matrix[i][1]==' '){
				matrix[i][1]='O';
				return;
			}
			else if(matrix[i][4]==' '){
				matrix[i][4]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-4 dan ke-5 adalah 'O' atau 'X', maka array index ke-3 dan ke-6 isi 'O'
	for(i=0;i<7;i++){
		if((matrix[i][3]==matrix[i][4]) && (matrix[i][3] != ' ')){									
			if(matrix[i][2]==' '){
				matrix[i][2]='O';
				return;
			}
			else if(matrix[i][5]==' '){
				matrix[i][5]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-5 dan ke-6 adalah 'O' atau 'X', maka array index ke-4 dan ke-7 isi 'O'
	for(i=0;i<7;i++){
		if((matrix[i][4]==matrix[i][5]) && (matrix[i][4] != ' ')){									
			if(matrix[i][3]==' '){
				matrix[i][3]='O';
				return;
			}
			else if(matrix[i][6]==' '){
				matrix[i][6]='O';
				return;
			}
		}
	}
		
		// Jika isi dari array index ke-6 dan ke-7 adalah 'O' atau 'X', maka array index ke-3 isi 'O'
	for(i=0;i<7;i++){
		if((matrix[i][5]==matrix[i][6]) && (matrix[i][5] != ' ')){									
			if(matrix[i][4]==' '){
				matrix[i][4]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-1 dan ke-3 adalah 'O' atau 'X', maka array index ke-2 isi 'O'
	for(i=0;i<7;i++){
		if((matrix[i][0]==matrix[i][2]) && (matrix[i][0] != ' ')){									
			if(matrix[i][1]==' '){
				matrix[i][1]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-2 dan ke-4 adalah 'O' atau 'X', maka array index ke-3 isi 'O'
	for(i=0;i<7;i++){
		if((matrix[i][1]==matrix[i][3]) && (matrix[i][1] != ' ')){									
			if(matrix[i][2]==' '){
				matrix[i][2]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-3 dan ke-5 adalah 'O' atau 'X', maka array index ke-4 isi 'O'
	for(i=0;i<7;i++){
		if((matrix[i][2]==matrix[i][4]) && (matrix[i][2] != ' ')){									
			if(matrix[i][3]==' '){
				matrix[i][3]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-4 dan ke-6 adalah 'O' atau 'X', maka array index ke-5 isi 'O'
	for(i=0;i<7;i++){
		if((matrix[i][3]==matrix[i][5]) && (matrix[i][3] != ' ')){									
			if(matrix[i][4]==' '){
				matrix[i][4]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-5 dan ke-7 adalah 'O' atau 'X', maka array index ke-6 isi 'O'
	for(i=0;i<7;i++){
		if((matrix[i][4]==matrix[i][6]) && (matrix[i][4] != ' ')){									
			if(matrix[i][5]==' '){
				matrix[i][5]='O';
				return;
			}
		}
	}
	
	//column checking jika 2 berturut-turut

		// Jika isi dari array index ke-1 dan ke-2 adalah 'O' atau 'X', maka array index ke-3 isi 'O'
	for(i=0;i<7;i++){
		if((matrix[0][i]==matrix[1][i]) && (matrix[0][i] != ' ')){									
			if(matrix[2][i]==' '){
				matrix[2][i]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-2 dan ke-3 adalah 'O' atau 'X', maka array index ke-1 dan ke-4 isi 'O'
	for(i=0;i<7;i++){
		if((matrix[1][i]==matrix[2][i]) && (matrix[1][i] != ' ')){									
			if(matrix[0][i]==' '){
				matrix[0][i]='O';
				return;
			}
			else if(matrix[3][i]==' '){
				matrix[3][i]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-3 dan ke-4 adalah 'O' atau 'X', maka array index ke-2 dan ke-5 isi 'O'
	for(i=0;i<7;i++){
		if((matrix[2][i]==matrix[3][i]) && (matrix[2][i] != ' ')){									
			if(matrix[1][i]==' '){
				matrix[1][i]='O';
				return;
			}
			else if(matrix[4][i]==' '){
				matrix[4][i]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-4 dan ke-5 adalah 'O' atau 'X', maka array index ke-3 dan ke-6 isi 'O'
	for(i=0;i<7;i++){
		if((matrix[3][i]==matrix[4][i]) && (matrix[3][i] != ' ')){									
			if(matrix[2][i]==' '){
				matrix[2][i]='O';
				return;
			}
			else if(matrix[5][i]==' '){
				matrix[5][i]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-5 dan ke-6 adalah 'O' atau 'X', maka array index ke-4 dan ke-7 isi 'O'
	for(i=0;i<7;i++){
		if((matrix[4][i]==matrix[5][i]) && (matrix[4][i] != ' ')){									
			if(matrix[3][i]==' '){
				matrix[3][i]='O';
				return;
			}
			else if(matrix[6][i]==' '){
				matrix[6][i]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-6 dan ke-7 adalah 'O' atau 'X', maka array index ke-5 isi 'O'
	for(i=0;i<7;i++){
		if((matrix[5][i]==matrix[6][i]) && (matrix[5][i] != ' ')){									
			if(matrix[4][i]==' '){
				matrix[4][i]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-1 dan ke-3 adalah 'O' atau 'X', maka array index ke-2 isi 'O'
	for(i=0;i<7;i++){
		if((matrix[0][i]==matrix[2][i]) && (matrix[0][i] != ' ')){									
			if(matrix[1][i]==' '){
				matrix[1][i]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-2 dan ke-4 adalah 'O' atau 'X', maka array index ke-3 isi 'O'
	for(i=0;i<7;i++){
		if((matrix[1][i]==matrix[3][i]) && (matrix[1][i] != ' ')){									
			if(matrix[2][i]==' '){
				matrix[2][i]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-3 dan ke-5 adalah 'O' atau 'X', maka array index ke-4 isi 'O'
	for(i=0;i<7;i++){
		if((matrix[2][i]==matrix[4][i]) && (matrix[2][i] != ' ')){									
			if(matrix[3][i]==' '){
				matrix[3][i]='O';
				return;
			}
		}
	}
		
		// Jika isi dari array index ke-4 dan ke-6 adalah 'O' atau 'X', maka array index ke-5 isi 'O'
	for(i=0;i<7;i++){
		if((matrix[3][i]==matrix[5][i]) && (matrix[3][i] != ' ')){									
			if(matrix[4][i]==' '){
				matrix[4][i]='O';
				return;
			}
		}
	}
	
		// Jika isi dari array index ke-5 dan ke-7 adalah 'O' atau 'X', maka array index ke-6 isi 'O'
	for(i=0;i<7;i++){
		if((matrix[4][i]==matrix[6][i]) && (matrix[4][i] != ' ')){									
			if(matrix[5][i]==' '){
				matrix[5][i]='O';
				return;
			}
		}
	}
	
		// Finalisasi dengan mengisi random di sekitar 'X' yang sudah ada
	for(i=0;i<7;i++){
		for(j=0;j<7;j++){
			if(matrix[i][j]=='X'){

				if(matrix[i][--j]==' '){
					matrix[i][j]='O';
					return;
				}

				else if(matrix[i][++j]==' '){
					matrix[i][j]='O';
					return;
				}
				else if(matrix[++i][j]==' '){
					matrix[i][j]='O';
					return;
				}

				else if(matrix[--i][j]==' '){
					matrix[i][j]='O';
					return;
				}

			}
		}
	}
		// Finalisasi dengan mengisi yang masih kosong	
	for(i=0;i<7;i++){
		for(j=0;j<7;j++){
			if(matrix[i][j] = ' '){
				matrix[i][j]='O';
				return;
			}
		}
	}
 }
 
/*******************************************************************
FUNCTION TO CHECK WIN 7X7
 ********************************************************************/
 
 char check_7X7() {
	int i,j;
	
		// row checking jika sudah 5 berturut-turut
	for(i=0;i<7;i++){ 
		if((matrix[i][0]==matrix[i][1]) && (matrix[i][1]==matrix[i][2]) && (matrix[i][2]==matrix[i][3]) && (matrix[i][3]==matrix[i][4]) && (matrix[i][0] != ' ')){
			return matrix[i][0];
		}
	}
	
	for(i=0;i<7;i++){
		if((matrix[i][1]==matrix[i][2]) && (matrix[i][2]==matrix[i][3]) && (matrix[i][3]==matrix[i][4]) && (matrix[i][4]==matrix[i][5]) && (matrix[i][1] != ' ')){
			return matrix[i][1];
		}
	}
	
	for(i=0;i<7;i++){
		if((matrix[i][2]==matrix[i][3]) && (matrix[i][3]==matrix[i][4]) && (matrix[i][4]==matrix[i][5]) && (matrix[i][5]==matrix[i][6]) && (matrix[i][2] != ' ')){
			return matrix[i][2];
		}
	}
	
		// column checking jika sudah 5 berturut-turut
	for(i=0;i<7;i++){
		if((matrix[0][i]==matrix[1][i]) && (matrix[1][i]==matrix[2][i]) && (matrix[2][i]==matrix[3][i]) && (matrix[3][i]==matrix[4][i]) && (matrix[0][i] != ' ')){
			return matrix[0][i];
		}
	}
	
	for(i=0;i<7;i++){
		if((matrix[1][i]==matrix[2][i]) && (matrix[2][i]==matrix[3][i]) && (matrix[3][i]==matrix[4][i]) && (matrix[4][i]==matrix[5][i]) && (matrix[1][i] != ' ')){
			return matrix[1][i];
		}
	}
	
	for(i=0;i<7;i++){
		if((matrix[2][i]==matrix[3][i]) && (matrix[3][i]==matrix[4][i]) && (matrix[4][i]==matrix[5][i]) && (matrix[5][i]==matrix[6][i]) && (matrix[2][i] != ' ')){
			return matrix[2][i];
		}
	}
	
		// diagonal checking jika sudah 5 berturut-turut
	    // kiri ke kanan
	if((matrix[0][2]==matrix[1][3]) && (matrix[1][3]==matrix[2][4]) && (matrix[2][4]==matrix[3][5]) && (matrix[3][5]==matrix[4][6]) && (matrix[0][2] != ' ')){
		return matrix[0][2];
	}
	if((matrix[0][1]==matrix[1][2]) && (matrix[1][2]==matrix[2][3]) && (matrix[2][3]==matrix[3][4]) && (matrix[3][4]==matrix[4][5]) && (matrix[0][1] != ' ')){
		return matrix[0][1];
	}
	if((matrix[1][2]==matrix[2][3]) && (matrix[2][3]==matrix[3][4]) && (matrix[3][4]==matrix[4][5]) && (matrix[4][5]==matrix[5][6]) && (matrix[1][2] != ' ')){
		return matrix[1][2];
	}
	if((matrix[0][0]==matrix[1][1]) && (matrix[1][1]==matrix[2][2]) && (matrix[2][2]==matrix[3][3]) && (matrix[3][3]==matrix[4][4]) && (matrix[0][0] != ' ')){
		return matrix[0][0];
	}
	if((matrix[1][1]==matrix[2][2]) && (matrix[2][2]==matrix[3][3]) && (matrix[3][3]==matrix[4][4]) && (matrix[4][4]==matrix[5][5]) && (matrix[1][1] != ' ')){
		return matrix[1][1];
	}
	if((matrix[2][2]==matrix[3][3]) && (matrix[3][3]==matrix[4][4]) && (matrix[4][4]==matrix[5][5]) && (matrix[5][5]==matrix[6][6]) && (matrix[2][2] != ' ')){
		return matrix[2][2];
	}
	if((matrix[1][0]==matrix[2][1]) && (matrix[2][1]==matrix[3][2]) && (matrix[3][2]==matrix[4][3]) && (matrix[4][3]==matrix[5][4]) && (matrix[1][0] != ' ')){
		return matrix[1][0];
	}
	if((matrix[2][1]==matrix[3][2]) && (matrix[3][2]==matrix[4][3]) && (matrix[4][3]==matrix[5][4]) && (matrix[5][4]==matrix[6][5]) && (matrix[2][1] != ' ')){
		return matrix[2][1];
	}
	if((matrix[2][0]==matrix[3][1]) && (matrix[3][1]==matrix[4][2]) && (matrix[4][2]==matrix[5][3]) && (matrix[5][3]==matrix[6][4]) && (matrix[2][0] != ' ')){
		return matrix[2][0];
	}
	
		// kanan ke kiri
	if((matrix[4][0]==matrix[3][1]) && (matrix[3][1]==matrix[2][2]) && (matrix[2][2]==matrix[1][3]) && (matrix[1][3]==matrix[0][4]) && (matrix[4][0] != ' ')){
		return matrix[4][0];
	}
	if((matrix[5][0]==matrix[4][1]) && (matrix[4][1]==matrix[3][2]) && (matrix[3][2]==matrix[2][3]) && (matrix[2][3]==matrix[1][4]) && (matrix[5][0] != ' ')){
		return matrix[5][0];
	}
	if((matrix[4][1]==matrix[3][2]) && (matrix[3][2]==matrix[2][3]) && (matrix[2][3]==matrix[1][4]) && (matrix[1][4]==matrix[0][5]) && (matrix[4][1] != ' ')){
		return matrix[4][1];
	}
	if((matrix[6][0]==matrix[5][1]) && (matrix[5][1]==matrix[4][2]) && (matrix[4][2]==matrix[3][3]) && (matrix[3][3]==matrix[2][4]) && (matrix[6][0] != ' ')){
		return matrix[6][0];
	}
	if((matrix[5][1]==matrix[4][2]) && (matrix[4][2]==matrix[3][3]) && (matrix[3][3]==matrix[2][4]) && (matrix[2][4]==matrix[1][5]) && (matrix[5][1] != ' ')){
		return matrix[5][1];
	}
	if((matrix[4][2]==matrix[3][3]) && (matrix[3][3]==matrix[2][4]) && (matrix[2][4]==matrix[1][5]) && (matrix[1][5]==matrix[0][6]) && (matrix[4][2] != ' ')){
		return matrix[4][2];
	}
	if((matrix[6][1]==matrix[5][2]) && (matrix[5][2]==matrix[4][3]) && (matrix[4][3]==matrix[3][4]) && (matrix[3][4]==matrix[2][5]) && (matrix[6][1] != ' ')){
		return matrix[6][1];
	}
	if((matrix[5][2]==matrix[4][3]) && (matrix[4][3]==matrix[3][4]) && (matrix[3][4]==matrix[2][5]) && (matrix[2][5]==matrix[1][6]) && (matrix[5][2] != ' ')){
		return matrix[5][2];
	}
	if((matrix[6][2]==matrix[5][3]) && (matrix[5][3]==matrix[4][4]) && (matrix[4][4]==matrix[3][5]) && (matrix[3][5]==matrix[2][6]) && (matrix[6][2] != ' ')){
		return matrix[6][2];
	}
	
		// If empty
	for(i=0;i<7;i++){
		for(j=0;j<7;j++){
			if(matrix[i][j]==' '){
				return ' ';
			}
		}
	}
	
		// Draw
	return 'D';																						
}

/*******************************************************************
END OF PROJECT
********************************************************************/
