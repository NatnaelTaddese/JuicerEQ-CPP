/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class JuicerEQAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    JuicerEQAudioProcessorEditor (JuicerEQAudioProcessor&);
    ~JuicerEQAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    JuicerEQAudioProcessor& audioProcessor;
    juce::Slider midiVolume;
    juce::Slider outPutVolume;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (JuicerEQAudioProcessorEditor)
};
