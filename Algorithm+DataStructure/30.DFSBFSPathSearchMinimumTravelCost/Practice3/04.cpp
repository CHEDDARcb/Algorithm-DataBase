#include <iostream>
#include <list>

using namespace std;

list<int> inputs;
int n;
int result = 0;

void Input()
{
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int data;
		cin >> data;

		inputs.push_back(data);
	}
}

int FindMin(bool isFirst)
{
	auto iter = inputs.begin();
	if (isFirst)
	{
		while (iter != inputs.end() && *iter == 0)
			++iter;
		if (iter == inputs.end())
			iter = inputs.begin();
	}

	auto min = iter;
	for (; iter != inputs.end(); ++iter)
	{
		if (*min > *iter)
		{
			if (*iter == 0 && isFirst)
				continue;
			min = iter;
		}
	}

	int result = *min;
	inputs.erase(min);
	return result;
}

void Solution()
{
	int num = FindMin(true);
	result += num;

	int k = n < 3 ? n : 3;
	--k;

	for (int i = 0; i < k; ++i)
	{
		result *= 10;
		num = FindMin(false);
		result += num;
	}
}
int main()
{
	Input();
	Solution();

	cout << result;
}