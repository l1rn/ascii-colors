#include <stdio.h>
#include <unistd.h>

int main() {
	int color = 31;
	char hello[] = "hi!!!";
	for(;;) {
		printf("\e[%dm%s\e[0m\n", color, hello);
		color += 1;
		sleep(1);
		if(color > 36) color = 31;
	}
	return 0;
}	
