#include <stdio.h>
#include <string.h>

#define IN 1
#define OUT 0
#define ARRAY_LENGTH 50

void reverse(char* w){
	int s = strlen(w);
	char* a = w;
	char* b = w + s - 1;

	for(int i = 0; i<s/2; i++){
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
		
		a++;
		b--;
	}
}

int main(int argc, char* argv[]){
	
	char c;
	char rev[ARRAY_LENGTH] = "";
	char tmp;

	while((c = getchar()) != EOF){
		scanf("%s", rev);
		if(c == '\n'){
			reverse(rev);
			printf("Reversed word: %s \n", rev);
			rev[0] = '\0';
		}
	}
	return 0;
}


