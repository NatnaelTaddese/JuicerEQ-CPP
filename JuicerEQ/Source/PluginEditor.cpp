/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
JuicerEQAudioProcessorEditor::JuicerEQAudioProcessorEditor (JuicerEQAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (500, 300);

    // these define the parameters of our slider object
    midiVolume.setSliderStyle(juce::Slider::LinearBarVertical);
    midiVolume.setRange(0.0, 127.0, 1.0);
    midiVolume.setTextBoxStyle(juce::Slider::NoTextBox, false, 90, 0);
    midiVolume.setPopupDisplayEnabled(true, false, this);
    midiVolume.setTextValueSuffix(" Volume");
    midiVolume.setValue(1.0);

    outPutVolume.setSliderStyle(juce::Slider::LinearHorizontal);
    outPutVolume.setRange(0.0, 127.0, 1.0);
    outPutVolume.setTextBoxStyle(juce::Slider::NoTextBox, false, 90, 0);
    outPutVolume.setPopupDisplayEnabled(true, false, this);
    outPutVolume.setValue(1.0);
    outPutVolume.setTextValueSuffix("Out Put");


    // this function adds the slider to the editor
    addAndMakeVisible(&midiVolume);
}

JuicerEQAudioProcessorEditor::~JuicerEQAudioProcessorEditor()
{
}

//==============================================================================
void JuicerEQAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::red);
    g.setFont (19.0f);
    g.drawFittedText ("JuicerEQ!", getLocalBounds(), juce::Justification::centred, 1);
}

void JuicerEQAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..

    // sets the position and size of the slider with arguments (x, y, width, height)
    midiVolume.setBounds(40, 30, 20, getHeight() - 60);
}
