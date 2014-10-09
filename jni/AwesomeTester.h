
#pragma once

#include <string>

namespace JniTestProject
{
  class AwesomeTester
  {
  public:
    const std::string& GetName() const;
    void SetName(std::string name);

    int GetAge() const;
    void SetAge(int age);

    bool IsAwesome();

  private:
    std::string name;
    int age;
  };
}
