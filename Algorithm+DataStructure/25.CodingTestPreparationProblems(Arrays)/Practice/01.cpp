#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(std::vector<int>& nums)
{
	int c = 1;
	for (int i = 1; i < nums.size(); ++i)
	{
		if (nums[i] != nums[c - 1])
		{
			nums[c] = nums[i];
			++c;
		}
	}

	return c;
}

int main()
{
	std::vector<int> nums = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
	int newLength = removeDuplicates(nums);
	std::cout << "New length: " << newLength << std::endl;
	std::cout << "Modified array: ";
	for (int i = 0; i < newLength; ++i)
	{
		std::cout << nums[i] << " ";
	}
	std::cout << std::endl;


	return 0;
}