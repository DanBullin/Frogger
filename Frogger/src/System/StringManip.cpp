#include ".\System\StringManip.h"

StringManip::StringManip()
{

}

string StringManip::getParameter(string sFileLine, int iParameter)
{
	// Returns the parameter wanted in a line which is a line from the config file
	char cParameterSeperator = ' '; // The seperator of values inside text file
	int iCount = 0;
	string str, substring, substring2;
	str = sFileLine;

	while(iCount != iParameter)
	{
		int iSpaceIndex = sFileLine.find_first_of(cParameterSeperator); // Find index of first space
		substring = sFileLine.substr(iSpaceIndex + 1, (sFileLine.length() - iSpaceIndex + 1)); // Create a substring starting from that index + 1 to end
		substring2 = sFileLine.substr(sFileLine.find_first_of(cParameterSeperator) + 1, substring.find_first_of(cParameterSeperator)); // Find the first space of that substring and create another substring
		sFileLine = substring;
		iCount++; // Add 1 to counter for whichever parameter we want
	}

	return substring2; // Return parameter
}

string StringManip::BoolConvertToString(bool bValue)
{
	if(bValue == true)
	{
		return "True";
	}
	else
	{
		return "False";
	}
}
