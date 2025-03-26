#include "pch.h"

LARGE_INTEGER TimeSystem::cpuFrequency = {};
LARGE_INTEGER TimeSystem::prevFrequency = {};
LARGE_INTEGER TimeSystem::currFrequency = {};
float TimeSystem::deltaTime = 0.0f;

void TimeSystem::Initialize() 
{
	// CPU ���� ������
	QueryPerformanceFrequency(&cpuFrequency);
	
	// ���α׷��� ���� ���� �� ���� ������
	QueryPerformanceCounter(&prevFrequency);
}

void TimeSystem::Update()
{
	QueryPerformanceCounter(&currFrequency);

	float differenceFrequency = static_cast<float>(currFrequency.QuadPart - prevFrequency.QuadPart);
	deltaTime = differenceFrequency / static_cast<float>(cpuFrequency.QuadPart);
	prevFrequency = currFrequency;
}

float TimeSystem::GetDeltaTime() { return deltaTime; }