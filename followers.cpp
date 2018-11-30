//	followers.cpp
//	Laura Lundell & Khan Howe
//	For CS 311 Fall 2018
//	Started: 11/29/18
//	Updated: 12/4/18
//	Source for followers.cpp
//	Exercise A: Following-Words Program
/*	Sources used:
*			Dr. Chappell's slides on Project 8 thoughts
*
*/

#include <iostream>
#include <string>
using std::string;
using std::getline;
using std::cin;
using std::cout;
using std::endl;
#include <fstream>
using std::ifstream;

int main()
{
	string file;




	while (true)
	{
		cout<<"Enter a file name to be read: "<<endl;
		getline(cin, file);
		ifstream inputFile {file};

		// if(!inputFile)
		// {
		//
		// }
		if (inputFile.is_open())
		{
			while(getline(inputFile, file))
			{
				cout<< file << endl;
			}


		}
		else cout << "Unable to open file";



	}
	return 0;
}
