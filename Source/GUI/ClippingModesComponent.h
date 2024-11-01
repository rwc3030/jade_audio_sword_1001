#ifndef CLIPPINGMODESCOMPONENT_H
#define CLIPPINGMODESCOMPONENT_H

#include <iostream>
#include <cassert>

class ClippingModesComponent {
public:
    enum class ClippingMode { Modern, Classic, Hard };

    ClippingModesComponent();
    void setClippingMode(ClippingMode mode);
    ClippingMode getCurrentMode() const;
    void updateUIForMode(ClippingMode mode); // Added method declaration

private:
    ClippingMode currentMode;
};

#endif // CLIPPINGMODESCOMPONENT_H
