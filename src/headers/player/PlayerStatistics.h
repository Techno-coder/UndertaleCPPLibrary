#pragma once

#include <memory>

namespace ug {
	class PlayerStatistics {
		struct Impl;
		std::unique_ptr<Impl> impl;
	public:
		PlayerStatistics();
		~PlayerStatistics();

		int getCurrentHealth() const;
		void setCurrentHealth(int currentHealth);

		int getMaxHealth() const;
		void setMaxHealth(int maxHealth);

		int getLevel() const;
		void setLevel(int level);

		const std::string& getName() const;
		void setName(const std::string& name);
	};
}

