#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void MoveZeroes(vector<int>& nums)
{
	int numIdx = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] != 0)
			nums[numIdx++] = nums[i];
	}

	while (numIdx < nums.size()) nums[numIdx++] = 0;
}

int main()
{
	vector<int> nums = { 0, 1, 0, 3, 12 };

	MoveZeroes(nums);

	for (auto& data : nums) cout << data << " ";
	return 0;
}