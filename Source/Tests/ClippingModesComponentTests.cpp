#include <cassert>
#include "ClippingModesComponent.h"

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