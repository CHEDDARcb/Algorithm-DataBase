#include <iostream>

using namespace std;

int main(void)
{
	char arr[5];

	for (auto& data : arr)
	{
		cin >> data;
	}

	int cnt = 0;
	int idxArr[5]{};
	for (int i = 0; i < 5; ++i)
	{
		if (arr[i] == 'A')
		{
			idxArr[cnt] = i;
			++cnt;
		}
	}

	cout << "문자A는 " << cnt << "개발견" << endl;
	for (int i = 0; i < cnt; ++i)
	{
		cout << idxArr[i] << "번" << endl;
	}
	return 0;
}
