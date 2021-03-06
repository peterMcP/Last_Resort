#ifndef _ENEMYDIVER_H__
#define _ENEMYDIVER_H__

#include "Enemy.h"
#include "ModuleTextures.h"

class EnemyDiver : public Enemy
{

private:

	float distance;
	float pivot;

	bool clock = false;
	bool jumping = true;
	//bool shoot = false;
	bool spawn = false;
	//bool bullet = true;
	//bool isShooting = false;
	bool shootingFlash = false;
	bool shootParticle = false;

	bool decelerate = false;
	float jumpSpeed = 2.5f;
	int waterLevel = 185;

	float xSpeed;
	float ySpeed;

	float chaseSpeed = 0.35f;

	bool left = true;
	bool right = true;

	//bool leftAnim = false;
	//bool rightAnim = false;

	Uint32 startTime;
	Uint32 now;
	Uint32 totalTime;

	Animation idleLeft;
	Animation idleRight;

	Animation animLeft;
	Animation animRight;

	Animation shootLeft;
	Animation shootRight;

	Animation spawnAnim;

	Animation* currentAnimation = nullptr;
	Animation* currentShootAnim = nullptr;

	SDL_Rect diverRect;
	SDL_Rect shootRect;
	SDL_Rect spawnRect;

	iPoint originalPos;

	//Animation* currentStepAnim = nullptr;
	//bool currentStateAnim = false;

public:

	EnemyDiver(int x, int y, powerUpTypes type, SDL_Texture* thisTexture = nullptr);

	void Move();
	void Draw();

};
#endif // !_ENEMYDIVER_H__
