#include <stdio.h>
#include <stdlib.h>

#include "charNode.c"

int main (){
	puts("Built OK");
	puts("Test input:");
	charNode *c;
	c = newNode(); // The test call
	
	// c->c = getc(stdin); // One version when not commented out
	// get_char(c);
	get_char_chain(c);
	
	printf("Input starts with: %c\n", c->c);
	
	charNode *c2 = c;
	printf("Input chain: ");
	while (c2->c != '\0') {
		printf("%c", c2->c);
		c2 = c2->next;
	}
	printf("\n");
	
	int length = listLength(c);
	
	printf("Chain length: %i\n", length);
	
	// Copy to string
	char string [length + 1];
	string[length] = '\0';
	
	// Independent block
	// Runs once and then clears from memory.
	{
		int iString = 0; // Index for copying string
		charNode cCopy = *c; // Get point to copy character from
		while (iString < length) 
		{
			// Copy character while using ++ to increment-in-place by +1
			string[iString++] = cCopy.c;
			// Move along character-linked-list
			cCopy = *cCopy.next;
		}
	}
	// Written before copyChars - I was not sure if its logic would work
	
	printf("Copied string: ");
	puts(string);
	
	puts("");
	
	// Clear linked list
	remove_chain(c);
	puts("Linked list cleared from memory");
	puts("");
	
	// Test usage of calloc - should have '\0' on char node
	charNode *ptr = newNode();
	charNode test = *ptr;
	
	if (test.c == '\0') 
		puts("NullChar OK from calloc");
	
	puts("Test call run OK");
}
