#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>


int mergeSort(int **numbers, int **personList,  int totalPerson)
{	
	int i=0, j=0, temp=0, temp2=0;
	for(i=0; i<totalPerson*6; i++) {
		for(j=0; j<totalPerson*6; j++) {
			if(numbers[i] <  numbers[j]) {
				temp = numbers[j];
				numbers[j] = numbers[i];
				numbers[i] = temp;

				temp2 = personList[j];
				personList[j] = personList[i];
				personList[i] = temp2;
			}
		}	
	}
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
		int **numbers[totalPerson*6];
		int **personList[totalPerson*6];
		int countNumbers = 0; //should be 6 * totalPerson	
		for(j=0; j<totalPerson; j++){
			fgets(str, maxChar, readFile);
			char *splittedNumber = strtok(str, " ");
			while(splittedNumber != NULL) { //split string to find number
				numbers[countNumbers] = atoi(splittedNumber);
				personList[countNumbers] = j;
				splittedNumber = strtok(NULL, " ");
				countNumbers++;
			}
		}
		mergeSort(numbers, personList,  totalPerson);
		int z=0;
		for(z=0; z<totalPerson*6; z++) {
			printf("%d %d \n", numbers[z], personList[z]);
		}
	}
	fclose(readFile);
	return 0;
}
