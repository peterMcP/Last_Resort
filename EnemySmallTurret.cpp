/*#include "Application.h"
#include "EnemySmallTurret.h"
#include "ModuleCollision.h"
#include "ModuleEnemies.h"
#include "EnemyTank.h"
#include "Path.h"

EnemySmallTurret::EnemySmallTurret(int x, int y, powerUpTypes type, SDL_Texture* sprite) : Enemy(x, y)
{
	//anims
	rotateAnim.PushBack({ 159, 158, 15, 6 });
	rotateAnim.PushBack({ 174, 158, 13, 8 });
	rotateAnim.PushBack({ 187, 158, 13, 9 });
	rotateAnim.PushBack({ 200, 158, 13, 9 });
	rotateAnim.PushBack({ 213, 158, 13, 9 });
	rotateAnim.PushBack({ 226, 158, 13, 9 });
	rotateAnim.PushBack({ 239, 158, 14, 6 });

	animation = &rotateAnim;

	texture = sprite;
	powerUpType = type;

	collider = App->collision->AddCollider({ 0, 0, 15, 9 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
}*/