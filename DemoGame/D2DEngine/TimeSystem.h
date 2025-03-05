#pragma once

class TimeSystem
{
private:

    static double prevTime;
    static double currTime;
    static double frameTime;
    static double _precision;

public:

    static void UpdateTime();

    static void InitTime();

    static double GetTick();

    static double GetDeltaTime();
};