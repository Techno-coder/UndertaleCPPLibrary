#pragma once

#include <memory>
#include "Soul.h"

namespace ug {
	class RedSoul : public Soul {
		struct Impl;
		std::unique_ptr<Impl> impl;
	public:
		RedSoul();
		void draw(sf::RenderTarget& target) override;
	};
}

