#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "book.h"

int main(int argc, char *argv[]){
	int fd, id, a;
	char c;
	struct book record;
	if((fd = open(argv[1], O_RDONLY)) == -1){
		perror(argv[1]);
		exit(2);
	}
	do {
		printf("0 : list of all books, 1: list of available books)");
		if (scanf("%d", a) == 0){

