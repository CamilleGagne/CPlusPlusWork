#ifndef DOG_H
#define DOG_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include <map>

using namespace std;

class Dog {

	string name;  
	string breed;  
	string age;  
	string gender;

public:
	// constructor and virtual destructor
	Dog() = default; 
	Dog(const Dog&) = default; 
	Dog& operator=(const Dog&) = default;
	~Dog() = default; 
	Dog(Dog&&) = default; 
	Dog& operator=(Dog&&) = default;

	Dog(string n, string b, string a, string g) :
		name(n), breed(b), age(a), gender(g) { }


	friend ostream& operator<<(ostream& sout, const Dog& d);
	friend istream& operator>>(istream&, Dog&);

	//accessor
	string getBreed() const { return breed; }
	string getName() const { return name; }
	string getAge() const { return age; }
	string getGender()	const { return gender; }

};

using DogMapDefault = multimap<string, Dog>;
using DogMapSorted = multimap<string, Dog, greater<string>>;
ostream& operator<<(ostream&, const DogMapDefault&);
ostream& operator<<(ostream&, const DogMapSorted&);

string trim(const string& str);                  
#endif