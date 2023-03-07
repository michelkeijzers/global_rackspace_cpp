#pragma once

#include "../View/Observable.h"
#include "MixerChannelSubModel.h"
#include "SubModel.h"
#include <string>

class SubModels;

class MixerChannelSubModel : public SubModel, public Observable
{
  public:
    enum class ESource
    {
        PrimaryKeyboard,
        PrimaryKeyboardPads,
        SecondaryKeyboard,
    };

    MixerChannelSubModel(SubModels subModels, int channelIndex);

    void Init() override;

    double GetVolume();
    void SetVolume(double volume);

    const std::string &GetName();
    void SetName(const std::string &name);

	 ESource GetSource();
    void SetSource(ESource source);

	 bool IsVolumeOverridden();
    void SetSource(bool volumeOverride);

  private:
    std::string GetSourceAsName();

    int _channelIndex;
    double _volume;
    
	 std::string _name;
    ESource _source;
     bool _volumeIsOverridden;
};
