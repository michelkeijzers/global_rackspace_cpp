#include "OrganSubModel.h"
#include "../Utilities/Debug.h"
#include "../Utilities/DoubleUtilities.h"
#include "../View/View.h"
#include "../View/ChangedProperties.h"

OrganSubModel::OrganSubModel() : SubModel(), _isPresent(false), _isRotatorSpeedFast(false)
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
    _isPresent = isPresent;
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
        Notify(ChangedProperties::EChangedProperty::Drawbar1);
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
        Notify(ChangedProperties::EChangedProperty::OrganRotatorSpeed);
    }
}

void OrganSubModel::SwapRotatorSpeed()
{
    SetRotatorSpeedFast(!_isRotatorSpeedFast);
}
