#include "organSubModel.h"
#include "../Utilities/Debug.h"

organSubModel::organSubModel() : SubModel(), _isPresent(false), _isRotatorSpeedFast(false)
{
    for (int n = 0; n < NR_OF_DRAWBARS; n++)
    {
        _drawbarValues.push_back(0.0);
    }
}

void organSubModel::Init() /* override */
{
}

bool organSubModel::IsPresent()
{
    return _isPresent;
}

void organSubModel::SetIsPresent(bool isPresent)
{
    _isPresent = isPresent;
}

double organSubModel::GetDrawbarValue(int drawbarIndex)
{
    Debug::Assert((drawbarIndex >= 0) && (drawbarIndex < NR_OF_DRAWBARS), __FUNCTION__,
                  "Drawbar index out of range: " + std::to_string(drawbarIndex));

    return _drawbarValues[drawbarIndex];
}

void organSubModel::SetDrawbarValue(int drawbarIndex, double newValue)
{
    Debug::Assert((drawbarIndex >= 0) && (drawbarIndex < NR_OF_DRAWBARS), __FUNCTION__,
                  "Drawbar index out of range: " + std::to_string(drawbarIndex));

	 if (fabs(newValue - _drawbarValues[drawbarIndex]) > 0.01) // TODO: Constant for 0.01
    {
        _drawbarValues[drawbarIndex] = newValue;

    }
}

bool organSubModel::IsRotatorSpeedFast()
{
    return _isRotatorSpeedFast;
}

void organSubModel::SetRotatorSpeedFast(bool rotatorSpeedFast)
{
    if (rotatorSpeedFast != _isRotatorSpeedFast)
    {
        _isRotatorSpeedFast = rotatorSpeedFast;
    }
}

void organSubModel::SwapRotatorSpeed()
{
    SetRotatorSpeedFast(!_isRotatorSpeedFast);
}