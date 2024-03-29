#pragma once

#include <memory>

namespace sf {
	class RenderTarget;
}

namespace ug {
	class PlayerStatistics;

	class ResourceResolver;

	class PlayerInfoInterface {
		struct Impl;
		std::unique_ptr<Impl> impl;
	public:
		PlayerInfoInterface(const PlayerStatistics& initialStatistics, std::shared_ptr<ResourceResolver> resources);
		~PlayerInfoInterface();

		void draw(sf::RenderTarget& target);
		void updateInterface(const PlayerStatistics& newStatistics);
		void setTopLeftPosition(float x, float y);
	};
}

