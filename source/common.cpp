#include "../include/common.hpp"

float RandomFloat(float min, float max)
{
    // this  function assumes max > min, you may want 
    // more robust error checking for a non-debug build
    assert(max > min); 
    float random = ((float) rand()) / (float) RAND_MAX;

    // generate (in your case) a float between 0 and (4.5-.78)
    // then add .78, giving you a float between .78 and 4.5
    float range = max - min;  
    return (random*range) + min;
}

//return a random number between min and max
int RandomInt(int min, int max)
{
	assert(max > min);
	int random = rand() % (max - min + 1) + min;
	return random;
}

bool isWithinScreenBounds(C2D_Sprite sprite){
    return sprite.params.pos.y + sprite.params.pos.h/2 > 0 ||
    sprite.params.pos.x - sprite.params.pos.w/2 > SCREEN_WIDTH ||
    sprite.params.pos.y - sprite.params.pos.h/2 < SCREEN_HEIGHT ||
    sprite.params.pos.x + sprite.params.pos.w/2 > 0;

}