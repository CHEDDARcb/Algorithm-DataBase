#include <iostream>
#include <ctime>

using namespace std;

class Array
{
	Array() = delete;
public:
	Array(const int size)
		: mCount(size)
	{
		mAray = new int[size];

		for (int i = 0; i < size; ++i)
		{
			mAray[i] = rand() % 10;
		}
	}
	~Array()
	{
		delete[] mAray;
	}

public:
	void PrintArray()
	{
		for (int i = 0; i < mCount; ++i)
		{
			cout << mAray[i];
		}
		cout << endl;
	}
private:
	int mCount;
	int* mAray;
};


int main(void)
{
	srand(time(NULL));

	Array arr1(3);
	Array arr2(5);

	arr1.PrintArray();
	arr2.PrintArray();

	return 0;
}