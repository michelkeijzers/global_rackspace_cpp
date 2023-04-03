#include "MidiInForOutputBlock.h"
#include "../Framework/MvcFramework.h"
#include "../Utilities/Debug.h"
#include "../Utilities/MidiUtilities.h"

MidiInForOutputBlock::MidiInForOutputBlock(const std::string name)
    : _name(name)
{
}

/* virtual */ void MidiInForOutputBlock::Init()
{
}

std::string MidiInForOutputBlock::GetName()
{
   return _name;
}

