#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void checkTextColor(char* x) {
	int colorNumber;
	x[strcspn(x, "\n")] = '\0';
	if(strcmp("red", x) == 0){
		colorNumber = 31;
		printf("text in your bash now red \e[%dm\n", colorNumber);
	}
	else if(strcmp("green", x) == 0){
		colorNumber = 32;
		printf("text now green \e[%dm\n", colorNumber);
	}
	else {
		printf("\e[%0m");
	}
}

void chooseColor(){
	char txtColor[40];
	int colorNumber;
	int bgColor;

	printf("choose text-color to change\n");
	printf("---------------------------------\n");
	printf("|0: reset all                  |\n");
	printf("|31 or red                      |\n");
	printf("|32 or green               	|\n");
	printf("|33: yellow text               	|\n");
	printf("|34: blue text                 	|\n");
	printf("|35: mageanta text            	|\n");
	printf("|36: cyan text                 	|\n");
	printf("|37: white text                 |\n");
	printf("---------------------------------\n");		
	fgets(txtColor, sizeof(txtColor), stdin);
	checkTextColor(txtColor);
	if(strcmp("red", txtColor) == -10){
		colorNumber = 31;
		printf("\e[%dm", colorNumber);	
	}
	// else if(strcmp("green", txtColor == -10){
	//	colorNumber	
	//}

	printf("choose bg-color to change\n");
	printf("---------------------------------\n");
	printf("|41: red bg                     |\n");
	printf("|42: green bg                   |\n");
	printf("|43: yellow bg                  |\n");
	printf("|44: blue bg                 	|\n");
	printf("|45: magenta bg			|\n");
	printf("---------------------------------\n");
	scanf("%d", &bgColor);
	printf("\e[%dm", bgColor);
}

int main() {
	chooseColor();
	return 0;
}
