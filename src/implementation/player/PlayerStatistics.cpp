#include <string>
#include "player/PlayerStatistics.h"

struct ug::PlayerStatistics::Impl {
	int currentHealth = 0;
	int maxHealth = 0;
	int level = 0;
	std::string name = "";
};

int ug::PlayerStatistics::getCurrentHealth() const {
	return impl->currentHealth;
}

void ug::PlayerStatistics::setCurrentHealth(int currentHealth) {
	impl->currentHealth = currentHealth;
}

int ug::PlayerStatistics::getMaxHealth() const {
	return impl->maxHealth;
}

void ug::PlayerStatistics::setMaxHealth(int maxHealth) {
	impl->maxHealth = maxHealth;
}

int ug::PlayerStatistics::getLevel() const {
	return impl->level;
}

void ug::PlayerStatistics::setLevel(int level) {
	impl->level = level;
}

ug::PlayerStatistics::~PlayerStatistics() {}

const std::string& ug::PlayerStatistics::getName() const {
	return impl->name;
}

void ug::PlayerStatistics::setName(const std::string& name) {
	impl->name = name;
}

ug::PlayerStatistics::PlayerStatistics() : impl(std::make_unique<Impl>()) {}
