#pragma once

#include <vector>
#include "SubModel.h"
#include "../View/Observable.h"

enum class EOrganRotatorSpeed
{
    Fast,
    Slow,
    Off
};

class SubModels;

class OrganSubModel : public SubModel, public Observable
{
  public:
    static const int NR_OF_DRAWBARS = 9;

    OrganSubModel(SubModels& subModels);
    const std::string GetDebugName() override;
	 	 
	 bool IsEnabled();
    void Enable(bool enable);

	 double GetDrawbarValue(int drawbarIndex);
    void SetDrawbarValue(int drawbarIndex, double newValue);

    bool IsRotatorSpeedFast();
    void SetRotatorSpeedFast(bool rotatorSpeedFast);
    void SwapRotatorSpeed();

	 double GetDrive();
    void SetDrive(double drive);
     
	 double GetReverbAmount();
    void SetReverbAmount(double reverbAmount);

	 // Setup
    bool IsPrimaryKeyboardActive();
    void SetPrimaryKeyboardActive(bool primaryKeyboardIsActive);
	 bool IsSecondaryKeyboardActive();
    void SetSecondaryKeyboardActive(bool secondaryKeyboardIsActive);
    void CheckIfEnabled();

	 int GetLowestNote();
    void SetLowestNote(int lowestNote);
    int GetHighestNote();
    void SetHighestNote(int highestNote);

	 bool IsSustainPedalActive();
    void SetSustainPedalActive(bool sustainPedalIsActive);

  private:
	 std::vector<double> _drawbarValues;
    bool _isEnabled;
    bool _isRotatorSpeedFast;
    double _drive;
    double _reverbAmount;

	 // Setup
    bool _primaryKeyboardIsActive;
    bool _secondaryKeyboardIsActive;
    int _lowestNote;
    int _highestNote;
    bool _sustainPedalIsActive;
};
