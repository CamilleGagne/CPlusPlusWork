#include "WordData.h"
#pragma warning(disable: 4996)

//Default constructor
WordData::WordData()
{
	ptr = NULL;
}

//Constructor overloading
WordData::WordData(char* word, int length, int lineNum)
{
	ptr = new char[length];
	strcpy(ptr, word);
	ptr[0] = tolower(ptr[0]);
	this->length = length;
	frequency = 1;

	intlist = NumList(lineNum);
}

//Copy constructor
WordData::WordData(WordData & worddata)
{
	ptr = NULL;
	*this = worddata;
}

//Assignment operator define
WordData &WordData::operator=(WordData &worddata)
{
	delete[]ptr;
	length = worddata.getLength();
	ptr = new char[length];
	strcpy(ptr, worddata.getWord());
	frequency = worddata.getFrequency();
	intlist = worddata.getList();
	return *this;
}

//Destructor
WordData::~WordData()
{
	delete[] ptr;
}

void WordData::appendLineNum(int lineNumber)
{
	frequency++;
	intlist.append(lineNumber);
}

int WordData::getFrequency() const
{
	return frequency;
}

int WordData::getLength() const
{
	return length;
}

const char * WordData::getWord() const
{
	return ptr;
}

const NumList& WordData::getList() const
{
	return intlist;
}

//Compares stores words
int WordData::compareWords(char * words) const
{
	char *src = ptr;
	char *dst = words;
	while (*src && *dst)
	{
		char c_local = *src, c_in = *dst;
		if (c_local >= 'A' && c_local <= 'Z')
			c_local += 32;
		if (c_in >= 'A' && c_in <= 'Z')
			c_in += 32;
		if (c_local == c_in)
		{
			++src;
			++dst;
		}
		else
		{
			if (c_local>c_in)
				return 1;
			else
				return -1;
		}
	}
	if (*src == *dst)
		return 0;         
	else if (*src)
		return 1;         //Dst is null: dst before src
	else
		return -1;		  //Src is null: dst after src	
}

void WordData::print() const
{
	//Print the word
	cout << setw(12) << right << ptr << setw(3) << "(" << setw(1) << frequency << ")";
	//Print the frequency and related line number
	for (int i = 0; i< intlist.getSize(); i++)
	{
		cout << setw(3) << intlist.getElement(i);
	}
	cout << endl;

}