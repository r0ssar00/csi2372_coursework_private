#include <stdio.h>

void fct(char* table, char* in);
int main() {
	char * data = "Assignment 1";
	
	char data_table [12][13];
	
	char * data_iter = &data_table[0][0];
	
	fct(data_iter, data);
	
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
	int left = 0;
	// declare pointers to keep track of memory location
	char * pointer_to_char = in;
	// init the array
	for (row=0; row<12; row++) {
		for (col=0; col<13; col++) {
			*(table + 12*row + col) = '\0';
		}
	}
	// keep the last row special because we don't need to process it
	for (row=0; row<12; row++) {
		for (col=0; col<=row; col++) {
			*(table + row*13 + col) = *(pointer_to_char++);
		}
		pointer_to_char = in;
	}
}