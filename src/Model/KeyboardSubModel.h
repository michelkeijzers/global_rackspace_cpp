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
    const std::string GetName() override;

	 std::string Serialize() override;
    int Deserialize(std::vector<std::string> lines, int currentLineIndex) override;

    bool IsSustainEnabled();
    void EnableSustain(bool enable = true);
    
	 double GetExpressionVolume();
    void SetExpressionVolume(double volume);

    enum class EParameters
    {
        IsPrimaryKeyboard,
		  SustainEnabled,
		  ExpressionVolume,
        Last
    };

  private:
    bool _isPrimaryKeyboard;
    bool _sustainEnabled;
    double _expressionVolume;
};
