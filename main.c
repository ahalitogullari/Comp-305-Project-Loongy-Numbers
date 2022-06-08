#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>


int findLongestNumber(int numbers[], int totalPerson)
{

	return 0;
}

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
		return 0;
	}

	fgets(str, maxChar, readFile); //length of case
	totalCase = atoi(str);
	int i=0, j=0;
	for(i=0; i<2; i++) {
		fgets(str, maxChar, readFile);
		totalPerson = atoi(str);
		int numbers[totalPerson*6];
		int countNumbers = 0; //should be 6 * totalPerson	
		for(j=0; j<totalPerson; j++){
			fgets(str, maxChar, readFile);
			char *splittedNumber = strtok(str, " ");
			while(splittedNumber != NULL) { //split string to find number
				numbers[countNumbers] = atoi(splittedNumber);
				splittedNumber = strtok(NULL, " ");
				countNumbers++;
			}
		}
		findLongestNumber(numbers, totalPerson);
	}
	fclose(readFile);
	return 0;
}
