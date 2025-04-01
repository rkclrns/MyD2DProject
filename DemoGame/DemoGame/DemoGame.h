#pragma once
#include "../D2DEngine/WinApp.h"

class  PlayScene;
class DemoGame 
	: public WinApp
{
public:

	void Initialize(HINSTANCE hInstance) override;

	void Run() override;
	
	void UnInitialize() override;
	
	void Update() override;

	void Render() override;

	void LoadScene();

private:
	PlayScene* playScene = nullptr;
};