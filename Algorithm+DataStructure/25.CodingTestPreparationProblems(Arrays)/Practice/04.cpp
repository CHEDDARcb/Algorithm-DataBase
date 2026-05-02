#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int>& nums)
{
	int result = 0;

	for (int i = 0; i < nums.size(); ++i)
	{
		result ^= nums[i];
	}

	return result;
}

int main()
{
	std::vector<int> nums = { 4, 1, 2, 1, 2 };
	int result = singleNumber(nums);

	cout << result;

	return 0;
}