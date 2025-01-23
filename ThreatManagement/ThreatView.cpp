#include "ThreatView.h"

void ThreatView::displayThreat(const Threat& threat) {
    std::cout << "Threat ID: " << threat.getID() << "\nLevel: " << threat.getLevel() << "\nDescription: " << threat.getDescription() << "\nTimestamp: " << threat.getTimestamp() << "\n";
}

void ThreatView::displayAllThreats(const std::vector<Threat>& threats) {
    for (const auto& Threat : threats) {
        displayThreat(Threat);
    }
}



void ThreatView::displayMenu() {                          //output options
    std::cout << "\n--- Threat Management System ---\n";
    std::cout << "1. Add Threat\n";
    std::cout << "2. Update Threat Information\n";
    std::cout << "3. Display Threat\n";
    std::cout << "4. List All Threats by Level\n";
    std::cout << "5. Remove Threat\n";
    std::cout << "6. Load Threats From File\n";
    std::cout << "7. Save Threats to File\n";
    std::cout << "8. Exit\n";
}

void ThreatView::displayMessage(const std::string& message) {
    std::cout << message << std::endl;  //output message
}

void ThreatView::promptForInput(const std::string& prompt, std::string& input) {
    std::cout << prompt;
    std::getline(std::cin, input); //get user input
}

