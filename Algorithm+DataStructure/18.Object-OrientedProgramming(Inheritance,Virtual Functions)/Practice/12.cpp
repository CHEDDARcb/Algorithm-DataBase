#include <iostream>

using namespace std;

class Pet
{
	Pet() = delete;
	Pet(const Pet&) = delete;
	Pet& operator=(const Pet&) = delete;

public:
	Pet(const char* name)
	{
		int len = strlen(name);
		strcpy_s(mName, len + 1, name);
	}
	virtual ~Pet() = default;

public:
	virtual void Vaccinate() = 0;

private:
	char mName[100];
};

class Dog : public Pet
{
	Dog() = delete;
	Dog(const Dog&) = delete;
	Dog& operator=(const Dog&) = delete;

public:
	Dog(const char* name)
		: Pet(name)
	{
	}
	~Dog() = default;

public:
	void Vaccinate()
	{
		cout << "Dog Vacccinated" << endl;
	}
};

class Bird : public Pet
{
	Bird() = delete;
	Bird(const Bird&) = delete;
	Bird& operator=(const Bird&) = delete;

public:
	Bird(const char* name)
		: Pet(name)
	{
	}
	virtual ~Bird() = default;

public:
	void Vaccinate()
	{
		cout << "Bird Vacccinated" << endl;
	}
};

int main(void)
{
	Dog d3("Bori"); Bird b2("Chirpy");
	Pet* pets[] = { &d3, &b2 };
	for (int i = 0; i < 2; ++i)
		pets[i]->Vaccinate();


	return 0;
}