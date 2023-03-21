/*
    # Parameter       Default value   Param Value   Param Value    Channels
          Name			                  Formula        Double          1   2   3   4   5    ..  24 Master
     - ---------------- -------------- ------------- ------------     --- --- --- --- ---      --- -------
     0 envelope L       Read only       Do not set
     1 envelope R       Read only       Do not set
     2 GateEnvL         Read only       Do not set
     3 GateEnvR         Read only       Do not set
     4 RMSGain		       0.0 dB         Unknown      0.0312500
     5 PeakGain	          2.8 dB         Unknown      0.0434777
     6 L CC                             (CC+1)/128       ->            0   4                   92    96
     7 R CC                             (CC+1)/128       ->            1   5                   93    97
     8 Channel              5           (MC-1)/15
     9 Mono/Stereo       Stereo            1.0
     10 Rate             1.8 ms            0.66
     11 Inertia            50             VAL/100
     12 Attack             17             VAL/100
     13 Release            27             VAL/100
     14 EnvScale          ???            Do not set
     15 Device             -                0
     16 MidiToHost         On               1
     17 AutomateHost       Off              0
     18 Gate Tresh        0.0 dB        (VAL+1)/128
     19 L Gate CC           2           (CC+1)/128)                    2   6                   94    98
     20 R Gate CC           3           (CC+1)/128)                    3   7                   95    99
     21 L On Value         127          (VAL+1)/128
     22 R On Value         127          (VAL+1)/128
     23 L Off Value         0           (VAL+1/128)
     24 R Off Value         0           (VAL+1/128)
     25 L Gate Reset     Do not use     Do not set
     26 R Gate Reset     DO not use     Do not set

     * dB calculation:  -inf + [ -95.8 .. 30.1 steps of 0.3] = 1 + (30.1--95.8)/0.3 = 1 +
     */

#include "AudioToCcPlugin.h"
#include "../Controller/Controller.h"
#include "../Framework/MvcFramework.h"
#include "../Model/MixerSubModel.h"
#include "../Utilities/BoolUtilities.h"
#include "../Utilities/Debug.h"
#include <iostream>

#ifdef TESTER
    #include "../../../JuceTester2/NewProject/Builds/VisualStudio2022/Source/GP_API/GigPerformerAPI.h"
#else
    #include <gigperformer/sdk/GigPerformerAPI.h>
#endif

static const int NR_OF_VARIABLE_PARAMETERS_PER_CHANNEL = 4;

enum EParameters
{
    EnvelopeLeft,
    EnvelopeRight,
    GateEnvelopeLeft,
    GateEnvelopeRight,
    RmsGain,
    PeakGain,
    LeftCc,
    RightCc,
    Channel,
    MonoStereo,
    Rate,
    Inertia,
    Attack,
    Release,
    EnvScale,
    Device,
    MidiToHost,
    AutomateHost,
    GateTreshold,
    LeftGateCc,
    RightGateCc,
    LeftOnValue,
    RightOnValue,
    LeftOffValue,
    RightOffValue,
    LeftGateReset,
    RightGateReset
};

AudioToCcPlugin::AudioToCcPlugin(View &view, MixerSubModel &mixerSubModel, bool master, int channelIndex,
                                 const std::string &name)

    : Plugin(name, view), _master(master), _channelIndex(channelIndex), _mixerSubModel(mixerSubModel)
{
    _mixerSubModel.Subscribe(*this);
}

/// <summary>
/// Set parameters
/// </summary>
void AudioToCcPlugin::Init() // override
{
    auto &api = MvcFramework::GetGigPerformerApi();
    auto &name = GetName();
    const int ccNumber = _channelIndex * NR_OF_VARIABLE_PARAMETERS_PER_CHANNEL;

	 api.setPluginParameter(name, EParameters::RmsGain, 0.0312500, true);  // 0.0 dB
    api.setPluginParameter(name, EParameters::PeakGain, 0.0434777, true); // 2.8 dB
    api.setPluginParameter(name, EParameters::LeftCc, (double)(ccNumber + 1) / 128.0, true);
    api.setPluginParameter(name, EParameters::RightCc, (double)(ccNumber + 2) / 128.0, true);
    api.setPluginParameter(name, EParameters::Channel, (double)(5 - 1) / 15.0, true);
    api.setPluginParameter(name, EParameters::MonoStereo, 1.0, true);
    api.setPluginParameter(name, EParameters::Rate, 0.66, true); // 1.8 ms
    api.setPluginParameter(name, EParameters::Inertia, 50 / 100.0, true);
    api.setPluginParameter(name, EParameters::Attack, 17 / 100.0, true);
    api.setPluginParameter(name, EParameters::Release, 27 / 100.0, true);
    api.setPluginParameter(name, EParameters::Device, 0, true);
    api.setPluginParameter(name, EParameters::MidiToHost, BoolUtilities::ToDouble(true), true);
    api.setPluginParameter(name, EParameters::AutomateHost, BoolUtilities::ToDouble(false), true);
    api.setPluginParameter(name, EParameters::GateTreshold, 1.0, true); // 0.0 dB
    api.setPluginParameter(name, EParameters::LeftGateCc, (ccNumber + 3) / 128.0, true);
    api.setPluginParameter(name, EParameters::RightGateCc, (ccNumber + 4) / 128.0, true);
    api.setPluginParameter(name, EParameters::LeftOnValue, (double)(127 + 1) / 128.0, true);
    api.setPluginParameter(name, EParameters::RightOnValue, (double)(127 + 1) / 128.0, true);
    api.setPluginParameter(name, EParameters::LeftOffValue, (double)(0 + 1) / 128.0, true);
    api.setPluginParameter(name, EParameters::RightOffValue, (double)(0 + 1) / 128.0, true);
}

#pragma warning( disable: 4100 )
void AudioToCcPlugin::Update(ChangedProperties::EChangedProperty changedProperty) /* override */
#pragma warning(default : 4100)
{
	// No subscriptions needed, however, maybe later to bypass unused channels
}
