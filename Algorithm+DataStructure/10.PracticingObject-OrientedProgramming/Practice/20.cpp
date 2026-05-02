#include <iostream>

using namespace std;

class Student
{
	Student() = delete;
	Student(const Student&) = delete;
	Student& operator=(const Student&) = delete;
public:
	Student(const char* _name, const char* _studnetNum,
		const char* _grade, const char* _department)
		: mName{}
		, mStudnetNum{}
		, mGrade{}
		, mDepartment{}
	{
		int len = strlen(_name);
		strncat_s(mName, len + 1, _name, len);

		len = strlen(_studnetNum);
		strncat_s(mStudnetNum, len + 1, _studnetNum, len);

		len = strlen(_grade);
		strncat_s(mGrade, len + 1, _grade, len);

		len = strlen(_department);
		strncat_s(mDepartment, len + 1, _department, len);
	}
	~Student() = default;

public:
	const char* GetName()const { return mName; }
	const char* GetStudentNum()const { return mStudnetNum; }
	const char* GetGrade()const { return mGrade; }
	const char* GetDepartment()const { return mDepartment; }

private:
	char	mName[256];
	char	mStudnetNum[256];
	char	mGrade[256];
	char	mDepartment[256];
};

class Course
{
	Course() = delete;
	Course(const Course&) = delete;
	Course& operator=(const Course&) = delete;
public:
	Course(const char* _course, const char* _instructor, const int _capacity)
		: mCourse{}
		, mInstructor{}
		, mCapacity(_capacity)
		, mStudents{}
		, mStudentsNum(0)
	{
		int len = strlen(_course);
		strncpy_s(mCourse, len + 1, _course, len);

		len = strlen(_instructor);
		strncpy_s(mInstructor, len + 1, _instructor, len);
	}
	~Course() = default;

public:
	void		AddStudent(Student* _st)
	{
		if (mStudentsNum >= mCapacity) return;
		mStudents[mStudentsNum++] = _st;
	}

public:
	void		PrintCourseInfo()const
	{
		cout << "Course: " << mCourse << " | ";
		cout << "Instructor: " << mInstructor << " | ";
		cout << "Capacity: " << mCapacity << endl;
		cout << "Students: " << endl;
		for (int i = 0; i < mStudentsNum; ++i)
		{
			cout << " - " << mStudents[i]->GetName();
			cout << " (" << mStudents[i]->GetDepartment();
			cout << ", " << mStudents[i]->GetGrade() << " year)" << endl;
		}
	}
private:
	char		mCourse[256];
	char		mInstructor[256];
	int			mCapacity;
	Student* mStudents[30];
	int			mStudentsNum;
};

int main()
{
	Student st1("Alice", "abc", "2nd", "CS");
	Student st2("Bob", "def", "1st", "EE");
	Student st3("Charlie", "ghi", "3rd", "CS");
	Course cs("Programing 101", "Dr. kim", 30);

	cs.AddStudent(&st1);
	cs.AddStudent(&st2);
	cs.AddStudent(&st3);

	cs.PrintCourseInfo();

	return 0;
}