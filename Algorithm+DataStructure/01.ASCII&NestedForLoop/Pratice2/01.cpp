#include <iostream>

using namespace std;


int main(void)
{
	char c1, c2;

	cin >> c1 >> c2;

	cout << "문자'" << c1 << "'의 아스키코드값은 " << static_cast<int>(c1) << endl;
	cout << "문자'" << c2 << "'의 아스키코드값은 " << static_cast<int>(c2) << endl;

	return 0;
}