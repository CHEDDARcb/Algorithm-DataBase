#include <iostream>

using namespace std;

class Time
{
	Time() = delete;
	Time& operator=(const Time&) = delete;
public:
	Time(const int _hour, const int _minute, const int _second)
		: mHour(_hour)
		, mMinute(_minute)
		, mSecond(_second)
	{
	}
	Time(const Time& _time)
		: mHour(_time.mHour)
		, mMinute(_time.mMinute)
		, mSecond(_time.mSecond)
	{
	}

public:
	void	Print()const
	{
		cout << mHour << "½Ã ";
		cout << mMinute << "ºÐ ";
		cout << mSecond << "ÃÊ ";
		cout << endl;
	}

public:
	Time operator+(const Time& _time)
	{
		int sec = mSecond + _time.mSecond;
		int tmp = sec / 60;
		sec %= 60;

		int min = mMinute + _time.mMinute + tmp;
		tmp = min / 60;
		min %= 60;

		int h = mHour + _time.mHour + tmp;
		h %= 24;

		return Time(h, min, sec);
	}
private:
	int		mHour;
	int		mMinute;
	int		mSecond;
};

int main()
{
	Time time1(4, 50, 40);
	Time time2(3, 40, 30);
	Time time3 = time1 + time2;

	time1.Print();
	time2.Print();
	time3.Print();

	return 0;
}