#include "stdafx.h" // remove if you are not using Microsoft Visual Studio
#include<iostream>
#include<string>

using namespace std;

int isPrime(int n, int d)
{
	if (d == 1) // base case nr.1
	{
		cout << "The number is prime." << endl;  //checks if the number is equal to 1(base case 1)
	}
	else if (n % d == 0) // checks if the number is divisible by d(base case d)
	{
		cout << "The number is NOT prime." << endl;
	}
	else
	{
		return isPrime(n, d - 1); //calling function recursively
	}

}

int main()
{
	int n;
	cout << "Enter a number: " << endl;
	cin >> n;
	int d = n - 1;
	isPrime(n, d);
}


/* PSEUDOCODE

ISPRIME(n,d)
if d=1
print "The number is prime."
else if n%d=0
print "The number is NOT prime."
else
return ISPRIME(n, d-1)

*/
