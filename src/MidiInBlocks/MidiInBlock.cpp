#include "MidiInBlock.h"
#include "../Utilities/Debug.h"
#include "../Utilities/MidiUtilities.h"

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

bool MidiInBlock::OnMidiIn(const uint8_t *data, int length)
{
    Debug::LogMethodEntry(__FUNCTION__, "length = " + std::to_string(length));
    bool handleMessage = true;
    if (MidiUtilities::IsCcMessage(data, length))
    {
        if (MidiUtilities::IsChannel1(data, length))
        {
            Debug::Assert(length == 3, __FUNCTION__, "Illegal length for MIDI CC message");
            handleMessage = HandleCcMessage(data[1], data[2]);
        }
    }
    Debug::LogMethodExit(__FUNCTION__);
    return handleMessage;
}
