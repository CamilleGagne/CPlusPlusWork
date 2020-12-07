/*Created by Camille Gagné on 2019-05-20.
* This class models a line of text stored dynamically in a array of character.
*/
#define _CRT_SECURE_NO_WARNINGS
#include "Line.h"
#include <cstring>



/*Default constructor for Line. This constructor assigns the length of the input
* as the value of the lineLength variable. It assign linePtr toa new array of that
* length and copies the content of the input in that new array.
* @Const char* text = argument
*/
Line::Line(const char* text) {
	lineLength = strlen(text);
	linePtr = new char[lineLength];
	strcpy(linePtr, text); 
	capacity = 0;                    //Capacity is 0 because the length of the text = lineLength
}



/*This destructor deletes the value pointed to by linePtr and assigns it to nullPtr
*/
Line::~Line() {
	linePtr = nullptr;
	delete[] linePtr;
	//linePtr = nullptr;
}



/*Copy Constructor. Creates a new object based on the instantiation of the default constructor
* @Const Line& copy = the value that is being copied
* */
Line::Line(const Line& copy) {
	lineLength = copy.lineLength;
	linePtr = new char[lineLength];
	strcpy(linePtr, copy.linePtr);
	capacity = copy.capacity;
}



/*An overload for operator =. Considers one line.
* @rsh the line that the new line must be equals to
* */
const Line& Line::operator = (const Line& rhs) {
	lineLength = rhs.lineLength;
	linePtr = new char[lineLength];
	strcpy(linePtr, rhs.linePtr);
	capacity = rhs.capacity;
	return *this;
}



/*Returns a C-string version of the line
* */
const char* Line::cstr() {
	return linePtr;
}



/*Return the length of the line
* */
const int Line::length() {
	return lineLength;
}



/*Indicates if the line is empty
* */
const bool Line::empty() {
	if (lineLength == 0) {
		return true;
	}
	else {
		return false;
	}
}



/*Indicate if the line is full
* */
const bool Line::full() {
	if (capacity == 0) {
		return true;
	}
	else {
		return false;
	}
}



/*Returns the capacity of the line
* */
const int Line::getCapacity() {
	return capacity;
}



/*Function that resizes the line if its full. It creates a new array that is twice the size
* of the actual full size and copies the values of the too small array in it.
* */
void Line::resize() {
	if (full()) {
		capacity += lineLength;
		char* newArray = new char[lineLength * 2];
		strcpy(newArray, linePtr);
		delete[] linePtr;
		linePtr = newArray;
	}
}



/*Function that adds a char to the end of the line.
* @ const char& ch the character that is being appended.
* */
void Line::push_back(const char& ch) {
	if (full()) {
		resize();
	}
	linePtr[lineLength] = ch;
	capacity--;
	lineLength++;
}



/*Function that deleted the last element of the line.
* */
void Line::pop_back() {
	if (!empty()) {
		linePtr[lineLength - 1] = '\0';
		capacity++;
		lineLength--;
	}
}



/*An overload for operator <<. Returns the line pointed to by linePtr.
* @ostream& out what is returned
* @const Line& line the line that is being printed
* */
ostream& operator<<(ostream& out, const Line& line)
{
	out << line.linePtr;
	return out;
}



/*An overload for operator >> that initiates a new array the size of the input
* and copies the input into it character by character.
*/
istream& operator>>(istream& in, Line& line) {
	in >> line.lineLength >> line.capacity;
	delete[] line.linePtr;
	line.linePtr = new char[line.lineLength];  //linePtr to have the same length as lineLength
	for (int i = 0; i < line.lineLength; i++) {
		in >> line.linePtr[i];
	}
	return in;
}



/*An overload operator for ==. Considers 2 lines to be the same if every character matches
* @ const Line& lhs left hand side line
* @ const Line& rhs right hand side line
* */
bool operator == (const Line& lhs, const Line & rhs) {
	if (strcmp(lhs.linePtr, rhs.linePtr) == 0) {
		return true;
	}
}



/*An overload operator for !=. Considers 2 lines to not be the same if == returned false
* @ const Line& lhs left hand side line
* @ const Line& rhs right hand side line
* */
bool operator != (const Line& lhs, const Line & rhs) {
	return !(lhs == rhs);
}
