#include "MidiInBlocks.h"
#include "../Utilities/Debug.h"
#include "MidiInBlock.h"
#include "PrimaryKeyboardMidiInBlock.h"

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
    _midiInBlocks.push_back(new PrimaryKeyboardMidiInBlock(_controller));
    _nameToMidiInBlocks.insert(std::pair<std::string, MidiInBlock *>("PrimaryKeyboardMidiInBlock",
                                                                     new PrimaryKeyboardMidiInBlock(_controller)));
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
    return *(_midiInBlocks.at((int)id));
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