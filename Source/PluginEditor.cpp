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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginProcessor.h"
#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
NewProjectAudioProcessorEditor::NewProjectAudioProcessorEditor (NewProjectAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]
	


    predelayslider.reset (new Slider ("predelay"));
    addAndMakeVisible (predelayslider.get());
    predelayslider->setRange (0, 200, 1);
    predelayslider->setSliderStyle (Slider::Rotary);
    predelayslider->setTextBoxStyle (Slider::TextBoxBelow, false, 50, 15);
    predelayslider->setColour (Slider::backgroundColourId, Colours::azure);
    predelayslider->setColour (Slider::trackColourId, Colours::red);
    predelayslider->setColour (Slider::rotarySliderFillColourId, Colours::red);
    predelayslider->setColour (Slider::textBoxTextColourId, Colours::grey);
    predelayslider->addListener (this);

    predelayslider->setBounds (112, 32, 96, 96);

    predelaylabel.reset (new Label ("prelay_label",
                                    TRANS("\n"
                                    "predelay/ms\n")));
    addAndMakeVisible (predelaylabel.get());
    predelaylabel->setFont (Font (15.0f, Font::plain).withTypefaceStyle ("Regular"));
    predelaylabel->setJustificationType (Justification::centred);
    predelaylabel->setEditable (false, false, false);
    predelaylabel->setColour (Label::textColourId, Colours::grey);
    predelaylabel->setColour (TextEditor::textColourId, Colours::black);
    predelaylabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    predelaylabel->setBounds (112, 8, 96, 16);

    wetlabel.reset (new Label ("wetlabel",
                                  TRANS("wet")));
    addAndMakeVisible (wetlabel.get());
    wetlabel->setFont (Font (15.0f, Font::plain).withTypefaceStyle ("Regular"));
    wetlabel->setJustificationType (Justification::centred);
    wetlabel->setEditable (false, false, false);
    wetlabel->setColour (Label::textColourId, Colours::grey);
    wetlabel->setColour (TextEditor::textColourId, Colours::black);
    wetlabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    wetlabel->setBounds (8, 8, 96, 16);

    wetslider.reset (new Slider ("wet/dry"));
    addAndMakeVisible (wetslider.get());
    wetslider->setTooltip (TRANS("\n"));
    wetslider->setRange (0, 5, 0.01);
    wetslider->setSliderStyle (Slider::Rotary);
    wetslider->setTextBoxStyle (Slider::TextBoxBelow, false, 50, 15);
    wetslider->setColour (Slider::backgroundColourId, Colour (0xff656529));
    wetslider->setColour (Slider::trackColourId, Colours::red);
    wetslider->setColour (Slider::rotarySliderFillColourId, Colours::red);
    wetslider->setColour (Slider::textBoxTextColourId, Colours::grey);
    wetslider->addListener (this);

    wetslider->setBounds (8, 32, 96, 96);

	rt60slider.reset (new Slider ("rt60"));
    addAndMakeVisible (rt60slider.get());
	rt60slider->setTooltip (TRANS("\n"));
	rt60slider->setRange (0, 15, 0.01);
	rt60slider->setSliderStyle (Slider::Rotary);
	rt60slider->setTextBoxStyle (Slider::TextBoxBelow, false, 50, 15);
	rt60slider->setColour (Slider::backgroundColourId, Colour (0xff656529));
	rt60slider->setColour (Slider::trackColourId, Colours::red);
	rt60slider->setColour (Slider::rotarySliderFillColourId, Colours::red);
	rt60slider->setColour (Slider::textBoxTextColourId, Colours::grey);
	rt60slider->addListener (this);

	rt60slider->setBounds (8, 160, 96, 96);

    diffusionslider.reset (new Slider ("diffusion"));
    addAndMakeVisible (diffusionslider.get());
    diffusionslider->setTooltip (TRANS("\n"));
    diffusionslider->setRange (0, 100, 1);
    diffusionslider->setSliderStyle (Slider::Rotary);
    diffusionslider->setTextBoxStyle (Slider::TextBoxBelow, false, 50, 15);
    diffusionslider->setColour (Slider::backgroundColourId, Colour (0xff656529));
    diffusionslider->setColour (Slider::trackColourId, Colours::red);
    diffusionslider->setColour (Slider::rotarySliderFillColourId, Colours::red);
    diffusionslider->setColour (Slider::textBoxTextColourId, Colours::grey);
    diffusionslider->addListener (this);

    diffusionslider->setBounds (112, 160, 96, 96);

	rt60label.reset (new Label ("rt60",
                                    TRANS("rt60")));
    addAndMakeVisible (rt60label.get());
	rt60label->setFont (Font (15.0f, Font::plain).withTypefaceStyle ("Regular"));
	rt60label->setJustificationType (Justification::centred);
	rt60label->setEditable (false, false, false);
	rt60label->setColour (Label::textColourId, Colours::grey);
	rt60label->setColour (TextEditor::textColourId, Colours::black);
	rt60label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

	rt60label->setBounds (8, 136, 96, 16);

    diffusionlabel.reset (new Label ("diffusion",
                                     TRANS("diffusion")));
    addAndMakeVisible (diffusionlabel.get());
    diffusionlabel->setFont (Font (15.0f, Font::plain).withTypefaceStyle ("Regular"));
    diffusionlabel->setJustificationType (Justification::centred);
    diffusionlabel->setEditable (false, false, false);
    diffusionlabel->setColour (Label::textColourId, Colours::grey);
    diffusionlabel->setColour (TextEditor::textColourId, Colours::black);
    diffusionlabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    diffusionlabel->setBounds (112, 136, 96, 16);

    dryslider.reset (new Slider ("decay"));
    addAndMakeVisible (dryslider.get());
    dryslider->setTooltip (TRANS("\n"));
    dryslider->setRange (0, 2, 0.01);
    dryslider->setSliderStyle (Slider::Rotary);
    dryslider->setTextBoxStyle (Slider::TextBoxBelow, false, 50, 15);
    dryslider->setColour (Slider::backgroundColourId, Colour (0xff656529));
    dryslider->setColour (Slider::trackColourId, Colours::red);
    dryslider->setColour (Slider::rotarySliderFillColourId, Colours::red);
    dryslider->setColour (Slider::textBoxTextColourId, Colours::grey);
    dryslider->addListener (this);

    dryslider->setBounds (16, 304, 96, 96);

    drylabel.reset (new Label ("dry",
                                 TRANS("dry")));
    addAndMakeVisible (drylabel.get());
    drylabel->setFont (Font (15.0f, Font::plain).withTypefaceStyle ("Regular"));
    drylabel->setJustificationType (Justification::centred);
    drylabel->setEditable (false, false, false);
    drylabel->setColour (Label::textColourId, Colours::grey);
    drylabel->setColour (TextEditor::textColourId, Colours::black);
    drylabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    drylabel->setBounds (8, 280, 96, 16);

    dampingslider.reset (new Slider ("damping"));
    addAndMakeVisible (dampingslider.get());
    dampingslider->setTooltip (TRANS("\n"));
    dampingslider->setRange (100, 20000, 100);
    dampingslider->setSliderStyle (Slider::Rotary);
    dampingslider->setTextBoxStyle (Slider::TextBoxBelow, false, 50, 15);
    dampingslider->setColour (Slider::backgroundColourId, Colour (0xff656529));
    dampingslider->setColour (Slider::trackColourId, Colours::red);
    dampingslider->setColour (Slider::rotarySliderFillColourId, Colours::red);
    dampingslider->setColour (Slider::textBoxTextColourId, Colours::grey);
    dampingslider->addListener (this);

    dampingslider->setBounds (120, 304, 96, 96);

    dampinglabel.reset (new Label ("highdamping",
                                   TRANS("lowpass/Hz\n")));
    addAndMakeVisible (dampinglabel.get());
    dampinglabel->setFont (Font (15.0f, Font::plain).withTypefaceStyle ("Regular"));
    dampinglabel->setJustificationType (Justification::centred);
    dampinglabel->setEditable (false, false, false);
    dampinglabel->setColour (Label::textColourId, Colours::grey);
    dampinglabel->setColour (TextEditor::textColourId, Colours::black);
    dampinglabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    dampinglabel->setBounds (120, 280, 96, 16);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

