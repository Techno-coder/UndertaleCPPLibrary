
#include "../../headers/fights/ActCommand.h"

const std::string& ug::ActCommand::getActID() const {
    return actID;
}

const std::string& ug::ActCommand::getActName() const {
    return actName;
}

ug::ActCommand::ActCommand(const std::string& actID, const std::string& actName) : actID(actID), actName(actName) {
}

ug::ActCommand::ActCommand(const std::string& actName) : ActCommand(actName, actName) {
}
