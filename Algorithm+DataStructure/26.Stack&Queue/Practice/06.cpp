#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> result;
	string str;

	cin >> str;

	int over = 5;
	for (int i = str.size() - 1; i >= 0; --i)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			int num = str[i] - '0';
			num += over;

			if (num >= 10)
			{
				num = num - 10;
				over = 1;
			}
			else
			{
				over = 0;
			}

			result.push_back(num);

			if (i - 1 >= 0 && (str[i - 1] < '0' || str[i - 1] > '9'))
				break;
		}
	}

	if (over) result.push_back(1);

	reverse(result.begin(), result.end());

	for (auto& data : result) cout << data;

	return 0;
}