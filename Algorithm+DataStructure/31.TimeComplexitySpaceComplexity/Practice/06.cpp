#include <iostream> 
#include <vector>

using namespace std;

int ps;
vector<int> pk = { 1, 2, 3, 3, 5, 1, 0, 1, 3 };


void Input()
{
	cin >> ps;
}

int Sum(auto start, auto end)
{
	int sum = 0;
	for (; start != end; ++start)
	{
		sum += *start;
	}

	return sum;
}

int FindMinCharge()
{
	int min = INT_MAX;
	for (auto iter = pk.begin(); iter != pk.end() - ps; ++iter)
	{
		int num = Sum(iter, iter + ps);
		if (min > num)
			min = num;
	}

	return min;
}

int main()
{
	Input();
	cout << FindMinCharge();

	return 0;
}