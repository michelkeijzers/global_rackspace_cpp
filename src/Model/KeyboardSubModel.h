#pragma once

#include "../View/Observable.h"
#include "SubModel.h"
#include <vector>

class SubModels;

class KeyboardSubModel : public SubModel, public Observable
{
  public:
    KeyboardSubModel(SubModels &subModels, bool primaryKeyboard);

  private:
    bool _isPrimaryKeyboard;
};
