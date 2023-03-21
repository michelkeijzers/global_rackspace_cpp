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

  private:
     KeyboardSubModel &_keyboardSubModel;
     bool _primaryKeyboard;
};
