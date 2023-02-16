#pragma once

#include <string>

class Widget
{
  public:
    Widget(std::string name);

	 std::string GetName();

  private:
    std::string _name;
};