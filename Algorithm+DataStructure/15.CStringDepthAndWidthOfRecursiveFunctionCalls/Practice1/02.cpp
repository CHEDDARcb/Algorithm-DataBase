#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	const char* gmID = "qlqlaqkq";
	const char* gmPass = "tkaruqtkf";
	char id[30];
	char pass[30];

	cin >> id >> pass;

	if (!strcmp(gmID, id) && !strcmp(gmPass, pass))
		cout << "LOGIN";
	else
		cout << "INVALID";

	return 0;
}