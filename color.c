#include <stdio.h>

void chooseColor(){
	int txtColor;
	int bgColor;
	
	printf("choose text-color to change\n");
	printf("---------------------------------\n");
	printf("|0: reset all changes in style  |\n");
	printf("|31: red text                 	|\n");
	printf("|32: green text               	|\n");
	printf("|33: yellow text               	|\n");
	printf("|34: blue text                 	|\n");
	printf("|35: mageanta text            	|\n");
	printf("|36: cyan text                 	|\n");
	printf("|37: white text                 |\n");
	printf("---------------------------------\n");
		
	scanf("%d", &txtColor);
	printf("\e[%dm\n", txtColor);
	if(txtColor == 0) return;

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
