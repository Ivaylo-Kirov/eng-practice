#pragma once

#include "Core.h"

namespace EnginePractice {
	class EP_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	};

	// to be defined in client
	EnginePractice::Application * CreateApplication();

}