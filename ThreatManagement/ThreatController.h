#pragma once

#include "Threat.h"
#include "ThreatView.h"
#include <vector>
#include <algorithm> 
#include <string>
#include <ctime>
#include <chrono>
#include <fstream>
#include <cstring>

class ThreatController {
private:
    std::vector<Threat> threats;
    ThreatView view;

public:
    void addThreat(const std::string& id, const std::string& level, const std::string& description, const std::string& timestamp);
    void updateThreat(const std::string& id, const std::string& level, const std::string& description);
    void removeThreat(const std::string& id);
    void displayThreat(const std::string& id);
    void listThreats();
    void saveThreatsToFile(const std::string& filename);
    void loadThreatsFromFile(const std::string& filename);
    void runProgram();
};

