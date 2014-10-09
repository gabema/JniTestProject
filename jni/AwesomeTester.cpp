#include "AwesomeTester.h"

namespace JniTestProject
{
	const std::string& AwesomeTester::GetName() const
	{
		return name;
	}

	void AwesomeTester::SetName(std::string name)
	{
		this->name = name;
	}

	int AwesomeTester::GetAge() const
	{
		return age;
	}
	void AwesomeTester::SetAge(int age)
	{
		this->age = age;
	}

	bool AwesomeTester::IsAwesome()
	{
		return age % name.length() < 2;
	}
}
