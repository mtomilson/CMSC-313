#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

// node of our tree
struct node
{
	char letter;
	struct node *left;
	struct node *right;
};

// allocates a new node with given letter
// right and left pointers are NULL
struct node *createNode(char character)
{
	struct node *newNode = malloc(sizeof(struct node));
	newNode->letter = character;
	newNode->right = NULL;
	newNode->left = NULL;

	return newNode;
}

void insertNode(struct node *root, const char *morse, char letter)
{
	struct node *current = root;

	while (*morse)
	{
		if (*morse == '.') // . means go left
		{
			if (!current->left)
			{
				current->left = createNode('0'); // if we don't have a left node, create a place holder to traverse
			}
			current = current->left; // if we do have a left node, simply move to the left node
		}
		else if (*morse == '-') // - means go right
		{
			if (!current->right)
			{
				current->right = createNode('0');
			}
			current = current->right;
		}
		morse++; // traverse the morse string,
	}
	current->letter = letter; // after reading the entire morse string, we'll be at the proper spot for the corresponding letter
}

// build the tree needed to do morse to english conversion
// see project description


// prints the Morse Tree in preorder
void printMorseTree(struct node *node)
{
	if (node == NULL)
	{
		return;
	}
	printf("%c\n", node->letter);

	printMorseTree(node->left);
	printMorseTree(node->right);
}

void deleteTree(struct node *root)
{
	if (root == NULL)
	{
		return;
	}

	deleteTree(root->left);
	deleteTree(root->right);

	free(root);
}
// converts all the characters(dot, dash, space, slash) pointed to
// by characters and converts to english characters and places the
// english conversions in output.
// This function will create the root by calling createNode.
// The data of the root node can be a character 0
// and will build the tree by calling buildTree(root)
// After building the tree, call printMorseTree to show it was built correctly
void convertMorseToEnglish(char *characters, char *output)
{
	struct node *root = createNode('0');
	int index = 0;
	buildMorseTree(root);

	struct node *current = root;

	// if theres a space, it means thats the end of the letter, and we want to reset and go back to the root?
	while (*characters)
	{
		if (*characters == ' ') // if we hit a space, want to set current to root
		{
			if (current->letter == '0')
			{
				output[index] = ' ';
			}
			else
			{
				output[index] = current->letter;
			}

			index++;
			current = root; // move current back to root to properly find next letter
		}
		if (*characters == '/')
		{
			output[index] = ' '; // assign space when it hits a '/'
		}
		if (*characters == '.') // move left
		{
			current = current->left;
		}
		else if (*characters == '-') // move right
		{
			current = current->right;
		}
		characters++;
	}

	deleteTree(root);
}

int main(int argc, char **argv)
{
	// create and initialize arrays message and output
	char message[200] = {'0'};
	char output[100] = {'\0'};
	// the input file is the second argument when executing the program

	FILE *datafile = fopen(argv[1], "r"); /* open file for reading*/

	if (datafile == NULL)
	{

		printf("can't open\n");
	}
	else
	{

		fgets(message, 199, datafile);

		int length = strlen(message);

		message[length] = ' ';
		message[length + 1] = '\0';

		convertMorseToEnglish(message, output);
		printf("%s\n", output);
		fclose(datafile);
	}
}
