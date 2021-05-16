#include ".\System\FileIO.h"

FileIO::FileIO()
{

}

bool FileIO::openFile(string sFileName, int iIO)
{
	// iIO determines whether we open an ifstream or an ofstream
	if(iIO == 0)
	{
		inputfileHandle.open(sFileName);

		if(inputfileHandle.is_open())
		{
			// File is open
			return true;
		}
		else
		{
			// File isn't open -- Can't find file, was the right name used?
			return false;
		}	
	}
	else
	{
		outputfileHandle.open(sFileName);

		if(outputfileHandle.is_open())
		{
			// File is open
			return true;
		}
		else
		{
			// File isn't open -- Can't find file, was the right name used?
			return false;
		}		
	}
	
}

void FileIO::closeFile(int iIO)
{
	// Closes the files on whatever stream is passed
	if(iIO == 0)
	{
		inputfileHandle.close();	
	}
	else
	{
		outputfileHandle.close();	
	}
}

bool FileIO::readLine(string &sFileLine)
{
	if(getline(inputfileHandle, sFileLine))
	{
		return true;
	}
	else
	{
		closeFile(0);
		return false; // We have reached the end of the file
	}
}

void FileIO::writeLine(vector<string> sNames, vector<string> sScores)
{
	// Writes to file -- This only works for writing scoreboards but since no other writing to file is needed, won't change the structure of this func
	int iSize = sNames.size();
	for(int i = 0; i < iSize; i++)
	{
		outputfileHandle << "[Score] " << sNames[i] << " " << sScores[i] << "\n";
	}
	outputfileHandle.close();
}

int FileIO::stringConvertToInt(string sValue)
{
	return stoi(sValue);
}