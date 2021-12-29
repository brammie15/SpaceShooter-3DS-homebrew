#include "../include/common.hpp"
#include "../include/bullet.hpp"

Bullet::Bullet(C2D_SpriteSheet spritesheet){
    C2D_SpriteFromSheet(&this->spr,spritesheet, 1);
	C2D_SpriteSetCenter(&this->spr,  0.5f,0.5f);
	C2D_SpriteSetPos(&this->spr, 0,0);
	C2D_SpriteSetRotation(&this->spr, 0);
	C2D_SpriteSetScale(&this->spr, 0.5f, 0.5f);
}

void Bullet::update(){
    C2D_SpriteMove(&this->spr, 0, -bulletSpeed);

}

void Bullet::render(){
    if(this->isFlying){
        C2D_DrawSprite(&this->spr);
    }
}

bool Bullet::checkDelete(){
    return this->spr.params.pos.y + this->spr.params.pos.h/2 < 0;
}

Bullet::~Bullet(){
}