#pragma once

// See https://refactoring.guru/design-patterns/observer/cpp/example

#include <string>

class IObserver
{
  public:
    virtual void Update(const std::string &changedProperty) = 0;
};
