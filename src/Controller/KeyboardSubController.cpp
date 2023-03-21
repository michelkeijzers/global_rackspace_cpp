#include <iostream>

#include "../Model/Model.h"
#include "../Model/KeyboardSubModel.h"
#include "../Plugins/KeyboardPlugin.h"
#include "../Utilities/Debug.h"
#include "../Utilities/DoubleUtilities.h"
#include "../View/View.h"
#include "Controller.h"
#include "KeyboardSubController.h"
#include "SubController.h"

KeyboardSubController::KeyboardSubController(Controller &controller, bool primaryKeyboard)
    : SubController(controller),
      _keyboardSubModel((KeyboardSubModel &)controller.GetModel().GetSubModel(SubModels::ESubModelId::Keyboard)),
      _primaryKeyboard(primaryKeyboard)
{
}

void KeyboardSubController::Init() // override
{
}

