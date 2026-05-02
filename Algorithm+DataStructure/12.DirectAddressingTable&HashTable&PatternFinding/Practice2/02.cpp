#include <iostream>

using namespace std;

int main()
{
	int base[6];

	for (auto& data : base)
		cin >> data;

	int bucket[256]{};
	for (const auto& data : base)
	{
		int idx = static_cast<int>(data);
		if (bucket[idx])
		{
			cout << "도플갱어 발견";
			break;
		}
		++bucket[idx];
	}
	return 0;
}