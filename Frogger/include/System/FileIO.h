#ifndef FILEIO_H
#define FILEIO_H

#include <string>
#include <fstream>
#include <vector>

using namespace std;

class FileIO
{
	private:
		ifstream inputfileHandle;
		ofstream outputfileHandle;
	public:
		FileIO();
		bool openFile(string sFileName, int iIO); // The name of the file -- Returns whether the file is open or not (0 -- Input == 1 -- Output)
		void closeFile(int iIO);
		bool readLine(string &sFileLine); // Reads a line of the file. Returns true is a new line is found, false if not
		void writeLine(vector<string> sName, vector<string> sScore);

		int stringConvertToInt(string sValue);
};

#endif