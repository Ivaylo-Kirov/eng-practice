#include "EP.h"

class Sandbox : public EnginePractice::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

EnginePractice::Application* EnginePractice::CreateApplication() {
	return new Sandbox();
}
