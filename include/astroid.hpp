#pragma once
#include "common.hpp"

class Astroid{
public:
    C2D_Sprite spr;
    float astroidSpeed = 5;

    Astroid(C2D_SpriteSheet spritesheet);
    void update();
    void render();
    bool checkDelete();
    void setSpeed(float speed);
    void setDir(float x, float y);
private:
    Vec2 dir;
    

};