#include <iostream>

using namespace std;

int main()
{
	int arr1[4];
	int arr2[4];

	for (auto& data : arr1)
		cin >> data;

	for (auto& data : arr2)
		cin >> data;

	int result[8];
	int idx1 = 0, idx2 = 0, rIdx = 0;
	while (idx1 < 4 || idx2 < 4)
	{
		// End Arr1
		if (idx1 >= 4)
		{
			for (int i = idx2; i < 4; ++i)
			{
				result[rIdx++] = arr2[i];
			}
			break;
		}
		else if (idx2 >= 4)
		{
			for (int i = idx1; i < 4; ++i)
			{
				result[rIdx++] = arr1[i];
			}
			break;
		}

		int min;
		if (arr1[idx1] < arr2[idx2])
			min = arr1[idx1++];
		else
			min = arr2[idx2++];

		result[rIdx++] = min;
	}

	for (const auto& data : result)
		cout << data << " ";

	return 0;
}