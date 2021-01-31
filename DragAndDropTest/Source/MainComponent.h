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

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <JuceHeader.h>
#include "DragAndDropTestAudioProcessor.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class MainComponent  : public juce::AudioProcessorEditor,
                       public juce::DragAndDropContainer
{
public:
    //==============================================================================
    MainComponent (DragAndDropTestAudioProcessor& p);
    ~MainComponent() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //==============================================================================
    class ListBoxModelOne : public juce::ListBoxModel
    {
    public:
        ListBoxModelOne (DragAndDropTestAudioProcessor& p);
        int getNumRows() override;
        void paintListBoxItem (int rowNumber, juce::Graphics& g,
                               int width, int height, bool rowIsSelected) override;
        //juce::var getDragSourceDescription (const juce::SparseSet<int>& selectedRows) override;
        DragAndDropTestAudioProcessor& processor;
    };

    //==============================================================================
    class ListBoxModelTwo : public juce::ListBoxModel
    {
    public:
        ListBoxModelTwo (DragAndDropTestAudioProcessor& p);
        int getNumRows() override;
        void paintListBoxItem (int rowNumber, juce::Graphics& g,
                               int width, int height, bool rowIsSelected) override;
        juce::var getDragSourceDescription (const juce::SparseSet<int>& selectedRows) override;
        DragAndDropTestAudioProcessor& processor;
    };

    //==============================================================================
    class ListBoxOne : public juce::ListBox, public juce::DragAndDropTarget
    {
    public:
        ListBoxOne (juce::ListBoxModel* model = nullptr)
        : juce::ListBox(juce::String(), model) {}
        bool isInterestedInDragSource (const SourceDetails &dragSourceDetails) override;
        void itemDragEnter (const SourceDetails &dragSourceDetails) override;
        void itemDragMove (const SourceDetails &dragSourceDetails) override;
        void itemDragExit (const SourceDetails &dragSourceDetails) override;
        void itemDropped (const SourceDetails &dragSourceDetails) override;
    };

    //==============================================================================
    DragAndDropTestAudioProcessor& processor;
    ListBoxModelOne listBoxModelOne;
    ListBoxModelTwo listBoxModelTwo;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<ListBoxOne> listBoxOne;
    std::unique_ptr<juce::ListBox> listBoxTwo;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

