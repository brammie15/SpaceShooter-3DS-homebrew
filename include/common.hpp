#pragma once

#include <citro2d.h>

#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>

#define SCREEN_WIDTH  400
#define SCREEN_HEIGHT 240

typedef struct{
	float x;
	float y;
} Vec2;

float RandomFloat(float min, float max);
//return a random number between min and max
int RandomInt(int min, int max);

bool isWithinScreenBounds(C2D_Sprite sprite);
