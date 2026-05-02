#include <iostream>
#include <vector>

using namespace std;

int dma[10000]{};

std::pair<int, int> TwoSum(std::vector<int>& nums, int target)
{
	for (int i = 0; i < nums.size(); ++i)
	{
		int remainNum = target - nums[i];
		if (remainNum > 0)
		{
			if (dma[remainNum])
			{
				return { i, dma[remainNum] - 1 };
			}
			dma[nums[i]] = i + 1;
		}
	}

	return { -1, -1 };
}

int main()
{
	std::vector<int> nums = { 3, 2, 4 };
	int target = 6;
	auto result = TwoSum(nums, target);

	cout << result.first << ", " << result.second;

	return 0;
}