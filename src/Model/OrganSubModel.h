#pragma once

#include <vector>
#include "SubModel.h"
#include "../Utilities/Observable.h"

enum class EOrganRotatorSpeed
{
    Fast,
    Slow,
    Off
};

class OrganSubModel : public SubModel, public Observable
{
  public:
    static const int NR_OF_DRAWBARS = 9;

    OrganSubModel();
	 	 
	 void Init() override;

	 bool IsPresent();
    void SetIsPresent(bool isPresent);

	 double GetDrawbarValue(int drawbarIndex);
    void SetDrawbarValue(int drawbarIndex, double newValue);

    bool IsRotatorSpeedFast();
    void SetRotatorSpeedFast(bool rotatorSpeedFast);
    void SwapRotatorSpeed();

  private:
	 std::vector<double> _drawbarValues;
    bool _isPresent;
    bool _isRotatorSpeedFast;
};
