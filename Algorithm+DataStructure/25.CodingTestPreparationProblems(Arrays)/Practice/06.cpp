#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> PlusOne(vector<int> num)
{
	for (int i = num.size() - 1; i >= 0; --i)
	{
		if (num[i] < 9)
		{
			num[i]++;
			return num;
		}
		num[i] = 0;
	}

	num.insert(num.begin(), 1);
	return num;
}

int main()
{
	vector<int> digits = { 9 };

	vector<int> result = PlusOne(digits);

	for (auto& data : result) cout << data << " ";

	return 0;
}