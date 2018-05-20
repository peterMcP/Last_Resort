#include "Application.h"
#include "EnemySubmarine.h"
#include "ModuleCollision.h"
#include "ModuleEnemies.h"
//#include "ModulePlayer.h"
#include "ModuleRender.h"

#include "ModuleSceneLvl3.h"

#include "ModulePowerUp.h"

#include "SDL\include\SDL_timer.h"

#include "Player.h"

#include "ModuleAudio.h"

EnemySubmarine::EnemySubmarine(int x, int y, powerUpTypes type, SDL_Texture* thisTexture) : Enemy(x, y)
{
	int k = 0; // for extracolliders assignements

	// assigns type to despawn check of moduleEnemies
	enemyType = ENEMY_TYPES::SUBMARINE;
	//links the correct spritesheet texture ----
	enemyTex = thisTexture;
	// -----------------------------------------
	// enemy parts / animations data
	// body
	submarineBodyRect = { 0,0,456,112 };
	submarineBodyDamageRect = { 0,138,456,112 };
	// non destroyed static parts ----
	// part1
	nonDestroyedParts[0].normalRect = { 16,112,32,12 };
	nonDestroyedParts[0].takenDamageRect = { 16,250, 32,12 };
	nonDestroyedParts[0].position = { 16, 84 };
	// part2
	nonDestroyedParts[1].normalRect = { 48,113,32,12 };
	nonDestroyedParts[1].takenDamageRect = { 48,251,32,12 };
	nonDestroyedParts[1].position = { 48, 84 };
	// part3
	nonDestroyedParts[2].normalRect = { 80,112,32,12 };
	nonDestroyedParts[2].takenDamageRect = { 80,250,32,12 };
	nonDestroyedParts[2].position = { 80, 84 };
	// part4
	nonDestroyedParts[3].normalRect = { 128,112,32,16 };
	nonDestroyedParts[3].takenDamageRect = { 128,251, 32,16 };
	nonDestroyedParts[3].position = { 128, 80 };
	// part5
	nonDestroyedParts[4].normalRect = { 165,112,27,16 };
	nonDestroyedParts[4].takenDamageRect = { 165,250, 27,16 };
	nonDestroyedParts[4].position = { 165, 64 };
	// part6 (ejectable enemy part static frame)
	//nonDestroyedParts[5].normalRect = { 457,0,60,32 };
	//nonDestroyedParts[5].takenDamageRect = { 457,33,60,32 };
	//nonDestroyedParts[5].position = { 196, 16 };
	//nonDestroyedParts[5].life = 10;
	// part7  (missile launcher part middle position static frame)
	//nonDestroyedParts[5].normalRect = { 459,66,64,32 };
	//nonDestroyedParts[5].takenDamageRect = { 459,99,64,32 };
	//nonDestroyedParts[5].position = { 208, 48 };
	// part8
	nonDestroyedParts[5].normalRect = { 288,112,24,8 };
	nonDestroyedParts[5].takenDamageRect = { 288,250,24,8 };
	nonDestroyedParts[5].position = { 288, 56 };
	// part9
	nonDestroyedParts[6].normalRect = { 304,121,32,16 };
	nonDestroyedParts[6].takenDamageRect = { 304,259,32,16 };
	nonDestroyedParts[6].position = { 304, 64 };
	// part9
	nonDestroyedParts[7].normalRect = { 336,112,32,16 };
	nonDestroyedParts[7].takenDamageRect = { 336,250,32,16 };
	nonDestroyedParts[7].position = { 336, 72 };
	// add colliders to each part
	for (int i = 0; i < NUM_NONDESTROYED_PARTS; ++i)
	{
		// one part its collider is a bit little on height
		if (i == 6) nonDestroyedParts[i].collider = extraColliders[i] = App->collision->AddCollider({0,0,32,12}, COLLIDER_ENEMY, (Module*)App->enemies);

		if (nonDestroyedParts[i].collider == nullptr)
			nonDestroyedParts[i].collider = extraColliders[i] = App->collision->AddCollider(nonDestroyedParts[i].normalRect, COLLIDER_ENEMY, (Module*)App->enemies);
	}
	// --------------------------------------------------

	// destroyed parts animations -----------------------
	destroyedParts[0].PushBack({ 457,197,96,12 });
	destroyedParts[0].PushBack({ 457,227,96,12 });
	destroyedParts[0].PushBack({ 457,257,96,12 });
	destroyedParts[0].PushBack({ 457,287,96,12 });
	destroyedParts[0].PushBack({ 457,317,96,12 });
	destroyedParts[0].PushBack({ 457,287,96,12 });
	destroyedParts[0].PushBack({ 457,257,96,12 });
	destroyedParts[0].PushBack({ 457,227,96,12 });
	destroyedParts[0].speed = 0.125f;

	destroyedParts[1].PushBack({ 569,193,32,16 });
	destroyedParts[1].PushBack({ 569,223,32,16 });
	destroyedParts[1].PushBack({ 569,253,32,16 });
	destroyedParts[1].PushBack({ 569,283,32,16 });
	destroyedParts[1].PushBack({ 569,313,32,16 });
	destroyedParts[1].PushBack({ 569,283,32,16 });
	destroyedParts[1].PushBack({ 569,253,32,16 });
	destroyedParts[1].PushBack({ 569,223,32,16 });
	destroyedParts[1].speed = 0.125f;

	destroyedParts[2].PushBack({ 609,178,24,15 });
	destroyedParts[2].PushBack({ 609,208,24,15 });
	destroyedParts[2].PushBack({ 609,238,24,15 });
	destroyedParts[2].PushBack({ 609,268,24,15 });
	destroyedParts[2].PushBack({ 609,298,24,15 });
	destroyedParts[2].PushBack({ 609,268,24,15 });
	destroyedParts[2].PushBack({ 609,238,24,15 });
	destroyedParts[2].PushBack({ 609,208,24,15 });
	destroyedParts[2].speed = 0.125f;

	destroyedParts[3].PushBack({ 649,132,48,29 });
	destroyedParts[3].PushBack({ 649,162,48,29 });
	destroyedParts[3].PushBack({ 649,192,48,29 });
	destroyedParts[3].PushBack({ 649,222,48,29 });
	destroyedParts[3].PushBack({ 649,252,48,29 });
	destroyedParts[3].PushBack({ 649,222,48,29 });
	destroyedParts[3].PushBack({ 649,192,48,29 });
	destroyedParts[3].PushBack({ 649,162,48,29 });
	destroyedParts[3].speed = 0.125f;

	destroyedParts[4].PushBack({ 729,169,80,24 });
	destroyedParts[4].PushBack({ 729,199,80,24 });
	destroyedParts[4].PushBack({ 729,229,80,24 });
	destroyedParts[4].PushBack({ 729,259,80,24 });
	destroyedParts[4].PushBack({ 729,289,80,24 });
	destroyedParts[4].PushBack({ 729,259,80,24 });
	destroyedParts[4].PushBack({ 729,229,80,24 });
	destroyedParts[4].PushBack({ 729,199,80,24 });
	destroyedParts[4].speed = 0.125f;
	// ------------------------------------------------

	// destroyable parts animations ( enemy ejection hatch and missile platforms launchers) -------------------------------
	// ejection hatch anim
	ejectionHatch.anim[NORMAL_ANIM].PushBack({ 457, 0, 60 ,32 });
	ejectionHatch.anim[NORMAL_ANIM].PushBack({ 520, 0, 60 ,32 });
	ejectionHatch.anim[NORMAL_ANIM].PushBack({ 588, 0, 60 ,32 });
	ejectionHatch.anim[NORMAL_ANIM].PushBack({ 656, 0, 60 ,32 }); // max open
	ejectionHatch.anim[NORMAL_ANIM].PushBack({ 588, 0, 60 ,32 });
	ejectionHatch.anim[NORMAL_ANIM].PushBack({ 520, 0, 60 ,32 });
	ejectionHatch.anim[NORMAL_ANIM].PushBack({ 457, 0, 60 ,32 }); // initial frame
	ejectionHatch.anim[NORMAL_ANIM].speed = 0.125f;
	ejectionHatch.anim[NORMAL_ANIM].repeat = false;
	// ---
	ejectionHatch.anim[DAMAGE_ANIM].PushBack({ 457, 33, 60, 32 });
	ejectionHatch.anim[DAMAGE_ANIM].PushBack({ 520, 33, 60, 32 });
	ejectionHatch.anim[DAMAGE_ANIM].PushBack({ 588, 33, 60, 32 });
	ejectionHatch.anim[DAMAGE_ANIM].PushBack({ 656, 33, 60, 32 }); // max open
	ejectionHatch.anim[DAMAGE_ANIM].PushBack({ 588, 33, 60, 32 });
	ejectionHatch.anim[DAMAGE_ANIM].PushBack({ 520, 33, 60, 32 });
	ejectionHatch.anim[DAMAGE_ANIM].PushBack({ 457, 33, 60, 32 }); // initial frame
	ejectionHatch.anim[DAMAGE_ANIM].speed = 0.125f;
	ejectionHatch.anim[DAMAGE_ANIM].repeat = false;
	ejectionHatch.position = { 196, 16 };
	ejectionHatch.collider = extraColliders[9] = App->collision->AddCollider({0,0, 60,32}, COLLIDER_ENEMY, (Module*)App->enemies);
	ejectionHatch.life = 40;
	// missiles platforms launchers anim
	missileLauncher.anim[NORMAL_ANIM].PushBack({ 459,66,64,32 });
	missileLauncher.anim[NORMAL_ANIM].PushBack({ 524,66,64,32 });
	missileLauncher.anim[NORMAL_ANIM].PushBack({ 589,66,64,32 });
	missileLauncher.anim[NORMAL_ANIM].PushBack({ 654,66,64,32 }); // max open
	missileLauncher.anim[NORMAL_ANIM].PushBack({ 589,66,64,32 }); // returning to 0 pos
	missileLauncher.anim[NORMAL_ANIM].PushBack({ 524,66,64,32 });
	missileLauncher.anim[NORMAL_ANIM].PushBack({ 459,66,64,32 });
	missileLauncher.anim[NORMAL_ANIM].speed = 0.125f;
	missileLauncher.anim[NORMAL_ANIM].repeat = false;
	// ---
	missileLauncher.anim[DAMAGE_ANIM].PushBack({ 459,99,64,32 });
	missileLauncher.anim[DAMAGE_ANIM].PushBack({ 524,99,64,32 });
	missileLauncher.anim[DAMAGE_ANIM].PushBack({ 589,99,64,32 });
	missileLauncher.anim[DAMAGE_ANIM].PushBack({ 654,99,64,32 }); // max open
	missileLauncher.anim[DAMAGE_ANIM].PushBack({ 589,99,64,32 });
	missileLauncher.anim[DAMAGE_ANIM].PushBack({ 524,99,64,32 });
	missileLauncher.anim[DAMAGE_ANIM].PushBack({ 459,99,64,32 }); // initial pos
	missileLauncher.anim[DAMAGE_ANIM].speed = 0.125f;
	missileLauncher.anim[DAMAGE_ANIM].repeat = false;
	missileLauncher.position = { 208, 48 };

	// ------------------------------------------------------------------------------------------------------------------
	// SUBMARINE TURRETS
	for (int i = 0; i < NUM_TURRETS; ++i)
	{
		submarineTurrets[i].anim[NORMAL_ANIM].PushBack({ 254,316,15,11 });
		submarineTurrets[i].anim[NORMAL_ANIM].PushBack({ 270,316,14,11 });
		submarineTurrets[i].anim[NORMAL_ANIM].PushBack({ 285,316,14,11 });
		submarineTurrets[i].anim[NORMAL_ANIM].PushBack({ 300,316,14,12 });
		submarineTurrets[i].anim[NORMAL_ANIM].PushBack({ 315,316,14,13 });
		submarineTurrets[i].anim[NORMAL_ANIM].PushBack({ 330,316,14,12 });
		submarineTurrets[i].anim[NORMAL_ANIM].PushBack({ 345,316,14,11 });
		submarineTurrets[i].anim[NORMAL_ANIM].PushBack({ 360,316,14,11 });
		submarineTurrets[i].anim[NORMAL_ANIM].PushBack({ 375,316,15,11 });
		submarineTurrets[i].anim[NORMAL_ANIM].speed = 0.125f;
		// ---
		submarineTurrets[i].anim[DAMAGE_ANIM].PushBack({ 254,302,15,11 });
		submarineTurrets[i].anim[DAMAGE_ANIM].PushBack({ 270,302,14,11 });
		submarineTurrets[i].anim[DAMAGE_ANIM].PushBack({ 285,302,14,11 });
		submarineTurrets[i].anim[DAMAGE_ANIM].PushBack({ 300,302,14,12 });
		submarineTurrets[i].anim[DAMAGE_ANIM].PushBack({ 315,302,14,13 });
		submarineTurrets[i].anim[DAMAGE_ANIM].PushBack({ 330,302,14,12 });
		submarineTurrets[i].anim[DAMAGE_ANIM].PushBack({ 345,302,14,11 });
		submarineTurrets[i].anim[DAMAGE_ANIM].PushBack({ 360,302,14,11 });
		submarineTurrets[i].anim[DAMAGE_ANIM].PushBack({ 375,302,15,11 });
		submarineTurrets[i].anim[DAMAGE_ANIM].speed = 0.125f;
		submarineTurrets[i].position = position + submarineTurretsPositions[i];

		// add colliders
		submarineTurrets[i].collider = extraColliders[i+13] = App->collision->AddCollider({ 0, 0, 14, 11 }, COLLIDER_ENEMY, (Module*)App->enemies);
	}
	// ------------------------------------------------------------------------------------------------------------------
	
	//animation = &nameAnim; //links animation
	
	// enemy data ----
	powerUpType = type;
	life = 140; // total core submarine life ( testing value, needs to be counted )
	enemyScore = 12000;
	// ---------------
	//fposition.x = x;
	//fposition.y = y;

	// body colliders (only damage the player/s)
	// full submarine base // 0,100,168,20
	fullBodyColliders[0] = extraColliders[10] = App->collision->AddCollider({0,100,456,20},COLLIDER_ENEMY, (Module*)App->enemies);
	// details
	fullBodyColliders[1] = extraColliders[11] = App->collision->AddCollider({ 0,100,24,20 }, COLLIDER_ENEMY, (Module*)App->enemies);

	coreCollider = extraColliders[12] = App->collision->AddCollider({ 0,0,48,24 }, COLLIDER_ENEMY, (Module*)App->enemies);


	// gameplay timers (testing block of code on constructor for the moment)
	start_ejectable_time = SDL_GetTicks();
	start_missiles_time = SDL_GetTicks();



	//position.x = -160;
	//position.x = 10;
	//position.y = 100;
}

