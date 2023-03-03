#include "PrimaryKeyboardMidiInBlock.h"
#include "MidiInBlock.h"
#include "MidiInBlocks.h"

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

MidiInBlock &MidiInBlocks::GetPluginById(EMidiInBlockId id)
{
    return *(_midiInBlocks.at((int)id));
}
