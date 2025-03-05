#include "pch.h"

double TimeSystem::prevTime;
double TimeSystem::currTime;
double TimeSystem::frameTime;
double TimeSystem::_precision;

void TimeSystem::InitTime() {

	LARGE_INTEGER freq;
	if (!QueryPerformanceFrequency(&freq)) {
		// TODO: Need a logger!
		throw std::runtime_error("Timer: Performance counter is not supported!");
	}
	_precision = 1.0 / static_cast<double>(freq.QuadPart);

	prevTime = GetTick();
	currTime = 0.0;
	frameTime = 0.0;
}

void TimeSystem::UpdateTime()
{
	currTime = GetTick();
	frameTime = currTime - prevTime;
	prevTime = currTime;
}

double TimeSystem::GetTick() {
	LARGE_INTEGER counter;
	QueryPerformanceCounter(&counter);
	return static_cast<double>(counter.QuadPart) * _precision;
}

double TimeSystem::GetDeltaTime() { return frameTime; }