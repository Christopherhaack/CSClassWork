#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void) {
    int i;
    char s[100];
    int t; 
    srand(time(0));
	t = rand() % 10 + 1;
    printf("enter your name!\n");
	scanf("%s", s);
	for (i = 0; i< t; i++) {
		if (t % 2 == 1){
			printf("%d hello, %s! \n", t, s);
		}
		else {
			printf("%d hi there, %s! \n", t, s) ;
		}
	} 
	return 0 ;
}