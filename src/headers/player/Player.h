#pragma once

#include <memory>

namespace ug {
	class PlayerStatistics;

	class Player {
		struct Impl;
		std::unique_ptr<Impl> impl;
	public:
		Player();
		~Player();
		PlayerStatistics& statistics();
	};
}

