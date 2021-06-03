#pragma once

class Playable
{
public:
    void Pause();

    void MoveForward(float AxisValue);
    void LookUp(float AxisValue);
    void MoveSide(float AxisValue);
    void LookSide(float AxisValue);
};