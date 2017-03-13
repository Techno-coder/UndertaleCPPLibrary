
#include "../../headers/core/LaunchParameters.h"

bool ug::LaunchParameters::isStartFullscreen() const {
    return startFullscreen;
}

void ug::LaunchParameters::setStartFullscreen(bool startFullscreen) {
    LaunchParameters::startFullscreen = startFullscreen;
}

unsigned int ug::LaunchParameters::getStartWindowWidth() const {
    return startWindowWidth;
}

void ug::LaunchParameters::setStartWindowWidth(unsigned int startWindowWidth) {
    LaunchParameters::startWindowWidth = startWindowWidth;
}

unsigned int ug::LaunchParameters::getStartWindowHeight() const {
    return startWindowHeight;
}

void ug::LaunchParameters::setStartWindowHeight(unsigned int startWindowHeight) {
    LaunchParameters::startWindowHeight = startWindowHeight;
}

const std::string &ug::LaunchParameters::getStartWindowTitle() const {
    return startWindowTitle;
}

void ug::LaunchParameters::setStartWindowTitle(const std::string &startWindowTitle) {
    LaunchParameters::startWindowTitle = startWindowTitle;
}

ug::State *ug::LaunchParameters::getStartingState() const {
    return startingState;
}

void ug::LaunchParameters::setStartingState(ug::State *startingState) {
    LaunchParameters::startingState = startingState;
}
