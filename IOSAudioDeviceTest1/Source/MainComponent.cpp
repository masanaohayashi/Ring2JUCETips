/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 6.0.5

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "MainComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
#include <juce_audio_plugin_client/Standalone/juce_StandaloneFilterWindow.h>
//[/MiscUserDefs]

//==============================================================================
MainComponent::MainComponent ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    comboSampleRate.reset (new juce::ComboBox (juce::String()));
    addAndMakeVisible (comboSampleRate.get());
    comboSampleRate->setEditableText (false);
    comboSampleRate->setJustificationType (juce::Justification::centredLeft);
    comboSampleRate->setTextWhenNothingSelected (juce::String());
    comboSampleRate->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboSampleRate->addListener (this);

    comboSampleRate->setBounds (24, 48, 150, 24);

    labelSampleRate.reset (new juce::Label (juce::String(),
                                            TRANS("Sample Rate")));
    addAndMakeVisible (labelSampleRate.get());
    labelSampleRate->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    labelSampleRate->setJustificationType (juce::Justification::centredLeft);
    labelSampleRate->setEditable (false, false, false);
    labelSampleRate->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    labelSampleRate->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    labelSampleRate->setBounds (24, 24, 150, 24);

    labelBitDepthCaption.reset (new juce::Label (juce::String(),
                                                 TRANS("Bit Depth")));
    addAndMakeVisible (labelBitDepthCaption.get());
    labelBitDepthCaption->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    labelBitDepthCaption->setJustificationType (juce::Justification::centredLeft);
    labelBitDepthCaption->setEditable (false, false, false);
    labelBitDepthCaption->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    labelBitDepthCaption->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    labelBitDepthCaption->setBounds (192, 24, 150, 24);

    labelBufferSize.reset (new juce::Label (juce::String(),
                                            TRANS("Buffer Size")));
    addAndMakeVisible (labelBufferSize.get());
    labelBufferSize->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    labelBufferSize->setJustificationType (juce::Justification::centredLeft);
    labelBufferSize->setEditable (false, false, false);
    labelBufferSize->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    labelBufferSize->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    labelBufferSize->setBounds (360, 24, 150, 24);

    comboBufferSize.reset (new juce::ComboBox (juce::String()));
    addAndMakeVisible (comboBufferSize.get());
    comboBufferSize->setEditableText (false);
    comboBufferSize->setJustificationType (juce::Justification::centredLeft);
    comboBufferSize->setTextWhenNothingSelected (juce::String());
    comboBufferSize->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBufferSize->addListener (this);

    comboBufferSize->setBounds (360, 56, 150, 24);

    labelBitDepth.reset (new juce::Label (juce::String(),
                                          TRANS("(depth)")));
    addAndMakeVisible (labelBitDepth.get());
    labelBitDepth->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    labelBitDepth->setJustificationType (juce::Justification::centredLeft);
    labelBitDepth->setEditable (false, false, false);
    labelBitDepth->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    labelBitDepth->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    labelBitDepth->setBounds (192, 48, 150, 24);

    labelError.reset (new juce::Label (juce::String(),
                                       TRANS("(error message)")));
    addAndMakeVisible (labelError.get());
    labelError->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    labelError->setJustificationType (juce::Justification::centredLeft);
    labelError->setEditable (false, false, false);
    labelError->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    labelError->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    labelError->setBounds (24, 88, 488, 24);


    //[UserPreSize]
    juce::StandalonePluginHolder* holder = juce::StandalonePluginHolder::getInstance();
    if (holder != nullptr)
    {
        juce::AudioIODevice* device = holder->deviceManager.getCurrentAudioDevice();
        if (device != nullptr)
        {
            auto availableSampleRates = device->getAvailableSampleRates();
            auto currentSampleRate = device->getCurrentSampleRate();
            comboSampleRate->clear();
            for (int i = 0; i < availableSampleRates.size(); i++)
            {
                comboSampleRate->addItem(juce::String(availableSampleRates[i]), i + 1);
                if (availableSampleRates[i] == currentSampleRate)
                    comboSampleRate->setSelectedId(i + 1);
            }

            labelBitDepth->setText (juce::String(device->getCurrentBitDepth()), juce::dontSendNotification);

            auto availableBufferSizes = device->getAvailableBufferSizes();
            auto currentBufferSize = device->getCurrentBufferSizeSamples();
            comboBufferSize->clear();
            for (int i = 0; i < availableBufferSizes.size(); i++)
            {
                comboBufferSize->addItem(juce::String(availableBufferSizes[i]), i + 1);
                if (availableBufferSizes[i] == currentBufferSize)
                    comboBufferSize->setSelectedId(i + 1);
            }
        }
    }
    //[/UserPreSize]

    setSize (1024, 768);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

