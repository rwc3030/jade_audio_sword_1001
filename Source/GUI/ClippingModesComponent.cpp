#include "ClippingModesComponent.h"

ClippingModesComponent::ClippingModesComponent() {
    currentMode = Modern; // Default mode
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

void ClippingModesComponent::setClippingMode(ClippingMode mode) {
    if (mode < Modern || mode > Hard) {
        DBG("Invalid clipping mode selected.");
        return;
    }
    currentMode = mode;
    updateUIForMode(mode);
}

void ClippingModesComponent::updateUIForMode(ClippingMode mode) {
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
    // Additional UI feedback can be added here
}

ClippingModesComponent::ClippingMode ClippingModesComponent::getCurrentMode() const {
    return currentMode;
}
