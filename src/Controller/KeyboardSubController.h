#pragma once

#include "../Model/KeyboardSubModel.h"
#include "KeyboardSubController.h"

class Controller;
class KeyboardSubModel;

class KeyboardSubController : public SubController
{
 public:
   KeyboardSubController(Controller &controller, bool primaryKeyboard);
   void Init() override;

   void EnableSustain(bool sustain = true, bool forced = false);
   void SetExpressionVolume(double volume, bool forced = false);

 private:
   KeyboardSubModel &_keyboardSubModel;
   bool _primaryKeyboard;
   bool _sustainEnabled;
};
