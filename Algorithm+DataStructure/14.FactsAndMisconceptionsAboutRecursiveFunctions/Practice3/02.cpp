class Person
{
public:
	Person()
		: name()
		, tel()
	{
	}

public:
	string getName() { return name; }
	string getTel() { return tel; }
	void set(string name, string tel)
	{
		this->name = name;
		this->tel = tel;
	}
private:
	string name;
	string tel;
};

int main()
{
	Person personArr[3];

	for (auto& person : personArr)
	{
		string name, tel;
		cin >> name >> tel;

		person.set(name, tel);
	}

	for (auto& person : personArr)
	{
		cout << "name: " << person.getName() << endl;
		cout << "tel: " << person.getTel() << endl;
		cout << endl;
	}

	return 0;
}