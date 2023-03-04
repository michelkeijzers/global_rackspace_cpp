#include "OrganSubModel.h"
#include "../Utilities/Debug.h"
#include "../Utilities/DoubleUtilities.h"
#include "../View/View.h"
#include "../View/ChangedProperties.h"

static const std::string SUB_MODEL_NAME = "Organ";

OrganSubModel::OrganSubModel(SubModels& subModels)
	: SubModel(subModels), _isPresent(false), _isRotatorSpeedFast(false)
{
    for (int n = 0; n < NR_OF_DRAWBARS; n++)
    {
        _drawbarValues.push_back(0.0);
    }
}

void OrganSubModel::Init() /* override */
{
}

bool OrganSubModel::IsPresent()
{
    return _isPresent;
}

void OrganSubModel::SetIsPresent(bool isPresent)
{
    if (_isPresent != isPresent)
    {
        _isPresent = isPresent;
        Debug::Log("# " + SUB_MODEL_NAME + ": Is Present, is present = " + std::to_string(isPresent));
        Notify(ChangedProperties::EChangedProperty::OrganIsPresent);
    }
}

double OrganSubModel::GetDrawbarValue(int drawbarIndex)
{
    Debug::Assert((drawbarIndex >= 0) && (drawbarIndex < NR_OF_DRAWBARS), __FUNCTION__,
                  "Drawbar index out of range: " + std::to_string(drawbarIndex));

    return _drawbarValues[drawbarIndex];
}

void OrganSubModel::SetDrawbarValue(int drawbarIndex, double newValue)
{
    Debug::Assert((drawbarIndex >= 0) && (drawbarIndex < NR_OF_DRAWBARS), __FUNCTION__,
                  "Drawbar index out of range: " + std::to_string(drawbarIndex));

	 if (!DoubleUtilities::AreEqual(newValue, _drawbarValues[drawbarIndex]))
    {
        _drawbarValues[drawbarIndex] = newValue;
        Debug::Log("# " + SUB_MODEL_NAME + ": Drawbar, index = " + std::to_string(drawbarIndex) +
                   ", value = " + std::to_string(newValue));
        Notify((ChangedProperties::EChangedProperty) ((int)ChangedProperties::EChangedProperty::OrganDrawbar1 + drawbarIndex));
    }
}

bool OrganSubModel::IsRotatorSpeedFast()
{
    return _isRotatorSpeedFast;
}

void OrganSubModel::SetRotatorSpeedFast(bool rotatorSpeedFast)
{
    if (rotatorSpeedFast != _isRotatorSpeedFast)
    {
        _isRotatorSpeedFast = rotatorSpeedFast;
        Debug::Log("# " + SUB_MODEL_NAME + ": Rotator Speed Fast, fast = " + std::to_string(rotatorSpeedFast));
        Notify(ChangedProperties::EChangedProperty::OrganRotatorSpeed);
    }
}

void OrganSubModel::SwapRotatorSpeed()
{
    SetRotatorSpeedFast(!_isRotatorSpeedFast);
}
