#include "ClippingModesComponent.h"
#include <JuceHeader.h>

ClippingModesComponent::ClippingModesComponent()
{
    // Set up buttons for each clipping mode
    modernButton.setButtonText("Modern");
    classicButton.setButtonText("Classic");
    hardButton.setButtonText("Hard");

    // Add buttons to the component
    addAndMakeVisible(modernButton);
    addAndMakeVisible(classicButton);
    addAndMakeVisible(hardButton);

    // Set up button click listeners
    modernButton.onClick = [this] { setClippingMode(ClippingMode::Modern); };
    classicButton.onClick = [this] { setClippingMode(ClippingMode::Classic); };
    hardButton.onClick = [this] { setClippingMode(ClippingMode::Hard); };

    // Set default mode
    setClippingMode(ClippingMode::Modern);
}

void ClippingModesComponent::paint(Graphics& g)
{
    // Draw the background
    g.fillAll(Colours::black);
}

void ClippingModesComponent::resized()
{
    // Layout buttons
    auto area = getLocalBounds();
    auto buttonWidth = area.getWidth() / 3;

    modernButton.setBounds(area.removeFromLeft(buttonWidth));
    classicButton.setBounds(area.removeFromLeft(buttonWidth));
    hardButton.setBounds(area);
}

void ClippingModesComponent::setClippingMode(ClippingMode mode)
{
    currentMode = mode;

    // Update button colors based on the selected mode
    modernButton.setColour(TextButton::buttonColourId, (currentMode == ClippingMode::Modern) ? Colours::yellow : Colours::grey);
    classicButton.setColour(TextButton::buttonColourId, (currentMode == ClippingMode::Classic) ? Colours::yellow : Colours::grey);
    hardButton.setColour(TextButton::buttonColourId, (currentMode == ClippingMode::Hard) ? Colours::yellow : Colours::grey);
}

ClippingModesComponent::ClippingMode ClippingModesComponent::getCurrentMode() const
{
    return currentMode;
}
