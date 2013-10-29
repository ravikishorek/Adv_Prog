#include <iostream>

class Person
{
public:

	Person() {
		// TODO prompt for first name and set member variable
		// TODO prompt for last name and set member variable
	}

	virtual ~Person() {}

	void
	sayHello() const
	{
		// TODO write greeting line
	}

	/// member variables holding first and last name
	std::string firstName;
	std::string lastName;
};


int main(int argc, char *argv[])
{
	Person p;
	p.sayHello();
	return 0;
}
