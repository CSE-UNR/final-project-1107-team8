//Jeff Freal, Aloysius Altarejos, Duy Vo
//Nov 25 2024
#include <stdio.h>
#define MAX_TEXT_LENGTH 1000
#define ROWS 100
#define COLUMNS 100

void get_user_inputs(int rows, int columns, char array[][columns]);
void read_file_onto_array(FILE* fp, int rows, int columns, char array[rows][columns]);
void display_array(int rows, int columns, char array[][columns]);
void stringSwap(char str1[], char str2[]);
void stringCopy(char source[], char dest[]);
int stringLength(char str[]);

int main(int argc, char *argv[]) {
	if (argc == 1) {
		printf("Please enter madlib text file name as a command line argument\n");
		return 0;
	}
	
	FILE* fp;
	char character[MAX_TEXT_LENGTH + 1], file_array[ROWS][COLUMNS];
	
	fp = fopen(argv[argc - 1], "r");
	
	if (fp == NULL) {
		printf("Invalid File!\n");
		return 0;
	}
	
	read_file_onto_array(fp, ROWS, COLUMNS, file_array);
	fclose(fp);
	get_user_inputs(ROWS, COLUMNS, file_array);
	display_array(ROWS, COLUMNS, file_array);
	printf("\n");
	
	return 0;
}

void get_user_inputs(int rows, int columns, char array[][columns]){
	int row, column;
	char user_word[MAX_TEXT_LENGTH];
	
	for(row = 0; row < rows; row++){
		switch (array[row][0]) {
			case 'A':
				printf("Please enter an adjective: ");
				fgets(user_word, MAX_TEXT_LENGTH, stdin);
				stringSwap(array[row], user_word);
				break;
			case 'N':
				printf("Please enter an noun: ");
				fgets(user_word, MAX_TEXT_LENGTH, stdin);
				stringSwap(array[row], user_word);
				break;
			case 'V':
				printf("Please enter an verb: ");
				fgets(user_word, MAX_TEXT_LENGTH, stdin);
				stringSwap(array[row], user_word);
				break;
		}
	}
}

int stringLength(char str[]){
	int num_of_letters = 0;
	
	while (str[num_of_letters] != '\0') {
		num_of_letters++;
	}
	return num_of_letters;
}

void stringCopy(char source[], char dest[]){
	int letter, source_length, dest_length;
	source_length = stringLength(source);
	dest_length = stringLength(dest);
	
	//clear dest
	for (letter = 0; letter <= dest_length; letter++) {
		dest[letter] = ' ';
	}
	
	//swap
	for (letter = 0; letter <= source_length; letter++) {
		dest[letter] = source[letter];
	}
}

void stringSwap(char str1[], char str2[]) {
	char temp_string[MAX_TEXT_LENGTH];
	temp_string[0] = '\0';
	
	stringCopy(str1, temp_string);
	stringCopy(str2, str1);
	stringCopy(temp_string, str2);
}

void read_file_onto_array(FILE* fp, int rows, int columns, char array[rows][columns]) {
	int row;
	row = 0;
	
	while (fgets(array[row], MAX_TEXT_LENGTH, fp) != NULL) {
		row++;
	}
}

void display_array(int rows, int columns, char array[][columns]) {
	int row, column;
	char character;
	row = 0;
	
	while (array[row][0] != '\0') {
		column = 0;
		while (array[row][column] != '\0') {
			character = array[row][column];
			if (character == '\n') {
				if (array[row+1][0] != '.' && array[row+1][0] != ',') {
					printf(" ");
				}
			} else {
				printf("%c", character);
			}
			column++;
		}
		row++;
	}
}
