#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#define UP 72
#define DOWN 80
#define RIGHT 77
#define LEFT 75
#define SPACEBAR 32
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

char key;
int x = 10, y = 10;
int player = 1;
int badukdol[21][21] = {0,};
void pan();
void gotoxy();
void put_stone();
void draw_stone();
void control_key();
void win();
void game();

void pan(){
	int i, j;
	
	printf("┌");
	
	 for(i=0;i<19;i++){
	 	printf("┬");
	 } 
	 
	 printf("┐\n");
	 
	 for(i=0;i<19;i++){
	 	printf("├");
	 	
	 	for(j=0;j<19;j++){
	 		printf("┼");
		 }
		 
		 printf("┤\n"); 
	 }
	 
	 printf("└");
	 
	 for(i=0;i<19;i++){
	 	printf("┴");
	 }
	 
	 printf("┘\n");
}

void gotoxy(){
	COORD Pos = {(SHORT)(x*2),(SHORT)y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
}

void put_stone(){
	
	if(badukdol[y][x] == 0){
		if(player == 1){
			badukdol[y][x] = 1;
			win();
			player = 2;
		}
		else{
			badukdol[y][x] = 2;
			win();
			player = 1;
		}
		draw_stone();
	}
}

void draw_stone(){

	if(player == 1)
		printf("●");
	else{
		printf("○");
	}
}

void control_key(){
	switch(key){
		case UP :
			if(y - 1 < 0)
				break;
			else
				y-=1;
				break;
				
		case DOWN :
			if(y + 1 > 20)
				break;
			else
				y+=1;
				break;
				
		case RIGHT :
			if(x + 1 > 20)
				break;
			else
				x+=1;
				break;
				
		case LEFT :
			if(x - 1 < 0)
				break;
			else
				x-=1;
				break;
				
		case SPACEBAR :
			put_stone();
			break;
			
		default :
			break;
		
	}
}

void win(){
	int i, j;
	int count = 0;
	
	for(i=x-4;i<=x+4;i++){
		
		if(badukdol[y][i] == player){
			count++;
			if(count == 5){
				if(player == 1){
					gotoxy(0, 22);
					printf("흑돌이 이겼습니다.");
				}
				else{
					gotoxy(0, 22);
					printf("백돌이 이겼습니다.");
				}
			}
		}
		else
			count = 0;
	}
	
	count = 0;
	for(i=y-4;i<=x+4;i++){
		
		if(badukdol[i][x] == player){
			count++;
			if(count == 5){
				if(player == 1){
					gotoxy(0, 22);
					printf("흑돌이 이겼습니다.");
				}
				else{
					gotoxy(0, 22);
					printf("백돌이 이겼습니다.");
				}
			}
		}
		else
			count = 0;
	}
	
	count = 0;
	for(i=x-4, j=y-4;i<=x+4;i++, j++){
		
		if(badukdol[j][i] == player){
			count++;
			if(count == 5){
				if(player == 1){
					gotoxy(0, 22);
					printf("흑돌이 이겼습니다.");
				}
				else{
					gotoxy(0, 22);
					printf("백돌이 이겼습니다.");
				}
			}
		}
		else
			count = 0;	
	}
	
	count = 0;
	for(i=x-4, j=y+4;i<=x+4;i++, j--){
		if(badukdol[j][i] == player){
			count++;
			if(count == 5){
				if(player == 1){
					gotoxy(0, 21);
					printf("흑돌이 이겼습니다.");
				}
				else{
					gotoxy(0, 21);
					printf("백돌이 이겼습니다.");
				}
			}
		}
		else
			count = 0;	
	}
}

void game(){
	
	pan();
	gotoxy();
	draw_stone();
	
	do{
		gotoxy();
		key = getch();
		control_key();	
	}while(key != 27);
}

int main(int argc, char *argv[]) {
	game();
	gotoxy(0, 21);
	
	return 0;
}
