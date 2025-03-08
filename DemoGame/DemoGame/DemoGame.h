#pragma once
#include "../D2DEngine/WinApp.h"
#include "../D2DEngine/TimeSystem.h"

class DemoGame 
	: public WinApp
{
public:

	void Initialize(HINSTANCE hInstance) override;

	void Run() override;
	
	void UnInitialize() override;
	
	void Update() override;

	void Render() override;

private:

};