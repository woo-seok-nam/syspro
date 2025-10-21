#include <stdio.h>

int main(int argc, char *argv[]){
	int a;
	char c;
	FILE *fp1, *fp2;
	fp1 =fopen(argv[1],"r");
	if (fp1 == NULL){
		fprintf(stderr, "File %s Open Error\n", argv[1]);
		return 2;
	}
	fp2 =fopen(argv[2],"w");
	while ((c = fgetc(fp1)) != EOF)
		fputc(c,fp2);

	fclose(fp1);
	fclose(fp2);
	return 0;
}
