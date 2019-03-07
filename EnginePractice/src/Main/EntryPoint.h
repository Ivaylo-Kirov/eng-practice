#pragma once
#include "Application.h"


extern EnginePractice::Application* EnginePractice::CreateApplication();

int main(int args, char** argv) {
	auto app = EnginePractice::CreateApplication();
	app->Run();
	delete app;
}

