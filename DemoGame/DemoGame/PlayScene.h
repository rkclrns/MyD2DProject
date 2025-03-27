#pragma once
#include "..\D2DEngine\Scene.h"

class PlayScene :
    public Scene
{
public:
	void Initialize() override;
	void PreUpdate() override;
	void Update() override;
	void PostUpdate() override;
	void PreRender() override;
	void Render() override;
	void PostRender() override;
private:

};

