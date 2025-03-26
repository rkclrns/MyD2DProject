#pragma once

class TimeSystem
{
public:

    static void Initialize();
    static void Update();

    static float GetDeltaTime();

private:
    static LARGE_INTEGER cpuFrequency;
    static LARGE_INTEGER prevFrequency;
    static LARGE_INTEGER currFrequency;
    static float deltaTime;
};