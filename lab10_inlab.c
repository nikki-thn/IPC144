/*----------------------------------------
Name : Nikki Truong
ID   : 112 314 174
IPC144 - Workshop 10 - In lab
-----------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//Function Prototypes

void formatJediPhoneRecord(char formattedRecord[], const char fullName[], const char npa[],
	const char co[], const char number[]);

int isJediMaster(const char name[]);


/*Funtion will search through a file, compare the string passed from caller and string from file
if match was found, return 1 */
int isJediMaster(const char name[]) {

	int isJedi = 0;

	char jediName[31];

	//Open file to be read
	FILE *fp = fopen("jedi_master.txt", "r");

	if (fp != NULL) {

		while (fscanf(fp, " %30[^\n]", jediName) != EOF) {

			//If match is found, isJedi = 1
			if (strcmp(jediName, name) == 0) {

				isJedi = 1;
			}

		}

		fclose(fp);

	}

	return isJedi;
}


//This function will format string as specified, then save the formatted string to the array that was passed from caller
void formatJediPhoneRecord(char formattedRecord[], const char fullName[], const char npa[], const char co[], const char number[]) {

	int length = 0;

	int numSpace = 0;

	int isJedi = 0;
	
	//call function isJedi to check if Jedi is 1
	isJedi = isJediMaster(fullName);

	//find length name to check for truncating
	length = strlen(fullName);

	//copy the first string to be saved
	strcpy(formattedRecord, fullName);

	//If length is greater than 16, truncate to 14, then add ".."
	if (length > 16) {

		formattedRecord[14] = '\0';

		strcat(formattedRecord, "..");

	}

	//if length is less than 16, add space to fill up to 16
	if (length < 16) {

		//calculate how many spaces to add
		numSpace = 16 - length;

		int i = 0;
        
		//loop through to add space
		for (i = 0; i < numSpace; i++) {

			strcat(formattedRecord, " ");

		}

	}

	//add format and the rest of string
	strcat(formattedRecord, " (");
	strcat(formattedRecord, npa);
	strcat(formattedRecord, ") ");
	strcat(formattedRecord, co);
	strcat(formattedRecord, "-");
	strcat(formattedRecord, number);

	//if Jedi, add label
	if (isJedi == 1) {

		strcat(formattedRecord, " Jedi Master");
	}

}


	int main(void) {

		FILE* fptr = fopen("starwars_directory.csv", "r");
		char name[31];
		char npa[4];
		char co[4];
		char number[5];
		char formatted[45];

		if (fptr) {
			while (fscanf(fptr, "%[^,],%s%s%s\n", name, npa, co, number) == 4) {
				formatJediPhoneRecord(formatted, name, npa, co, number);
				printf("%s\n", formatted);
			}

			fclose(fptr);
		}

		else {

			printf("File not found!\n");

		}

		return 0;
	}

