#ifndef _MODULEENEMIES_H__
#define _MODULEENEMIES_H__

#include "Module.h"
#include "EnemyTank.h"
#include "BasicEnemy.h"
#include "EnemyOscilatory.h"
#include "EnemyBee.h"
#include "EnemyRedbird.h"
#include "EnemyLamella.h"
#include "EnemyMiniTank.h"
#include "EnemySubmarine.h"
#include "EnemyDiver.h"
#include "EnemyPilot.h"
#include "ModuleParticles.h"

//#include "Enemy.h"


#define MAX_ENEMIES 300

enum ENEMY_TYPES
{
	NO_TYPE,
	BASIC_ENEMY,
	ENEMYOSCILATORY,
	REDBIRD,
	TANK,
	ENEMYBEE,
	POWERUP_BEE,
	ENEMYPROTATOR,
	LAMELLA,
	MINITANK,
	SUBMARINE,
	DIVER,
	ENEMYPILOT
};

//class Enemy;
//struct SDL_Texture;

struct EnemyInfo
{
	ENEMY_TYPES type = ENEMY_TYPES::NO_TYPE;
	int x, y;
	//SDL_Texture* texture;
	powerUpTypes powerUpType = powerUpTypes::NONE;
};

class ModuleEnemies : public Module
{
public:

	ModuleEnemies();
	~ModuleEnemies();

	bool Start();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();
	void OnCollision(Collider* c1, Collider* c2);

	bool AddEnemy(ENEMY_TYPES type, int x, int y, powerUpTypes powerUpType);

	void pleaseKillMe(Enemy*);
	

	//more textures - in public because we call outside this module
	//more enemies textures -------
	SDL_Texture* enemy1Texture;
	SDL_Texture* enemy2Texture;
	SDL_Texture* enemyTankTexture;
	SDL_Texture* enemyBeeTexture;
	SDL_Texture* beeBulletTexture;
	SDL_Texture* enemyRedbirdTexture;
	SDL_Texture* enemyPowerBeeTexture;
	SDL_Texture* enemyProtatorTexture;
	SDL_Texture* enemyLamellaTexture;
	SDL_Texture* enemyMiniTankTexture;
	SDL_Texture* enemySubmarineTexture;
	SDL_Texture* enemyDiverTexture;
	SDL_Texture* enemyPilotTexture;
	// ----------------------------
	//ENEMY PARTICLES
	Particle beeBullet;
	Particle tankBigShot;
	Particle tankSmallShot;
private:

	void SpawnEnemy(EnemyInfo& info);// , powerUpTypes powerUpType = powerUpTypes::NONE, SDL_Texture* texture = nullptr);

private:

	EnemyInfo queue[MAX_ENEMIES];
	Enemy* enemies[MAX_ENEMIES];
	SDL_Texture* sprites; //general spriteSheet texture, used when we call AddEnemy from the scene without 
					      //specificate exclusive texture
};

#endif // _MODULEENEMIES_H__