#ifndef CLIPPINGMODESCOMPONENT_H
#define CLIPPINGMODESCOMPONENT_H

#include <JuceHeader.h>

class ClippingModesComponent : public juce::Component
{
public:
    ClippingModesComponent();

    void paint(juce::Graphics& g) override;
    void resized() override;

    enum class ClippingMode { Modern, Classic, Hard };

    ClippingMode getCurrentMode() const;
    void setClippingMode(ClippingMode mode); // Added function declaration

private:
    void updateUIForMode(ClippingMode mode); // Added function declaration

    ClippingMode currentMode;

    juce::TextButton modernButton;
    juce::TextButton classicButton;
    juce::TextButton hardButton;
};

#endif // CLIPPINGMODESCOMPONENT_H
