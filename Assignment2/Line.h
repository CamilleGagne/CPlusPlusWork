/*Created by Camille Gagné on 2019-05-20.
* This class models a line of text stored in a dynamically created array or characters.
*/
#ifndef ASSIGNMENT1_LINE_H
#define ASSIGNMENT1_LINE_H
#include <iostream>
#include <cstring>

using namespace std;

class Line {
private:
	char* linePtr;    //pointer to first element of the array
	int lineLength;   //length of this line
	int capacity;     //storage capacity of this line

public:
	Line(const char*);
	virtual ~Line();
	Line(const Line&);
	const Line& operator = (const Line&);
	const char* cstr();
	const int length();
	const bool empty();
	const bool full();
	const int getCapacity();
	void resize();
	void push_back(const char&);
	void pop_back();
	friend ostream& operator<<(ostream&, const Line&);
	friend istream& operator>>(istream&, Line&);
	friend bool operator == (const Line& lhs, const Line & rhs);
	friend bool operator != (const Line& lhs, const Line & rhs);
};


#endif //ASSIGNMENT1_LINE_H
