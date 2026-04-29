	#include <iostream>

	using namespace std;

	string eel;

	int main(void)
	{
		cin >> eel;
		int otherCnt = 0;
		int eelSize = 0;
		int maxEelSize = INT_MIN;
		int es = 0, ee = 0;
		int ems = 0, eme = 0;

		for (int i = 0; i < eel.size(); ++i)
		{
			if (eel[i] == '#')
				++otherCnt;
			else if (eel[i] == '~')
			{
				++eelSize;
				if (i == 0)
				{
					es = i;
					++otherCnt;
				}
				else if (otherCnt == 1 && eelSize == 1)
					es = i;
				else if (i == eel.size() - 1)
					++otherCnt;
			}

			if (otherCnt == 2)
			{
				if (maxEelSize < eelSize)
				{
					maxEelSize = eelSize;

					if (eel[i] == '#')
						ee = i - 1;
					else if (eel[i] == '~')
						ee = i;

					ems = es;
					eme = ee;
				}

				otherCnt = 1;
				eelSize = 0;
			}
		}

		for (int i = ems; i <= eme; ++i)
		{
			cout << eel[i];
		}

		return 0;
	}