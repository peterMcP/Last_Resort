#include "Application.h"
#include "EnemyBee.h"
#include "ModuleCollision.h"
#include "ModuleEnemies.h"
#include "ModulePlayer.h"

EnemyBee::EnemyBee(int x, int y, powerUpTypes type, SDL_Texture* sprite) : Enemy(x, y)
{
	flyToLeft.PushBack({ 0, 0, 48, 45 });
	flyToLeft.PushBack({ 49, 0, 48, 45 });
	flyToLeft.PushBack({ 98, 0, 37, 46 });
	flyToLeft.PushBack({ 147, 0, 39, 46 });
	flyToLeft.PushBack({ 196, 0, 41, 46 });
	flyToLeft.PushBack({ 245, 0, 41, 46 });
	flyToLeft.PushBack({ 294, 0, 48, 46 });
	flyToLeft.PushBack({ 343, 0, 48, 46 });
	flyToLeft.PushBack({ 392, 0, 41, 46 });
	flyToLeft.PushBack({ 441, 0, 41, 46 });

	flyToLeft.PushBack({ 0, 46, 37, 46 });
	flyToLeft.PushBack({ 49, 46, 39, 46 });
	flyToLeft.PushBack({ 98, 46, 48, 45 });
	flyToLeft.PushBack({ 147, 46, 48, 45 });
	flyToLeft.PushBack({ 196, 46, 42, 45 });
	flyToLeft.PushBack({ 245, 46, 42, 45 });
	flyToLeft.PushBack({ 294, 46, 43, 45 });
	flyToLeft.PushBack({ 343, 46, 44, 45 });
	flyToLeft.PushBack({ 392, 46, 37, 46 });
	flyToLeft.PushBack({ 441, 46, 37, 46 });

	flyToLeft.PushBack({ 0, 92, 40, 46 });
	flyToLeft.PushBack({ 49, 92, 40, 46 });
	flyToLeft.PushBack({ 98, 92, 48, 46 });
	flyToLeft.PushBack({ 147, 92, 48, 46 });

	flyToLeft.PushBack({ 196, 92, 40, 46 });
	flyToLeft.PushBack({ 245, 92, 40, 46 });
	flyToLeft.PushBack({ 294, 92, 37, 46 });
	flyToLeft.PushBack({ 343, 92, 37, 46 });
	flyToLeft.PushBack({ 392, 92, 43, 46 });
	flyToLeft.PushBack({ 441, 92, 44, 46 });

	flyToLeft.PushBack({ 0, 138, 42, 45 });
	flyToLeft.PushBack({ 49, 138, 42, 45 });


	flyToLeft.speed = 0.2f;

	animation = &flyToLeft; //links animation


	texture = sprite;


	fposition.x = x;
	fposition.y = y;

	powerUpType = type;
	life = 1; //6 points of life original
	enemyScore = 300;

	iSpeed = 40;
	//fSpeed = 50;
	fSpeed = 47.3f;

	collider = App->collision->AddCollider({ 0, 0, 32, 16 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

}

void EnemyBee::Move()
{

	fposition.x += ((float)App->player->position.x - fposition.x) / fSpeed;
	fposition.y += ((float)App->player->position.y - fposition.y) / fSpeed;

	position.x = fposition.x + 1;
	position.y = fposition.y;

}