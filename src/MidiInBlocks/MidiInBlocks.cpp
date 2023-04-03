#include "MidiInBlocks.h"
#include "../Utilities/Debug.h"
#include "AudioToCcMidiInBlock.h"
#include "FootBoardMidiInBlock.h"
#include "MidiInBlock.h"
#include "PrimaryKeyboardMidiInBlock.h"
#include "SecondaryKeyboardMidiInBlock.h"

MidiInBlocks::MidiInBlocks(Controller &controller) : _controller(controller)
{
}

MidiInBlocks::~MidiInBlocks()
{
   _midiInBlocks.clear();
   _nameToMidiInBlocks.clear();
}

void MidiInBlocks::Fill()
{
   PrimaryKeyboardMidiInBlock *primaryKeyboardMidiInBlock = new PrimaryKeyboardMidiInBlock(_controller);
   _midiInBlocks.push_back(primaryKeyboardMidiInBlock);
   _nameToMidiInBlocks.insert(
    std::pair<std::string, MidiInBlock *>("PrimaryKeyboardMidiInBlock", primaryKeyboardMidiInBlock));
   SecondaryKeyboardMidiInBlock *secondaryKeyboardMidiInBlock = new SecondaryKeyboardMidiInBlock(_controller);
   _midiInBlocks.push_back(secondaryKeyboardMidiInBlock);
   _nameToMidiInBlocks.insert(
    std::pair<std::string, MidiInBlock *>("SecondaryKeyboardMidiInBlock", secondaryKeyboardMidiInBlock));
   FootBoardMidiInBlock *footBoardMidiInBlock = new FootBoardMidiInBlock(_controller);
   _midiInBlocks.push_back(footBoardMidiInBlock);
   _nameToMidiInBlocks.insert(std::pair<std::string, MidiInBlock *>("FootBoardMidiInBlock", footBoardMidiInBlock));
   AudioToCcMidiInBlock *audioToCcMidiInBlock = new AudioToCcMidiInBlock(_controller);
   _midiInBlocks.push_back(audioToCcMidiInBlock);
   _nameToMidiInBlocks.insert(std::pair<std::string, MidiInBlock *>("AudioToCcMidiInput", audioToCcMidiInBlock));
}

void MidiInBlocks::Init()
{
   for (auto midiInBlock : _midiInBlocks)
   {
      midiInBlock->Init();
   }
}

MidiInBlock &MidiInBlocks::GetMidiInBlock(EMidiInBlockId id)
{
   return *(_midiInBlocks.at(static_cast<int>(id)));
}

MidiInBlock &MidiInBlocks::GetMidiInBlock(const std::string &midiInBlockName)
{
   return *_nameToMidiInBlocks[midiInBlockName];
}

bool MidiInBlocks::OnMidiIn(const std::string &deviceName, const uint8_t *data, int length)
{
   bool processed = false;

   MidiInBlock &midiInBlock = GetMidiInBlock(deviceName);
   processed = midiInBlock.OnMidiIn(data, length);

   return processed;
}
