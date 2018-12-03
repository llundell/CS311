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
#include <set>

int main()
{
	string file, word;
	ifstream inputFile;
	std::set<string> wordList;

	while (true)
	{
		cout<<"Enter a file name to be read: "<<endl;
		getline(cin, file);
		inputFile.open(file);
		if (inputFile.is_open())
			break;
		cout << "Unable to open file. Try another filename." << endl;
	}
	int counts;
	while(inputFile >> word)
	{
		counts++;
		wordList.insert(word);
	}

	cout<< "There are " << counts << " total words and " <<
		wordList.size() << " distinct words in the file." << endl;
	return 0;
}
