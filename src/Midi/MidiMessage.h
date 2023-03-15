#pragma once

#ifdef WIN32
	#include "../../../JuceTest1/NewProject/Builds/VisualStudio2022/GP_API/types.h"
#else
	#include "../../build/windows-native/_deps//gp-sdk-src/c/include/gigperformer/sdk/types.h"
#endif

/* static */ class MidiMessage
{
  public:
    static bool IsChannel1(const uint8_t *data, int length);
    static bool IsCcMessage(const uint8_t *data, int length);

	 static double MidiToParam(uint8_t value);
    static uint8_t ParamToMidi(double value);

  private:
    MidiMessage();
};
