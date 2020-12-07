#include <iostream>
#include <fstream>  
#include <sstream>
#include "Dog.h"
#include <istream>
#include <iterator>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
#include <set>

using namespace std;
/* ========================================  PART 3 =================================================== 
          --------------------------TASK 1 ----------------------- */
/*As given inthe assignment, this function loads a dogMap from an input file.
This is used in task 1.
@param	the map to load the file into
		the filename to read from
*/
void load_csvFile_Normal_Loop(DogMapDefault& dog_map, string filename) {
	ifstream input_file_stream(filename); // Create an input file stream
	if (!input_file_stream.is_open()) {        // Check that the file is open
		cout << "Could not open file " + filename << endl;
		throw runtime_error("Could not open file " + filename);
	}
	string line;
	while (getline(input_file_stream, line)) {        // read a line
		stringstream my_line_stream(line); // turn the line into an input stream
		Dog dog{};
		my_line_stream >> dog;                  // initialize dog using Dog's operator>>
		dog_map.emplace(dog.getBreed(), dog);   // insert dog into dog_map
	}
	input_file_stream.close(); // Close file
}

/*          ----------------------- TASK 2 -----------------------
As given inthe assignment, this function loads a dogMap from an input file.
This is using For_each and is used in task 2.
@param	the map to load the file into
		the filename to read from
*/
void load_csvFile_For_Each(DogMapDefault& dog_map, string filename)
{
   ifstream input_file_stream(filename); 

   if (!input_file_stream.is_open()) {       
	  cout << "Could not open file " + filename << endl;
	  throw runtime_error("Could not open file " + filename);
   }

   istream_iterator<Dog> input_stream_begin{ input_file_stream};
   istream_iterator<Dog> input_stream_end{};

// Copy Dog elements from input to dog_map using the for_each function
   cout << "starting for each " << endl;
   for_each(input_stream_begin, input_stream_end, [&dog_map](Dog dog) { dog_map.emplace(dog.getBreed(), dog); });
   cout << "done for each" << endl;
   input_file_stream.close();
}

/*          ----------------------- TASK 3 -----------------------
As given inthe assignment, this function loads a dogMap from an input file.
This is using transform and is used in task 3.
@param	the map to load the file into
		the filename to read from
*/
void load_csvFile_Transform(DogMapDefault& dog_map, string filename) {
	ifstream input_file_stream(filename); // Create an input file stream
	if (!input_file_stream.is_open()) {        // Check that the file is open
		cout << "Could not open file " + filename << endl;
		throw runtime_error("Could not open file " + filename);
	}

	istream_iterator<Dog> input_stream_begin{ input_file_stream };
	istream_iterator<Dog> input_stream_end{};

	transform(input_stream_begin, input_stream_end, inserter(dog_map, dog_map.end()), [](Dog dog)->pair<string, Dog> { return pair<string, Dog>(dog.getBreed(), dog); });
}

/*          ----------------------- TASK 4 -----------------------
This function sorts the dog map in reverse order.
@param	the map to load the file into
		the filename to read from
*/
void load_csvFile_Normal_LoopTask4(DogMapSorted& dog_map, string filename) {
	ifstream input_file_stream(filename); // Create an input file stream
	if (!input_file_stream.is_open()) {        // Check that the file is open
		cout << "Could not open file " + filename << endl;
		throw runtime_error("Could not open file " + filename);
	}
	string line;
	while (getline(input_file_stream, line)) {        // read a line
		stringstream my_line_stream(line); // turn the line into an input stream
		Dog dog{};
		my_line_stream >> dog;                  // initialize dog using Dog's operator>>
		dog_map.emplace(dog.getBreed(), dog);   // insert dog into dog_map
	}
	input_file_stream.close(); // Close file
}

