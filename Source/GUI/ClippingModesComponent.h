#ifndef CLIPPINGMODESCOMPONENT_H
#define CLIPPINGMODESCOMPONENT_H

#include <JuceHeader.h>

class ClippingModesComponent : public Component
{
public:
    enum ClippingMode
    {
        Modern,
        Classic,
        Hard
    };

    ClippingModesComponent();
    void setClippingMode(ClippingMode mode);
    ClippingMode getCurrentMode() const;

private:
    void updateUIForMode(ClippingMode mode);

    ClippingMode currentMode;
    TextButton modernButton;
    TextButton classicButton;
    TextButton hardButton;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ClippingModesComponent)
};

#endif // CLIPPINGMODESCOMPONENT_H
