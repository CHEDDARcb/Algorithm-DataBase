#include <iostream>

using namespace std;

string dameWord[5] =
{
	"chicken",
	"pizza",
	"jockbal",
	"bread",
	"samhap"
};
string input;

bool IsDame(int idx, int* jumpSize)
{
	for (int k = 0; k < 5; ++k)
	{
		string& curWord = dameWord[k];

		if (idx + (int)curWord.size() > (int)input.size())
			continue;

		int sameCnt = curWord.size();
		int sIdx = idx;
		for (int i = 0; i < curWord.size(); ++i)
		{
			if (input[sIdx] != curWord[i] &&
				input[sIdx] + 32 != curWord[i] &&
				input[sIdx] - 32 != curWord[i])
				break;
			else
			{
				--sameCnt;
				++sIdx;
			}
		}
		if (sameCnt == 0)
		{
			*jumpSize = curWord.size();
			return true;
		}
	}

	return false;
}

int main(void)
{
	cin >> input;

	for (int i = 0; i < input.size(); ++i)
	{
		int jumpSize = 0;
		if (IsDame(i, &jumpSize))
		{
			cout << "###";
			i += jumpSize - 1;
		}
		else
			cout << input[i];
	}

	return 0;
}
