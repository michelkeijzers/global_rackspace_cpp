#include "PrimaryKeyboardMidiInBlock.h"
#include "MidiInBlock.h"
#include "MidiInBlocks.h"
#include "../Utilities/Debug.h"

MidiInBlocks::MidiInBlocks(Controller &controller) : _controller(controller)
{
}

MidiInBlocks::~MidiInBlocks()
{
    _midiInBlocks.clear();
}

void MidiInBlocks::Fill()
{
    _midiInBlocks.push_back(new PrimaryKeyboardMidiInBlock(_controller));
}

void MidiInBlocks::Init()
{
    for (auto midiInBlock : _midiInBlocks)
    {
        midiInBlock->Init();
	 }
}

MidiInBlock &MidiInBlocks::GetMidiInBlockById(EMidiInBlockId id)
{
    return *(_midiInBlocks.at((int)id));
}

bool MidiInBlocks::OnMidiIn(const std::string &deviceName, const uint8_t *data, int length)
{
    bool processed = false;

    MidiInBlock& midiInBlock = GetMidiInBlockByName(deviceName); //  TODO: Use map string->id
    processed = midiInBlock.OnMidiIn(data, length); // TODO: Make virtual abstract

	 return processed;
}