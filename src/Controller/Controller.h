#pragma once

#include <string>
#include <juce_core/juce_core.h>
#include <juce_core/threads/juce_HighResolutionTimer.h>
#include "../MidiInBlocks/MidiInBlocks.h"
#include "SubControllers.h"

class PrimaryKeyboardMidiInBlock;
class Model;
class View;
class WidgetsListener;

class Controller : juce::HighResolutionTimer
{
  public:
    Controller(Model &model, View &view);
    ~Controller();

    Model &GetModel();
    View &GetView();

    bool OnMidiIn(const std::string &deviceName, const uint8_t *data, int length);

	 void StartTimer();

    void Fill();
    void Init();

    SubController &GetSubController(SubControllers::ESubControllerId id);

  private:
    void hiResTimerCallback() override;

	 Model &_model;
    View &_view; 

    SubControllers _subControllers;
    MidiInBlocks _midiInBlocks;

	 const std::string ConvertDataToString(const uint8_t *data, int length);
};
