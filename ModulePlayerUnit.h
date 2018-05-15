#ifndef __MODULEPLAYERUNIT_H__
#define __MODULEPLAYERUNIT_H__

#define MAX_ANIMS 16

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModulePlayer.h"
#include <math.h>
#include "ModulePowerUp.h"

enum actualState
{
	LINKED,
	FREE,
	RETURN,
	POSITIONING
};


class ModulePlayerUnit : public Module
{
public:
	struct axisPos
	{
		float x, y;
	} playerPos;

public:

	ModulePlayerUnit();
	~ModulePlayerUnit();
	//bool Init();
	bool Start();
	update_status PreUpdate();
	update_status Update();
	bool CleanUp();

	void swapColor(powerUpColor color);


public:

	bool alive = false; //prevent

	//some needed vars or specific functions
	SDL_Texture * graphics;
	Animation playerUnitAnim[MAX_ANIMS];
	Animation *currentUnitAnim;

	int unitIndex; //stores the index of the last
	float frameIncrement = 0; //stores the index for applicate the speed of the rotation and points to its correct
						      //and current frame
	float lastFrame; //stores last frame to start next position

	bool unitLocked = false;

	int pivotArrayPositionsX[16] = { 1,1,1,1,1,2,6,7,7,7,6,2,1,1,1,1 };

	int pivotArrayPositionsY[16] = { 1,2,6,8,7,8,6,2,1,1,1,1,1,1,1,1 };								

	//values needed to control the circular position movement
	float orbitSpeed = 3.0f;
	float angle = 0;
	float last_tick;
	float delta_time;

	//values needed for basic shooting  ------------------------------------
	//on x coord. we have to assume that we have -1 (playerMovement(+1) to followCameraMov.)
	iPoint shotVectorSpeed[16] = { { 6,0 }, { 5,-2 }, { 4,-3 }, { 3,-4 }, { 1,-4 }, { -1,-4 }, { -2,-3 }, { -3,-2 },
	                               {-4,0 }, { -3,2 }, { -2, 3 }, { -1, 4 }, { 1,4 }, { 3,4 }, { 4,3 }, { 5,2 } };

	powerUpColor actualUnitColor;

	int playerIndex; //index for assign unit to player

	actualState this_state = actualState::LINKED; //unit spawns linked to player

	// throwing variables ------------
	float charge = 0;

	void boomerangShot(float charge);

	SDL_Texture* chargeGraphics = nullptr;
	Animation chargingAnim;
	Animation freeAnim;

	int chargePivotsX[15] = { 18, 16, 16, 14, 14, 16, 16, 15, 15, 14, 14, 23, 23, 21, 21 };
	int chargePivotsY[15] = { 18, 16, 16, 14, 14, 16, 16, 15, 15, 13, 13, 23, 23, 21, 21 };

	float vx = 0.0f;
	float vy = 0.0f;
	float posX = 0.0f;
	float posY = 0.0f;
	float unitBoomerangSpeed = 4.5f;
	float positioningSpeed = 2.5f;
	float increaseVectorX = 0;
	float increaseVectorY = 0;

	int throwPivots[8] = { 2,3,4,3,2,1,0,1 };

	//time calculations

	Uint32 start_boomerang_time;
	Uint32 now;
	Uint32 max_boomerang_time = 1000;

	//trail animation
	Animation trailsAnim[4];
	Uint32 next_trail_time = 150;
	Uint32 now_trail_time;
	Uint32 start_next_trail_time;
	int trailsCounter = 0;
	float trailsDistance[2];
	fPoint trailsPosition[2];

	//

	struct trailsInfo
	{
		Animation* anim;
		iPoint initialPos;
		iPoint currentPos;
		iPoint targetPos;
		float distance;
		iPoint minDistance;
		float maxDistance;
		float tx;
		float ty;
		int pivotsX[8];
		int pivotsY[8];
	};

	trailsInfo trailsData[4];


};
#endif // !__MODULEPLAYERUNIT_H__
