#include <iostream>
#include <cassert>

class ClippingModesComponent {
public:
    enum class ClippingMode { Modern, Classic, Hard };

    ClippingModesComponent() : currentMode(ClippingMode::Modern) {}

    void setClippingMode(ClippingMode mode) {
        if (mode < ClippingMode::Modern || mode > ClippingMode::Hard) {
            std::cerr << "Invalid clipping mode selected." << std::endl;
            return;
        }

        if (mode == currentMode) {
            std::cout << "Already in the selected mode." << std::endl;
            return;
        }

        currentMode = mode;
        updateUIForMode(mode);
    }

    void updateUIForMode(ClippingMode mode) {
        switch (mode) {
            case ClippingMode::Modern:
                std::cout << "Switched to Modern mode." << std::endl;
                break;
            case ClippingMode::Classic:
                std::cout << "Switched to Classic mode." << std::endl;
                break;
            case ClippingMode::Hard:
                std::cout << "Switched to Hard mode." << std::endl;
                break;
        }
    }

    ClippingMode getCurrentMode() const {
        return currentMode;
    }

private:
    ClippingMode currentMode;
};

void testSetClippingMode() {
    ClippingModesComponent component;

    component.setClippingMode(ClippingModesComponent::ClippingMode::Classic);
    assert(component.getCurrentMode() == ClippingModesComponent::ClippingMode::Classic);

    component.setClippingMode(ClippingModesComponent::ClippingMode::Hard);
    assert(component.getCurrentMode() == ClippingModesComponent::ClippingMode::Hard);

    component.setClippingMode(ClippingModesComponent::ClippingMode::Modern);
}

void testInvalidClippingMode() {
    ClippingModesComponent component;
    component.setClippingMode(static_cast<ClippingModesComponent::ClippingMode>(-1)); // Invalid mode
    assert(component.getCurrentMode() == ClippingModesComponent::ClippingMode::Modern); // Should remain Modern
}

int main() {
    testSetClippingMode();
    testInvalidClippingMode();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
