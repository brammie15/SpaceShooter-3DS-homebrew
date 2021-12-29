#pragma once
#include "common.hpp"

class Bullet{
    public:
    C2D_Sprite spr;
    float bulletSpeed = 5;
    bool isFlying = false;

    Bullet(C2D_SpriteSheet spritesheet);
    ~Bullet();
    void update();
    void render();
    bool checkDelete();
};