void EnemySubmarine::Move()
{
	// movement calculations before colliders update positions --
	position.x += 1;
	fposition.x = position.x;
	fposition.y = position.y;
	// ----------------------------------------------------------

	// update colliders positions ---------------------------------------------------------------------

	for (int i = 0; i < NUM_NONDESTROYED_PARTS; ++i)
	{
		if (extraColliders[i] != nullptr)
		{
			if (i == 6)
				extraColliders[i]->SetPos(position.x + nonDestroyedParts[i].position.x, position.y + 72);
			else
				extraColliders[i]->SetPos(position.x + nonDestroyedParts[i].position.x, position.y + nonDestroyedParts[i].position.y);
		}
	}
	// ---
	// fullbody colliders
	fullBodyColliders[0]->SetPos(position.x, position.y + 84);
	fullBodyColliders[1]->SetPos(position.x + 168, position.y + 64);
	// ---
	// CORE collider 
	coreCollider->SetPos(position.x + 208, position.y + 24);
	// ejectionHatch collider
	if (ejectionHatch.collider != nullptr)
		ejectionHatch.collider->SetPos(position.x + ejectionHatch.position.x, position.y + ejectionHatch.position.y);
	
	// turrets collider
	for (int i = 0; i < NUM_TURRETS; ++i)
		if (submarineTurrets[i].collider != nullptr)
			submarineTurrets[i].collider->SetPos(position.x + submarineTurrets[i].position.x, position.y + submarineTurrets[i].position.y - 11 );
	
	// ----------------------------------------------------------------------------------------------
	// TURRETS movement and shooting logic

	goTurretsGo(); // angle calculations and animation desired frames
	//goTurretsAttack();
}

