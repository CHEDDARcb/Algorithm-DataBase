#include <iostream>
#include <vector>

using namespace std;

void Sort(vector<int>& vec)
{
	for (int i = 0; i < vec.size(); ++i)
	{
		int min = i;
		for (int j = i + 1; j < vec.size(); ++j)
		{
			if (vec[min] > vec[j]) min = j;

		}
		int tmp = vec[i];
		vec[i] = vec[min];
		vec[min] = tmp;
	}
}

vector<int> Intersect(vector<int>& v1, vector<int>& v2)
{
	int p1 = 0;
	int p2 = 0;
	vector<int> result;
	while (p1 < v1.size() && p2 < v2.size())
	{
		if (v1[p1] == v2[p2])
		{
			result.push_back(v1[p1]);
			++p1;
			++p2;
		}
		else if (v1[p1] > v2[p2])
			++p2;
		else
			++p1;
	}

	return result;
}

int main()
{
	std::vector<int> nums1 = { 4,4,9 };
	std::vector<int> nums2 = { 9,4,9,8,4 };

	Sort(nums2);
	Sort(nums1);

	vector<int> result = Intersect(nums1, nums2);

	for (auto& data : result) cout << data << " ";

	return 0;
}