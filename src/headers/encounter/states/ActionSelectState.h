#pragma once

#include <state/State.h>
#include <memory>
#include <encounter/components/ButtonInterface.h>
#include <functional>
#include <resource/ResourceResolver.h>

namespace ug {
	class Soul;

	class ActionSelectState : public State {
		struct Impl;
		std::unique_ptr<Impl> impl;
	public:
		ActionSelectState(std::function<void(ButtonInterface::Button)> callbackOnSelect, std::unique_ptr<Soul> soul,
		                  std::shared_ptr<ResourceResolver> resources);
		virtual ~ActionSelectState();

		void enter() override;
		void handleEvent(sf::Event& event) override;
		void update() override;
		void draw(sf::RenderTarget& target) override;
	};
}

