#pragma once

#include <vector>
#include "SubModel.h"
#include "../Utilities/Observable.h"

class OrganSubModel;

enum class EOrganRotatorSpeed
{
    Fast,
    Slow,
    Off
};

class organSubModel : SubModel, Observable<OrganSubModel>
{
  public:
    static const int NR_OF_DRAWBARS = 9;

    organSubModel();
	 	 
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