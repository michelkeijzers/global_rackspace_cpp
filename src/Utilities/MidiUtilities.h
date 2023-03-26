#pragma once

#ifdef TESTER
#include "../../../JuceTester2/NewProject/Builds/VisualStudio2022/Source/GP_API/types.h"
#else
#include "../../build/windows-native/_deps/gp-sdk-src/c/include/gigperformer/sdk/types.h"
#endif

/* static */ class MidiUtilities
{
 public:
   static void FillCcMessage(uint8_t *data, uint8_t ccNumber, uint8_t ccValue);

   static bool IsChannel1(const uint8_t *data, int length);
   static bool IsCcMessage(const uint8_t *data, int length);

   static double MidiToParam(uint8_t value);
   static bool MidiToBool(uint8_t value);
   static uint8_t BoolToMidi(bool value);
   static uint8_t ParamToMidi(double value);

 private:
   MidiUtilities();
};
