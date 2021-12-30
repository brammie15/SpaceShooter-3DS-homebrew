#pragma once
#include "common.hpp"


class Star{
public:
    float DissolveTime;
    double rotateSpeed;
    float scaleSpeed;
    C2D_Sprite spr;
    Star(C2D_SpriteSheet spritesheet);
    Star();
    void render();
    void update();
};