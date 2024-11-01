#include <iostream>
#include <cassert>
#include "ClippingModesComponent.cpp"

void testSetClippingMode(ClippingModesComponent::ClippingMode mode) {
    ClippingModesComponent component;
    component.setClippingMode(mode);
    assert(component.getCurrentMode() == mode);
}

void testInvalidClippingMode() {
    ClippingModesComponent component;
    component.setClippingMode(static_cast<ClippingModesComponent::ClippingMode>(-1)); // Invalid mode
    assert(component.getCurrentMode() == ClippingModesComponent::ClippingMode::Modern); // Should remain Modern
}

void testRapidModeSwitching() {
    ClippingModesComponent component;
    component.setClippingMode(ClippingModesComponent::ClippingMode::Classic);
    component.setClippingMode(ClippingModesComponent::ClippingMode::Hard);
    assert(component.getCurrentMode() == ClippingModesComponent::ClippingMode::Hard);
}

void testEdgeCaseModeSwitching() {
    ClippingModesComponent component;
    component.setClippingMode(ClippingModesComponent::ClippingMode::Modern);
    component.setClippingMode(static_cast<ClippingModesComponent::ClippingMode>(-1)); // Invalid mode
    assert(component.getCurrentMode() == ClippingModesComponent::ClippingMode::Modern); // Should remain Modern
}

int main() {
    testSetClippingMode(ClippingModesComponent::ClippingMode::Classic);
    testSetClippingMode(ClippingModesComponent::ClippingMode::Hard);
    testSetClippingMode(ClippingModesComponent::ClippingMode::Modern);
    testInvalidClippingMode();
    testRapidModeSwitching();
    testEdgeCaseModeSwitching();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
