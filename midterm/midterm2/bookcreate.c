#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "book.h"

int main(int argc, char *argv[]){
	int fd;
	struct book record;
	if (argc < 2){
		fprintf(stderr, "How to use: %s file\n", argv[0]);
		exit(1;
	}
	if((fd = open[1], O_WRONLT|O_CREAT|O_EXCL, 0640) == -1){
	perror(argv[1]);
	exit(2);
	}
	printf("%-3s %-9s %-9s %-5s %-3s %-7s\n", "id", "Bookname", "author", "year", "numofborrow", "borrow");
	while (scanf("%d %s %s %d %d %s", &record.id, record.Bookname, record.author, &record.year, &record.numoborrow, record.borrow) == 6){
	lseek(fd, (record.id - START_id) *sizeof(record), SEEK_SET);
	write(fd, (char *) &record, sizeof(record));
	}
	close(fd);
	exit(0);
	}
