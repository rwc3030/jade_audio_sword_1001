#include "ClippingModesComponent.h"

ClippingModesComponent::ClippingModesComponent() {
    // Initialization code
    currentMode = Modern; // Default mode
    // Create UI controls for clipping modes
    addAndMakeVisible(modernButton);
    addAndMakeVisible(classicButton);
    addAndMakeVisible(hardButton);

    modernButton.setButtonText("Modern");
    classicButton.setButtonText("Classic");
    hardButton.setButtonText("Hard");

    modernButton.onClick = [this] { setClippingMode(Modern); };
    classicButton.onClick = [this] { setClippingMode(Classic); };
    hardButton.onClick = [this] { setClippingMode(Hard); };
}

void ClippingModesComponent::paint(Graphics& g) {
    // Painting code
    g.fillAll(Colours::black);
}

void ClippingModesComponent::resized() {
    // Resizing code
    auto area = getLocalBounds();
    auto buttonHeight = 30;
    modernButton.setBounds(area.removeFromTop(buttonHeight));
    classicButton.setBounds(area.removeFromTop(buttonHeight));
    hardButton.setBounds(area.removeFromTop(buttonHeight));
}

void ClippingModesComponent::setClippingMode(ClippingMode mode) {
    if (mode < Modern || mode > Hard) {
        // Handle invalid mode selection
        DBG("Invalid clipping mode selected.");
        return;
    }
    currentMode = mode;
    updateUIForMode(mode);
}

ClippingModesComponent::ClippingMode ClippingModesComponent::getCurrentMode() const {
    return currentMode;
}

void ClippingModesComponent::updateUIForMode(ClippingMode mode) {
    // Provide visual feedback for the selected mode
    switch (mode) {
        case Modern:
            modernButton.setColour(TextButton::buttonColourId, Colours::blue);
            classicButton.setColour(TextButton::buttonColourId, Colours::grey);
            hardButton.setColour(TextButton::buttonColourId, Colours::grey);
            break;
        case Classic:
            modernButton.setColour(TextButton::buttonColourId, Colours::grey);
            classicButton.setColour(TextButton::buttonColourId, Colours::blue);
            hardButton.setColour(TextButton::buttonColourId, Colours::grey);
            break;
        case Hard:
            modernButton.setColour(TextButton::buttonColourId, Colours::grey);
            classicButton.setColour(TextButton::buttonColourId, Colours::grey);
            hardButton.setColour(TextButton::buttonColourId, Colours::blue);
            break;
    }
}
