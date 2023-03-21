#include <memory>
#include "KeyboardSubModel.h"
#include "../Utilities/Debug.h"
#include "../Utilities/DoubleUtilities.h"
#include "../View/ChangedProperties.h"
#include "../View/View.h"
#include "SubModels.h"

static const std::string SUB_MODEL_NAME = "Keyboard";

KeyboardSubModel::KeyboardSubModel(SubModels& subModels, bool isPrimaryKeyboard)
	: SubModel(subModels), _isPrimaryKeyboard(isPrimaryKeyboard), _sustainEnabled(false)
{
}

const std::string KeyboardSubModel::GetDebugName() /* override */
{
    return SUB_MODEL_NAME + (_isPrimaryKeyboard ? " Primary" : " Secondary");
}

void KeyboardSubModel::EnableSustain(bool enable /* = true */)
{
    if (enable != _sustainEnabled)
    {
        _sustainEnabled = enable;
        Debug::Log("# " + GetDebugName() + ": Sustain, enabled is = " + std::to_string(_sustainEnabled));
		  
		  if (_isPrimaryKeyboard)
        {
            Notify(ChangedProperties::EChangedProperty::PrimaryKeyboardSustainEnabled);
        }
		  else
		  {
            Notify(ChangedProperties::EChangedProperty::SecondaryKeyboardSustainEnabled);
		  }
    }
}

bool KeyboardSubModel::IsSustainEnabled()
{
    return _sustainEnabled;
}