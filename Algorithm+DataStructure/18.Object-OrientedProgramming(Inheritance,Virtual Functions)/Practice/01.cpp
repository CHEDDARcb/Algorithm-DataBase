#include <iostream>

using namespace std;

class Animal
{
	Animal() = delete;
	Animal(const Animal&) = delete;
	Animal& operator=(const Animal&) = delete;

public:
	Animal(const char* name)
	{
		int len = strlen(name);
		strcpy_s(mName, len + 1, name);
	}
	virtual ~Animal() = default;

public:
	virtual void Speek()const = 0;

private:
	char mName[100];
};

class Dog : public Animal
{
	Dog() = delete;
	Dog(const Animal&) = delete;
	Dog& operator=(const Dog&) = delete;

public:
	Dog(const char* name)
		: Animal(name)
	{

	}
	~Dog() = default;

public:
	void Speek()const override
	{
		cout << "barks!" << endl;
	}
};

class Cat : public Animal
{
	Cat() = delete;
	Cat(const Cat&) = delete;
	Cat& operator=(const Cat&) = delete;

public:
	Cat(const char* name)
		: Animal(name)
	{
	}
	~Cat() = default;

public:
	void Speek()const override
	{
		cout << "Meows!" << endl;
	}
};

int main(void)
{
	Dog d1("Baekgu");
	Cat c1("Nabi");
	Animal* animals[] = { &d1, &c1 };

	for (int i = 0; i < 2; ++i)
		animals[i]->Speek();

	return 0;
}