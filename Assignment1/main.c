/*
	Name: Kevin Ross
	Student #: 5327746
	Lab Section: 1
*/
#include <stdio.h>
// declare the array sizes
#define ROWS 12
#define COLS 13
// declare the data manipulation function
void fct(char* table, char* in);
int main() {
	// variable declarations.
	char * data = "Assignment 1";
	char data_table [ROWS][COLS];
	// perform the manipulation
	fct(&data_table[0][0], data);
	// print the results
	int i;
	for (i=0; i<12; i++) {
		printf("Line: %s\n", data_table[i]);
	}
	return 0;
}

void fct(char* table, char* in) {
	// declare variables to keep track of cell location
	int col = 0;
	int row;
	// declare a pointer to keep track of memory location
	char * pointer_to_char = in;
	// init the array
	for (row=0; row<ROWS; row++) {
		for (col=0; col<COLS; col++) {
			*(table + row*COLS + col) = '\0';
		}
	}
	// process it
	for (row=0; row<ROWS; row++) {
		for (col=0; col<=row; col++) {
			*(table + row*COLS + col) = *(pointer_to_char++);
		}
		// reset the pointer to the data back to the start of the string
		pointer_to_char = in;
	}
}