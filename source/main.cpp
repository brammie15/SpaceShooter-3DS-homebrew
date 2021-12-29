#include "../include/common.hpp"
#include "../include/bullet.hpp"

#define SCREEN_WIDTH  400
#define SCREEN_HEIGHT 240



bool isFlying = false;
bool fistFly = true;


static C2D_SpriteSheet spriteSheet;
static C2D_SpriteSheet backgroundSpriteSheet;
static C2D_Image backgroundImage;
static C2D_Image backgroundImage2;
float playerX = SCREEN_WIDTH/2; 
float ScrollDist = 0;
float playerSpeed = 5;
C2D_Sprite playerSprite;
Vec2 playerTL;
std::vector<Bullet> bullets;


Vec2 getTopLeftSprite(C2D_Sprite in){
	return (Vec2){in.params.pos.x - in.params.pos.w/2,in.params.pos.y - in.params.pos.h/2};
}

void playerMove(C2D_Sprite _player, float dir){
	float moveBy = dir * playerSpeed;
	playerTL = getTopLeftSprite(playerSprite);

	if(playerX + moveBy >= SCREEN_WIDTH - _player.params.pos.w/2){
		playerX = SCREEN_WIDTH - _player.params.pos.w/2;
	}else if (playerX + moveBy < _player.params.pos.w/2){
		playerX = _player.params.pos.w/2;
	}else{
		playerX += moveBy;
	}
	C2D_SpriteSetPos(&playerSprite,playerX, 200);
}

static void initSprites(){
	//Player Init
	C2D_SpriteFromSheet(&playerSprite, spriteSheet, 0);
	C2D_SpriteSetCenter(&playerSprite,  0.5f,0.5f);
	C2D_SpriteSetPos(&playerSprite, playerX, 200);
	C2D_SpriteSetRotation(&playerSprite, 0);
	C2D_SpriteScale(&playerSprite, 0.75f,0.75f);
	playerTL = getTopLeftSprite(playerSprite);
	//End PlayerInit
}

int main(int argc, char* argv[])
{
	romfsInit();
	gfxInitDefault();
	C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
	C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
	C2D_Prepare();
	consoleInit(GFX_BOTTOM, NULL);
	C3D_RenderTarget* top = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);

	spriteSheet = C2D_SpriteSheetLoad("romfs:/gfx/sprites.t3x");
	if (!spriteSheet) svcBreak(USERBREAK_PANIC);
	backgroundSpriteSheet = C2D_SpriteSheetLoad("romfs:/gfx/backgrounds.t3x");
	if (!spriteSheet) svcBreak(USERBREAK_PANIC);
	backgroundImage  = C2D_SpriteSheetGetImage(backgroundSpriteSheet,0);
	backgroundImage2 = C2D_SpriteSheetGetImage(backgroundSpriteSheet,0);

	initSprites();
	// Main loop \x1b[r;cH
	while (aptMainLoop())
	{
		u32 kHeld = hidKeysHeld();
		u32 kDown = hidKeysDown();
		hidScanInput();
		
		if (kDown & KEY_START)
			break; // break in order to return to hbmenu

		if(kDown & KEY_LEFT || kHeld & KEY_LEFT){
			playerMove(playerSprite, -1);
		}
		if(kDown & KEY_RIGHT || kHeld & KEY_RIGHT){
			playerMove(playerSprite, 1);
		}
		if(kDown & KEY_A){
			printf("FIRE\n");
			Bullet b = Bullet(spriteSheet);
			b.isFlying = true;
			b.spr.params.pos.x = playerSprite.params.pos.x;
			b.spr.params.pos.y = playerSprite.params.pos.y - playerSprite.params.pos.h/2;
			bullets.push_back(b);
			
		}

		for (u16 i = 0; i < bullets.size(); i++){
			bullets[i].update();
			if(bullets[i].checkDelete()){
				bullets.erase(bullets.begin() + i);
			}
		}		
		printf("\x1b[0;0HAmount of Bullets: %d\n", bullets.size());

		C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
		C2D_TargetClear(top, C2D_Color32(0,0,0,1));
		C2D_SceneBegin(top);
		double xScale = SCREEN_WIDTH/backgroundImage.tex->width;
		C2D_DrawImageAt(backgroundImage,0,ScrollDist,0,NULL,(double)400/256,1);
		C2D_DrawImageAt(backgroundImage2,0,ScrollDist - 256,0,NULL,(double)400/256,1);
		ScrollDist+= 0.5;
		if(ScrollDist > 256){
			ScrollDist = 0;
		}

		C2D_DrawSprite(&playerSprite);
		
		for (u16 i = 0; i < bullets.size(); i++){
			//C2D_DrawSprite(&bullets[i].spr);
			bullets[i].render();
		}
		

		//C2D_DrawCircleSolid(Bullet.params.pos.x, Bullet.params.pos.y, 0, 20, clrWhite);

		C3D_FrameEnd(0);

	}

	C2D_SpriteSheetFree(spriteSheet);
	C2D_SpriteSheetFree(backgroundSpriteSheet);
	C2D_Fini();
	C3D_Fini();
	gfxExit();
	romfsExit();
	return 0;
}
