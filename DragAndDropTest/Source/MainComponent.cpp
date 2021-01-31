/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 6.0.7

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "MainComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MainComponent::MainComponent (DragAndDropTestAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p), listBoxModelOne (p), listBoxModelTwo (p)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    listBoxOne.reset (new ListBoxOne (&listBoxModelOne));
    addAndMakeVisible (listBoxOne.get());

    listBoxTwo.reset (new juce::ListBox (juce::String(), &listBoxModelTwo));
    addAndMakeVisible (listBoxTwo.get());


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //listBoxTwo->setMultipleSelectionEnabled (true);
    listBoxOne->updateContent();
    listBoxTwo->updateContent();
    //[/Constructor]
}

MainComponent::~MainComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    listBoxOne = nullptr;
    listBoxTwo = nullptr;


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
    std::cout << "MainComponent::resized() width: " + juce::String(getWidth()) + " Height: " + juce::String(getHeight()) + "\n";
    //[/UserPreResize]

    listBoxOne->setBounds (16, 16, proportionOfWidth (0.4667f), getHeight() - 32);
    listBoxTwo->setBounds (getWidth() - 16 - proportionOfWidth (0.4667f), 16, proportionOfWidth (0.4667f), getHeight() - 32);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//==============================================================================
MainComponent::ListBoxModelOne::ListBoxModelOne (DragAndDropTestAudioProcessor& p)
: processor (p)
{

}

int MainComponent::ListBoxModelOne::getNumRows()
{
    return processor.getNumPrograms();
}

void MainComponent::ListBoxModelOne::paintListBoxItem (int rowNumber, juce::Graphics& g,
                                                       int width, int height, bool rowIsSelected)
{
    if (rowIsSelected)
        g.fillAll (juce::Colours::lightblue);

    g.setColour (juce::LookAndFeel::getDefaultLookAndFeel().findColour (juce::Label::textColourId));
    g.setFont ((float) height * 0.7f);

    juce::String name = processor.getProgramName(rowNumber);
    g.drawText (name,
                5, 0, width, height,
                juce::Justification::centredLeft, true);
}

/*
juce::var MainComponent::ListBoxModelOne::getDragSourceDescription (const juce::SparseSet<int>& selectedRows)
{
    // for our drag description, we'll just make a comma-separated list of the selected row
    // numbers - this will be picked up by the drag target and displayed in its box.
    juce::StringArray rows;

    for (int i = 0; i < selectedRows.size(); ++i)
        rows.add (juce::String (selectedRows[i] + 1));

    return rows.joinIntoString (", ");
}
 */

//==============================================================================
MainComponent::ListBoxModelTwo::ListBoxModelTwo (DragAndDropTestAudioProcessor& p)
: processor (p)
{
}

int MainComponent::ListBoxModelTwo::getNumRows()
{
    return processor.getNumFiles();
}

void MainComponent::ListBoxModelTwo::paintListBoxItem (int rowNumber, juce::Graphics& g,
                                                       int width, int height, bool rowIsSelected)
{
    if (rowIsSelected)
        g.fillAll (juce::Colours::lightblue);

    g.setColour (juce::LookAndFeel::getDefaultLookAndFeel().findColour (juce::Label::textColourId));
    g.setFont ((float) height * 0.7f);

    juce::String name = processor.getFile(rowNumber).getFileName();
    g.drawText (name,
                5, 0, width, height,
                juce::Justification::centredLeft, true);
}

juce::var MainComponent::ListBoxModelTwo::getDragSourceDescription (const juce::SparseSet<int>& selectedRows)
{
    // for our drag description, we'll just make a comma-separated list of the selected row
    // numbers - this will be picked up by the drag target and displayed in its box.
    juce::StringArray rows;

    for (int i = 0; i < selectedRows.size(); ++i)
        rows.add (juce::String (selectedRows[i] + 1));

    juce::File file = processor.getFile(selectedRows[0]);

    //return rows.joinIntoString (", ");
    return file.getFullPathName();
}

//==============================================================================
bool MainComponent::ListBoxOne::isInterestedInDragSource (const SourceDetails &dragSourceDetails)
{
    return true;
}

void MainComponent::ListBoxOne::itemDragEnter (const SourceDetails &dragSourceDetails)
{
    int row = getRowContainingPosition(dragSourceDetails.localPosition.getX(), dragSourceDetails.localPosition.getY());
    std::cout << "Row = " + juce::String(row) + "\n";
}

void MainComponent::ListBoxOne::itemDragMove (const SourceDetails &dragSourceDetails)
{
    int row = getRowContainingPosition(dragSourceDetails.localPosition.getX(), dragSourceDetails.localPosition.getY());
    std::cout << "Row = " + juce::String(row) + "\n";
}

void MainComponent::ListBoxOne::itemDragExit (const SourceDetails &dragSourceDetails)
{
    int row = getRowContainingPosition(dragSourceDetails.localPosition.getX(), dragSourceDetails.localPosition.getY());
    std::cout << "Row = " + juce::String(row) + "\n";
}

void MainComponent::ListBoxOne::itemDropped (const SourceDetails &dragSourceDetails)
{
    int row = getRowContainingPosition(dragSourceDetails.localPosition.getX(), dragSourceDetails.localPosition.getY());
    std::cout << "Row = " + juce::String(row) + "\n";

    juce::String name = dragSourceDetails.description.toString();
    ((ListBoxModelOne*)getModel())->processor.changeProgramName(row, name);
    updateContent();
    repaint();
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MainComponent" componentName=""
                 parentClasses="public juce::AudioProcessorEditor, public juce::DragAndDropContainer"
                 constructorParams="DragAndDropTestAudioProcessor&amp; p" variableInitialisers="AudioProcessorEditor (&amp;p), processor (p), listBoxModelOne (p), listBoxModelTwo (p)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44"/>
  <GENERICCOMPONENT name="" id="cd24d3cd0af2071c" memberName="listBoxOne" virtualName=""
                    explicitFocusOrder="0" pos="16 16 46.667% 32M" class="ListBoxOne"
                    params="&amp;listBoxModelOne"/>
  <GENERICCOMPONENT name="" id="35f4392bfd2b8621" memberName="listBoxTwo" virtualName=""
                    explicitFocusOrder="0" pos="16Rr 16 46.667% 32M" class="juce::ListBox"
                    params="juce::String(), &amp;listBoxModelTwo"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

