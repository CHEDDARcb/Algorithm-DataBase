#include <iostream>
#include <vector>

using namespace std;

namespace JYS
{
	template <typename T>
	class vector
	{
	public:
		vector()
			: mArr(nullptr)
			, mSize(0)
			, mCapacity(DefaultCapacity)
		{
			mArr = new T[mCapacity];
		}
		~vector()
		{
			delete[] mArr;
			mArr = nullptr;
		}
	public:
		void push_back(const T data)
		{
			if (mSize >= mCapacity)
			{
				int newCap = mCapacity * 2;
				T* newArr = new T[newCap];

				memcpy(newArr, mArr, newCap);

				delete[] mArr;
				mArr = newArr;
				mCapacity = newCap;
			}

			mArr[mSize++] = data;
		}

		void clear()
		{
			mSize = 0;
		}

		void resize(int newSize)
		{
			if (newSize <= mSize) return;

			T* newArr = new T[newSize];

			for (int i = 0; i < newSize; ++i)
				newArr[i] = mArr[i];

			delete[] mArr;

			mArr = newArr;
			mSize = newSize;
			mCapacity = newSize;
		}

	public:
		int size()const { return mSize; }

	public:
		T& operator[](size_t idx) { return mArr[idx]; }

	private:
		static const int DefaultCapacity = 4;
		T* mArr;
		int mSize;
		int mCapacity;
	};
}

int main(void)
{
	JYS::vector<int> myVec;
	myVec.push_back(1);
	myVec.push_back(2);
	myVec.push_back(3);

	cout << myVec[0] << endl;
	cout << myVec.size();

	myVec.resize(10);
	myVec.clear();

	return 0;
}