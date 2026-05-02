#include <iostream>
#include <vector>

using namespace std;

vector<int> ar(4, 0);
int n;

void Init()
{
	cin >> n;
}

void Solution()
{
	while (n--)
	{
		int data;
		cin >> data;
		int i = ar.size() - 1;
		for (; i >= 0 && ar[i] < data; --i)
		{
			if (i == ar.size() - 1) continue;
			else
				ar[i + 1] = ar[i];
		}
		ar[i + 1] = data;
	}
}

int main(void)
{
	Init();

	Solution();

	for (int i = 0; i < 3; ++i)
	{
		switch (i)
		{
		case 0:
			cout << "±Ý";
			break;
		case 1:
			cout << "Àº";
			break;
		case 2:
			cout << "µ¿";
			break;
		default:
			break;
		}
		cout << ar[i] << endl;
	}
}