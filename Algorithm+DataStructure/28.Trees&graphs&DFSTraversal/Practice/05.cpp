#include <iostream>
#include <vector>

using namespace std;


int main()
{
	int input;
	vector<int> nums;

	cin >> input;

	int over = 0;
	while (input > 0)
	{
		int digit = input % 10 + 1 + over;
		over = digit / 10;
		digit %= 10;

		nums.push_back(digit);
		input /= 10;
	}

	if (over)
		nums.push_back(over);

	for (auto& data : nums)
		cout << data;

	return 0;

}