#include "Organ.h"
#include "../Utilities/Debug.h"

Organ::Organ() : _isPresent(false), _isRotatorSpeedFast(false)
{
    for (int n = 0; n < NR_OF_DRAWBARS; n++)
    {
        _drawbarValues.push_back(0.0);
	 }
}

bool Organ::IsPresent()
{
    return _isPresent;
}

void Organ::SetIsPresent(bool isPresent)
{
    _isPresent = isPresent;
}

double Organ::GetDrawbarValue(int drawbarIndex)
{
    Debug::Assert((drawbarIndex >= 0) && (drawbarIndex < NR_OF_DRAWBARS), __FUNCTION__,
                  "Drawbar index out of range: " + std::to_string(drawbarIndex));

	 return _drawbarValues[drawbarIndex];
}

void Organ::SetDrawbarValue(int drawbarIndex, double newValue)
{
    Debug::Assert((drawbarIndex >= 0) && (drawbarIndex < NR_OF_DRAWBARS), __FUNCTION__,
                  "Drawbar index out of range: " + std::to_string(drawbarIndex));

    _drawbarValues[drawbarIndex] = newValue;
}

bool Organ::IsRotatorSpeedFast()
{
    return _isRotatorSpeedFast;
}

void Organ::SetRotatorSpeedFast(bool rotatorSpeedFast)
{
    if (rotatorSpeedFast != _isRotatorSpeedFast)
    {
        _isRotatorSpeedFast = rotatorSpeedFast;
    }
}

void Organ::SwapRotatorSpeed()
{
    SetRotatorSpeedFast(!_isRotatorSpeedFast);
}