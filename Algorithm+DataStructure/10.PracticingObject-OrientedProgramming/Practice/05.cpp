#include <iostream>

using namespace std;

class Student
{
	Student() = delete;
	Student(const Student&) = delete;
	Student& operator=(const Student&) = delete;
public:
	Student(const char* name, const int id, const int mScore = 0, const int eScore = 0, const int sScore = 0)
		: mName{}
		, mID(id)
		, mMathScore(mScore)
		, mEnglishScore(eScore)
		, mScienceScore(sScore)
		, mAverage(0.f)
		, mGrade('-')
	{
		CalcAverage();
		int len = strlen(name);
		strncpy_s(mName, len + 1, name, len);

		CalGrade();
	}
	~Student() = default;


public:
	void			SetMathScore(const int mScore)
	{
		mMathScore = mScore;
		CalcAverage();
	}
	void			SetEnglishScore(const int eScore)
	{
		mEnglishScore = eScore;
		CalcAverage();
	}
	void			SetScienceScore(const int sScore)
	{
		mScienceScore = sScore;
		CalcAverage();
	}

public:
	const int		GetMathScore() const { return mMathScore; }
	const int		GetEnglishScore() const { return mEnglishScore; }
	const int		GetScienceScore() const { return mScienceScore; }

public:
	void			PrintStudentInfo() const
	{
		cout << "Name: " << mName << "(ID: " << mID << ")" << endl;
		cout << "Math: " << mMathScore << ", ";
		cout << "English: " << mEnglishScore << ", ";
		cout << "Science: " << mScienceScore << endl;
		cout << "Average Score: " << mAverage << endl;
		cout << "Grade: " << mGrade << endl;
	}

private:
	void			CalcAverage()
	{
		mAverage = (mMathScore + mEnglishScore + mScienceScore) / 3.f;
	}
	void			CalGrade()
	{
		if (mAverage >= 90)
			mGrade = 'A';
		else if (mAverage >= 80)
			mGrade = 'B';
		else if (mAverage >= 70)
			mGrade = 'C';
		else if (mAverage >= 60)
			mGrade = 'D';
		else
			mGrade = 'F';
	}

private:
	char	mName[256];
	int		mID;
	int		mMathScore;
	int		mEnglishScore;
	int		mScienceScore;
	float	mAverage;
	char	mGrade;

};

int main()
{
	Student st1("John", 20231234, 85, 78, 92);
	Student st2("Minho", 20231235, 85, 88, 92);
	Student st3("Gahong", 20231236, 95, 78, 92);

	st1.PrintStudentInfo();
	cout << endl;
	st2.PrintStudentInfo();
	cout << endl;
	st3.PrintStudentInfo();
	cout << endl;

	return 0;
}