/*          ----------------------- TASK 5 -----------------------
This function returns the data from the input file that matched the key provided
@param	string defining the key 
		dogMap that receives the data
*/
DogMapDefault findBreedRange(DogMapDefault& source, const string& key_breed)
{
	DogMapDefault toRet;
	auto range = source.equal_range(key_breed);
	for (multimap<string, Dog>::iterator it = range.first; it != range.second; ++it)
		toRet.emplace(it->first, it->second);
	return toRet;
}


/* =========================================== PART 4 ============================================ 
Determines if the character is a letter
@param c	The char to verify
@return bool
*/
bool isNecessary(char c) {
	if (isalpha(c)) {
		return false;
	} else return true;
}

/*
Determines if an input is a palindrome.
@param s  The string to look at
@return   True if it's a palindrome, false if it's not.
*/
bool is_palindrome(const string& s) {
	string localCopy;

	remove_copy_if(s.begin(), s.end(), back_inserter(localCopy), isNecessary);
	transform(localCopy.begin(), localCopy.end(), localCopy.begin(), ::tolower);
	if (equal(localCopy.begin(), localCopy.begin() + (localCopy.size() / 2), localCopy.rbegin())) {
		return true;
	}
	else return false;
}


//as given in the assignment
void test_is_palindrome()
{
	string str_i = string("was it a car or A Cat I saW?");
	string str_u = string("was it A Car or a cat U saW?");
	cout << "the phrase \"" + str_i + "\" is " +
		(is_palindrome(str_i) ? "" : "not ") + "a palindrome\n";
	cout << "the phrase \"" + str_u + "\" is " +
		(is_palindrome(str_u) ? "" : "not ") + "a palindrome\n";
}

/* ================================== PART 5 ===================================
Function template that finds the second largest element in a container.
@param Iterator, Iterator
@return pair<Iterator, bool>
*/
template<class Iterator>
pair<Iterator, bool>
second_max(Iterator start, Iterator finish) 
{
	int size = distance(start, finish);
	if (size == 0) {
		return make_pair(finish, false);
	}

	Iterator max = start;
	Iterator second_max = start;
	Iterator iter = next(start, 1);
	for (; iter != finish; ++iter, ++start) {
		if (*iter > * start) {
			max = iter;
			second_max = start;
		}
		else if (*iter < *start) {
			max = start;
			second_max = iter;
		}
	}
	if (*max == *second_max) {
		return make_pair(start, false);
	}
	else { return make_pair(second_max, true); }
}

//As given in the assignment
void test_second_max(std::vector<int> vec)
{
	auto retval = second_max(vec.begin(), vec.end());

	if (retval.second)
	{
		cout << "The second largest element in vec is "
			<< *retval.first << endl;
	}
	else
	{
		if (retval.first == vec.end())
			cout << "List empty, no elements\n";
		else
			cout << "Container's elements are all equal to "
			<< *retval.first << endl;
	}
}

/* ============================================= PART 6 =============================================
Lambda expression that verifies if the size of the vector > than given number
@param vector<string>, int
@return int
*/
int unsigned p;
int testCountStringsLambda(vector<string>& vec, unsigned int n) {
	return count_if(vec.begin(), vec.end(), [n](string s) {return s.length() < n; });
}

/**
Free function that returns the size of a vector and verifies if > than a given number
@param vector<string>, int
@return int
*/
bool isLess(string s) { return (s.length() < p); } //Returns true if number is bigger than size of the container

int testCountStringsFreeFun(vector<string>& vec, int n) {
	p = n;
	return count_if(vec.begin(), vec.end(), isLess);
}

/**
Functor that returns the count of a vector and verifies if its size > than given number.
@param vector<string>, int
@return int
*/
struct S {                        //Structure for testCountStringFunctor.
	int num;
	S(int n) :num(n) {}
	bool operator()(string str) {
		return str.length() < num;
	}
};

int testCountStringsFunctor(vector<string>& vec, int n) {
	return count_if(vec.begin(), vec.end(), S(n));
}


/* ========================= PART 7 =========================
struct for multisetUsingDefaultComparator to sort the element lexicographically
*/
struct classcomp {
	bool operator() (const string& lhs, const string& rhs) const
	{
		if (lhs.size() == rhs.size()) {
			return (lhs < rhs);
		}
		else if (lhs.size() > rhs.size()) {
			return false;
		}
	}
};

