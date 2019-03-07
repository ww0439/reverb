/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.4.1

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include"PluginProcessor.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class NewProjectAudioProcessorEditor  : public AudioProcessorEditor,
                                        public Slider::Listener
{
public:
    //==============================================================================
    NewProjectAudioProcessorEditor (NewProjectAudioProcessor& p);
    ~NewProjectAudioProcessorEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
	NewProjectAudioProcessor& processor;
    std::unique_ptr<Slider> predelayslider;
    std::unique_ptr<Label> predelaylabel;
    std::unique_ptr<Label> wetlabel;
    std::unique_ptr<Slider> wetslider;
    std::unique_ptr<Slider> rt60slider;
    std::unique_ptr<Slider> diffusionslider;
    std::unique_ptr<Label> rt60label;
    std::unique_ptr<Label> diffusionlabel;
    std::unique_ptr<Slider> dryslider;
    std::unique_ptr<Label> drylabel;
    std::unique_ptr<Slider> dampingslider;
    std::unique_ptr<Label> dampinglabel;
	

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NewProjectAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
