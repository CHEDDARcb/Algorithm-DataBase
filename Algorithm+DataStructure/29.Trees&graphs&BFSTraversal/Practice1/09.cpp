#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int targetYear;

	cin >> targetYear;

	vector<int> mogura;
	mogura.push_back(1);

	while (targetYear--)
		mogura.push_back(mogura.back() * 3);

	int result = 0;
	for (const auto& data : mogura)
		result += data;

	cout << result;

	return 0;
}