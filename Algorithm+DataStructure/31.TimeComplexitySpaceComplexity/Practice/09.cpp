#include <iostream> 
#include <vector>

using namespace std;

int n;
vector<int> a;

void Input()
{
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int data;
		cin >> data;
		a.push_back(data);
	}
}

int Sum(auto start, auto end)
{
	int sum = 0;
	for (; start != end; ++start)
	{
		sum += *start;
	}

	return sum;
}

void FindMax(vector<int>::iterator* b, vector<int>::iterator* e)
{
	int max = INT_MIN;
	for (vector<int>::iterator s = a.begin(); s != a.end(); ++s)
	{
		for (vector<int>::iterator z = s + 1; ; ++z)
		{
			int num = Sum(s, z);

			if (num > max)
			{
				max = num;
				*b = s;
				*e = z;

			}

			if (z == a.end()) break;
		}
	}

}

int main()
{
	//입력
	Input();
	//계산
	vector<int>::iterator b;
	vector<int>::iterator e;
	FindMax(&b, &e);
	//출력
	cout << b - a.begin() << " ";
	cout << e - a.begin() - 1;



	return 0;
}