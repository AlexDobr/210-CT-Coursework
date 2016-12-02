#include "stdafx.h"
#include<iostream>
#include<vector>
#include<string>


using namespace std;


int main()
{
	vector<int> v = { 3,5,4,8,7,9,10,1,2,6 };
	vector<int> result = {};             // 3 vectors to find the longest ascending subsequence
	vector<vector <int>> subsequences = {};
	vector<int> currentSub = {};


	for (int i = 0; i<v.size() - 1; i++)
	{

		if (v[i] < v[i + 1])
		{
			currentSub.push_back(v[i]);
		}
		else
		{
			currentSub.push_back(v[i]);
			subsequences.push_back(currentSub);
			currentSub = {};

		}
	}
	int maxLength = 0;
	for (int i = 0; i < subsequences.size(); i++)
	{
		if (subsequences[i].size() > maxLength)
		{
			maxLength = subsequences[i].size();
			result = subsequences[i];
		}
	}
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << endl;
	}


}
