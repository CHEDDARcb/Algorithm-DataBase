template<size_t I, size_t J>
int FindMaxLen(const char(&_strs)[I][J])
{
	int maxLen = INT_MIN;
	int maxIdx = -1;
	for (size_t i = 0; i < I; ++i)
	{
		int len = strlen(_strs[i]);

		if (len >= maxLen)
		{
			maxLen = len;
			maxIdx = i;
		}
	}

	return maxIdx;
}

int main()
{
	char strs[3][11];

	for (auto& str : strs)
		cin >> str;

	int maxLenIdx = FindMaxLen(strs);

	char maxStrTmp[11];

	strcpy_s(maxStrTmp, sizeof(maxStrTmp), strs[maxLenIdx]);
	strcpy_s(strs[maxLenIdx], sizeof(strs[maxLenIdx]), strs[0]);
	strcpy_s(strs[0], sizeof(strs[0]), maxStrTmp);

	for (const auto& str : strs)
		cout << str << endl;
}