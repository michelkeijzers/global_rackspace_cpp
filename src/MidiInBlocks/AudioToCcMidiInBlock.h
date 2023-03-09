#pragma once

#include "MidiInBlock.h"

class Controller;

class AudioToCcMidiInBlock : public MidiInBlock
{
  public:
    AudioToCcMidiInBlock(Controller &controller);

    bool OnMidiIn(const uint8_t *data, int length) override;

  private:
    enum class ECcType
    {
        LevelLeft,
        LevelRight,
        GateLeft,
        GateRight
    };

	 bool HandleCcMessage(uint8_t ccNumber, uint8_t value);

	 ECcType GetCcType(uint8_t ccNumber);
};
