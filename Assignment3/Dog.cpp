// Dog.cpp
// ...

#include "Dog.h"


using namespace std;

/*Removes any leading and trailing whitespace in a supplied string.
@param str The supplied string
@return A copy of the supplied string, with any leading and trailing whitespace removed.
*/
string trim(const string& str) {
	string s = str;
	string space = (" \t\f\v\n\r");

	size_t f = s.find_first_not_of(space);
	if (f != std::string::npos)
		s.erase(0,f);

	size_t found = s.find_last_not_of(space);
	if (found != std::string::npos)
		s.erase(found + 1);

	cout << "returning: " << s << endl;

	return s;
}

ostream& operator<<(ostream& sout, const Dog& dog) {
	sout << dog.name << ", " << dog.breed << ", " << dog.age << ", " << dog.gender;
	return sout;
}

bool isValid(const Dog& d) {
	
	if (d.getName().length() == 0 | d.getBreed().length() == 0 || d.getAge().length() == 0 || d.getGender().length() == 0)) {
		cout << "is zero: " << d.getName() << endl;
		return false;
	}	
	return true;
}


istream& operator>>(istream& sin, Dog& d) {

		getline(sin, d.name, ',');		d.name = trim(d.name);
		getline(sin, d.breed, ',');		d.breed = trim(d.breed);
		getline(sin, d.age, ',');		d.age = trim(d.age);
		getline(sin, d.gender); 		d.gender = trim(d.gender);

		cout << "if statement" << endl;
		
		if (!isValid(d)) {
			cout << d << " not valid" << endl;
			throw runtime_error("error");
		}
		
		cout << "passed if statement" << endl;

		return sin;
}


std::ostream& operator<<(std::ostream& sout, const DogMapDefault& dogmap) {
	
	for (const auto & dog : dogmap) { 
	        cout << setw(25) << dog.first << " --> " << dog.second << endl;
	    }

	return sout;
}

std::ostream& operator<<(std::ostream& sout, const DogMapSorted& dogmap) {
	for (const auto& dog : dogmap) { 
		cout << setw(25) << dog.first << " --> " << dog.second << endl;
	}

	return sout;
}

