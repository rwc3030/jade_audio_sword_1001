#ifndef CLIPPINGMODESCOMPONENT_H
#define CLIPPINGMODESCOMPONENT_H

#include <JuceHeader.h>

class ClippingModesComponent : public Component {
public:
    enum ClippingMode { Modern, Classic, Hard };

    ClippingModesComponent();
    void paint(Graphics& g) override;
    void resized() override;

    void setClippingMode(ClippingMode mode);
    ClippingMode getCurrentMode() const;

private:
    void updateUIForMode(ClippingMode mode);
    void cleanupResources(); // New method to clean up resources

    ClippingMode currentMode;
    TextButton modernButton, classicButton, hardButton;
};

#endif // CLIPPINGMODESCOMPONENT_H
