#include <iostream>

using namespace std;

int main()
{
	char cardList[16];
	char bucket[256]{};

	cin >> cardList;

	int typeCount = 0;
	for (int i = 0; cardList[i] != '\0'; ++i)
	{
		int idx = static_cast<int>(cardList[i]);
		if (!bucket[idx])
			typeCount++;
		++bucket[idx];
	}

	cout << typeCount << "°³";
}