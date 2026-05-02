#include <iostream>

using namespace std;

char c1, c2;

void input()
{
	cin >> c1 >> c2;
}

void output()
{
	if ((c1 >= 'A' && c1 <= 'Z') && (c2 >= 'A' && c2 <= 'Z'))
		cout << "대문자들";
	else if ((c1 >= 'A' && c1 <= 'Z') && (c2 >= 'a' && c2 <= 'z'))
		cout << "대소문자";
	else if ((c1 >= 'a' && c1 <= 'z') && (c2 >= 'A' && c2 <= 'Z'))
		cout << "대소문자";
	else
		for (char i = 'a'; i <= 'z'; ++i)
			cout << i << " ";

}

int main(void)
{
	input();
	output();

	return 0;
}