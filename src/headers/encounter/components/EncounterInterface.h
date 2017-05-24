#pragma once

#include <memory>
#include "ButtonInterface.h"

namespace sf {
	class RenderTarget;
}

namespace ug {
	class PlayerStatistics;

	class ResourceResolver;

	/**
	 * Encapsulates the buttons, arena and player info interface
	 */
	class EncounterInterface {
		struct Impl;
		std::unique_ptr<Impl> impl;
	public:
		EncounterInterface(const ug::PlayerStatistics& newStatistics, std::shared_ptr<ResourceResolver> resources);
		~EncounterInterface();

		void draw(sf::RenderTarget& target);

		void updateStatistics(const ug::PlayerStatistics& newStatistics);
		void setHighlightedButton(const ug::ButtonInterface::Button& button);
	};
}

