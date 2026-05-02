#include <iostream>

int main()
{
	int d;
	int result;
	int count;

	std::cin >> d;      // 0~15입력

	count = 0;
	
	// 8비트를모두확인(15 = 0000 1111)
	for (size_t i = 0; i < 8; i++)
	{
		result = (d >> i) & 0x1;    // i번비트확인

		if (result > 0)
				count++;  // 1인비트 개수 증가
	}

	std::cout << count << std::endl;

	return 0;
}
