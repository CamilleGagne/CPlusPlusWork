#pragma once
#include "WordData.h"

class WordNode{
public:
	WordNode();
	WordNode(char *word, int length, int lineNum); // Word + line number constructor
	~WordNode();
	WordData & getData();
	WordNode *getNext();
	void setNext(WordNode *next);

private:
	WordData worddata; 
	WordNode *next;   
};

class WordList{
public:

	WordList(char *file);
	~WordList();
	void printFormat() const;			//Formatted print the list
	int getSize() const;				// Get the size of the list

private:
	WordNode *head;						// Pointer to first node
	WordNode *end;						// Pointer to last node
	int size;							// Size of the list;

	void loadList(char* file);			// Load list based on words in the input file
	WordNode *getPointer(char* words);  //Get a pointer to stored given word 
	void wordsSort(char *words, int length, int linenNum);


};