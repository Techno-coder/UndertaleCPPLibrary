#pragma once

#include "Locator.h"

namespace ug {
	class ResourceResolver;

	typedef ug::Locator<ug::ResourceResolver> ResourceLocator;

	template <>
	std::shared_ptr<ug::ResourceResolver> ug::ResourceLocator::get();
}
