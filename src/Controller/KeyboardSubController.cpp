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
      _keyboardSubModel((KeyboardSubModel &)controller.GetModel().GetSubModel(
			 primaryKeyboard ? SubModels::ESubModelId::PrimaryKeyboard : SubModels::ESubModelId::SecondaryKeyboard)),
      _primaryKeyboard(primaryKeyboard),  _sustainEnabled(false)
{
}

void KeyboardSubController::Init() // override
{
}

void KeyboardSubController::EnableSustain(bool sustain, bool forced /* = false */)
{
    if (forced || (sustain != _keyboardSubModel.IsSustainEnabled()))
    {
        _keyboardSubModel.EnableSustain(sustain);
    }
}

void KeyboardSubController::SetExpressionVolume(double volume, bool forced /* = false */)
{
    if (forced || (volume != _keyboardSubModel.GetExpressionVolume()))
    {
        _keyboardSubModel.SetExpressionVolume(volume);
    }
}

