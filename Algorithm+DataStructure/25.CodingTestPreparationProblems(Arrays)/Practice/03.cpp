//规过1
#include <iostream>
#include <vector>

using namespace std;

void RotateNum(vector<int>& nums, int k)
{
	int swapCount = 0;
	for (int i = 0; swapCount < nums.size(); ++i)
	{
		int tmp = nums[i];
		int targetPos = i;
		int targetPrevPos = (targetPos - k);
		targetPrevPos = targetPrevPos < 0 ? nums.size() + targetPrevPos : targetPrevPos;
		while (targetPrevPos != i)
		{
			nums[targetPos] = nums[targetPrevPos];
			targetPos = targetPrevPos;
			targetPrevPos = targetPrevPos - k;
			targetPrevPos = targetPrevPos < 0 ? nums.size() + targetPrevPos : targetPrevPos;
			++swapCount;
		}
		nums[targetPos] = tmp;
		++swapCount;
	}
}

int main()
{
	vector<int> nums = { 1, 2, 3, 4, 5, 6, 7 };
	int k = 3;

	RotateNum(nums, k);

	for (auto& data : nums) cout << data << " ";

	return 0;
}

//规过2
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//void Reverse(vector<int>::iterator start, vector<int>::iterator end)
//{
//	vector<int>::iterator f = start;
//	vector<int>::iterator l = end - 1;
//	while (f < l)
//	{
//		int tmp = *f;
//		*f = *l;
//		*l = tmp;
//
//		++f;
//		--l;
//	}
//}
//
//int main()
//{
//	vector<int> nums = { 1, 2, 3, 4, 5, 6, 7 };
//	int k = 3;
//
//	Reverse(nums.begin(), nums.end());
//	Reverse(nums.begin(), nums.begin() + k);
//	Reverse(nums.begin() + k, nums.end());
//
//	for (auto& data : nums) cout << data << " ";
//
//	return 0;
//}
