#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> nums(51);

void Init()
{
	cin >> n;

	for (int i = 0; i < nums.size(); ++i)
	{
		nums[i] = i;
	}
}

int main(void)
{
	Init();

	int u = 0;
	int d = nums.size() - 1;
	while (n--)
	{
		int data;
		string du;

		cin >> data >> du;

		if (du == "UP" && u < data)
			u = data;
		else if (du == "DOWN" && d > data)
			d = data;
	}

	if (d - u - 1 == 1)
		cout << u + 1;
	else if (d - u - 1 <= 0)
		cout << "ERROR";
	else
		for (int i = u + 1; i < d; ++i)
			cout << i << " ";

	return 0;
}