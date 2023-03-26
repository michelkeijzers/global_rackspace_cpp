#pragma once

#include "../Model/organSubModel.h"
#include "SubController.h"

class Controller;
class OrganSubModel;

class OrganSubController : public SubController
{
 public:
   OrganSubController(Controller &controller);

   void Init() override;

   void Enable(bool enable, bool forced = false);

   void SetDrawbarValue(int drawbarIndex, double newValue, bool forced = false);

   void SetRotatorSpeed(bool newRotatorSpeedFast, bool forced = false);
   void SwapRotatorSpeed();

   void SetDrive(double drive, bool forced = false);
   void SetReverbAmount(double reverbAmount, bool forced = false);

   // Setup
   void SetPrimaryKeyboardActive(bool active, bool forced = false);
   void SetSecondaryKeyboardActive(bool active, bool forced = false);
   void SetLowestNote(uint8_t note, bool forced = false);
   void SetHighestNote(uint8_t note, bool forced = false);
   void SetSustainPedalActive(bool active, bool forced = false);

 private:
   OrganSubModel &_organSubModel;
};
