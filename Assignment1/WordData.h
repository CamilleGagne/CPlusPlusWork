#include "NumList.h"

class WordData{

public:
	WordData();
	WordData(char* word, int length, int lineNum);
	WordData(WordData &worddata);
	WordData &operator=(WordData &worddata);
	~WordData();

	void appendLineNum(int lineNumber);   //Append number to the list of line number
	int getFrequency() const;             //Get frequency count
	int getLength() const;				  //Get length
	const char * getWord() const;		  // Get a read-only pointer to the stored word
	const NumList& getList() const;		  // Get a read-only reference to the NumList object
	int compareWords(char * words) const; // Determine if words compare
	void print() const;					   //print the word, its frequency count and list of line number

private:
	char *ptr;       // A pointer to a dynamically allocated array
	int length;      // length of the array
	int frequency;   // frequency count of the word
	NumList intlist; // Object storing a list of line numbers associated with word
};