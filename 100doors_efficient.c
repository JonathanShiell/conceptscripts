#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char* argv[]) {
	int nDoors;
	if (argc >= 2) {
		nDoors = atoi(argv[1]);
	}
	
	else {
		printf("Please enter a number of doors: ");
		scanf("%i", &nDoors);
	}
	
	unsigned int doorsSize = nDoors / sizeof(long long int) + 1;
	
	unsigned long long int* doorBits;
	
	if (doorsSize == 1) {
		*doorBits = 0;
	}
	
	else {
		doorBits = (unsigned long long int*) calloc (doorsSize, sizeof(long long int));
	}
	
	// Outer loop is the multiple for divisibility
	for (int i = 1; i <= nDoors; i++) {
		// Inner loop is the door number
		// Value j corresponds to door number j + 1 >>>> doorBit = j - 1;
		for (int j = 1; j <= nDoors; j++) {
			if (j % i == 0) {
				int door_nBit = j - 1;
				int shiftBit = door_nBit / sizeof(long long int);
				int bit = door_nBit % sizeof(long long int);
				
				// Shift bit using bitwise XOR, in-place operator `^=`
				*(doorBits + shiftBit) ^= (unsigned long long int) pow(2, bit);
			}
			
		}

	}
	
	// Iterate over result variable and print open doors
	for (int i = 0; i < nDoors; i++) {
		int shiftBit = i / sizeof(long long int);
		int bit = i % sizeof(long long int);
		unsigned long long int bit2 = (unsigned long long int) pow (2, bit);
		
		// Print number if door open, detect using bitwise and operator `&`
		if (*(doorBits + shiftBit) & bit2)
			printf("%i\n", i + 1);
	}
	
	
	// Finally, deal with the outcome of the else statement that calls calloc
	if (doorsSize != 1)
		free(doorBits);
}