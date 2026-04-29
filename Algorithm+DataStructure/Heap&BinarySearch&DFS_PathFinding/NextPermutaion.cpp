#include <iostream>

using namespace std;

const int DATASIZE = 3;

int dt[DATASIZE] = { 8, 1, 1};
int x;
int n = DATASIZE;
bool result;

bool NextPermutation(int* data, int n)
{
	// 맨 오른쪽부터 숫자부터2개씩 비교한다

	// 오른쪽 왼쪽으로a찾기(index)
	int i = n - 1;
	// 왼쪽보다 오른쪽 숫자가 더 큰 index찾아서 찾기
	while (i > 0 && data[i - 1] >= data[i])
		i -= 1;
	if (i <= 0)
		return false;

	int a = i - 1;

	// 오른쪽에서 왼쪽으로 b찾기(index)
	int j = n - 1;
	// 맨 오른쪽부터 a보다 큰 숫자 찾기
	while (data[j] <= data[a])
		j -= 1;

	int b = j;

	// 각각 찾은 [a],[b]를 swap
	int tmp = data[a];
	data[a] = data[b];
	data[b] = tmp;

	// [a] 다음 숫자부터 맨 끝까지 숫자를 전부 뒤집기
	int f = a + 1;
	int l = n - 1;
	while (f < l)
	{
		tmp = data[f];
		data[f] = data[l];
		data[l] = tmp;
		f += 1;
		l -= 1;
	}

	return true;
}

int main(void)
{
	while (true)
	{
		for (x = 0; x < DATASIZE; ++x)
			cout << dt[x];
		cout << endl;

		result = NextPermutation(dt, n);
		if (!result)
			break;
	}

	return 0;
}
