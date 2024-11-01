#ifndef CLIPPINGMODESCOMPONENT_H
#define CLIPPINGMODESCOMPONENT_H

class ClippingModesComponent {
public:
    enum class ClippingMode {
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
};

#endif // CLIPPINGMODESCOMPONENT_H
