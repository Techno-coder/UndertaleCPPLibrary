#pragma once

#include <string>

namespace ucl {
	class Resources {
	public:
		static std::string getResourcesRoot();
		static std::string createResourcesPath(const std::string& internalPath);
	};
}

