#pragma once

namespace engine {
	class Resource {
	public:
		Resource() {}
		~Resource() {}

		virtual bool Init() = 0;
		virtual bool Shutdown() = 0;
	};
}
