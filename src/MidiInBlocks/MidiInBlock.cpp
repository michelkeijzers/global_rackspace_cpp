#include "MidiInBlock.h"

MidiInBlock::MidiInBlock(Controller &controller, std::string name) : _controller(controller), _name(name)
{
}

std::string MidiInBlock::GetName()
{
    return _name;
}


Controller& MidiInBlock::GetController()
{
    return _controller;
}
