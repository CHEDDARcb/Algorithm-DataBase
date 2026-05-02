#include <iostream>

using namespace std;

struct MC
{
	char bugger1[8];
	char bugger2[8];
};

int main()
{
	MC bob, tom;

	cin >> bob.bugger1 >> bob.bugger2;
	cin >> tom.bugger1 >> tom.bugger2;

	int buggerLen = 0;
	while (bob.bugger1[buggerLen] != '\0') { buggerLen++; }
	cout << "bob.bugger1 = " << buggerLen << endl;

	buggerLen = 0;
	while (bob.bugger2[buggerLen] != '\0') { buggerLen++; }
	cout << "bob.bugger2 = " << buggerLen << endl;

	buggerLen = 0;
	while (tom.bugger1[buggerLen] != '\0') { buggerLen++; }
	cout << "tom.bugger1 = " << buggerLen << endl;

	buggerLen = 0;
	while (tom.bugger2[buggerLen] != '\0') { buggerLen++; }
	cout << "tom.bugger2 = " << buggerLen << endl;

	return 0;
}