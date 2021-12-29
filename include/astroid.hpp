#pragma once
#include "common.hpp"

class Astroid{
    public:
    C2D_Sprite spr;
    float astroidSpeed = 5;
    bool isFlying = false;

    Astroid(C2D_SpriteSheet spritesheet);
    ~Astroid();
    void update();
    void render();
    bool checkDelete();

};