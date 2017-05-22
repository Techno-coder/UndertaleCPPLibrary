#pragma once

#include <memory>
#include "Soul.h"

namespace ug {
	class RedSoul : public Soul {
		struct Impl;
		std::unique_ptr<Impl> impl;
	public:
		RedSoul();
		~RedSoul();
		void draw(sf::RenderTarget& target) override;
		void setPosition(float x, float y) override;
	};
}

