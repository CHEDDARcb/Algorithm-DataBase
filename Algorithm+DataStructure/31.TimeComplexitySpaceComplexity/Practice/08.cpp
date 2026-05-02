#include <iostream> 
#include <vector>

using namespace std;

int n;
string str;


void Input()
{
	cin >> str;
	cin >> n;
}

void Bake()
{
	int over = 0;
	string tmp;
	tmp.reserve(str.size());
	for (int i = str.size() - 1; i >= 0; --i)
	{
		int n = ((str[i] - '0') * 2) + over;
		tmp += (n % 10) + '0';
		over = n / 10;
	}

	if (over)
		tmp += over + '0';

	str = tmp;

}

int main()
{
	Input();

	for (int i = 0; i < n; ++i)
	{
		Bake();
	}

	cout << str;

	return 0;
}