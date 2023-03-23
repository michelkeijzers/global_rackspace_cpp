#pragma once

#include "../MidiInBlocks/MidiInBlocks.h"
#include "SubControllers.h"
#include <juce_core/juce_core.h>
#include <juce_core/threads/juce_HighResolutionTimer.h>
#include <string>

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

    void OnSongChanged(int oldIndex, int newIndex);
    void OnPreviousSong();
    void OnNextSong();
    void WriteSong();

    SubController &GetSubController(SubControllers::ESubControllerId id);

  private:
    const std::string ConvertDataToString(const uint8_t *data, int length);

    void hiResTimerCallback() override;

    std::string GetCurrentSongName();

    Model &_model;
    View &_view;

    SubControllers _subControllers;
    MidiInBlocks _midiInBlocks;
};
