#include "EP.h"

class ExampleLayer : public EnginePractice::Layer {
public:
	ExampleLayer()
		: Layer("Example") { }

	void OnUpdate() override {
		EP_INFO("ExampleLayer::Update");
	}

	void OnEvent(EnginePractice::Event& event) override {
		EP_INFO(event.GetName());
	}
};

class Sandbox : public EnginePractice::Application {
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
		PushOverlay(new EnginePractice::ImGuiLayer());
	}

	~Sandbox() {

	}
};

EnginePractice::Application* EnginePractice::CreateApplication() {
	return new Sandbox();
}
