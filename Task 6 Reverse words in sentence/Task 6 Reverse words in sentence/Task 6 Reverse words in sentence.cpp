#include "stdafx.h"
#include<iostream>
#include<cmath>
#include<math.h>


using namespace std;

int main()
{
	int n;
	cout << "Enter a number: " << endl;
	cin >> n;

	cout << "The closest perfect square to " << n << " is " << (floor(sqrt(n)))*(floor(sqrt(n))) << endl;

	// returns highest perfect square by floor multiplying the square root of given number. 


}



/* PSEUDOCODE

INPUT n
print floor (sqrt n) * floor (sqrt n)

*/
