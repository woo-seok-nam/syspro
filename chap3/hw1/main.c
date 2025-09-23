#include <stdio.h>
#include <string.h>
#include "copy.h"

#define N 5

int main(){
	char lines[N][MAXLINE];
	char temp[MAXLINE];
	int i, j;

	for(i = 0; i < N; i++){
		fgets(lines[i], MAXLINE, stdin);
		lines[i][strcspn(lines[i], "\n")] = '\0';
	}

	for(i = 0; i < N - 1; i++){
		for(j =0; j < N - 1 - i; j++){
			if(strlen(lines[j]) < strlen(lines[j+1])){
					copy(lines[j], temp);
					copy(lines[j + 1], lines[j]);
					copy(temp, lines[j + 1]);
				}
			}
	}
	for(i = 0; i < N; i++){
	printf("%s\n", lines[i]);
	}
	return 0;
	}
