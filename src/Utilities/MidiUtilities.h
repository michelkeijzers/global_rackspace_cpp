#pragma once

#ifdef TESTER
#include "../../../JuceTester2/NewProject/Builds/VisualStudio2022/Source/GP_API/types.h"
#else
#include "../../build/windows-native/_deps/gp-sdk-src/c/include/gigperformer/sdk/types.h"
#endif

#define MIDI_MESSAGE_CC_LENGTH 3
#define MIDI_MESSAGE_NOTE_ON_OFF_LENGTH 3

/* static */ class MidiUtilities
{
 public:
   enum class ECCs
   {
      ModulationWheel = 1,
      Sustain = 64
   };

   static void FillNoteOffMessage(uint8_t *data, uint8_t ccNumber, uint8_t ccValue);
   static void FillNoteOnMessage(uint8_t *data, uint8_t ccNumber, uint8_t ccValue);
   static void FillCcMessage(uint8_t *data, uint8_t ccNumber, uint8_t ccValue);

   static bool IsChannel1(const uint8_t *data, int length);
   static bool IsCcMessage(const uint8_t *data, int length);
   static bool IsNoteOffMessage(const uint8_t *data, int length);
   static bool IsNoteOnMessage(const uint8_t *data, int length);

   static double MidiToParam(uint8_t value);
   static bool MidiToBool(uint8_t value);
   static uint8_t BoolToMidi(bool value);
   static uint8_t ParamToMidi(double value);

 private:
   static void FillNoteOnOffMessage(uint8_t *data, bool noteOnMessage, uint8_t ccNumber, uint8_t ccValue);

   const static uint8_t NOTE_ON_MESSAGE = 0x80;
   const static uint8_t NOTE_OFF_MESSAGE = 0x90;
   const static uint8_t CC_MESSAGE = 0xB0;

   MidiUtilities();
};