MainComponent::~MainComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    comboSampleRate = nullptr;
    labelSampleRate = nullptr;
    labelBitDepthCaption = nullptr;
    labelBufferSize = nullptr;
    comboBufferSize = nullptr;
    labelBitDepth = nullptr;
    labelError = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MainComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void MainComponent::comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == comboSampleRate.get())
    {
        //[UserComboBoxCode_comboSampleRate] -- add your combo box handling code here..
        juce::StandalonePluginHolder* holder = juce::StandalonePluginHolder::getInstance();
        if (holder != nullptr)
        {
            juce::AudioIODevice* device = holder->deviceManager.getCurrentAudioDevice();
            if (device != nullptr)
            {
                auto availableSampleRates = holder->deviceManager.getCurrentAudioDevice()->getAvailableSampleRates();
                auto value = comboBoxThatHasChanged->getSelectedId() - 1;
                if ((value >= 0) && (value < availableSampleRates.size()))
                {
                    juce::AudioDeviceManager::AudioDeviceSetup setup = holder->deviceManager.getAudioDeviceSetup();
                    setup.sampleRate = availableSampleRates[value];
                    auto error = holder->deviceManager.setAudioDeviceSetup(setup, true);
                    if (error.isNotEmpty())
                        labelError->setText (error, juce::dontSendNotification);
                }
            }
        }
        //[/UserComboBoxCode_comboSampleRate]
    }
    else if (comboBoxThatHasChanged == comboBufferSize.get())
    {
        //[UserComboBoxCode_comboBufferSize] -- add your combo box handling code here..
        juce::StandalonePluginHolder* holder = juce::StandalonePluginHolder::getInstance();
        if (holder != nullptr)
        {
            juce::AudioIODevice* device = holder->deviceManager.getCurrentAudioDevice();
            if (device != nullptr)
            {
                auto availableBufferSizes = holder->deviceManager.getCurrentAudioDevice()->getAvailableBufferSizes();
                auto value = comboBoxThatHasChanged->getSelectedId() - 1;
                if ((value >= 0) && (value < availableBufferSizes.size()))
                {
                    juce::AudioDeviceManager::AudioDeviceSetup setup = holder->deviceManager.getAudioDeviceSetup();
                    setup.bufferSize = availableBufferSizes[value];
                    auto error = holder->deviceManager.setAudioDeviceSetup(setup, true);
                    if (error.isNotEmpty())
                        labelError->setText (error, juce::dontSendNotification);
                }
            }
        }
        //[/UserComboBoxCode_comboBufferSize]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MainComponent" componentName=""
                 parentClasses="public juce::Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="1024" initialHeight="768">
  <BACKGROUND backgroundColour="ff323e44"/>
  <COMBOBOX name="" id="55cb80f1880cd399" memberName="comboSampleRate" virtualName=""
            explicitFocusOrder="0" pos="24 48 150 24" editable="0" layout="33"
            items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="" id="f1e859fc07edbb85" memberName="labelSampleRate" virtualName=""
         explicitFocusOrder="0" pos="24 24 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Sample Rate" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="" id="6ef42c9e2878c9b8" memberName="labelBitDepthCaption"
         virtualName="" explicitFocusOrder="0" pos="192 24 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Bit Depth" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="" id="d38bff9aad74e82" memberName="labelBufferSize" virtualName=""
         explicitFocusOrder="0" pos="360 24 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Buffer Size" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="" id="80bd3d17d31a5cc8" memberName="comboBufferSize" virtualName=""
            explicitFocusOrder="0" pos="360 56 150 24" editable="0" layout="33"
            items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="" id="d8e9aed5e99b3590" memberName="labelBitDepth" virtualName=""
         explicitFocusOrder="0" pos="192 48 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="(depth)" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="" id="1bedf469ba52c71f" memberName="labelError" virtualName=""
         explicitFocusOrder="0" pos="24 88 488 24" edTextCol="ff000000"
         edBkgCol="0" labelText="(error message)" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

