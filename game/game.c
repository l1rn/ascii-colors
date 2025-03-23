#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "input.h"

#define WIDTH 40
#define HEIGHT 20

int tailX[100], tailY[100];

int tailLen;

int fruitX, fruitY;

int gameover, key, score;

int x, y, width, height;

void sleep_ms(int milliseconds){
	usleep(milliseconds * 1000);
}

void setup(){
	width = WIDTH;
	height = HEIGHT;
	x = WIDTH / 2;
	y = HEIGHT / 2;

	fruitX = rand() % WIDTH;
	fruitY = rand() % HEIGHT;

	score = 0;
}

void input(){
	if(khbit()){

		switch(tolower(getchar()))
		{
			case 'w':
			key = 1;
			break;

			case 's':
			key = 2;
			break;

			case 'a':
			key = 3;
			break;

			case 'd':
			key = 4;
			break;
		
			case 'q':
			gameover = 1;
			break;
		}
	}
} 
void draw() {
	system("clear");
	for(int i = 0; i < WIDTH + 2; i++)
		printf("\e[104m \e[0m");
	printf("\n");
	for(int i = 0; i < HEIGHT; i++){
		for(int j = 0; j <= WIDTH; j++){
			if(j == 0 || j == WIDTH){
				printf("\e[104m \e[0m");
			}
			if(i == y && j == x){
				printf("\e[102m\e[92mO\e[0m");	
			}
			else if(i == fruitY && j == fruitX) {
				printf("\e[101m \e[0m");
			}
			else{
				int prevTail = 0;	
				for(int k = 0; k < tailLen;k++){
					if(tailX[k] == j	
					&& tailY[k] == i){
						printf("\e[42m\e[32mo\e[0m");
						prevTail = 1;
					}	
				}
				if(!prevTail){
					printf(" ");
				}
			}
		}
		printf("\n");		
	}
	for(int i = 0; i < WIDTH + 2; i++)
		printf("\e[104m \e[0m");
	printf("\n");
	printf("x: %d, y: %d \n", x, y);
	printf("score: %d \n", score);
}

void logic(){
	int prevX = tailX[0]; 
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for(int i = 1; i < tailLen; i++){
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	
	switch(key){
		case 1:
			y--;
			break;
		case 2: 
			y++;
			break;
		case 3:
			x--;
			break;
		case 4:
			x++;
			break;
		default:
			break;

	}
	if(x == WIDTH)
		x = WIDTH - WIDTH + 1;

	if(x == WIDTH - WIDTH)
		x = WIDTH - 1;

	if(y == HEIGHT)
		y = HEIGHT - HEIGHT + 1;

	if(y == HEIGHT - HEIGHT)
		y = HEIGHT - 1;

	for(int i = 0; i < tailLen; i++){
		if(tailX[i] == x && tailY[i] == y)
			gameover = 1;
	}
	if(x == fruitX && y == fruitY){
		fruitX = rand() % WIDTH;
		fruitY = rand() % HEIGHT;
		tailLen++;
		score++;
	}
}
int main(void){
	setup();
	while(!gameover){
		draw();
		input();
		logic();	
		sleep_ms(100);
	}
}
