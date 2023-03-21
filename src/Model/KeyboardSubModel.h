#pragma once

#include "../View/Observable.h"
#include "SubModel.h"
#include <vector>

class SubModels;

class KeyboardSubModel : public SubModel, public Observable
{
  public:
    KeyboardSubModel(SubModels &subModels, bool primaryKeyboard);
    const std::string GetDebugName() override;

    void EnableSustain(bool enable = true);
    bool IsSustainEnabled();

  private:
    bool _isPrimaryKeyboard;
    bool _sustainEnabled;
};
