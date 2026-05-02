#include <iostream>
#include <vector>
using namespace std;

int start;
vector<int> nums = { 3, 2, -1, 3, -2, 0, -1 };

void Search(int idx)
{
	if (idx == 5)
	{
		cout << idx << "¹ø" << endl;
		return;
	}

	Search(idx + nums[idx]);
	cout << idx << "¹ø" << endl;
}

int main(void)
{
	cin >> start;

	Search(start);
	return 0;
}