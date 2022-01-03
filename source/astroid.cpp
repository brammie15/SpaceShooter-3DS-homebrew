#include "../include/common.hpp"
#include "../include/astroid.hpp"

Astroid::Astroid(C2D_SpriteSheet spritesheet){
    //Astroid Init
    C2D_SpriteFromSheet(&spr, spritesheet, RandomInt(0, C2D_SpriteSheetCount(spritesheet)));
    C2D_SpriteSetCenter(&spr,  0.5f,0.5f);
    C2D_SpriteSetPos(&spr, 0, 0);
    C2D_SpriteSetRotation(&spr, 0);
    C2D_SpriteScale(&spr, 0.75f,0.75f);
    //End Astroid Init
}

void Astroid::render(){
    if(isWithinScreenBounds(spr)){
        C2D_DrawSprite(&this->spr);
    }
}
void Astroid::update(){
    if(spr.params.pos.x - spr.params.pos.w/2 <= 0){ //left side
        dir.x = 1;
    }
    if(spr.params.pos.x + spr.params.pos.w/2 >= SCREEN_WIDTH){ //right side
        dir.x = -1;
    }
    C2D_SpriteRotate(&spr, rotationSpeed);
    C2D_SpriteMove(&spr, dir.x * astroidSpeed, dir.y * astroidSpeed);
			
}

bool Astroid::checkDelete(){
    return spr.params.pos.y - spr.params.pos.h/2 > SCREEN_HEIGHT;
}

void Astroid::setSpeed(float speed){
    this->astroidSpeed = speed;
}
void Astroid::setDir(float x, float y){
    this->dir.x = x;
    this->dir.y = y;
}