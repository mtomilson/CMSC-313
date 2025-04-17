#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

//node of our tree
struct node {
	char letter;
	struct node* left;
	struct node* right;
};

//allocates a new node with given letter
//right and left pointers are NULL
struct node* createNode(char character) {
	return NULL;
}

//build the tree needed to do morse to english conversion
//see project description
void buildMorseTree(struct node* root) {
}

//prints the Morse Tree in preorder
void printMorseTree(struct node* node) {
}

//converts all the characters(dot, dash, space, slash) pointed to 
//by characters and converts to english characters and places the 
//english conversions in output.
//This function will create the root by calling createNode.
//The data of the root node can be a character 0
//and will build the tree by calling buildTree(root)
//After building the tree, call printMorseTree to show it was built correctly
void convertMorseToEnglish(char* characters, char* output) {
	//struct node* root = createNode('0');
	//buildTree(root);
	//printMorseTree(root);
	//Convert morse characters to english output
}

int main(int argc, char** argv) {
	//create and initialize arrays message and output
	char message[200] = { '0' };
	char output[100] = { '\0' };
	//the input file is the second argument when executing the program
	FILE* datafile = fopen(argv[1], "r");/* open file for reading*/
	if (datafile == NULL) { printf("can't open\n"); }
	else
	{
		fgets(message, 199, datafile);
		int length = strlen(message);
		message[length] = ' ';
		message[length + 1] = '\0';
		convertMorseToEnglish(message,output);
		// print out the output
		// destroy the MorseTree
	}
}
