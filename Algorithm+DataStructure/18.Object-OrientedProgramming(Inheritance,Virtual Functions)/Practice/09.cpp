#include <iostream>

using namespace std;

class Exercise
{
	Exercise() = delete;
	Exercise(const Exercise&) = delete;
	Exercise& operator=(const Exercise&) = delete;

public:
	Exercise(int exTime)
		: mExerciseTime(exTime)
	{
	}
	virtual ~Exercise() = default;

public:
	virtual void PrintCalories()const = 0;

protected:
	int GetExerTime()const { return mExerciseTime; }

private:
	int mExerciseTime;
};

class Running : public Exercise
{
	Running() = delete;
	Running(const Running&) = delete;
	Running& operator=(const Running&) = delete;

public:
	Running(int exTime)
		: Exercise(exTime)
	{
	}
	virtual ~Running() = default;

public:
	void PrintCalories()const override
	{
		cout << "Running: " << GetExerTime() * 5 << endl;
	}
};

class Cycling : public Exercise
{
	Cycling() = delete;
	Cycling(const Cycling&) = delete;
	Cycling& operator=(const Cycling&) = delete;

public:
	Cycling(int exTime)
		: Exercise(exTime)
	{
	}
	virtual ~Cycling() = default;

public:
	void PrintCalories()const override
	{
		cout << "Cycling: " << GetExerTime() * 6 << endl;
	}
};

int main(void)
{
	Running run(30); Cycling cyc(60);
	Exercise* logs[] = { &run, &cyc };
	for (int i = 0; i < 2; ++i)
		logs[i]->PrintCalories();

	return 0;
}