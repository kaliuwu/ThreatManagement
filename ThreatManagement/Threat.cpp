#include "Threat.h"
#include <stdexcept>
Threat::Threat(const std::string& id, const std::string& level, const std::string& description, const std::string& timestamp){
    this->id = id;
    this->level = level;
    this->description = description;
    this->timestamp = timestamp;
}

std::string Threat::getID() const {
    return id;
}

std::string Threat::getLevel() const {
    return level;
}

std::string Threat::getDescription() const {
    return description;
}

std::string Threat::getTimestamp() const {
    return timestamp;
}

void Threat::setLevel(const std::string& newLevel) {
    level = newLevel;
}
void Threat::setDescription(const std::string& newDescription) {
    description = newDescription;
}
