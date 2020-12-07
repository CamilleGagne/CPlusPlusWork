#include <iostream>
using namespace std;
#include "WordList.h"

int main()
{
	WordList w1 = WordList("input.txt");
	w1.printFormat();
	return 0;
}

