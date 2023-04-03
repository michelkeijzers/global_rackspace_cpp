#include "MidiInForOutputBlocks.h"
#include "../Utilities/Debug.h"
#include "OrganMidiInForOutputBlock.h"
#include "../Model/Model.h"

MidiInForOutputBlocks::MidiInForOutputBlocks(Controller &controller) : _controller(controller)
{
}

MidiInForOutputBlocks::~MidiInForOutputBlocks()
{
   _midiInForOutputBlocks.clear();
   _nameToMidiInForOutputBlocks.clear();
}

void MidiInForOutputBlocks::Fill()
{
   OrganSubModel &organSubModel =
    static_cast<OrganSubModel &>(_controller.GetModel().GetSubModel(SubModels::ESubModelId::Organ));
   MidiInForOutputBlock *block = new OrganMidiInForOutputBlock(organSubModel, "OrganMidiInBlock");
   _midiInForOutputBlocks.push_back(block);
   _nameToMidiInForOutputBlocks.insert(std::pair<std::string, MidiInForOutputBlock *>("OrganMidiInBlock", block));
}

void MidiInForOutputBlocks::Init()
{
   for (auto midiInForOutputBlock : _midiInForOutputBlocks)
   {
      midiInForOutputBlock->Init();
   }
}

MidiInForOutputBlock &MidiInForOutputBlocks::GetMidiInForOutputBlock(EMidiInForOutputBlockId id)
{
   return *(_midiInForOutputBlocks.at(static_cast<int>(id)));
}

MidiInForOutputBlock &MidiInForOutputBlocks::GetMidiInForOutputBlock(const std::string &midiInForOutputBlockName)
{
   return *_nameToMidiInForOutputBlocks[midiInForOutputBlockName];
}
