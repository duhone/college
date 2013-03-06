//Name Eric Duhon
//SSN: 453-97-8531

// String class abstracts a String of characters. Only ascii strings are supported. The
// operators +,=,!,[],<<, and >> are overloaded for your conveniance.


#include <iostream.h>



class String
{
public:
	String();
		//Purpose: To create a new string
		//Requirement:
		//Promise: will create a new empty string
		//Exception: 
	String(const String& strarg);
		//Purpose: To create a new string
		//Requirement: a String object
		//Promise: will create a new string with the same value as strarg
		//Exception: 
	String(const char* strarg);
		//Purpose: To create a new string
		//Requirement: a null terminated array of characters
		//Promise: will create a new string with the same value in strarg
		//Exception: 
	String& operator=(const String& strarg);
		//Purpose: To assign the value of strarg to this string
		//Requirement:A String object
		//Promise: will copy the value of strarg to this string
		//Exception: 
	String operator+(const String& strarg) const;
		//Purpose: To concatenate this string with strarg and return the result
		//Requirement:A String object
		//Promise: will not modify this string or strarg.
		//Exception: 
	~String();
		//Purpose: To destroy this string
		//Requirement:
		//Promise: will free all memory used by this string
		//Exception: 
	const char* getsring() const;
		//Purpose: To return a character array representing this string
		//Requirement:
		//Promise: will return the value of this string
		//Exception: 
	const char& operator[](const unsigned int subscript) const;
		//Purpose: To get the character value at position subscript
		//Requirement:An int with the subsript of the required character
		//Promise: will not modify this object
		//Exception:will throw outofrange if subscript is not a valid index
	char& operator[](const unsigned int subscript);
		//Purpose: To get a refrence to the character value at position subscript
		//Requirement:An int with the subsript of the required character
		//Promise: will return a character reference ready to be modified
		//Exception:will throw outofrange if subscript is not a valid index 
	bool operator!() const;
		//Purpose: To determin if a string is empty
		//Requirement:
		//Promise: will return true if empty false if not empty
		//Exception: 
private:
	char* charstring;



};

ostream& operator<<(ostream& s,const String& strarg);
		//Purpose: To output the string to the ostream
		//Requirement:A String object
		//Promise: will output the string strarg to the ostream
		//Exception: 

istream& operator>>(istream& s,String& strarg);
		//Purpose: To get input from istream and put it into strarg
		//Requirement:A String object
		//Promise: will take the input from istream and place it into strarg. there is a Maximum 
		//			of 256 characters
		//Exception: 

class OutOfRange
{
public:
	OutOfRange();
		//Purpose: To create an outofrange exeption
		//Requirement:
		//Promise: will create an outofrange exeption with an empty message
		//Exception: 
	OutOfRange(const OutOfRange& arg);
		//Purpose: To create an outofrange exeption
		//Requirement:An outofrange object
		//Promise: will create an outofrange exeption with the same message as arg
		//Exception: 
	OutOfRange(const String& arg);
		//Purpose: To create an outofrange exeption
		//Requirement:a string object
		//Promise: will create an outofrange exeption with the same message as arg
		//Exception: 
	OutOfRange(const char* arg);
		//Purpose: To create an outofrange exeption
		//Requirement:a character array
		//Promise: will create an outofrange exeption with the same message as arg
		//Exception: 
	OutOfRange& operator=(const OutOfRange& arg);
		//Purpose: To asign the message of arg to this object
		//Requirement:An outofrange object
		//Promise: will asign the message of arg to this object
		//Exception: 
	~OutOfRange();
		//Purpose: To destroy outofrange object
		//Requirement:
		//Promise: will free any memory used by outofobject
		//Exception: 
	const char* getError();
		//Purpose: To get the error message held by this object
		//Requirement:
		//Promise: will return the message contained in this object
		//Exception: 
private:
	String message;
};
