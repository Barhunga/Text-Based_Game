//#define _CRT_SECURE_NO_WARNINGS         // for use with strcpy and strcat
#include "String.h"
#include <iostream>
using namespace std;

// Default constructor
String::String() {
	_string = new char[1];
	_string[0] = '\0';
	//cout << "default constructor called\n";
}

// Constructor for characters
String::String(const char* _str) {
	_string = new char[strlen(_str) + 1];
	for (size_t i = 0; i < Length(); i++) {
		_string[i] = _str[i];
	}
	//strcpy(_string, _str);			   //    <- Alternative with _CRT_SECURE_NO_WARNINGS
	//cout << "2nd constructor called\n";
}

// Copy constructor
String::String(const String& _other) {
	_string = new char[_other.Length() + 1];
	for (size_t i = 0; i < Length(); i++) {
		_string[i] = _other[i];            //    const [] overload - used in other functions also
	}
	//strcpy(_string, _other._string);	   //    <- Alternative with _CRT_SECURE_NO_WARNINGS
	//cout << "copy constructor called\n";
}

// Destructor
String::~String() {
	delete[] _string;
	_string = nullptr;
	//cout << "destructor called\n";
}

// Returns an integer representing the length of the string
size_t String::Length() const
{
	size_t _length = 0;
	for (int i = 0; _string[i] != '\0'; i++) {
		_length++;
	}
	return _length;
}

// Returns character at _index 
char& String::CharacterAt(size_t _index)
{
	if (_index >= 0 && _index < Length()) { // If index is in range of the string, returns the character at index
		return _string[_index];
	}
	else {
		return _string[Length()]; // Returns null terminator
	}
}

// Returns character at _index (const version)
const char& String::CharacterAt(size_t _index) const
{
	if (_index >= 0 && _index < Length()) {
		return _string[_index];
	}
	else {
		return _string[Length()];
	}
}

// Returns true if _other contains the same characters.
bool String::EqualTo(const String& _other) const
{
	for (size_t i = 0; i < Length() || i < _other.Length(); i++) { 
		if (_string[i] != _other._string[i]) {
			return false;
		}
	}
	return true;
	//if (strcmp(_string, _other._string) == 0) {	//	<- Alternative
	//	return true;
	//}
	//return false;
}

// Adds str to the end of the string
String& String::Append(const String& _str)
{
	// Create new empty string with length of both strings combined 
	size_t new_length = Length() + _str.Length();
	char* new_string = new char[new_length + 1];

	// Copy first string to the new string
	for (size_t i = 0; i < Length(); i++) {
		new_string[i] = _string[i];
	}
	// strcpy(new_string, _string);       //  <- Alternative with _CRT_SECURE_NO_WARNINGS

	// Copy second string to index after first string in the new string
	for (size_t i = 0; i < new_length; i++) {
		new_string[i + Length()] = _str[i];
	}
	//strcat(new_string, _str._string);  //  <- Alternative with _CRT_SECURE_NO_WARNINGS

   // Delete old string data, assign string to the new string created
	delete[] _string;
	_string = new_string;
	return *this;
}

// Adds str to the beginning of the string
String& String::Prepend(const String& _str)
{
	// Create new empty string with length of both strings combined 
	size_t new_length = Length() + _str.Length();
	char* new_string = new char[new_length + 1];

	// Copy second string to the new string 
	for (size_t i = 0; i < _str.Length(); i++) {
		new_string[i] = _str[i];
	}
	//strcpy(new_string, _str._string);  //  <- Alternative with _CRT_SECURE_NO_WARNINGS

   // Copy first string to index after second string in the new string
	for (size_t i = 0; i < new_length; i++) {
		new_string[i + _str.Length()] = _string[i];
	}
	//strcat(new_string, _string);       //  <- Alternative with _CRT_SECURE_NO_WARNINGS

   // Delete old string data, assign string to the new string created
	delete[] _string;
	_string = new_string;
	return *this;
}

// Return the const char * that is useable with std::cout
const char* String::CStr() const
{
	return _string;
}

