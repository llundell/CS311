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
#include <map>
#include <vector>
#include <algorithm>    // std::sort

void printWordMap(const std::map<string, std::vector<string> > & wordMap) {

	cout << "Number of distinct words: " << wordMap.size() << endl;
	for (auto iter = wordMap.cbegin(); iter != wordMap.cend(); iter++)
	{
		//retrieve vector, (so we can sort it. had issues sort via iter->secon.begin())
		std::vector<string> v = iter->second;
		//sort
		std::sort(v.begin(),v.end());
		//print the key
	    cout << iter->first << ": ";

		//loop vector, aka the value attached to the key
	    for (auto list_iter = v.begin(); list_iter != v.end(); list_iter++)
			//print each word to screen seperated by space
	        cout << " " << *list_iter;
		//move to new line
		cout << endl;
	}

}

bool currentWordIsNotPresentInKey(const std::vector<string> & wordVector, string word) {

	//if find reaches the end of the vector witout finding the word, then it isnt yet present for that key
	if (std::find(wordVector.begin(), wordVector.end(), word) == wordVector.end() ) {
		return true;
	}
	else {
		return false;
	}
}




int main()
{
	string file, word;
	string previousWord;
	ifstream inputFile;
	std::set<string> wordList;
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
	int counts;
	while(inputFile >> word)
	{

		//if were on the first word, just make the previous word the current word and move on
		if (counts < 1) {
			previousWord = word;
			counts++;
			continue;
		}
		else {
			//if current word is not already in key, add it!
			if (currentWordIsNotPresentInKey(wordMap[previousWord], word)) {
				wordMap[previousWord].push_back(word);
			}
			//set previous word to current word
			// previousWord = word;
		}
		previousWord = word;
		counts++;

		//TODO get rid of old testing
		wordList.insert(word);
	}
	wordMap[previousWord].push_back("");


	printWordMap(wordMap);

	//TODO get rid of old testing
	cout<< "There are " << counts << " total words and " <<
		wordList.size() << " distinct words in the file." << endl;
	return 0;
}
