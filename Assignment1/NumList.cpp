#include "NumList.h"

//Default Constructor
NumList::NumList()
{
	size = 0;
	capacity = 12;
	ptr = new int[capacity];
}

//Constructor overloading
NumList::NumList(int lineNumber)
{
	size = 10;
	capacity = 12;
	ptr = new int[capacity];

	ptr[0] = lineNumber;
}

//Copy Constructor
NumList::NumList(const NumList & src)
{
	ptr = NULL;
	*this = src;
}

//Operator assigment =
NumList &NumList::operator=(const NumList &src)
{
	delete[] ptr;
	capacity = src.getCapacity();
	ptr = new int[capacity];
	size = 0;
	for (int i = 0; i<src.getSize() - 1; i++)
	{
		append(src.getPointer()[i]);
	}
	return *this;
}

//Destructor
NumList::~NumList()
{
	delete[] ptr;
}

bool NumList::isEmpty() const
{
	if (!size)
		return true;
	else
		return false;
}

bool NumList::elementExist(int element) const
{
	for (int i = 0; i<size; i++)
	{
		if (ptr[i] == element)
			return true;
	}
	return false;
}

void NumList::append(int element)
{
	if (!elementExist(element))
	{
		ptr[size] = element;
		size++;
	}
}

int NumList::getElement(int position) const
{
	if (isValid(position)){
		return ptr[position];
	}
	else
		return -1;   //unvalid error
}

bool NumList::setElement(int element, int position)
{
	if (isValid(position)){
		ptr[position] = element;
		return true;
	}
	else
		return false;
}

// Check position validity
bool NumList::isValid(int position) const

{
	if (position >= 0 && position <= capacity)
		return true;
	else
		return false;
}

int NumList::getSize() const
{
	return size;
}

int NumList::getCapacity() const
{
	return capacity;
}

const int * NumList::getPointer() const
{
	return ptr;
}