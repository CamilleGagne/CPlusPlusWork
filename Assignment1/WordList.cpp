#include "WordList.h"

//WORDNODE
WordNode::WordNode()
{
	next = NULL;
}

WordNode::WordNode(char *word, int length, int lineNum)
{
	next = NULL;
	worddata = WordData(word, length, lineNum);
}

WordNode::~WordNode()
{
	delete next;
}

WordData & WordNode::getData()
{
	return worddata;
}

void WordNode::setNext(WordNode * next)
{
	this->next = next;
}

WordNode * WordNode::getNext()
{
	return next;
}


//WORDLIST
WordList::WordList(char *file)
{
	size = 1;
	head = NULL;
	end = NULL;
	loadList(file);
}


WordList::~WordList()
{
	delete head;
}

void WordList::loadList(char* file)
{
	char temp[30];
	char ch;
	int length = 0;
	int lineNum = 1;
	ifstream fin(file);

	//First word is read into head node
	cout << "Word Collection Source File: " << file << endl;
	do{
		ch = fin.get();
		if (ch == ' ')
		{
			temp[length] = '\0';
			head = new WordNode(temp, length + 1, lineNum);

			end = head;
			length = 0;
			break;
		}
		else
		{
			temp[length] = ch;
			length++;
		}
	} while (1);


	//Rest if the words are read
	do{

		ch = fin.get();
		if (ch == '\n')
			lineNum++;
		if (ch == ' ' || ch == ';' || ch == '\n') 
		{
			temp[length] = '\0';
			if (length != 0)
				wordsSort(temp, length + 1, lineNum);  //WordSort operation
			length = 0;
		}
		else if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z') || (ch == '.'&&temp[length - 1] == 'i') || (temp[length - 1] == 't'&&ch == '\'')) 
		{
			temp[length] = ch;
			length++;
		}
	} while (!fin.eof());
	temp[length] = '\0';
	wordsSort(temp, length + 1, lineNum);   //Last Word is read

}
void WordList::wordsSort(char * words, int length, int lineNum)
{
	WordNode *previous = NULL;
	WordNode *current = getPointer(words);
	
	if (current == NULL) //Insert word into list if not already in there
	{
		current = head;
		int flag;

		do
		{
			flag = current->getData().compareWords(words);
			if (flag == -1)
			{
				previous = current;
				current = current->getNext();
				if (current == NULL)   //Insert at the end
				{
					end = new WordNode(words, length, lineNum);
					previous->setNext(end);
					break;
				}
			}
			else        //Insert at beginning
			{
				if (current == head) 
				{
					head = new WordNode(words, length, lineNum);
					head->setNext(current);
					break;
				}
				else 
				{
					WordNode *temp = new WordNode(words, length, lineNum);
					temp->setNext(current);
					previous->setNext(temp);
					break;
				}
			}
		} while (1);
		size++;
	}
	else
	{
		current->getData().appendLineNum(lineNum);
	}
}

WordNode * WordList::getPointer(char* words)
{
	WordNode *current = head;
	int i = 1;
	for (int i = 0; i<size; i++)
	{
		if (current->getData().compareWords(words) == 0)
			return current;
		current = current->getNext();
	}
	return NULL;
}

int  WordList::getSize() const
{
	return size;
}

//Print Format
void  WordList::printFormat() const
{
	char ch = 'A';
	WordNode *current = head;
	cout << left << setw(1) << "<" << 'A' << ">" << endl;
	while (current != NULL)
	{
		if (ch == toupper(current->getData().getWord()[0]))
		{
			current->getData().print();
			current = current->getNext();
		}
		else
		{
			ch++;
			cout << left << setw(1) << "<" << ch << ">" << endl;
		}
	}
	if (ch != 'Z')
		cout << left << setw(1) << "<" << ++ch << ">" << endl;
	cin.get();
}