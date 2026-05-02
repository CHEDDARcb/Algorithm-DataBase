#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	int sts[6];

	for (auto& st : sts)
		cin >> st;

	for (int i = 0; i < 5; ++i)
	{
		if (std::abs(sts[i] - sts[i + 1] > 3))
		{
			cout << "재배치필요";
			return 0;
		}
	}

	cout << "완벽한배치";

	return 0;
}