// Return string in lowercase
String& String::ToLower()
{
	for (int i = 0; i < Length(); i++) {
		if (_string[i] >= 65 && _string[i] <= 92) { // If uppercase character
			_string[i] += 32; // Makes character lower case
		}
		//_string[i] = tolower(_string[i]);   //  <- Alternative
	}
	return *this;
}

// Return string in uppercase
String& String::ToUpper()
{
	for (int i = 0; i < Length(); i++) {
		if (_string[i] >= 97 && _string[i] <= 122) { // If lowercase character
			_string[i] -= 32; // Makes character upper case
		}
		//_string[i] = toupper(_string[i]);   //  <- Alternative
	}
	return *this;
}

// Returns the location of _str. If not found, return -1
size_t String::Find(const String& _str)
{
	return Find(0, _str);
}

// Returns the location of _str beginning the search from startIndex. If not found, return -1
size_t String::Find(size_t _startIndex, const String& _str)
{
	// Checking from the start index while it is less than the length of the string
	for (size_t i = _startIndex; i < Length(); i++) {

		// If the character matches the first character of _str
		if (_string[i] == _str[0]) {
			int success = 1;

			// From the next character until the last character of _str
			for (size_t j = 1; j < _str.Length(); j++) {

				// Increment success counter if they match/break the loop if they don't
				if (_string[i + j] == _str[j]) {
					success++;
				}
				else break;
			}
			// If the amount of successful matches is the same as the length of _str, return the starting position of that success 
			if (success == _str.Length()) {
				return i;
			}
		}
	}
	// Return -1 if nothing matches completely
	return -1;

	//if (strstr(_string + _startIndex, _str._string) != nullptr); {    // <- Alternative
	//	return strstr(_string + _startIndex, _str._string) - _string;
	//}
	//return -1;
}

// Replaces all occurrences of _find with _replace in a string
String& String::Replace(const String& _find, const String& _replace)
{
	// If no instances are found, return the string
	if (Find(_find) == -1) {
		return *this;
	}
	// Start loop ready to replace instances
	size_t start_index = Find(_find);
	int found = 1;
	while (start_index != -1) {

		// Create a new empty string with length accounting for the current replacement
		size_t new_length = Length() - _find.Length() + _replace.Length() + 1;
		char* new_string = new char[new_length];

		// Copy start of string to new string
		for (size_t i = 0; i < start_index; i++) {
			new_string[i] = _string[i];
		}

		// Copy _replace where _find was
		for (size_t i = start_index; i < start_index + _replace.Length(); i++) {
			new_string[i] = _replace[i - start_index];
		}

		// Continue to copy the rest of the string as it was
		for (size_t i = start_index + _replace.Length(); i < new_length; i++) {
			new_string[i] = _string[i - (_replace.Length() - _find.Length())];
		}

		// Delete old string data, assign string to the new string created
		delete[] _string;
		_string = new_string;

		// Update found counter if there is another instance to replace
		if (Find(start_index + _replace.Length(), _find) != -1) {
			found++;
		}
		// Set new start_index
		start_index = Find(start_index + _replace.Length(), _find);
	}
	cout << "Found and replaced " << found << " occurances\n";
	return *this;
}

// Wait for input in the console window and store the result
String& String::ReadFromConsole()
{
	cout << "\nEnter input\n";
	char input[1000];
	cin.getline(input, 1000);
	*this = input;
	return *this;
}

// Write the string to the console window.
String& String::WriteToConsole()
{
	cout << _string << endl;
	return *this;
}

//  Returns true if lhs == rhs
bool String::operator==(const String& _other)
{
	return EqualTo(_other) == 1;
}

// Returns true if lhs != rhs
bool String::operator!=(const String& _other)
{
	return !(*this == _other);
}

// Replaces the characters in lhs with the characters in rhs
String& String::operator=(const String& _str)
{
	delete[] _string;
	_string = new char[_str.Length() + 1];
	for (size_t i = 0; i < Length(); i++) {
		_string[i] = _str[i];
	}
	//strcpy(_string, _str._string);			 // Alternative with _CRT_SECURE_NO_WARNINGS
	return *this;
}

// Returns the character located at index
char& String::operator[](size_t _index)
{
	return _string[_index];
}

// Returns the character located at index (const version)
const char& String::operator[](size_t _index) const
{
	return _string[_index];
}