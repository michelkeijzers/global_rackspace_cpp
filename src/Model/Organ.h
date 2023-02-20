#pragma once

enum class EOrganRotatorSpeed
{
    Fast,
    Slow,
    Off
};

class Organ
{
  public:
    Organ();

	 bool IsPresent();
    void SetIsPresent(bool isPresent);

    bool IsRotatorSpeedFast();
    void SetRotatorSpeedFast(bool rotatorSpeedFast);
    void SwapRotatorSpeed();

  private:
    bool _isPresent;
    bool _isRotatorSpeedFast;
};