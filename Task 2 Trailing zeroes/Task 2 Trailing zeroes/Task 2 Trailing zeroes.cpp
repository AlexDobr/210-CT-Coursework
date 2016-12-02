#include "stdafx.h"
#include "stdafx.h"
#include<iostream>
#include<math.h>
using namespace std;


int main()
{
	int n;
	int i;
	int counter = 0;
	cout << "Input the factorial number: " << endl;
	cin >> n;

	// count factors of 5
	for (i = 5; n / i >= 1; i = i * 5)
	{
		counter = counter + n / i;
	}
	cout << "The number of trailing zeroes is: " << counter << endl;


}
