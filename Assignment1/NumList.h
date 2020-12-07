#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class NumList{
public:
	NumList();
	NumList(int lineNumber);
	NumList(const NumList & src);
	NumList &operator=(const NumList &src);
	~NumList();

	bool isEmpty() const;						// Determine whether the list is empty
	bool elementExist(int element) const;		// Determine  whether a given element exist in the list
	void append(int element);					// Append an element to the end of the list
	int  getElement(int position) const;		// Get an element at a specified position
	bool setElement(int element, int position); // Set an element at a specified position
	bool isValid(int position) const;			// Determine whether the position is valid
	int getSize() const;						// Get size of the list
	int getCapacity() const;					//Get capacity of the list
	const int *getPointer() const;				// Get a read-only pointer to the underlying array

private:
	int *ptr;			// A pointer to a dynamically allocated array
	int size;			// Size of the list
	int capacity;		// Capacity of the list

};