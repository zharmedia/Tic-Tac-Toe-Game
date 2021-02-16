#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

/* Declaration */																										  

char matrix[8][8]; 														// Frame Board Game							 			    

void introduction();													// Header Start Program								

void mainMenu();														// Main Menu Program									 
void menuHelp();														// Menu Help											 					
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

typedef struct data{
	int grid;
	char namePlayer[255];
	int levelComputer;
	char time[100];
};
	struct data dataPemain;
	
/* Modul Papan_Permainan */
int main() {
    int i, j, player, against, choiceMainMenu, kodeWarna, chooseLanguage;
    char done;
    char p1[8],p2[8];
    
    // Main Menu
	menu:
	done = ' '; 												// Untuk main lagi
	player=1;													// Untuk main lagi
    mainMenu();
    scanf("%d",&choiceMainMenu);
    
    // Start Program
    if(choiceMainMenu==1){
    	system("cls");
    	
    	// Input Board Game
    	system("cls");
    	introduction();
    	printf("  Board Game\n");
    	printf("  Press 3 and Enter for [3X3]\n");
		printf("  Press 5 and Enter for [5X5]\n");
		printf("  Press 7 and Enter for [7X7]\n\n");
		printf("  Choose one : ");
		scanf("%d",&dataPemain.grid);
		
		// Input Opponent
		system("cls");
    	introduction();
		printf("  Whom do you wanna play?\n");
		printf("  Press 1 and Enter for playing with computer\n");
		printf("  Press 2 and Enter for playing with player2\n\n");
		printf("  Choose one : ");
		scanf("%d",&against);
		
		// Input Name and Symbol
		system("cls");
    	introduction();
		if(against==1){
			printf("  Enter player's name : ");
			scanf("%s",dataPemain.namePlayer);
			printf("  %s's symbol is 'X'",dataPemain.namePlayer);
			
			printf("\n\n  Computer's symbol is 'O'");
			sleep(2);
		}
		else if(against==2){
			printf("  Enter player1's name : ");
			scanf("%s",p1);
			printf("  %s's symbol is 'X'",p1);
			
			printf("\n\n  Enter player2's name : ");
			scanf("%s",p2);
			printf("  %s's symbol is 'O'",p2);
			sleep(1);
		}
		
		// Input level computer
		system("cls");
		introduction();
		if(against==1){
			printf("  Enter level komputer : \n");
			printf("  [1] Easy\n");
			printf("  [2] Normal\n");
			printf("  [3] Hard\n\n");
			printf("  Choose one : ");
			scanf("%d",&dataPemain.levelComputer);
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
				printf("\n  Player1 wins");
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
				printf("\n  Player1 wins");
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
				printf("\n  Player1 wins");
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
				printf("\n  Player wins");
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
				printf("\n  Player wins");
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
				printf("\n  Player wins");
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
				printf("\n  Player wins");
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
				printf("\n  Player wins");
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
				printf("\n  Player wins");
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
		
		printf("\n\n\n  Press Esc on your keyboard to play again ");
		getch();
    	goto menu;
	}
    
    // Help Program
	else if(choiceMainMenu==2){
		system("cls");
		printf("\n\n    ================================\n");
		printf("\n\t   Help Tic Tac Toe \n\n");
		printf("    ================================\n\n");
		printf("\t    [1] Indonesian\n\t    [2] English\n\n");
		printf("             Choose one : ");
		scanf("%d",&chooseLanguage);
		menuHelp(chooseLanguage);
		printf("\n\n\n  Press Esc on your keyboard to main menu");
		getch();
    	goto menu;
	}
	
	// ColorTheme Program
	else if(choiceMainMenu==3){
		chooseColorTheme();
		scanf("%d",&kodeWarna);
		showColorTheme(kodeWarna);
		printf("\n\n\n  Press Esc on your keyboard to main menu");
		getch();
		goto menu;
	}
	
	// Credit Program
	else if(choiceMainMenu==4){
		credit();
		printf("\n\n\n  Press Esc on your keyboard to main menu");
		getch();
		goto menu;
	}
	
	// Highscore Game
	else if(choiceMainMenu==5){
		system("cls");
		readHighscore();
		printf("\n\n\n  Press Esc on your keyboard to main menu");
		getch();
		goto menu;
	}
	
	// Exit Program
	else if(choiceMainMenu==6){
		system("cls");
		printf("\n  Press Esc on your keyboard to exit this game\n");
		exit(0);
	}
	
	else {
		goto menu;
	}
	
    return 0;
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
PROCEDURE TO MAKE A MENUHELP #2
 ********************************************************************/
 
void menuHelp(int chooseLanguage){
	if(chooseLanguage==1){
		system("cls");
		printf("\n\n    =======================================================================================================\n");
		printf("\n\t\t\t\t\t\tHelp Tic Tac Toe \n\n");
		printf("    =======================================================================================================\n\n");
		printf("    Apa ini? :\n");
		printf("    Game ini bernama tic tac toe. Dalam game ini, terdapat 2 komponen utama\n");
		printf("    yaitu papan permainan yang terdiri dari 3 ukuran (3x3, 5x5, 7x7) dan\n");
		printf("    juga pemain/bot yang dapat menempatkan tanda 'X' atau 'O' di papan permainan\n");
		printf("\n\n    Seperti yang anda lihat, pada bagian main menu terdapat beberapa pilihan :\n");
		printf("    1. Start untuk memulai game\n");
		printf("    2. Help untuk menampilkan deskripsi game dan juga cara bermainnya\n");
		printf("    3. Highscore untuk menampilkan riwayat kemenangan melawan komputer\n");
		printf("    4. Color Theme untuk memilih background dan text color pada permainan\n");
		printf("    5. Credits untuk menampilkan identitas developer atau creator dari permainan\n");
		printf("    6. Exit untuk keluar dari game\n\n");
		printf("    Bagaimana cara bermainnya? :\n");
		printf("    1. Silakan pilih start pada main menu.\n");
		printf("    2. Setelah itu, pilih ukuran grid permainan (3x3,5x5,7x7)\n");
		printf("    3. Pilih lawan, bisa melawan player 2 dan juga komputer\n");
		printf("    4. Inputkan nama anda. Jika melawan player 2, maka inputkkan juga namanya\n");
		printf("    5. Pilih tingkat kesulitan dari komputer\n");
		printf("    6. Setelah itu, pilih siapa yang mendapatkan giliran pertama main\n");
		printf("    7. Perlu diingat bahwa setiap giliran dibatas dengan 10 detik\n");
		printf("    8. Player 1 memiliki tanda 'X', sedangkan player 2 atau komputer memiliki tanda 'O'\n");
		printf("    9. Setiap player atau komputer dapat mengisi tandanya masing-masing di papan permainan\n");
		printf("    10. Pemain/bot dikatakan menang, jika sudah mengisi tandanya sebanyak 3 kali berturut-turut\n");
		printf("    pada grid 3x3 atau 4 kali berturut-turut pada grid 5x5 dan/atau 5 kali berturut-turut pada grid 7x7\n");
		printf("    11. Setiap ronde selesai, pemain dapat menentukan apakah mau melanjutkan permainan atau tidak\n");
		printf("    12. Setiap kemenangan melawan komputer, maka pemain dapat melihat riwayatnya di menu highscore");
	}
	else if(chooseLanguage==2){
		system("cls");
		printf("\n\n    =======================================================================================================\n");
		printf("\n\t\t\t\t\t\tHelp Tic Tac Toe \n\n");
		printf("    =======================================================================================================\n\n");
		printf("    What is this? :\n");
		printf("    So, this game is called tic-tac-toe. In this game, there's a board game in the form of grid (3x3, 5x5, 7x7)\n    and two players, X and O, who take turns marking spaces ' ' in the board game. The player who takes\n");
		printf("    the turn can mark in the row, column or diagonal side in the board game.\n");
		printf("\n    Also, as you can see in main menu, there's a couple of choices :'  :\n");
		printf("    1. Start to start the game.\n");
		printf("    2. Help to display game descriptions, rules and how to play.\n");
		printf("    3. Highscore to display the history of the player's victory against the computer.\n");
		printf("    4. Color Theme to select the display color of this game.\n");
		printf("    5. Credits for displaying the identity of the developer or creator of this game.\n");
		printf("    6. Exit to exit the game.\n\n");
		printf("    How to play this game? :\n");
		printf("    1. Select Start.\n");
		printf("    2. Select the size of the game board (3x3, 5x5, 7x7).\n");
		printf("    3. Choose who you want to play with (Player/Computer).\n");
		printf("    4. Enter the player name.\n");
		printf("    5. Choose a difficulty level\n");
		printf("    6. Choose who will take the first turn.\n");
		printf("    7. Each turn is limited to 10 seconds.\n");
		printf("    8. You are 'X', your friend (or the computer in this case) is 'O'.\n    Players take turns putting their marks in empty squares.\n");
		printf("    9. The first player to get all of her marks in a row (up, down, across, or diagonally) is the winner.\n");
		printf("    10. When all squares are full, the game is over. If no player has won, the game ends in a tie");
	}	
}

/*******************************************************************
PROCEDURE TO SHOW A COLORTHEME #3
 ********************************************************************/
 
void showColorTheme(int kodeWarna){
 	if(kodeWarna==14){
			system("color 7D");
		}
		else if(kodeWarna==15){
			system("color 7C");
		}
		else if(kodeWarna==16){
			system("color 7B");
		}
		else if(kodeWarna==24){
			system("color 1D");
		}
		else if(kodeWarna==25){
			system("color 1C");
		}
		else if(kodeWarna==26){
			system("color 1B");
		}
		else if(kodeWarna==34){
			system("color 8D");
		}
		else if(kodeWarna==35){
			system("color 8C");
		}
		else if(kodeWarna==36){
			system("color 8B");
		}
 }
 
/*******************************************************************
PROCEDURE TO CHOOSE A COLORTHEME #3
 ********************************************************************/
 
void chooseColorTheme(){
		system("cls");
		printf("\n\n\t================================\n");
		printf("\n\t\t  Color Theme\n\n");
		printf(" \t================================\n\n");
		printf("    Aturan Perwarnaan : \n");
		printf("    [1] Pemain dapat mengatur background color dan juga text color\n");
		printf("    [2] Untuk mengatur background color, pemain harus menginput kode antara\n    0-9 dengan rincian warna sebagai berikut : \n");
		printf("        1 = White\n");
		printf("        2 = Blue\n");
		printf("        3 = Gray\n");
		printf("    [3] Untuk mengatur text color, pemain harus menginput kode antara A-F dengan\n    rincian warna sebagai berikut : \n");
		printf("        4 = Light Purple\n");
		printf("        5 = Light Red\n");
		printf("        6 = Light Aqua\n\n");
		printf("\n    Contoh : \n");
		printf("    Pemain ingin mengubah background color menjadi White dan text color menjadi Light Purple\n    Maka kode yang diinput adalah '14'\n");
		printf("\n\n    Input Kode Warna	: ");
}

/*******************************************************************
PROCEDURE TO SHOW CREDITS #4
********************************************************************/

void credit(){
		system("cls");
		printf("\n");
    	printf("   * Game's Name: Tic-Tac-Toe\n");
   	 	printf("   * Developer 1: Muhammad Azhar Alauddin D4TI-1A-201524013\n");
   	 	printf("   * Developer 2: Difa Mochammad Fadillah D4TI-1A-201524006\n");
    	printf("   * Date: 17 February 2021\n");
    	printf("   * Comment: I hope you guys can enjoy this game ^_^\n\n");
    	printf("   Stay in touch! Thanks a lot...");
}

/*******************************************************************
FUNCTION TO SAVE HIGHSCORE #5
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

    fopen_s(&pFile,"Data.dat","ab+"); // append and update binary, can be read
    if(!pFile)
    return 1; //fopen error

    fwrite(&Record,sizeof(Record),1,pFile);
    fclose(pFile);
        
    return 0;
}
/*******************************************************************
PROCEDURE TO READ HIGHSCORE #5 
********************************************************************/

int readHighscore(){  //
	FILE* pFile = 0;
        int i = 1;
        pFile = fopen("Data.dat","ab+"); // append and update binary, can be read
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
            if(!feof(pFile) && i <= 10){
                strncpy(Record.namePlayer, Record.namePlayer, 15);
                printf("  \xB3%-2d\xB3%-20s\xB3%-5d\xB3%-15d\xB3%-15s\xB3\n", i++, Record.time, Record.grid, Record.levelComputer, Record.namePlayer);
            }
        }while(!feof(pFile) && i <= 10);
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
	
	printf("\n  Enter x and y co-ordinates of your move: ");
	scanf("%d %d",&x,&y);															//user to input the x & y co-ordinate of his move
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
 	scanf("%d %d",&x,&y);
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

