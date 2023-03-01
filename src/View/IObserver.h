#pragma once

// See https://refactoring.guru/design-patterns/observer/cpp/example

#include <string>
#include "ChangedProperties.h"

class IObserver
{
  public:
    virtual void Update(ChangedProperties::EChangedProperty changedProperty) = 0;
};
