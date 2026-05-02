#include <iostream>

using namespace std;

namespace JYS
{
	class string
	{
	public:
		string()
			: mStr(nullptr)
			, mSize(0)
			, mCapacity(0)
		{
		}
		string(const char* str)
			: mStr(nullptr)
			, mSize(0)
			, mCapacity(0)
		{
			mSize = strlen(str);
			mCapacity = (mSize * 2) + (mSize / 2);

			mStr = new char[mCapacity];
			memset(mStr, 0, mCapacity);
			memcpy(mStr, str, mSize + 1);
		}
		~string()
		{
			delete mStr;
			mStr = nullptr;
		}

	public:
		void operator+=(const char* str)
		{
			int len = strlen(str);
			int newSize = mSize + len;

			if (newSize >= mCapacity)
			{
				mCapacity = (newSize * 2) + (newSize / 2);
				char* newStr = new char[mCapacity];
				memset(newStr, 0, mCapacity);
				memcpy(newStr, mStr, mSize);

				delete[] mStr;
				mStr = nullptr;

				mStr = newStr;
			}

			memcpy(mStr + mSize, str, len + 1);
			mSize = newSize;
		}

		char& operator[](int index)
		{
			return mStr[index];
		}

		int Size()const
		{
			return mSize;
		}

		const char* c_str()const
		{
			return mStr;
		}

	private:
		char* mStr;
		int mSize;
		int mCapacity;
	};
}

int main(void)
{
	JYS::string str("Hello");
	cout << "JYS::string 초기값: " << str.c_str() << std::endl;
	cout << "크기: " << str.Size() << endl;

	str += " world~~~~~~";
	cout << "문자열 추가 후: " << str.c_str() << endl;
	cout << "크기: " << str.Size() << endl;

	str[4] = 'a';
	cout << "4번째 문자 변경 후: " << str.c_str() << endl;
	cout << "4번째 문자: " << str[4] << endl;

	return 0;
}