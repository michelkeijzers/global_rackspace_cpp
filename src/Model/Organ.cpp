#include "Organ.h"

Organ::Organ() 
	: _isPresent(false),
	_rotatorSpeed(EOrganRotatorSpeed::Off)
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


EOrganRotatorSpeed Organ::GetRotatorSpeed()
{
    return _rotatorSpeed;
}

void Organ::SetRotatorSpeed(EOrganRotatorSpeed rotatorSpeed)
{
    _rotatorSpeed = rotatorSpeed;
}

EOrganRotatorSpeed Organ::SwapRotatorSpeed()
{
    if (_rotatorSpeed == EOrganRotatorSpeed::Fast)
    {
        SetRotatorSpeed(EOrganRotatorSpeed::Slow);
    }
    else if (_rotatorSpeed == EOrganRotatorSpeed::Slow)
    {
        SetRotatorSpeed(EOrganRotatorSpeed::Fast);
    }

    return _rotatorSpeed;
}