void EnemySubmarine::goTurretsGo()
{

	float distance = GetNearestPlayerSqrtDistance();
	float tx = NULL;
	float ty = NULL;

	for (int i = 0; i < NUM_TURRETS; ++i) // assigns animation frame
	{
		if (nearestTarget == nearestPlayer::P1)
		{
			tx = (position.x + submarineTurrets[i].position.x) - App->player[0]->position.x - 12;
			ty = (position.y + submarineTurrets[i].position.y) - App->player[0]->position.y + 6 ;

			submarineTurrets[i].angle = atan2f(ty, tx);

			//LOG("angle: %f", submarineTurrets[i].angle);
		}
		else if (nearestTarget == nearestPlayer::P2)
		{
			submarineTurrets[i].angle = atan2(ty, tx);
		}

		float AlphaCentaury = submarineTurrets[i].angle;

		if (AlphaCentaury < 0 || AlphaCentaury < 0.39f)
		{
			submarineTurrets[i].current_frame = 0;
		}
		if (AlphaCentaury > 0.39f && AlphaCentaury < 0.785f)
		{
			submarineTurrets[i].current_frame = 1;
		}
		if (AlphaCentaury > 0.785f && AlphaCentaury < 1.18f)
		{
			submarineTurrets[i].current_frame = 2;
		}
		if (AlphaCentaury > 1.18f && AlphaCentaury < 1.57f)
		{
			submarineTurrets[i].current_frame = 3;
		}
		if (AlphaCentaury > 1.57f && AlphaCentaury < 1.96f)
		{
			submarineTurrets[i].current_frame = 4;
		}
		if (AlphaCentaury > 1.96f && AlphaCentaury < 2.35f)
		{
			submarineTurrets[i].current_frame = 5;
		}
		if (AlphaCentaury > 2.35f && AlphaCentaury < 2.74f)
		{
			submarineTurrets[i].current_frame = 6;
		}
		if (AlphaCentaury > 2.74f && AlphaCentaury < 3.13f)
		{
			submarineTurrets[i].current_frame = 7;
		}
		if (AlphaCentaury > 3.13f && AlphaCentaury && AlphaCentaury < 3.52f)
		{
			submarineTurrets[i].current_frame = 8;
		}
	}
}

