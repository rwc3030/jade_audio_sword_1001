#ifndef CLIPPINGMODESCOMPONENT_H
#define CLIPPINGMODESCOMPONENT_H

#include <iostream>

class ClippingModesComponent {
public:
    enum class ClippingMode {
        Modern,
        Classic,
        Hard
    };

    ClippingModesComponent();
    void setClippingMode(ClippingMode mode);
    void updateUIForMode(ClippingMode mode);
    ClippingMode getCurrentMode() const;

private:
    ClippingMode currentMode;
};

#endif // CLIPPINGMODESCOMPONENT_H
