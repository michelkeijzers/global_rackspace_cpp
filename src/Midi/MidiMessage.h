#pragma once

#ifdef TESTER
	#include "../../../JuceTester2/NewProject/Source/types.h"
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
