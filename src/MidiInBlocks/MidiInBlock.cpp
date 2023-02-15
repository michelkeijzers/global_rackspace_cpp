#include "MidiInBlock.h"

MidiInBlock::MidiInBlock()
{
}

MidiInBlock::MidiInBlock(std::string name)
{
    _name = name;
}

std::string MidiInBlock::GetName()
{
    return _name;
}
