#include <iostream>

using namespace std;

class Student
{
	Student() = delete;
	Student(const Student&) = delete;
	Student& operator=(const Student&) = delete;
public:
	Student(const char* _name, const int _grade, const char _class, const int _score)
		: mName{}
		, mGrade(_grade)
		, mClass(_class)
		, mScore(_score)
	{
		int len = strlen(_name);
		strncat_s(mName, len + 1, _name, len);
	}

public:
	const char* GetName()const { return mName; }
	const int			GetGrade()const { return mGrade; }
	const char			GetClass()const { return mClass; }
	const int			GetScore()const { return mScore; }

private:
	char	mName[256];
	int		mGrade;
	char	mClass;
	int		mScore;
};

class Teacher
{
	Teacher() = delete;
	Teacher(const Teacher&) = delete;
	Teacher& operator=(const Teacher&) = delete;
public:
	Teacher(const char* _name, const char* _subject, const int _years)
		: mName{}
		, mSubject{}
		, mYears(_years)
		, mStudents{}
		, mStudentNum(0)
	{
		int len = strlen(_name);
		strncat_s(mName, len + 1, _name, len);

		len = strlen(_subject);
		strncat_s(mSubject, len + 1, _subject, len);
	}
	~Teacher() = default;

public:
	void		AddStudent(Student* st)
	{
		mStudents[mStudentNum++] = st;
	}

public:
	void		PrintTeacherInfo()const
	{
		cout << "Teacher: " << mName << " (" << mSubject << ", " << mYears << ")" << endl;
		cout << "Students: " << endl;
		for (int i = 0; i < mStudentNum; ++i)
		{
			cout << "- " << mStudents[i]->GetName() << " ";
			cout << "(Grade " << mStudents[i]->GetGrade() << ", ";
			cout << "Class " << mStudents[i]->GetClass() << "): ";
			cout << mStudents[i]->GetScore() << endl;
		}
	}

private:
	char		mName[256];
	char		mSubject[256];
	int			mYears;
	Student* mStudents[30];
	int			mStudentNum;
};

int main()
{
	Student st1("Tom", 2, 'A', 85);
	Student st2("Jane", 2, 'A', 90);
	Student st3("Sam", 2, 'A', 75);
	Teacher tch("Mr. Lee", "Math", 10);

	tch.AddStudent(&st1);
	tch.AddStudent(&st2);
	tch.AddStudent(&st3);

	tch.PrintTeacherInfo();

	return 0;
}