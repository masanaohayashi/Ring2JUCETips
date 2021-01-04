/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "MainComponent.h"

//==============================================================================
/**
*/
class IOSAudioDeviceTest1AudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    IOSAudioDeviceTest1AudioProcessorEditor (IOSAudioDeviceTest1AudioProcessor&);
    ~IOSAudioDeviceTest1AudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    IOSAudioDeviceTest1AudioProcessor& audioProcessor;
    std::unique_ptr<MainComponent> mainComponent;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (IOSAudioDeviceTest1AudioProcessorEditor)
};
