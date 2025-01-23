#pragma once

#include "Threat.h"
#include <vector>
#include <iostream>
#include <string>

class ThreatView {
public:
    void displayThreat(const Threat& threat);
    void displayAllThreats(const std::vector<Threat>& threats);
    void listThreatsByLevel(const std::string& level);
    void displayMenu();
    void displayMessage(const std::string& message);
    void promptForInput(const std::string& prompt, std::string& input);
};


