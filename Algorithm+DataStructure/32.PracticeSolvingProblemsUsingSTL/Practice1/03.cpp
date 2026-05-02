#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> ar;
int n;

int main(void)
{
	stack<int> st;
	cin >> n;
	int prevNum;
	cin >> prevNum;
	st.push(prevNum);
	int cnt = 1;

	for (int i = 1; i < n; ++i)
	{
		int data;
		cin >> data;
		st.push(data);

		if (prevNum == data)
		{
			++cnt;
			if (cnt == 3)
			{
				for (int i = 0; i < 3; ++i)
				{
					st.pop();
				}
				cnt = 0;
			}
		}
		else
		{
			prevNum = data;
			cnt = 1;
		}
	}

	int size = st.size();
	ar.resize(size);

	for (int i = 0; i < size; ++i)
	{
		ar[i] = st.top();
		st.pop();
	}

	sort(ar.begin(), ar.end());

	for (auto& data : ar)
		cout << data << " ";
}