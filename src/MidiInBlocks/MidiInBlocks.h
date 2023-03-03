#pragma once

#include <string>
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

    MidiInBlock &GetMidiInBlockById(EMidiInBlockId organ);

	 bool OnMidiIn(const std::string &deviceName, const uint8_t *data, int length);

  private:
    std::vector<MidiInBlock *> _midiInBlocks;

    Controller &_controller;
};
