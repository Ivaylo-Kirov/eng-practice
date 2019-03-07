#include "Application.h"
#include <iostream>

namespace EnginePractice {

	Application::Application()
	{
	}


	Application::~Application()
	{
	}

	void Application::Run() {
		std::cout << "Engine started\n";
		while (true);
	}

}