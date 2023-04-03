#pragma once

#include <map>
#include <string>
#include <vector>

class MidiInForOutputBlock;
class Controller;

class MidiInForOutputBlocks
{
 public:
   enum class EMidiInForOutputBlockId
   {
      Organ
   };

   MidiInForOutputBlocks(Controller &controller);
   ~MidiInForOutputBlocks();

   void Fill();
   void Init();

   MidiInForOutputBlock &GetMidiInForOutputBlock(EMidiInForOutputBlockId organ);
   MidiInForOutputBlock &GetMidiInForOutputBlock(const std::string &midiInForOutputBlockName);

 private:
   std::vector<MidiInForOutputBlock *> _midiInForOutputBlocks;
   std::map<std::string, MidiInForOutputBlock *> _nameToMidiInForOutputBlocks;

   Controller &_controller;
};