NewProjectAudioProcessorEditor::~NewProjectAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    predelayslider = nullptr;
    predelaylabel = nullptr;
    wetlabel = nullptr;
    wetslider = nullptr;
	rt60slider = nullptr;
    diffusionslider = nullptr;
	rt60label = nullptr;
    diffusionlabel = nullptr;
    dryslider = nullptr;
    drylabel = nullptr;
    dampingslider = nullptr;
    dampinglabel = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void NewProjectAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::azure);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void NewProjectAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void NewProjectAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == predelayslider.get())
    {
        //[UserSliderCode_predelayslider] -- add your slider handling code here..
        //[/UserSliderCode_predelayslider]
		processor.setParameterNotifyingHost(processor.kpredelay,predelayslider->getValue());
    }
    else if (sliderThatWasMoved == wetslider.get())
	{
		processor.setParameterNotifyingHost(processor.kwet,wetslider->getValue());
        //[UserSliderCode_wetdryslider] -- add your slider handling code here..
        //[/UserSliderCode_wetdryslider]
    }
    else if (sliderThatWasMoved == rt60slider.get())
	{
		processor.setParameterNotifyingHost(processor.krt60, rt60slider->getValue());
        //[UserSliderCode_roomsizeslider] -- add your slider handling code here..
        //[/UserSliderCode_roomsizeslider]
    }
    else if (sliderThatWasMoved == diffusionslider.get())
	{
		processor.setParameterNotifyingHost(processor.kdiffusion,diffusionslider->getValue());
        //[UserSliderCode_diffusionslider] -- add your slider handling code here..
        //[/UserSliderCode_diffusionslider]
    }
    else if (sliderThatWasMoved == dryslider.get())
	{
		processor.setParameterNotifyingHost(processor.kdry,dryslider->getValue());
        //[UserSliderCode_decayslider] -- add your slider handling code here..
        //[/UserSliderCode_decayslider]
    }
    else if (sliderThatWasMoved == dampingslider.get())
	{
		processor.setParameterNotifyingHost(processor.kdamping, dampingslider->getValue());
        //[UserSliderCode_dampingslider] -- add your slider handling code here..
        //[/UserSliderCode_dampingslider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="NewProjectAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor"
                 constructorParams="NewProjectAudioProcessorEditor&amp; p" variableInitialisers="NewProjectAudioProcessorEditor (&amp;p), processor (p)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.33"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="fff0ffff"/>
  <SLIDER name="predelay" id="57ac458cf7d6fc0b" memberName="predelayslider"
          virtualName="" explicitFocusOrder="0" pos="112 32 96 96" bkgcol="fff0ffff"
          trackcol="ffff0000" rotarysliderfill="ffff0000" textboxtext="ff808080"
          min="0.0" max="250.0" int="1.0" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="50" textBoxHeight="15" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="prelay_label" id="18ad7a2e562686e4" memberName="predelaylabel"
         virtualName="" explicitFocusOrder="0" pos="112 8 96 16" textCol="ff808080"
         edTextCol="ff000000" edBkgCol="0" labelText="&#10;predelay/ms&#10;"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
         italic="0" justification="36"/>
  <LABEL name="wetlabel" id="909b7071c45ba88f" memberName="wetlabel"
         virtualName="" explicitFocusOrder="0" pos="8 8 96 16" textCol="ff808080"
         edTextCol="ff000000" edBkgCol="0" labelText="wet/dry/%" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="wet" id="83d03f98628abe88" memberName="wetslider"
          virtualName="" explicitFocusOrder="0" pos="8 32 96 96" tooltip="&#10;"
          bkgcol="ff656529" trackcol="ffff0000" rotarysliderfill="ffff0000"
          textboxtext="ff808080" min="0.0" max="100.0" int="1.0" style="Rotary"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="50"
          textBoxHeight="15" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="rt60" id="bb8823daa1eeff75" memberName="rt60slider"
          virtualName="" explicitFocusOrder="0" pos="8 160 96 96" tooltip="&#10;"
          bkgcol="ff656529" trackcol="ffff0000" rotarysliderfill="ffff0000"
          textboxtext="ff808080" min="0.0" max="100.0" int="1.0" style="Rotary"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="50"
          textBoxHeight="15" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="diffusion" id="3d276de4070281ab" memberName="diffusionslider"
          virtualName="" explicitFocusOrder="0" pos="112 160 96 96" tooltip="&#10;"
          bkgcol="ff656529" trackcol="ffff0000" rotarysliderfill="ffff0000"
          textboxtext="ff808080" min="0.0" max="100.0" int="1.0" style="Rotary"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="50"
          textBoxHeight="15" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="rt60" id="afffcb5077926fc6" memberName="rt60label"
         virtualName="" explicitFocusOrder="0" pos="8 136 96 16" textCol="ff808080"
         edTextCol="ff000000" edBkgCol="0" labelText="roomsize" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="diffusion" id="82e5e34f3c35557c" memberName="diffusionlabel"
         virtualName="" explicitFocusOrder="0" pos="112 136 96 16" textCol="ff808080"
         edTextCol="ff000000" edBkgCol="0" labelText="diffusion" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="dry" id="eb8c1455614fcc84" memberName="dryslider" virtualName=""
          explicitFocusOrder="0" pos="16 304 96 96" tooltip="&#10;" bkgcol="ff656529"
          trackcol="ffff0000" rotarysliderfill="ffff0000" textboxtext="ff808080"
          min="0.0" max="20.0" int="1.0" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="50" textBoxHeight="15" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="dry" id="3d90b12a10673b80" memberName="drylabel" virtualName=""
         explicitFocusOrder="0" pos="8 280 96 16" textCol="ff808080" edTextCol="ff000000"
         edBkgCol="0" labelText="decay/sec" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="damping" id="24ed2afe7982447e" memberName="dampingslider"
          virtualName="" explicitFocusOrder="0" pos="120 304 96 96" tooltip="&#10;"
          bkgcol="ff656529" trackcol="ffff0000" rotarysliderfill="ffff0000"
          textboxtext="ff808080" min="5000.0" max="20000.0" int="100.0"
          style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="50" textBoxHeight="15" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="highdamping" id="2ad3cb640fe30a3d" memberName="dampinglabel"
         virtualName="" explicitFocusOrder="0" pos="120 280 96 16" textCol="ff808080"
         edTextCol="ff000000" edBkgCol="0" labelText="damping/Hz&#10;"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
         italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
