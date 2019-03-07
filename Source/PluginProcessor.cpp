/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
NewProjectAudioProcessor::NewProjectAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
	schro.setBypass(false);
	f.setup(fs, 100);
	predelay = 0.0f;
	wet = 0.0f;
	rt60 = 0.0f; 
	diffusion = 0.0f;
	dry = 0.0f;
	damping=5000.0f;


}

NewProjectAudioProcessor::~NewProjectAudioProcessor()
{
}

//==============================================================================
const String NewProjectAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool NewProjectAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool NewProjectAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool NewProjectAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double NewProjectAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int NewProjectAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int NewProjectAudioProcessor::getCurrentProgram()
{
    return 0;
}

void NewProjectAudioProcessor::setCurrentProgram (int index)
{
}

const String NewProjectAudioProcessor::getProgramName (int index)
{
    return {};
}

void NewProjectAudioProcessor::changeProgramName (int index, const String& newName)
{
}





int NewProjectAudioProcessor::getNumParameters() {
	return numparaneters;


}
float NewProjectAudioProcessor::getParameter(int index) {

	switch (index)
	{
	case kpredelay: return predelay;
	case kwet: return wet;
	case krt60: return rt60;
	case kdiffusion: return diffusion;
	case kdry: return dry;
	case kdamping: return damping;
		
	default:
		break;
	}


}
void NewProjectAudioProcessor::setParameter(int index, float newValue) {

	switch (index)
	{
	case kpredelay: 
		predelay=newValue;
		break;
	case kwet: 
		wet=newValue;
		break;
	case krt60:
		rt60 =newValue;
		schro.setDecayFactor(rt60);
		break;
	case kdiffusion: 
		diffusion=newValue;
		break;
	case kdry: 
		dry=newValue;
		break;
	case kdamping: 
		damping=newValue;
		f.setup(fs, damping);
		break;
	default:
		break;
	}



}






//==============================================================================
void NewProjectAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void NewProjectAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool NewProjectAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void NewProjectAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
	
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();
	int numsamples = buffer.getNumSamples();
    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    // Make sure to reset the state if your inner loop is processing
    // the samples and the outer loop is handling the channels.
    // Alternatively, you can process the samples with the channels
    // interleaved by keeping the same state.


	float* channelDataLeft = buffer.getWritePointer(0);  //buffer.getSampleData(0);
	float* channelDataRight = buffer.getWritePointer(1);

	float outL = 0.0f, outR = 0.0f;

	//stereo interleaved so process left and right
	//then step through in increments of 2
	for (int i = 0; i < numsamples; i += 2) {
		float in = f.filter(channelDataLeft[i]), in_1 =f.filter(channelDataRight[i + 1]);
		//seperate left and right processing
		outL = wet * schro.next(in) + dry * in;
		outR = wet * schro.next(in_1) + dry * in_1;

		channelDataLeft[i] = outL;

		//MONO-IN, Stereo Out
		if (getNumInputChannels() == 1 && getNumOutputChannels() == 2) {
			channelDataRight[i + 1] = channelDataLeft[i]; //copy mono
		}

		//Stereo In , Stereo Out
		if (getNumInputChannels() == 2 && getNumOutputChannels() == 2) {
			channelDataRight[i + 1] = outR;
		}

	}


	
  /*  for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
		
		auto* channelData = buffer.getWritePointer (channel);


		for ( int i = 0; i < numsamples; ++i)
		{
			float in = channelData[i];
			float out=  (1-wet)*in+wet*schro.next(in);
			channelData[i] = out;
		}*/
         //..do something to the data...
    
}

//==============================================================================
bool NewProjectAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* NewProjectAudioProcessor::createEditor()
{
    return new NewProjectAudioProcessorEditor (*this);
}

//==============================================================================
void NewProjectAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void NewProjectAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new NewProjectAudioProcessor();
}
