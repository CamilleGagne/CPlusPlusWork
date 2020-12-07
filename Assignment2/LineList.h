/*Created by Camille Gagné on 2019-05-20.
* This class models a line of text and stores it dynamically in an array of characters.
*/

#ifndef ASSIGNMENT1_LINELIST_H
#define ASSIGNMENT1_LINELIST_H
#include "Line.h"


class LineList {
private:
	class Node {                                  //Private node class
	public:
		Line data;                               //Node's data object
		Node *prev, *next;                        //Pointer to previous and next node
		Node(const Line&, Node*, Node*);         //Constructor
	};
	Node *head{ nullptr }, *tail{ nullptr };     //Pointer to the first and last node  in the list
	int theSize;                              //Number of element in the list
public:
	LineList();
	virtual ~LineList();
	LineList(const LineList&);
	const LineList& operator=(const LineList& rhs);
	void push_front(const Line&);
	void push_back(const Line&);
	void pop_front();
	void pop_back();
	int size() const;
	const bool empty();
	void insert(const Line&, int k);
	void remove(int k);
	Line get(int k) const;
	void print();
};
#endif //ASSIGNMENT1_LINELIST_H
