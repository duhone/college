//Name Eric Duhon
//SSN: 453-97-8531

#include <String.h>
#include <strings.h>
#include <stdio.h>



String::String()
{
	charstring = NULL;
	charstring = new char[1];
	charstring[0] = 0;
}

String::String(const String& strarg)
{
	charstring = NULL;
	charstring = new char[strlen(strarg.charstring) + 1];
	strcpy(charstring,strarg.charstring);
}

String::String(const char* const strarg)
{
	charstring = NULL;
	charstring = new char[strlen(strarg) + 1];
	strcpy(charstring,strarg);

}

String& String::operator=(const String& strarg)
{
	if(this != &strarg)
	{
		if(charstring != NULL)
			delete[] charstring;
		charstring = NULL;
		charstring = new char[strlen(strarg.charstring) + 1];
		strcpy(charstring,strarg.charstring);
	}
	return *this;

}

String String::operator+(const String& strarg) const
{
	String returnstring;
	char *tempstring = NULL;
	tempstring = new char[strlen(charstring) + strlen(strarg.charstring) + 1];
	strcpy(tempstring,charstring);
	strcat(tempstring,strarg.charstring);
	returnstring = tempstring;
	delete[] tempstring;
	return returnstring;
}



String::~String()
{
	if(charstring != NULL)
		delete[] charstring;
}

const char* String::getsring() const
{
	return charstring;
}

const char& String::operator[](const unsigned int subscript) const
{
	if(subscript >= strlen(charstring)) 
	{
		char message[100];
		sprintf(message,"Access attempt position %d on string of size %d",subscript,strlen(charstring));
		throw OutOfRange(message);	
	}
	return charstring[subscript];
}

char& String::operator[](const unsigned int subscript)
{
	static char garbage = 'E';
	if(subscript >= strlen(charstring)) return garbage;
	return charstring[subscript];
}

bool String::operator!() const
{
	if(strlen(charstring) > 0) return false;
	else return true;
}

ostream& operator<<(ostream& s,const String& strarg)
{
	return s << strarg.getsring();
}

istream& operator>>(istream& s,String& strarg)
{
	char* buffer;
	buffer = new char[256];
	cin.width(256);
	s >> buffer;
	strarg = buffer;
	delete[] buffer;
	return s;
}

OutOfRange::OutOfRange()
{
	message = "There was some error";
}

OutOfRange::OutOfRange(const OutOfRange& arg)
{
	message = arg.message;
}

OutOfRange::OutOfRange(const String& arg)
{
	message = arg;
}

OutOfRange::OutOfRange(const char* arg)
{
	message = arg;
}

OutOfRange& OutOfRange::operator=(const OutOfRange& arg)
{
	if(this != &arg)
	{
		message = arg.message;
	}
	return *this;
}

OutOfRange::~OutOfRange()
{

}

const char* OutOfRange::getError()
{

	return message.getsring();
}
