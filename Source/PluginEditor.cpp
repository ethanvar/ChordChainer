/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
using namespace std;
#define LOG(x) std::cout << x << std::endl;

//==============================================================================
ChordVstAudioProcessorEditor::ChordVstAudioProcessorEditor (ChordVstAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    gainSlider.setSliderStyle (juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    gainSlider.setTextBoxStyle (juce::Slider::TextBoxBelow, false, 100, 20);
    addAndMakeVisible (gainSlider);

    gainSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment> (audioProcessor.apvts, "GAIN", gainSlider);
    setSize (800, 600);
    centreWithSize (getWidth(), getHeight());
    setVisible (true);
    // centreWithSize (getWidth(), getHeight());
    // LOG (getHeight());
    // setVisible (true);
}

ChordVstAudioProcessorEditor::~ChordVstAudioProcessorEditor()
{

}

//==============================================================================
void ChordVstAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (juce::Colours::black);
    g.setColour (juce::Colours::white);
    g.setFont (juce::FontOptions (15.0f));
    // g.drawFittedText ("Chord Chainer", getLocalBounds(), juce::Justification::centred, 1);
    // setSize (1024, 768);
}

void ChordVstAudioProcessorEditor::resized()
{
  gainSlider.setBounds (getWidth()/2-100, getHeight()/2-50, 200, 100);
  // cout << "W: " << getWidth() << " H: " << getHeight() << endl;
}
