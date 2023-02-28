#pragma once

// See https://refactoring.guru/design-patterns/observer/cpp/example

#include <string>

//template < typename T> struct IObserver
class IObserver
{
  public:
    //virtual void Update(T &source, const std::string &messageFromSubject) = 0;
    virtual void Update(const std::string &changedProperty) = 0;
};
