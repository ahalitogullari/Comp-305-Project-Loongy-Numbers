#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>


int main(int argc, char *argv[])
{
	int totalCase = 0;
	int totalPerson = 0; //includes all situation in case
	int maxChar = 100;
	char str[maxChar];

	FILE *readFile;
	readFile = fopen("small-testdata.in", "r");
	
	if (readFile == NULL) {
		printf("\n no file \n");
	}

	fgets(str, maxChar, readFile); //length of case
	totalCase = atoi(str);
	int i=0, j=0;
	for(i=0; i<totalCase; i++) {
		fgets(str, maxChar, readFile);
		totalPerson = atoi(str);	
		for(j=0; j<totalPerson; j++){
			fgets(str, maxChar, readFile);
		}
		printf("%s%d\n", "Step", totalPerson);
	}
	fclose(readFile);
	return 0;
}
