#pragma once

#include "../View/Observable.h"
#include "SubModel.h"
#include <string>
#include <vector>

enum class EOrganRotatorSpeed
{
   Fast,
   Slow,
   Off
};

class Model;
class MixerSubModel;

class OrganSubModel : public SubModel, public Observable
{
 public:
   static const int NR_OF_DRAWBARS = 9;

   OrganSubModel(Model &model);
   const std::string GetName() override;

   std::string Serialize() override;
   int Deserialize(std::vector<std::string> lines, int currentLineIndex) override;

   bool IsEnabled();
   void Enable(bool enable);

   double GetDrawbars(int drawbarIndex);
   void SetDrawbars(int drawbarIndex, double newValue);

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

   uint8_t GetLowestNote();
   void SetLowestNote(uint8_t lowestNote);
   uint8_t GetHighestNote();
   void SetHighestNote(uint8_t highestNote);

   bool IsSustainPedalActive();
   void SetSustainPedalActive(bool sustainPedalIsActive);

   enum class EParameters
   {
      Drawbar,
      IsEnabled,
      IsRotatorSpeedFast,
      Drive,
      ReverbAmount,
      PrimaryKeyboardIsActive,
      SecondaryKeyboardIsActive,
      LowestNote,
      HighestNote,
      SustainPedalIsActive,
      Last
   };

 private:
   std::vector<double> _drawbars;
   bool _isEnabled;
   bool _isRotatorSpeedFast;
   double _drive;
   double _reverbAmount;

   // Setup
   bool _primaryKeyboardIsActive;
   bool _secondaryKeyboardIsActive;
   uint8_t _lowestNote;
   uint8_t _highestNote;
   bool _sustainPedalIsActive;
};
