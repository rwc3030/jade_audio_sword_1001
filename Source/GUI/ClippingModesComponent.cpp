#include "ClippingModesComponent.h"
#include <iostream>

ClippingModesComponent::ClippingModesComponent() {
    currentMode = ClippingMode::Modern;
}

void ClippingModesComponent::setClippingMode(ClippingMode mode) {
    if (mode < ClippingMode::Modern || mode > ClippingMode::Hard) {
        std::cerr << "Invalid clipping mode selected." << std::endl;
        return;
    }

    if (mode == currentMode) {
        std::cout << "Already in the selected mode." << std::endl;
        return;
    }

    currentMode = mode;
    updateUIForMode(currentMode);
}

void ClippingModesComponent::updateUIForMode(ClippingMode mode) {
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

ClippingModesComponent::ClippingMode ClippingModesComponent::getCurrentMode() const {
    return currentMode;
}
