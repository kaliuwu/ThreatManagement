#pragma once
#include <string>

class Threat {
private:
    std::string id;
    std::string level;
    std::string description;
    std::string timestamp;

public:
    Threat(const std::string& id, const std::string& level, const std::string& description, const std::string& timestamp);

    std::string getID() const;
    std::string getLevel() const;
    std::string getDescription() const;
    std::string getTimestamp() const;
    
    void setLevel(const std::string& level);
    void setDescription(const std::string& description);
};


