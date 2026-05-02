#include <iostream>
#include <vector>

using namespace std;

int main()
{
	string input;
	bool dma[150]{};

	cin >> input;

	int count = 0;
	for (int i = 0; i < input.size(); ++i)
	{
		if (dma[input[i]] == false)
		{
			count++;
			dma[input[i]] = true;
		}
	}

	cout << count << "Á¾·ù";


	return 0;
}