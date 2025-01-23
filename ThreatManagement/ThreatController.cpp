// ThreatController.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "ThreatController.h"

void ThreatController::addThreat(const std::string& id, const std::string& level, const std::string& description, const std::string& timestamp) {
    for (const Threat& threat : threats) {
        if (threat.getID() == id) {
            view.displayMessage("Threat " + id + " already exists.");                       //display already exists msg
            return;
        }
    }
    try
    {
        threats.push_back(Threat(id, level, description, timestamp));
        view.displayMessage("Threat " + id + " added.");
    }
    catch (const std::exception& e) {
        view.displayMessage(e.what());
    }
}

void ThreatController::updateThreat(const std::string& id, const std::string& newLevel, const std::string& newDescription) {
    for (Threat& threat : threats) {
        if (threat.getID() == id) {
            try {
                threat.setLevel(newLevel);
                threat.setDescription(newDescription);
                view.displayMessage("Updated " + id + "'s role to " + newLevel + ".");         //output successful update message
                view.displayMessage("Updated " + id + "'s role to " + newDescription + ".");
                return;
            }
            catch (const std::exception& e) {
                view.displayMessage(e.what());
            }
        }
    }
    view.displayMessage("Threat " + id + " not found.");                                    //output not found message
}



void ThreatController::removeThreat(const std::string& id) {                                  //remove user function

    bool removed = false;
    for (int i = 0; i < threats.size(); i++) {
        if (threats.at(i).getID() == id) {
            threats.erase(threats.begin() + i);
            view.displayMessage("Threat " + id + " removed.");                              //removed user msg
            removed = true;
            break;
        }
    }
    if (!removed) {
        view.displayMessage("Threat " + id + " not found.");                                //user nf msg
    }
}
void ThreatController::displayThreat(const std::string &id){
    for (const Threat& threat : threats){
        if (threat.getID() == id){
            view.displayThreat(threat);
            return;
        }
        
    }
    view.displayMessage("Threat " + id + "not found!");
}

void ThreatController::listThreats(){
    if (threats.empty()){
        view.displayMessage("No Threats Found!");
        return;
    }
    view.displayAllThreats(threats);
}

void ThreatController::saveThreatsToFile(const std::string& filename) {
    std::ofstream FILE(filename, std::ios::app);
    if (!FILE){
        std::cerr << "CANT OPEN!\n";
        return;
    }
    for (const Threat& threat : threats){
        std::string line = threat.getID() + '|' + threat.getLevel() + '|' + threat.getDescription() + '|' + threat.getTimestamp() + "\n";
        FILE << line;
    }
    if (FILE.fail()) {
        std::cerr << "Error occurred while writing to file\n";
        
    }
    else {
        std::cout << "THREATS SAVED!\n" << std::endl;
    }
    FILE.close();
    FILE.flush();
}

void ThreatController::loadThreatsFromFile(const std::string& filename) {
    /*
    std::ifstream FILE(filename);
    if (FILE){
        std::string lines;
        while (getline(FILE, lines));
    }
    FILE.close();
    std::string line;
    std::string tempThreat[4];;
    std::stringstream ss(line);
    std::string temp;
    int itr = 0;
    while (getline(ss, temp, '|')){
        itr+= 1;
        std::cout << temp << std::endl;
        tempThreat[itr] = temp;
    }
    addThreat(tempThreat[0], tempThreat[1], tempThreat[2], tempThreat[3]);
    */
    std::cout << "THREATS READ!\n" << std::endl;
}

void ThreatController::runProgram(){
    char choice;
    do {
        std::string userInput;
        view.displayMenu();                                                                 //display menu
        view.promptForInput("Enter Choice: ", userInput);                                  //prompt choice input
        
        choice = userInput[0];                                                              //assign choice to first char of usrinp
        
        switch (choice) {   // select case based on user input
            case '1': {
                std::string id, level, description, timestamp, choice;
                
                
                view.promptForInput("Enter ID: ", id);
                view.promptForInput("Enter Level: ", level);
                view.promptForInput("Enter Description: ", description);
                view.displayMessage("Enter Timestamp manually (0) OR use current time (1)");
                view.promptForInput("(0)/(1)?: ", choice);
                if (choice == "0"){
                    view.promptForInput("Enter Timestamp IN UTC!!! ( Format: \"[YYYY]-[mm]-[dd]T[hh]:[mm]:[ss]Z\"): ", timestamp);
                }
                else if (choice == "1"){
                    auto now = std::chrono::system_clock::now();
                        // Convert to time_t, which represents epoch time in seconds
                    time_t current_epoch = std::chrono::system_clock::to_time_t(now);
                    std::tm* utc_time = std::gmtime(&current_epoch);
                    
                       // Format the UTC time as a readable string
                    // Use ostringstream to format the time as a string
                     std::ostringstream timestamp_stream;
                     timestamp_stream << std::put_time(utc_time, "%Y-%m-%dT%H:%M:%SZ");
                     timestamp = timestamp_stream.str();
                }
                else {
                    std::cout << "invalid SELECTION!!!\n";
                }
                addThreat(id, level, description, timestamp);                                                            //call add user function
                break;
            }
            case '2': {
                std::string id, newLevel, newDescription;
                view.promptForInput("Enter ID of Threat to update: ", id);
                view.promptForInput("Enter new Level: ", newLevel);
                view.promptForInput("Enter new Description: ", newDescription);
                updateThreat(id, newLevel, newDescription);                                                  //call update user function
                break;
            }
            case '3': {
                std::string id;
                view.promptForInput("Enter ID of Threat to display: ", id);
                displayThreat(id);                                                              //call display user function
                break;
            }
            case '4': {
                listThreats();
                break;
            case '5': {
                std::string id;
                view.promptForInput("Enter ID of Threat to remove: ", id);                    //prompt user to enter name
                removeThreat(id);                                                               //call remove user function
                break;
            }
            case '6': {
                std::string filename;
                view.promptForInput("Enter file PATH to LOAD THREATS: ", filename);
                loadThreatsFromFile(filename);
                break;
            }
            case '7': {
                std::string filename;
                view.promptForInput("Enter file PATH to SAVE THREATS: ", filename);
                saveThreatsToFile(filename);
                break;
            }
            case '8': {
                exit(0);
            }
            default:
                view.displayMessage("Invalid choice. Please try again.");
            }
        }
    } while (choice != '8');                                                                //loop while user not selected 6 (exit)
}
