#include "Organ.h"

Organ::Organ() : _isPresent(false), _isRotatorSpeedFast(false)
{
}

bool Organ::IsPresent()
{
    return _isPresent;
}

void Organ::SetIsPresent(bool isPresent)
{
    _isPresent = isPresent;
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

bool Organ::SwapRotatorSpeed()
{
    SetRotatorSpeedFast(!_isRotatorSpeedFast);

    return _isRotatorSpeedFast;
}