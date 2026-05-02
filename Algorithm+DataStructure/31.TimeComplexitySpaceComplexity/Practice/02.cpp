#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> arr;

void Input()
{
	cin >> n;

	arr.reserve(n);

	for (int i = 0; i < n; ++i)
	{
		int data;
		cin >> data;
		arr.push_back(data);
	}
}

int FourSum(auto start, auto end)
{
	int sum = 0;
	for (; start != end; ++start)
	{
		sum += *start;
	}

	return sum;
}

int Solution()
{
	int min = INT_MAX;
	for (auto iter = arr.begin();
		iter != arr.end() - 4 - 1; ++iter)
	{
		int num = FourSum(iter, iter + 4);

		if (min > num)
			min = num;
	}

	return min;
}

int main(void)
{
	Input();
	cout << Solution();

	return 0;
}
