#include <stdio.h>
#include <stdlib.h>

/* Please note that this will not compile solo due to lack of main function. 
Please compile `charNodeTest.c` instead, which will include this file via 
#include ... */

// Definition and initialisation
typedef struct charNode{
	char c;
	struct charNode * next;
} charNode;

charNode * newNode() {
	return (charNode*) calloc(sizeof(charNode), 1);
}

void get_char_chain(charNode * node) {
	/*
	Reads character from scanf and instantiates new blank node as next node.
	*/
	char ch = '\0';
	while (ch != '\n') {
		scanf("%c", &ch);
		if (ch != '\n') {
		node->c = ch;
		node->next = newNode();
		node = node->next;
		}
	}
	node->c = '\0';
}

// Get length
int listLength (charNode *node) {
	/*
	A recursive function that measures the length of a chain of charNode structs
	*/
	if ((node == NULL) || (node->c == '\0')) return 0;
	return 1 + listLength(node->next);
}

// Copy to target, needs to be declared with size of >= listLength(...) + 1
void copyChars (charNode *node, char * target) {
	// Declare and initialise values for length
	int charIndex = 0;
	int length = listLength (node);
	
	// Create node variable as value
	charNode cNode = *node;
	
	// Copy characters over
	while (charIndex < length) {
		// Coopy character whilst advancing pointer
		target[charIndex++] = cNode.c;
		// Move along character chain
		cNode = *cNode.next;
	}
}

// Destroy chain
void remove_chain(charNode * node) {
	while (node != NULL) {
		charNode * tmp = node->next;
		free(node);
		node = tmp;
	}
}