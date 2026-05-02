#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int num;
	cin >> num;

	int tfCn = 0;
	int stCn = 0;
	int sCn = 0;
	int oCn = 0;

	while (num >= 35)
	{
		++tfCn;
		num -= 35;
	}
	while (num >= 17)
	{
		++stCn;
		num -= 17;
	}

	while (num >= 7)
	{
		++sCn;
		num -= 7;
	}
	while (num >= 1)
	{
		++oCn;
		num -= 1;
	}

	cout << "35: " << tfCn << "개" << endl;
	cout << "17: " << stCn << "개" << endl;
	cout << "7: " << sCn << "개" << endl;
	cout << "1: " << oCn << "개" << endl;


	return 0;
}