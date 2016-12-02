// Task 1 Shuffle.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include<iostream>
#include<time.h>
#include<vector>
#include <stdlib.h> 

using namespace std;

vector<int> shuffle(vector<int> v)
{
	srand(time(NULL)); // random seed
	for (int i = 0; i < v.size(); i++)
	{


		int random = rand() % v.size();  // generate randon number from 0 to size 
		int temp = v[i];
		v[i] = v[random];
		v[random] = temp;
	}
	return v;

}



int main()
{
	vector<int> v;
	v = { 1,2,3,4,5,6,7,8,9,10 };
	v = shuffle(v);
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}

	return 0;
}

