#include <iostream>
#include <vector>
using namespace std;

vector<int> arr1(4);
vector<int> arr2(4);
vector<int> result(arr1.size() + arr2.size());
void Input()
{
	for (int i = 0; i < arr1.size(); ++i)
	{
		cin >> arr1[i];
	}

	for (int i = 0; i < arr2.size(); ++i)
	{
		cin >> arr2[i];
	}
}

void SortTwoArr()
{
	int i1 = 0;
	int i2 = 0;
	int r = 0;
	while (i1 < arr1.size() && i2 < arr2.size())
	{
		int min;
		if (arr1[i1] < arr2[i2])
			min = arr1[i1++];
		else
			min = arr2[i2++];

		result[r++] = min;
	}

	if (i1 < arr1.size())
	{
		for (int i = i1; i < arr1.size(); ++i)
		{
			result[r] = arr1[i];
		}
	}
	else if (i2 < arr2.size())
	{
		for (int i = i2; i < arr2.size(); ++i)
		{
			result[r] = arr2[i];
		}
	}
}

int main()
{
	Input();
	SortTwoArr();

	for (const auto& data : result)
		cout << data << " ";

	return 0;
}