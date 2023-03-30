#pragma once

#include "../View/Observable.h"
#include "SubModel.h"
#include <string>
#include <vector>

class Model;

class KeyboardSubModel : public SubModel, public Observable
{
 public:
   KeyboardSubModel(Model &model, bool primaryKeyboard);
   void Init() override;
   const std::string GetName() override;

   std::string Serialize() override;
   int Deserialize(std::vector<std::string> lines, int currentLineIndex) override;

   bool IsSustainEnabled();
   void EnableSustain(bool enable = true);

   double GetExpressionVolume();
   void SetExpressionVolume(double volume);

	// Only used for testing
	void SetAsSecondaryKeyboard(); 

   enum class EParameters
   {
      IsPrimaryKeyboard,
      SustainEnabled,
      Last
   };

 private:
   bool _isPrimaryKeyboard;
   bool _sustainEnabled;
   double _expressionVolume;
};
