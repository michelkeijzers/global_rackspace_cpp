#include "AudioToCcMidiInBlock.h"
#include "../Controller/Controller.h"
#include "../Utilities/MidiUtilities.h"
#include "../Model/MixerSubModel.h"
#include "../Model/Model.h"
#include "../Utilities/Debug.h"
#include "../Utilities/IntUtilities.h"
#include <iostream>

AudioToCcMidiInBlock::AudioToCcMidiInBlock(Controller &controller) : MidiInBlock(controller, "AudioToCcMidiInput")
{
}

/// <summary>
/// Handle CC message. See table in AudioToCcPlugin.cpp
/// </summary>
/// <param name="ccNumber"></param>
/// <param name="value"></param>
/// <returns></returns>
bool AudioToCcMidiInBlock::HandleCcMessage(uint8_t ccNumber, uint8_t value)
{
    bool handleMessage = true;
    bool master = false;
    MixerSubController &mixerSubController =
        (MixerSubController &)(GetController().GetSubController(SubControllers::ESubControllerId::Mixer));

    int channelIndex = ccNumber / 4;
    if (channelIndex == MixerSubModel::NR_OF_MIXER_CHANNELS)
    {
        master = true;
        channelIndex = -1;
    }

    ECcType ccType = GetCcType(ccNumber);

    switch (ccType)
    {
    case ECcType::LevelLeft:
        mixerSubController.SetChannelLevelLeft(master, channelIndex, MidiUtilities::MidiToParam(value));
        handleMessage = true;
        break;

    case ECcType::LevelRight:
        mixerSubController.SetChannelLevelRight(master, channelIndex, MidiUtilities::MidiToParam(value));
        handleMessage = true;
        break;

    case ECcType::GateLeft:
        mixerSubController.SetChannelGateLeft(master, channelIndex, MidiUtilities::MidiToParam(value));
        handleMessage = true;
        break;

    case ECcType::GateRight:
        mixerSubController.SetChannelGateRight(master, channelIndex, MidiUtilities::MidiToParam(value));
        handleMessage = true;
        break;

    default:
        Debug::Error(__FUNCTION__, "Illegal CC type");
    }

    return handleMessage;
}

AudioToCcMidiInBlock::ECcType AudioToCcMidiInBlock::GetCcType(uint8_t ccNumber)
{
    ECcType ccType = ECcType::GateLeft;

    switch (ccNumber % 4)
    {
    case 0:
        ccType = ECcType::LevelLeft;
        break;

    case 1:
        ccType = ECcType::LevelRight;
        break;

    case 2:
        ccType = ECcType::GateLeft;
        break;

    case 3:
        ccType = ECcType::GateRight;
        break;

    default:
        Debug::Error(__FUNCTION__, "Illegal CC type");
    }

    return ccType;
}
