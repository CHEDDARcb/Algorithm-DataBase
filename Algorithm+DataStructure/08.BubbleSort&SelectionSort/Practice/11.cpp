#include <iostream>

using namespace std;

int main(void)
{
	char arr[2][6] =
	{
		{'D', 'A', 'T', 'A', 'W', '\0'},
		{'B', 'B', 'Q', 'K', '\0', '\0'}
	};
	int input;

	cin >> input;

	int len1 = 0;
	while (arr[0][len1++] != '\0') {}
	--len1;

	int len2 = 0;
	while (arr[1][len2++] != '\0') {}
	--len2;

	if (input % 2)
	{
		//Bubble
		//for (int i = 0; i < len1 - 1; ++i)
		//{
		//	for (int j = 0; j < len1 - i - 1; ++j)
		//	{
		//		if (arr[0][j] > arr[0][j + 1])
		//		{
		//			char tmp = arr[0][j];
		//			arr[0][j] = arr[0][j + 1];
		//			arr[0][j + 1] = tmp;
		//		}
		//	}
		//}

		//Select
		for (int p = 0; p < len1 - 1; ++p)
		{
			int mIdx = p;
			for (int i = p + 1; i < len1; ++i)
			{
				if (arr[0][mIdx] > arr[0][i])
					mIdx = i;
			}

			char tmp = arr[0][mIdx];
			arr[0][mIdx] = arr[0][p];
			arr[0][p] = tmp;
		}
	}
	else
	{
		//Bubble
		//for (int i = 0; i < len2 - 1; ++i)
		//{
		//	for (int j = 0; j < len2 - i - 1; ++j)
		//	{
		//		if (arr[1][j] > arr[1][j + 1])
		//		{
		//			char tmp = arr[1][j];
		//			arr[1][j] = arr[1][j + 1];
		//			arr[1][j + 1] = tmp;
		//		}
		//	}
		//}

		//Select
		for (int p = 0; p < len2 - 1; ++p)
		{
			int mIdx = p;
			for (int i = p + 1; i < len2; ++i)
			{
				if (arr[1][mIdx] > arr[1][i])
					mIdx = i;
			}

			char tmp = arr[1][mIdx];
			arr[1][mIdx] = arr[1][p];
			arr[1][p] = tmp;
		}

	}

	for (const auto& str : arr)
	{
		cout << str << endl;
	}
}
