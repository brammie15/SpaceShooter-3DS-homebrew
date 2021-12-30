#include "../include/common.hpp"
#include "../include/star.hpp"

Star::Star(C2D_SpriteSheet spritesheet){
    C2D_SpriteFromSheet(&spr, spritesheet, 0);
    C2D_SpriteSetCenter(&spr, 0.5, 0.5);
    C2D_SpriteSetPos(&spr, RandomFloat(0, SCREEN_WIDTH), RandomFloat(0, SCREEN_HEIGHT));
    C2D_SpriteSetScale(&spr, RandomFloat(0.5, 1.5), RandomFloat(0.5, 1.5));
    C2D_SpriteRotate(&spr, RandomFloat(0, 360));
    DissolveTime = RandomFloat(0, 10);
    rotateSpeed = RandomFloat(2, 30);
    scaleSpeed = RandomFloat(-0.1, 0.1);

}
Star::Star(){}


void Star::render(){
    C2D_DrawSprite(&this->spr);
}


void Star::update(){
    C2D_SpriteRotate(&this->spr, this->rotateSpeed);
    C2D_SpriteScale(&this->spr, scaleSpeed,scaleSpeed);
    scaleSpeed -= 0.01;
    rotateSpeed -= 0.0005f;
}
