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

private:
    void setClippingMode(ClippingMode mode);

    ClippingMode currentMode;

    juce::TextButton modernButton;
    juce::TextButton classicButton;
    juce::TextButton hardButton;
};

#endif // CLIPPINGMODESCOMPONENT_H
