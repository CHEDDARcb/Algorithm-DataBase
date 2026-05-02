#include <iostream>

using namespace std;

class Date
{
	Date() = delete;
	Date(const Date&) = delete;
	Date& operator=(const Date&) = delete;
public:
	Date(const int _year, const int _month, const int _day)
		: mYear(_year)
		, mMonth(_month)
		, mDay(_day)
	{
	}
	Date(const char* _date)
		: mYear(0)
		, mMonth(0)
		, mDay(0)
	{
		int startIdx;
		int dateTMP[5]{};

		// Year
		int j = 0;
		for (startIdx = 0; _date[startIdx] != '/'; ++startIdx)
		{
			dateTMP[j++] = static_cast<int>(_date[startIdx] - '0');
		}
		int y = 1000;
		for (int k = 0; k < j; ++k)
		{
			mYear += dateTMP[k] * y;
			y /= 10;
		}

		// Month
		++startIdx;
		j = 0;
		for (; _date[startIdx] != '/'; ++startIdx)
		{
			dateTMP[j++] = static_cast<int>(_date[startIdx] - '0');
		}
		if (j > 1) y = 10;
		else y = 1;
		for (int k = 0; k < j; ++k)
		{
			mMonth += dateTMP[k] * y;
			y /= 10;
		}

		// Day
		++startIdx;
		j = 0;
		for (; _date[startIdx] != '\0'; ++startIdx)
		{
			dateTMP[j++] = static_cast<int>(_date[startIdx] - '0');
		}
		if (j > 1) y = 10;
		else y = 1;
		for (int k = 0; k < j; ++k)
		{
			mDay += dateTMP[k] * y;
			y /= 10;
		}
	}
	~Date() = default;

public:
	const int getYear()const { return mYear; }
	const int getMonth()const { return mMonth; }
	const int getDay()const { return mDay; }

public:
	void	show()const
	{
		cout << mYear << "³â";
		cout << mMonth << "¿ù";
		cout << mDay << "ÀÏ";
		cout << endl;
	}

private:
	int		mYear;
	int		mMonth;
	int		mDay;
};
int main()
{
	Date birth(2014, 03, 20);
	Date indenpendenceDay("1981/8/12");

	indenpendenceDay.show();
	cout << birth.getYear() << "," << birth.getMonth() << "," << birth.getDay() << endl;

	return 0;
}