void EnemySubmarine::Draw()
{

	// ----------------------------------------------------------------------------------------------
	// SUBMARINE TURRETS DRAW
	//
	for (int i = 0; i < NUM_TURRETS; ++i)
	{
		if (!submarineTurrets[i].destroyed)
		{
			// damage timer
			submarineTurrets[i].now_damage_time = SDL_GetTicks() - submarineTurrets[i].start_damage_time;
			if (submarineTurrets[i].now_damage_time > submarineTurrets[i].damage_anim_time)
			{
				submarineTurrets[i].takenDamage = false;
			}

			// swap damage/normal sprites
			if (!submarineTurrets[i].takenDamage)
			{
				submarineTurrets[i].current_animation = &submarineTurrets[i].anim[NORMAL_ANIM];
				submarineTurrets[i].current_animation->current_frame = submarineTurrets[i].current_frame;

			}
			else
			{
				submarineTurrets[i].current_animation = &submarineTurrets[i].anim[DAMAGE_ANIM];
				submarineTurrets[i].current_animation->current_frame = submarineTurrets[i].current_frame;
			}

			// finally draw!
			submarineTurrets[i].rect = submarineTurrets[i].current_animation->GetCurrentFrame();

			App->render->Blit(enemyTex, position.x + submarineTurrets[i].position.x,
				position.y + submarineTurrets[i].position.y - submarineTurrets[i].rect.h, &submarineTurrets[i].rect);
		}
	}

	// ----------------------------------------------------------------------------------------------

	// draw full body without any destroyable part --------------------------------------------------
	App->render->Blit(enemyTex, position.x, position.y, &submarineBodyRect);
	// ----------------------------------------------------------------------------------------------

	// draw destroyed parts animations --------------------------------------------------------------
	for (int i = 0; i < NUM_DESTROYABLE_PARTS; ++i)
	{
		App->render->Blit(enemyTex, position.x + positionPartsX[i], position.y + positionPartsY[i], &destroyedParts[i].GetCurrentFrame());
	}

	// draw non destroyed static parts --------------------------------------------------------------
	for (int i = 0; i < NUM_NONDESTROYED_PARTS; ++i)
	{
		if (!nonDestroyedParts[i].destroyed)
		{
			// checks if the current part is the animated one and are in animated cycle ( only ejection hatch, missiles launcher is not relevant)
			//if (i == 5 && ejectionHatch.throwEnemy) continue; // ignore the draw

			App->render->Blit(enemyTex, position.x + nonDestroyedParts[i].position.x,
				position.y + nonDestroyedParts[i].position.y, &nonDestroyedParts[i].normalRect);
		}
	}

	// BODY and ALL PARTS damage sprite swap timer  ---------------------------------------------------------------------
	
	nowDamagetime = SDL_GetTicks() - start_damage_time;

	if (nowDamagetime > damageAnimTime)
	{
		receiveDamage = false;
		// deactivate missiles launchers damage too
		missileLauncher.takenDamage = false;
	}

	//if we are taken damage, print only the full body and the alive destroyable parts damage sprite --
	if (receiveDamage)
	{
		App->render->Blit(enemyTex, position.x, position.y, &submarineBodyDamageRect); // full body without destroyable parts

		for (int i = 0; i < NUM_NONDESTROYED_PARTS; ++i) // destroyable alive parts
		{
			if (!nonDestroyedParts[i].destroyed)
				App->render->Blit(enemyTex, position.x + nonDestroyedParts[i].position.x, 
					nonDestroyedParts[i].position.y + position.y, &nonDestroyedParts[i].takenDamageRect);
		}

		// missile launchers
		missileLauncher.takenDamage = true;
	}

	// -------------------------------------------------------------------------------------------------------------------

	// draw animated parts (ejectable hatch can be destroyed, but missile launchers not ----------------------------------

	// ejectable enemy timer and animation --------------------------------------------

	if (!ejectionHatch.destroyed)
	{
		// damage timer
		ejectionHatch.now_damage_time = SDL_GetTicks() - ejectionHatch.start_damage_time;
		if (ejectionHatch.now_damage_time > ejectionHatch.damage_anim_time)
		{
			ejectionHatch.takenDamage = false;
		}

		// swap damage/normal sprites
		if (!ejectionHatch.takenDamage)
		{
			ejectionHatch.current_animation = &ejectionHatch.anim[NORMAL_ANIM];
			ejectionHatch.current_animation->current_frame = ejectionHatch.current_frame;

		}
		else
		{
			ejectionHatch.current_animation = &ejectionHatch.anim[DAMAGE_ANIM];
			ejectionHatch.current_animation->current_frame = ejectionHatch.current_frame;
		}

		// ejectable timer ----
		now_ejectable_time = SDL_GetTicks() - start_ejectable_time;
		if (now_ejectable_time > ejectable_cadence_timer && ejectionHatch.readyToEject)
		{
			ejectionHatch.throwEnemy = true;
			LOG("throwing enemy");
			ejectionHatch.readyToEject = false;
		}
		// ------

		if (!ejectionHatch.throwEnemy)
		{
			ejectionHatch.rect = ejectionHatch.current_animation->frames[0];
		}
		else
		{
			ejectionHatch.rect = ejectionHatch.current_animation->GetCurrentFrame();
			if (ejectionHatch.current_animation->finish)
			{
				ejectionHatch.throwEnemy = false;
				LOG("stop enemy launching");
				start_ejectable_time = SDL_GetTicks();
				ejectionHatch.readyToEject = true;

				// reset damage and normal anim
				ejectionHatch.anim[NORMAL_ANIM].current_frame = 0;
				ejectionHatch.anim[NORMAL_ANIM].finish = false;
				ejectionHatch.anim[DAMAGE_ANIM].current_frame = 0;
				ejectionHatch.anim[DAMAGE_ANIM].finish = false;
			}
		}

		ejectionHatch.current_frame = ejectionHatch.current_animation->current_frame;

		App->render->Blit(enemyTex, position.x + ejectionHatch.position.x, position.y + ejectionHatch.position.y, &ejectionHatch.rect);

	}
	// ---------------------------------------------------------------------

	// ------------------------------------------------------------------------------------------------------------------ 

	// missile launchers

	if (!missileLauncher.destroyed)
	{
		now_missiles_time = SDL_GetTicks() - start_missiles_time;
		if (now_missiles_time > missiles_cadence_timer && missileLauncher.readyToEject)
		{
			missileLauncher.throwEnemy = true;
			LOG("throwing enemy MISSILES");
			missileLauncher.readyToEject = false;
		}

		// swap damage/normal sprites
		if (!missileLauncher.takenDamage)
		{
			missileLauncher.current_animation = &missileLauncher.anim[NORMAL_ANIM];
			missileLauncher.current_animation->current_frame = missileLauncher.current_frame;

		}
		else
		{
			missileLauncher.current_animation = &missileLauncher.anim[DAMAGE_ANIM];
			missileLauncher.current_animation->current_frame = missileLauncher.current_frame;
		}

		if (!missileLauncher.throwEnemy)
		{
			missileLauncher.rect = missileLauncher.current_animation->frames[0];
		}
		else
		{
			missileLauncher.rect = missileLauncher.current_animation->GetCurrentFrame();
			if (missileLauncher.current_animation->finish)
			{
				missileLauncher.throwEnemy = false;
				LOG("stop MISSILES enemy launching");
				start_missiles_time = SDL_GetTicks();
				missileLauncher.readyToEject = true;

				// reset damage and normal anim
				missileLauncher.anim[NORMAL_ANIM].current_frame = 0;
				missileLauncher.anim[NORMAL_ANIM].finish = false;
				missileLauncher.anim[DAMAGE_ANIM].current_frame = 0;
				missileLauncher.anim[DAMAGE_ANIM].finish = false;
			}
		}

		missileLauncher.current_frame = missileLauncher.current_animation->current_frame;

		App->render->Blit(enemyTex, position.x + missileLauncher.position.x, position.y + missileLauncher.position.y, &missileLauncher.rect);
	}

	

	// -----------------------------------------------------------------------------------------------
}

