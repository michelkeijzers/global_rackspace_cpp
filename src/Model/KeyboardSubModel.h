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

    bool IsSustainEnabled();
    void EnableSustain(bool enable = true);
    
	 double GetExpressionVolume();
    void SetExpressionVolume(double volume);

  private:
    bool _isPrimaryKeyboard;
    bool _sustainEnabled;
    double _expressionVolume;
};
