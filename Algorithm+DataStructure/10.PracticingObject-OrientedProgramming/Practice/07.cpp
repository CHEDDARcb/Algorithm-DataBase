#include <iostream>

using namespace std;

class Timer
{
	Timer() = delete;
	Timer(const Timer&) = delete;
	Timer& operator=(const Timer&) = delete;
public:
	Timer(const char* name, const int totalSeconds = 0)
		: mTotalSeconds(totalSeconds)
		, mName{}
		, mIsStarted(false)
		, mIsEnd(false)
		, mElapsed(0)
	{
		int len = strlen(name);
		strncpy_s(mName, len + 1, name, len);
	}
	~Timer() = default;

public:
	void			SetTotalSeconds(const int totalSeconds) { mTotalSeconds = totalSeconds; }

public:
	const int		GetTotalSeconds() const { return mTotalSeconds; }
	const char* GetName() const { return mName; }
	const bool		IsStarted() const { return mIsStarted; }
	const bool		IsEnd() const { return mIsEnd; }
	const int		GetElapsed() const { return mElapsed; }

public:
	void			StartTimer() { mIsStarted = true; }
	void			CountTime()
	{
		if (mElapsed < mTotalSeconds && mIsStarted && !mIsEnd)
			++mElapsed;
		SetIsEnd();
	}
	void			PrintTimerInfo() const
	{
		cout << "Tiemr " << "\"" << mName << "\" ";
		if (!mIsStarted && !mIsEnd && !mElapsed)
			cout << "waiting." << endl;
		else if (mIsStarted && !mIsEnd && !mElapsed)
			cout << "started." << endl;
		else if (mIsStarted && !mIsEnd && mElapsed > 0 && mElapsed < 300)
			cout << "counting." << endl;
		else
			cout << "ended." << endl;
		cout << "Elapsed: " << mElapsed << "s " << "/ Total: " << mTotalSeconds << "s" << endl;
		cout << endl;

	}
	void			ResetTimer()
	{
		cout << "Reset Timer" << endl;
		mIsStarted = false;
		mIsEnd = false;
		mElapsed = 0;
	}

private:
	void			SetIsEnd()
	{
		if (mElapsed >= mTotalSeconds)
			mIsEnd = true;
	}

private:
	char	mName[256];
	bool	mIsStarted;
	bool	mIsEnd;
	int		mElapsed;
	int		mTotalSeconds;
};

int main()
{
	Timer timer("Cooking");

	timer.SetTotalSeconds(300);

	timer.StartTimer();
	timer.PrintTimerInfo();

	while (!timer.IsEnd())
	{
		timer.CountTime();
		timer.PrintTimerInfo();
	}

	timer.ResetTimer();
	timer.PrintTimerInfo();

	return 0;
}