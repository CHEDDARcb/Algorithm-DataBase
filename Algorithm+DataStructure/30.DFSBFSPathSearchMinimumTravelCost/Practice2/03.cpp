#include <iostream>
#include <vector>

using namespace std;

vector<int> base = { 1, 5, 4, 2, -5, -7 };

void Sort()
{
	// bubble
	//for (int i = 0; i < base.size() - 1; ++i)
	//{                                                                                                                  
	//	for (int j = 0; j < base.size() - i - 1; ++j)
	//	{
	//		if (base[j] > base[j + 1])
	//		{
	//			int tmp = base[j];
	//			base[j] = base[j + 1];
	//			base[j + 1] = tmp;
	//		}
	//	}
	//}

	// select
	for (int i = 0; i < base.size() - 1; ++i)
	{
		int minIdx = i;
		for (int j = i + 1; j < base.size(); ++j)
		{
			if (base[minIdx] > base[j])
				minIdx = j;
		}

		int tmp = base[i];
		base[i] = base[minIdx];
		base[minIdx] = tmp;
	}
}

int main()
{
	int input;

	cin >> input;

	Sort();

	cout << base[base.size() - input];

	return 0;
}