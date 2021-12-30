#include "../include/common.hpp"
#include "../include/astroid.hpp"

Astroid::Astroid(C2D_SpriteSheet spritesheet){
    //Astroid Init
    //C2D_SpriteFromSheet(&spr, spritesheet, round(rand()*C2D_SpriteSheetCount(spritesheet)));
    C2D_SpriteFromSheet(&spr, spritesheet, RandomInt(0, C2D_SpriteSheetCount(spritesheet)));
    C2D_SpriteSetCenter(&spr,  0.5f,0.5f);
    C2D_SpriteSetPos(&spr, 0, 0);
    C2D_SpriteSetRotation(&spr, 0);
    C2D_SpriteScale(&spr, 0.75f,0.75f);
    //End Astroid Init
}

void Astroid::render(){
        C2D_DrawSprite(&this->spr);
}
void Astroid::update(){
    //Bullet Update
    C2D_SpriteSetPos(&spr, dir.x, dir.y);
    //check if the astroid is hitting the side edge
    if(spr.params.pos.x + spr.params.pos.w/2 > SCREEN_WIDTH || spr.params.pos.x - spr.params.pos.w/2 < 0){
        dir.x *= -1;
    }
    //End Bullet Update
}

bool Astroid::checkDelete(){
    //Bullet CheckDelete
    if(spr.params.pos.x > SCREEN_WIDTH || spr.params.pos.x < 0 || spr.params.pos.y > SCREEN_HEIGHT || spr.params.pos.y < 0){
        return true;
    }
    //End Bullet CheckDelete
    return false;
}

void Astroid::setSpeed(float speed){
    this->astroidSpeed = speed;
}

void Astroid::setDir(float x, float y){
    this->dir.x = x;
    this->dir.y = y;
}