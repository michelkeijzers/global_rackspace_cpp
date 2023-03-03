#pragma once

#include <vector>

class MidiInBlock;
class Controller;

class MidiInBlocks
{
  public:
    enum class EMidiInBlockId
    {
        PrimaryKeyboard
    };

    MidiInBlocks(Controller &controller);
    ~MidiInBlocks();

    void Fill();
    void Init();

    MidiInBlock &GetPluginById(EMidiInBlockId organ);

  private:
    std::vector<MidiInBlock *> _midiInBlocks;

    Controller &_controller;
};
