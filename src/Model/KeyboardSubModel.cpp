#include <memory>
#include "KeyboardSubModel.h"
#include "../Utilities/Debug.h"
#include "../Utilities/DoubleUtilities.h"
#include "../View/ChangedProperties.h"
#include "../View/View.h"
#include "SubModels.h"

static const std::string SUB_MODEL_NAME = "Keyboard";

KeyboardSubModel::KeyboardSubModel(SubModels &subModels, bool isPrimaryKeyboard)
    : SubModel(subModels), _isPrimaryKeyboard(isPrimaryKeyboard)
{
}
