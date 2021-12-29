#include "../include/common.hpp"
#include "../include/astroid.hpp"

Astroid::Astroid(){
    //Astroid Init
    C2D_SpriteFromSheet(&spr, spriteSheet, 0);
    C2D_SpriteSetCenter(&spr,  0.5f,0.5f);
    C2D_SpriteSetPos(&spr, 0, 0);
    C2D_SpriteSetRotation(&spr, 0);
    C2D_SpriteScale(&spr, 0.75f,0.75f);
    //End Astroid Init
}
