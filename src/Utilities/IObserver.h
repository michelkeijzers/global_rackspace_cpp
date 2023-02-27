#pragma once

// See https://refactoring.guru/design-patterns/observer/cpp/example

#include <string>

template < typename T> struct IObserver
{
    virtual void Update(T &source, const std::string &messageFromSubject) = 0;
};
