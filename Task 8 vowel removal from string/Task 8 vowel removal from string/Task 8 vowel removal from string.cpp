#include "stdafx.h"
#include<iostream>
#include<string>


using namespace std;


string vowelRemoval(string sentence)
{
	if (sentence.length() == 0)
	{
		return sentence;
	}
	if (sentence[0] == 'a' || sentence[0] == 'e' || sentence[0] == 'i' || sentence[0] == 'o' || sentence[0] == 'u' || sentence[0] == 'A' || sentence[0] == 'E' || sentence[0] == 'I' || sentence[0] == 'O' || sentence[0] == 'U') //check if character is a vowel
	{
		return vowelRemoval(sentence.substr(1)); // jumps over character if it is a vowel
	}
	else
	{
		return sentence[0] + vowelRemoval(sentence.substr(1));  // adds letter if it is not a vowel
	}
}


int main()
{
	string sentence;
	cout << "Enter a sentence: (The vowels will be removed from them)" << endl;
	getline(cin, sentence);
	cout << vowelRemoval(sentence) << endl;
	return 0;
}

/*  PSEUDOCODE

vowelRemoval(sentence)

if length of sentence is 0
return sentence
if sentence[1] = vowel(case sensitive)
return vowelRemoval (rest of sentence)
else
return sentence[1] + vowelRemoval (rest of sentence)


*/