// Creates a multiset by sorting a vector using the classcomp structure.
void multisetUsingMyComparator() {
	multiset<string, classcomp> strSet;
	vector<string> vec =
	{ "C", "BB", "A", "CC", "A", "B", "BB", "A", "D", "CC", "DDD", "AAA" };
	copy(vec.begin(), vec.end(), 
		inserter(strSet, strSet.begin()));
	
	ostream_iterator<string> out(cout, " ");
	copy(strSet.begin(), strSet.end(), out);
}



int main() {
	
	cout << "3. DOG MULTI-MAP" << endl;
	
	cout << "--- START TASK 1 ---" << endl;
	DogMapDefault dogMap1;
	load_csvFile_Normal_Loop(dogMap1, "C:\\Users\\cgagne\\source\\repos\\DogDB.csv");
	cout << dogMap1 << endl;

	cout << "--- START TASK 2 ---" << endl;
	DogMapDefault dogMap2;
	load_csvFile_For_Each(dogMap2, "C:\\Users\\cgagne\\source\\repos\\DogDB.csv");
	cout << dogMap2 << endl;

	/*
	cout << "--- START TASK 3 ---" << endl;
	DogMapDefault dogMap3;
	load_csvFile_Transform(dogMap3, "C:\\Users\\cgagne\\source\\repos\\DogDB.csv");
	cout << dogMap3 << endl;

	cout << "--- START TASK 4 ---" << endl;
	DogMapSorted dogMap4;
	load_csvFile_Normal_LoopTask4(dogMap4, "C:\\Users\\cgagne\\source\\repos\\DogDB.csv");
	cout << dogMap4 << endl;

	cout << "--- START TASK 5 ---" << endl;
	DogMapDefault dog_map;
	load_csvFile_Normal_Loop(dog_map, "C:\\Users\\cgagne\\source\\repos\\DogDB.csv");
	DogMapDefault breedRangeMap1 = findBreedRange(dog_map, std::string("Greyhound"));
	cout << breedRangeMap1 << "----------" << endl;
	DogMapDefault breedRangeMap2 = findBreedRange(dog_map, std::string("Lakeland Terrier"));
	cout << breedRangeMap2 << "----------" << endl;
	DogMapDefault breedRangeMap3 = findBreedRange(dog_map, std::string("Pug"));
	cout << breedRangeMap3 << "----------" << endl;
	DogMapDefault breedRangeMap4 = findBreedRange(dog_map, std::string("Xyz"));
	cout << breedRangeMap4 << "----------" << endl;
	DogMapDefault breedRangeMap5 = findBreedRange(dog_map, std::string("Bull Terrier"));
	cout << breedRangeMap5 << "----------" << endl;

	cout << "4. PALINDROME" << endl;
	test_is_palindrome();
	cout << "\n";

	cout << "5. SECOND_MAX" << endl;
	vector<int> v1{ 1 }; // one element
	test_second_max(v1);

	vector<int> v2{ 1, 1 }; // all elements equal
	test_second_max(v2);

	vector<int> v3{ 1, 1, 3, 3, 7, 7 }; // at least with two distict elements
	test_second_max(v3);
	cout << "\n";

	
	cout << "6. STRINGS OF EQUAL LENGTH" << endl;
	vector<string> vecstr
	{ "count_if", "Returns", "the", "number", "of", "elements", "in", "the",
	   "range", "[first", "last)", "for", "which", "pred", "is", "true."
	};
	cout << testCountStringsLambda(vecstr, 5) << endl;
	cout << testCountStringsFreeFun(vecstr, 5) << endl;
	cout << testCountStringsFunctor(vecstr, 5) << endl;
	cout << "\n";
	
	
	cout << "7. SORTING STRINGS" << endl;
	multisetUsingMyComparator();
	cout << "\n";
	*/
	return 0;

}