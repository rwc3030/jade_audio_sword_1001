#include "ClippingModesComponent.h"

ClippingModesComponent::ClippingModesComponent() {
    // Initialize default mode
    currentMode = ClippingMode::Modern;
}

void ClippingModesComponent::setClippingMode(ClippingMode mode) {
    if (mode < ClippingMode::Modern || mode > ClippingMode::Hard) {
        // Handle invalid mode selection
        std::cerr << "Invalid clipping mode selected." << std::endl;
        return;
    }
    
    // Validate input parameters
    if (mode == currentMode) {
        std::cout << "Already in the selected mode." << std::endl;
        return;
    }

    currentMode = mode;
    updateUIForMode(mode);
}

void ClippingModesComponent::updateUIForMode(ClippingMode mode) {
    // Provide visual feedback for mode change
    switch (mode) {
        case ClippingMode::Modern:
            // Update UI for Modern mode
            std::cout << "Switched to Modern mode." << std::endl;
            break;
        case ClippingMode::Classic:
            // Update UI for Classic mode
            std::cout << "Switched to Classic mode." << std::endl;
            break;
        case ClippingMode::Hard:
            // Update UI for Hard mode
            std::cout << "Switched to Hard mode." << std::endl;
            break;
    }
}

ClippingModesComponent::ClippingMode ClippingModesComponent::getCurrentMode() const {
    return currentMode;
}
