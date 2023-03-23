#pragma once

#include <string>
#include "../View/Observable.h"
#include "SubModel.h"
#include <vector>

class SubModels;

class KeyboardSubModel : public SubModel, public Observable
{
  public:
    KeyboardSubModel(SubModels &subModels, bool primaryKeyboard);
    const std::string GetDebugName() override;

	 std::string Serialize() override;
    void Deserialize(std::string data) override;

    bool IsSustainEnabled();
    void EnableSustain(bool enable = true);
    
	 double GetExpressionVolume();
    void SetExpressionVolume(double volume);

    enum class EParameters
    {
        IsPrimaryKeyboard,
        // TODO: Serialization
        Last
    };

  private:
    bool _isPrimaryKeyboard;
    bool _sustainEnabled;
    double _expressionVolume;
};
