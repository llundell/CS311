//	followers.cpp
//	Laura Lundell & Khan Howe
//	For CS 311 Fall 2018
//	Started: 11/29/18
//	Updated: 12/4/18
//	Source for followers.cpp
//	Exercise A: Following-Words Program
/*	Sources used:
*			Dr. Chappell's slides on Project 8 thoughts
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
#include <map>
#include <vector>
#include <algorithm>	// std::sort


//	printWordMap()
//	Pre-conditions:
//		Valid map container passed in
//	Post-conditions: Prints each distinct word followed by the word that
//		immediately follows the each word, in lexicographic order
//	Strong Guarantee
void printWordMap(const std::map<string, std::vector<string> > & wordMap)
{
	cout << "Number of distinct words: " << wordMap.size() << endl;
	for (auto iter = wordMap.cbegin(); iter != wordMap.cend(); iter++)
	{
		std::vector<string> v = iter->second;
		//	Sort in lexicographic order
		std::sort(v.begin(),v.end());
	    cout << iter->first << ": ";
	    for (auto list_iter = v.begin(); list_iter != v.end(); list_iter++)
	        cout << " " << *list_iter;
		cout << endl;
	}

}

//	currentWordIsNotPresentInKey()
//	Pre-conditions:
//		Valid vector and string passed in the function
//	Post-conditions: Returns true if the current word is not already in the wordVector
//	Strong Guarantee
bool currentWordIsNotPresentInKey(const std::vector<string> & wordVector, string word)
{
	if (std::find(wordVector.begin(), wordVector.end(), word) == wordVector.end() ) {
		return true;
	}
	else {
		return false;
	}
}

// main()
int main()
{
	string file, word;
	string previousWord;
	ifstream inputFile;
	std::map<string, std::vector<string> > wordMap;

	while (true)
	{
		cout<<"Enter a file name to be read: "<<endl;
		getline(cin, file);
		inputFile.open(file);
		if (inputFile.is_open())
			break;
		cout << "Unable to open file. Try another filename." << endl;
	}
	int counts = 0;
	while(inputFile >> word)
	{

		//	If we're on the first word, just make the previous word the current word and move on
		if (counts < 1)
		{
			previousWord = word;
			counts++;
			continue;
		}
		else
		{
			//	If current word is not already in key, add it!
			if (currentWordIsNotPresentInKey(wordMap[previousWord], word))
			{
				wordMap[previousWord].push_back(word);
			}
		}
		previousWord = word;
		counts++;
	}
	wordMap[previousWord].push_back("");
	printWordMap(wordMap);

	return 0;
}
