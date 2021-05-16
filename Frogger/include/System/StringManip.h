#ifndef STRINGMANIP_H
#define STRINGMANIP_H

#include <string>

using namespace std;

/*
	This class handles any from of string manipulation
*/

class StringManip
{
	private:

	public:
		StringManip();
		string getParameter(string sFileLine, int iParameter); // Finds what parameter you want from the string
		string BoolConvertToString(bool bValue); // Converts boolean to text value
};

#endif