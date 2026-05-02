#include <iostream>

using namespace std;

class ArtWork
{
	ArtWork() = delete;
	ArtWork(const ArtWork&) = delete;
	ArtWork& operator=(const ArtWork&) = delete;

public:
	ArtWork(const char* title)
	{
		int len = strlen(title);
		strcpy_s(mTitle, len + 1, title);
	}
	virtual ~ArtWork() = default;

public:
	virtual void Display() = 0;

protected:
	const char* GetName()const { return mTitle; }

private:
	char mTitle[100];
};

class Painting : public ArtWork
{
	Painting() = delete;
	Painting(const Painting&) = delete;
	Painting& operator=(const Painting&) = delete;

public:
	Painting(const char* title)
		: ArtWork(title)
	{
	}
	~Painting() = default;

public:
	void Display()override
	{
		cout << GetName() << " diplay" << endl;
	}
};

class Sculpture : public ArtWork
{
	Sculpture() = delete;
	Sculpture(const Sculpture&) = delete;
	Sculpture& operator=(const Sculpture&) = delete;

public:
	Sculpture(const char* title)
		: ArtWork(title)
	{
	}
	virtual ~Sculpture() = default;

public:
	void Display()override
	{
		cout << GetName() << " diplay" << endl;
	}
};

int main(void)
{
	Painting p2("Mona Lisa"); Sculpture s2("David");
	ArtWork* gallery[] = { &p2, &s2 };
	for (int i = 0; i < 2; ++i)
		gallery[i]->Display();


	return 0;
}