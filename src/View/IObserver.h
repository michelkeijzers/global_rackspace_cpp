#pragma once

// See https://refactoring.guru/design-patterns/observer/cpp/example

#include "ChangedProperties.h"
#include <string>

class IObserver
{
 public:
   virtual void Update(ChangedProperties::EChangedProperty changedProperty) = 0;
};
