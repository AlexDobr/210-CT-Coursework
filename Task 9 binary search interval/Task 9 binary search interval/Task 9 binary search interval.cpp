#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

bool binarySearch(vector<int> input, int lowValue, int highValue, int low, int high)
{
	int mid;

	if (low > high)
	{
		return false;
	}
	else
	{
		mid = (low + high) / 2;

		if (input[mid] <= highValue && input[mid] >= lowValue)
		{
			return true;
		}
		else if (input[mid] < lowValue)
		{
			return binarySearch(input, lowValue, highValue, mid + 1, high);
		}
		else
		{
			return binarySearch(input, lowValue, highValue, low, mid - 1);
		}
	}
};

int main()
{
	vector<int> input = { 12, 22, 34, 47, 55, 67, 82, 98 };

	int lowValue;
	int highValue;

	cout << " Enter a low value for the interval: " << endl;
	cin >> lowValue;
	cout << " Enter a high value for the interval: " << endl;
	cin >> highValue;


	bool result = binarySearch(input, lowValue, highValue, 0, input.size());
	cout << result << endl;

	return 0;
}
