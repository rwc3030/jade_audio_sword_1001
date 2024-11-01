#include <iostream>
#include "ClippingModesComponent.h"

class ClippingModesUIComponent {
public:
    ClippingModesUIComponent(ClippingModesComponent& component) : clippingComponent(component) {}

    void display() {
        std::cout << "Select Clipping Mode: " << std::endl;
        std::cout << "1. Modern" << std::endl;
        std::cout << "2. Classic" << std::endl;
        std::cout << "3. Hard" << std::endl;
    }

    void selectMode(int choice) {
        switch (choice) {
            case 1:
                clippingComponent.setClippingMode(ClippingModesComponent::ClippingMode::Modern);
                break;
            case 2:
                clippingComponent.setClippingMode(ClippingModesComponent::ClippingMode::Classic);
                break;
            case 3:
                clippingComponent.setClippingMode(ClippingModesComponent::ClippingMode::Hard);
                break;
            default:
                std::cerr << "Invalid selection." << std::endl;
                break;
        }
    }

private:
    ClippingModesComponent& clippingComponent;
};

int main() {
    ClippingModesComponent clippingComponent;
    ClippingModesUIComponent ui(clippingComponent);

    ui.display();
    int choice;
    std::cin >> choice;
    ui.selectMode(choice);

    return 0;
}
