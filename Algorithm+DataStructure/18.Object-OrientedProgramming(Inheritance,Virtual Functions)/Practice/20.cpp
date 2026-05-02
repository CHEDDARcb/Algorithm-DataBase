#include <iostream>

using namespace std;

class Workout
{
	Workout() = delete;
	Workout(const Workout&) = delete;
	Workout& operator=(const Workout&) = delete;

public:
	Workout(const int set)
		: mSet(set)
	{
	}
	virtual ~Workout() = default;

public:
	virtual void Show() = 0;

protected:
	const int GetSet()const { return mSet; }

private:
	int mSet;
};

class Pushup : public Workout
{
	Pushup() = delete;
	Pushup(const Pushup&) = delete;
	Pushup& operator=(const Pushup&) = delete;

public:
	Pushup(const int set)
		: Workout(set)
	{
	}
	~Pushup() = default;

public:
	void Show()override
	{
		cout << "Push UP: " << GetSet() << endl;
	}
};

class Squat : public Workout
{
	Squat() = delete;
	Squat(const Squat&) = delete;
	Squat& operator=(const Squat&) = delete;

public:
	Squat(const int set)
		: Workout(set)
	{
	}
	virtual ~Squat() = default;

public:
	void Show()override
	{
		cout << "Squat: " << GetSet() << endl;
	}
};

int main(void)
{
	Pushup pu(20); Squat sq(30);
	Workout* program[] = { &pu, &sq };
	for (int i = 0; i < 2; ++i)
		program[i]->Show();


	return 0;
}