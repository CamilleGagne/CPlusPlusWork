/*Created by Camille Gagné on 2019-05-20.
* This class models a doubly linked list of nodes storing a line object.
*/
#include <iostream>
#include <cstring>
#include "LineList.h"

using std::cout;
using std::endl;
using std::strcpy;


/*Node constructor
* @const Line& in the data in the node
* @Node* p pointer to previous node
* @Node* n pointer to next node
* */
LineList::Node::Node(const Line& in, Node* p, Node* n) : data(in)
{
	prev = p;
	next = n;
}



/*Line List constructor. Creates an empty linked list structure with a head and a tail node.
* The head node points to the tail and the tail node points to the head. The other link is nullptr.
* */
LineList::LineList() {
	head = new Node(Line("Head"), nullptr, nullptr);
	tail = new Node(Line("Tail"), head, nullptr);
	head->next = tail;
	theSize = 0;
}



/*Copy constructor of a linked list. It creates a new Head and Tail nodes, defines the structure
* and iterated through the list created with the constructor to copy its data in new nodes
* added at the end of the structure.
* @rhs right hand side list that is being copied.
* */
LineList::LineList(const LineList& rhs) {
	head = new Node(Line("Head"), nullptr, nullptr);
	tail = new Node(Line("Tail"), head, nullptr);
	head->next = tail;
	theSize = 0;
	Node* current = rhs.head->next;
	for (int i = 0; i < rhs.theSize; i++) {
		push_back(Line(current->data));
		current = current->next;
	}
}


/*Destructor for a linked list. Iterates through the list and deletes the previous node until
* it reaches the tail.
* */
LineList::~LineList() {
	Node* current = head;
	for (int i = 0; i <= theSize; i++) {
		current = current->next;
		delete current->prev;
	}
	delete tail;
}



/*An overload operator for =. Assigns the right hand side list to a new list.
* @rhs right hand side list that is being copied.
* */
const LineList& LineList::operator=(const LineList& rhs)
{
	Node* current = head;
	for (int i = 0; i <= theSize; i++) {
		current = current->next;
		delete current->prev;
	}
	delete tail;
	head = new Node(Line("Head"), nullptr, nullptr);
	tail = new Node(Line("Tail"), head, nullptr);
	head->next = tail;
	theSize = 0;
	current = rhs.head->next;
	for (int i = 0; i < rhs.theSize; i++) {
		push_back(Line(current->data));
		current = current->next;
	}
	return *this;
}



/*Creates a new node to add a line to the front of the list.
* @const Line& line the line that is being added.
* */
void LineList::push_front(const Line& line) {
	theSize++;
	Node* l = new Node(line, head, head->next);
	head->next->prev = l;
	head->next = l;
}



/*Creates a new node to add a line to the back of the list.
* @const Line& line the line that is being added.
* */
void LineList::push_back(const Line& line) {
	theSize++;
	Node* l = new Node(line, tail->prev, tail);
	tail->prev->next = l;
	tail->prev = l;
}



/*Deletes a line (node) to the front of the list.
* */
void LineList::pop_front() {
	theSize--;
	Node* current = head->next;
	head->next = head->next->next;
	head->next->prev = head;
	delete(current);
}



/*Deletes a line (node) to the back of the list.
* */
void LineList::pop_back() {
	theSize--;
	Node* current = tail->prev;
	tail->prev = tail->prev->prev;
	tail->prev->next = tail;
	delete(current);
}



/*Returns the size of the list
* */
int LineList::size() const {
	return theSize;
}



/*Returns whether the list is empty or not
* */
const bool LineList::empty() {
	if (theSize == 0) {
		return true;
	}
	else {
		return false;
	}
}



/*Creates a new node to add a line to a given place in the list.
* @const Line& line the line that is being added.
* @int K the position in the list where the line in inserted
* */
void LineList::insert(const Line& line, int k) {
	theSize++;
	Node *current = head;
	for (int i = 0; i < k; i++) {
		current = current->next;
	}
	Node *l = new Node(line, tail->prev, tail);   //create a new node when for loop reaches k
	current->prev->next = l;
	l->next = current;
	l->prev = current->prev;
	current->prev = l;
}



/*Removes a line from a given place in the list.
* @int K the position in the list where the line should be removed.
* */
void LineList::remove(int k) {
	theSize--;
	Node *current = head;
	for (int i = 0; i < k; i++) {
		current = current->next;
	}
	current->prev->next = current->next;
	current->next->prev = current->prev;
	delete (current);
}



/*Returns the data contained in a node at a given place in the list
* @int k the index of the element to be returned
* */
Line LineList::get(int k) const {
	Node* current = head;
	for (int i = 0; i<k; i++) {
		current = current->next;
	}
	return current->data;
}



/*Function that prints a list starting at index 1
* */
void LineList::print() {
	Node* current = head->next;
	int i = 1;
	while (current != tail) {
		cout << "(" << i << ") " << (current->data) << endl;
		current = current->next;
		i++;
	}
}