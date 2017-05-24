#pragma once

#include <memory>
#include "ResourceResolver.h"

namespace ug {
	/**
	 * Class encapsulating default registered resources
	 * Reads from RESOURCES_ROOT/default/resource_map
	 */
	class DefaultResourceResolver
			: public ResourceResolver { //TODO consider making this more generic by taking in a path to a resource map
		struct Impl;
		std::unique_ptr<Impl> impl;
	public:
		DefaultResourceResolver();
		virtual ~DefaultResourceResolver();

		const sf::Texture& getTexture(const std::string& ID) const override;
		const sf::Font& getFont(const std::string& ID) const override;
		const sf::SoundBuffer& getSound(const std::string& ID) const override;

		static std::unique_ptr<ResourceResolver> createNew();
	};
}

