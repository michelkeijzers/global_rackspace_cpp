#pragma once

#include <string>
#include <juce_core/juce_core.h>
#include <juce_events/timers/juce_Timer.h>
#include "../MidiInBlocks/MidiInBlocks.h"
#include "SubControllers.h"

class PrimaryKeyboardMidiInBlock;
class Model;
class View;
class WidgetsListener;

class Controller : juce::Timer
{
  public:
    Controller(Model &model, View &view);
    ~Controller();

    Model &GetModel();
    View &GetView();

    bool OnMidiIn(const std::string &deviceName, const uint8_t *data, int length);

    void Fill();
    void Init();

    SubController &GetSubController(SubControllers::ESubControllerId id);

  private:
    void timerCallback(); // override

	 Model &_model;
    View &_view; 

    SubControllers _subControllers;
    MidiInBlocks _midiInBlocks;

	 const std::string ConvertDataToString(const uint8_t *data, int length);
};
