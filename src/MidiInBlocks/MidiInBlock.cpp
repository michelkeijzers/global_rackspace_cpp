#include "MidiInBlock.h"

MidiInBlock::MidiInBlock(Controller* controller)
{
    _controller = controller;
}

MidiInBlock::MidiInBlock(std::string name)
{
    _name = name;
}

std::string MidiInBlock::GetName()
{
    return _name;
}


Controller* MidiInBlock::GetController()
{
    return _controller;
}
