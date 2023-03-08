#include "MidiInBlock.h"

MidiInBlock::MidiInBlock(Controller &controller, const std::string name) : _controller(controller), _name(name)
{
}

/* virtual */ void MidiInBlock::Init()
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
