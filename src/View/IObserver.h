#pragma once

// See https://refactoring.guru/design-patterns/observer/cpp/example

#include <string>
#include "View.h"

class IObserver
{
  public:
    virtual void Update(View::EChangedProperty changedProperty) = 0;
};
