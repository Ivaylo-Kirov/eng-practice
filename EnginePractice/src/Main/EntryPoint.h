#pragma once


extern EnginePractice::Application* EnginePractice::CreateApplication();

int main(int args, char** argv) {

	EnginePractice::Log::Init();
	EP_CORE_WARN("Initialized Log");
	EP_INFO("Client Info Log");


	auto app = EnginePractice::CreateApplication();
	app->Run();
	delete app;
}
