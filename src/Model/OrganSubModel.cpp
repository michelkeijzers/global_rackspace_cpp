#include "OrganSubModel.h"
#include "../Utilities/Debug.h"
#include "../View/View.h"

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

	 if (fabs(newValue - _drawbarValues[drawbarIndex]) > 0.01) // TODO: Constant for 0.01
    {
        _drawbarValues[drawbarIndex] = newValue;
        Notify(View::EChangedProperty::Drawbar1);
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
    }
}

void OrganSubModel::SwapRotatorSpeed()
{
    SetRotatorSpeedFast(!_isRotatorSpeedFast);
}