void EnemySubmarine::OnCollision(Collider* collider, Collider* collider2)
{
	// taken damage, submarine BODY and ALL PARTS only takes damage and plays damage animation when the core is reached/damaged
	if (collider2 == coreCollider && !receiveDamage)
	{
		receiveDamage = true;
		start_damage_time = SDL_GetTicks();
		life -= collider->damage; // substract the damage taken by the damage amount of particle/collider associated to core life
	}

	// taken damage for TURRETS
	for (int i = 0; i < NUM_TURRETS; ++i)
	{
		if (collider2 == submarineTurrets[i].collider)
		{
			if (readyToRumble && collider->type == COLLIDER_UNIT) // collisions logic for unit orbit
			{
				LOG("TURRET %d RECEIVING DAMAGE", i + 1);

				submarineTurrets[i].takenDamage = true;
				submarineTurrets[i].start_damage_time = SDL_GetTicks();
				submarineTurrets[i].life -= collider->damage;
			}
			else if (collider->type != COLLIDER_UNIT)
			{
				submarineTurrets[i].takenDamage = true;
				submarineTurrets[i].life -= collider->damage;
				submarineTurrets[i].start_damage_time = SDL_GetTicks();
			}

		}
	}

	// taken damage for ejection hatch
	if (collider2 == ejectionHatch.collider)//nonDestroyedParts[5].collider)
	{
		
		
		LOG("ejectionHatch damaged");

		if (readyToRumble && collider->type == COLLIDER_UNIT) // if the collider is the Unit and is ready to already take damage of it
		{
			ejectionHatch.life -= collider->damage; // substract collider unit charged/normal damage
			ejectionHatch.takenDamage = true;
			ejectionHatch.start_damage_time = SDL_GetTicks();

		}
		else if (collider->type != COLLIDER_UNIT)
		{
			ejectionHatch.life -= collider->damage;
			ejectionHatch.takenDamage = true;
			ejectionHatch.start_damage_time = SDL_GetTicks();
		}

		if (ejectionHatch.life <= 0)
		{
			ejectionHatch.destroyed = true;
			ejectionHatch.collider->to_delete = true;
			ejectionHatch.collider = nullptr;
			extraColliders[9] = nullptr; // 9 is the extraCollider associated with the ejection hatch collider

			// play audio fx
			App->audio->ControlAudio("EnemyDeath", SFX, PLAY);
			// instantiate explosion particle
			App->particles->AddParticle(App->particles->explosion, position.x + ejectionHatch.position.x + 60 / 2,
				position.y + ejectionHatch.position.y, COLLIDER_NONE);

		}
		else
		{
			// instantiate bullet impact particle 
		}
	}

	// STATIC DESTROYABLE PARTS ----------------------------------------------------------------------------------------------------------
	// substract life to each static part
	for (int i = 0; i < NUM_NONDESTROYED_PARTS ; ++i)
	{
		//if (extraColliders[i] == nullptr) 
			//continue;

		if (collider2 == nonDestroyedParts[i].collider) // destroyable static parts
		{
			if (readyToRumble && collider->type == COLLIDER_UNIT) // if the collider is the Unit and is ready to already take damage of it
				nonDestroyedParts[i].life -= collider->damage; // substract collider unit charged/normal damage
			else if (collider->type != COLLIDER_UNIT)
				nonDestroyedParts[i].life -= collider->damage;

			if (nonDestroyedParts[i].life <= 0)
			{
				nonDestroyedParts[i].destroyed = true;
				extraColliders[i]->to_delete = true;
				extraColliders[i] = nullptr;
				nonDestroyedParts[i].collider = nullptr;

				// play audio fx
				App->audio->ControlAudio("EnemyDeath", SFX, PLAY);
				// instantiate explosion particle
				App->particles->AddParticle(App->particles->explosion, position.x + nonDestroyedParts[i].position.x + nonDestroyedParts[i].normalRect.w / 2, 
					position.y + nonDestroyedParts[i].position.y, COLLIDER_NONE);

			}
			else
			{
				// instantiate bullet impact particle 
			}

		
		}
	}
}

const Collider* EnemySubmarine::GetCollider() const
{
	return extraColliders[collisionColliderIndex];
}

EnemySubmarine::~EnemySubmarine()
{
	if (collider != nullptr)
	{
		collider->to_delete = true;

		

		if (life <= 0) //only spawn powerup if the enemy is really death
		{
			//position.y -= 30;
			//position.x += 16;
			//App->player[0]->playerScore += enemyScore;
			//App->particles->AddParticle(App->particles->explosion, position.x - 8, position.y, COLLIDER_NONE);
			//collider = nullptr; //avoid double enemy destructor heritance
		}

		//delete this->enemyTex;
		//enemyTex = nullptr;
	}

	for (int i = 0; i < MAX_EXTRA_COLLIDERS; ++i) // delete extra colliders
	{
		if (extraColliders[i] != nullptr)
		{
			extraColliders[i]->to_delete = true;
			extraColliders[i] = nullptr;
		}
	}
	for (int i = 0; i < 2; ++i) // delete full body colliders
	{
		if (fullBodyColliders[i] != nullptr)
		{
			fullBodyColliders[i]->to_delete = true;
			fullBodyColliders[i] = nullptr;
		}

	}

}