#pragma once

#include <string>
#include <vector>
#include <map>

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

    MidiInBlock &GetMidiInBlock(EMidiInBlockId organ);
    MidiInBlock &GetMidiInBlock(const std::string &midiInBlockName);

	 bool OnMidiIn(const std::string &deviceName, const uint8_t *data, int length);

  private:
     std::vector<MidiInBlock *> _midiInBlocks;
     std::map<std::string, MidiInBlock *> _nameToMidiInBlocks;
    
    Controller &_controller;
};
