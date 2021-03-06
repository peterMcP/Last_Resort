#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModulePlayerUnit.h"
#include "ModuleParticles.h"
#include "ModulePowerUp.h"
#include "ModuleAudio.h"

#include "SDL\include\SDL_timer.h"

#define UNITANIMSPEED 0.25f

ModulePlayerUnit::ModulePlayerUnit()
{
	//needed rects for animations

	//animation 8 extra axis
	playerUnitAnim[15].PushBack({ 88,212,22,17 });
	playerUnitAnim[15].PushBack({ 66,212 , 22,17 });
	playerUnitAnim[15].PushBack({ 44,212 , 22,17 });
	playerUnitAnim[15].PushBack({ 22,212 , 22,17 });
	playerUnitAnim[15].PushBack({ 0,212 , 22,17 });
	playerUnitAnim[15].PushBack({ 229,189 , 22,17 });
	playerUnitAnim[15].PushBack({ 207,189 , 22,17 });
	playerUnitAnim[15].PushBack({ 185,189 , 22,17 });
	playerUnitAnim[15].speed = UNITANIMSPEED; //original framerate update
	//animation 8 basic axis
	playerUnitAnim[14].PushBack({ 164,189 , 21,21 });
	playerUnitAnim[14].PushBack({ 143,189 , 21,21 });
	playerUnitAnim[14].PushBack({ 122,189 , 21,21 });
	playerUnitAnim[14].PushBack({ 101,189 , 21,21 });
	playerUnitAnim[14].PushBack({ 80,189 , 21,21 });
	playerUnitAnim[14].PushBack({ 59,189 , 21,21 });
	playerUnitAnim[14].PushBack({ 38,189 , 21,21 });
	playerUnitAnim[14].PushBack({ 17,189 , 21,21 });
	playerUnitAnim[14].speed = UNITANIMSPEED;
	//animation 7 extra axis
	playerUnitAnim[13].PushBack({ 0,189 , 17,23 });
	playerUnitAnim[13].PushBack({ 230,166 , 17,23 });
	playerUnitAnim[13].PushBack({ 213,166 , 17,23 });
	playerUnitAnim[13].PushBack({ 196,166 , 17,23 });
	playerUnitAnim[13].PushBack({ 179,166 , 17,23 });
	playerUnitAnim[13].PushBack({ 162,166 , 17,23 });
	playerUnitAnim[13].PushBack({ 145,166 , 17,23 });
	playerUnitAnim[13].PushBack({ 128,166 , 17,23 });
	playerUnitAnim[13].speed = UNITANIMSPEED;
	//animation 7 basic axis
	playerUnitAnim[12].PushBack({ 112,166 , 16,22 });
	playerUnitAnim[12].PushBack({ 96,166 , 16,22 });
	playerUnitAnim[12].PushBack({ 80,166 , 16,22 });
	playerUnitAnim[12].PushBack({ 64,166 , 16,22 });
	playerUnitAnim[12].PushBack({ 48,166 , 16,22 });
	playerUnitAnim[12].PushBack({ 32,166 , 16,22 });
	playerUnitAnim[12].PushBack({ 16,166 , 16,22 });
	playerUnitAnim[12].PushBack({ 0,166 , 16,22 });
	playerUnitAnim[12].speed = UNITANIMSPEED;
	//animation 6 extra axis
	playerUnitAnim[11].PushBack({ 224,143 , 17,23 });
	playerUnitAnim[11].PushBack({ 207,143 , 17,23 });
	playerUnitAnim[11].PushBack({ 190,143 , 17,23 });
	playerUnitAnim[11].PushBack({ 173,143 , 17,23 });
	playerUnitAnim[11].PushBack({ 156,143 , 17,23 });
	playerUnitAnim[11].PushBack({ 139,143 , 17,23 });
	playerUnitAnim[11].PushBack({ 122,143 , 17,23 });
	playerUnitAnim[11].PushBack({ 105,143 , 17,23 });
	playerUnitAnim[11].speed = UNITANIMSPEED;
	//animation 6 basic axis
	playerUnitAnim[10].PushBack({ 84,143 , 21,21 });
	playerUnitAnim[10].PushBack({ 63,143 , 21,21 });
	playerUnitAnim[10].PushBack({ 42,143 , 21,21 });
	playerUnitAnim[10].PushBack({ 21,143 , 21,21 });
	playerUnitAnim[10].PushBack({ 0,143 , 21,21 });
	playerUnitAnim[10].PushBack({ 218,122 , 21,21 });
	playerUnitAnim[10].PushBack({ 197,122 , 21,21 });
	playerUnitAnim[10].PushBack({ 176,122 , 21,21 });
	playerUnitAnim[10].speed = UNITANIMSPEED;
	//animation 5 extra axis
	playerUnitAnim[9].PushBack({ 154,122 , 22,17 });
	playerUnitAnim[9].PushBack({ 132,122 , 22,17 });
	playerUnitAnim[9].PushBack({ 110,122 , 22,17 });
	playerUnitAnim[9].PushBack({ 88,122 , 22,17 });
	playerUnitAnim[9].PushBack({ 66,122 , 22,17 });
	playerUnitAnim[9].PushBack({ 44,122 , 22,17 });
	playerUnitAnim[9].PushBack({ 22,122 , 22,17 });
	playerUnitAnim[9].PushBack({ 0,122 , 22,17 });
	playerUnitAnim[9].speed = UNITANIMSPEED;
	//animation 5 basic axis
	playerUnitAnim[8].PushBack({ 220,105 , 22,16 });
	playerUnitAnim[8].PushBack({ 198,105 , 22,16 });
	playerUnitAnim[8].PushBack({ 176,105 , 22,16 });
	playerUnitAnim[8].PushBack({ 154,105 , 22,16 });
	playerUnitAnim[8].PushBack({ 132,105 , 22,16 });
	playerUnitAnim[8].PushBack({ 110,105 , 22,16 });
	playerUnitAnim[8].PushBack({ 88, 105 , 22,16 });
	playerUnitAnim[8].PushBack({ 66,105 , 22,16 });
	playerUnitAnim[8].speed = UNITANIMSPEED;
	//animation 4 extra axis
	playerUnitAnim[7].PushBack({ 44,105 , 22,17 });
	playerUnitAnim[7].PushBack({ 22,105 , 22,17 });
	playerUnitAnim[7].PushBack({ 0,105 , 22,17 });
	playerUnitAnim[7].PushBack({ 214,84 , 22,17 });
	playerUnitAnim[7].PushBack({ 192,84 , 22,17 });
	playerUnitAnim[7].PushBack({ 170,84 , 22,17 });
	playerUnitAnim[7].PushBack({ 148,84 , 22,17 });
	playerUnitAnim[7].PushBack({ 126,84 , 22,17 });
	playerUnitAnim[7].speed = UNITANIMSPEED;
	//animation 4 basic axis
	playerUnitAnim[6].PushBack({ 105,84 , 21,21 });
	playerUnitAnim[6].PushBack({ 84,84 , 21,21 });
	playerUnitAnim[6].PushBack({ 63,84 , 21,21 });
	playerUnitAnim[6].PushBack({ 42,84 , 21,21 });
	playerUnitAnim[6].PushBack({ 21,84 , 21,21 });
	playerUnitAnim[6].PushBack({ 0,84 , 21,21 });
	playerUnitAnim[6].PushBack({ 221,61 , 21,21 });
	playerUnitAnim[6].PushBack({ 200,61 , 21,21 });
	playerUnitAnim[6].speed = UNITANIMSPEED;
	//animation 3 extra axis
	playerUnitAnim[5].PushBack({ 183,61 , 17,23 });
	playerUnitAnim[5].PushBack({ 166,61 , 17,23 });
	playerUnitAnim[5].PushBack({ 149,61 , 17,23 });
	playerUnitAnim[5].PushBack({ 132,61 , 17,23 });
	playerUnitAnim[5].PushBack({ 115,61 , 17,23 });
	playerUnitAnim[5].PushBack({ 98,61 , 17,23 });
	playerUnitAnim[5].PushBack({ 81,61 , 17,23 });
	playerUnitAnim[5].PushBack({ 64,61 , 17,23 });
	playerUnitAnim[5].speed = UNITANIMSPEED;
	//animation 3 basic axis (pointing UP)
	playerUnitAnim[4].PushBack({ 48,61 , 16,22 });
	playerUnitAnim[4].PushBack({ 32,61 , 16,22 });
	playerUnitAnim[4].PushBack({ 16,61 , 16,22 });
	playerUnitAnim[4].PushBack({ 0,61 , 16,22 });
	playerUnitAnim[4].PushBack({ 226,38 , 16,22 });
	playerUnitAnim[4].PushBack({ 210,38 , 16,22 });
	playerUnitAnim[4].PushBack({ 194,38 , 16,22 });
	playerUnitAnim[4].PushBack({ 178,38 , 16,22 });
	playerUnitAnim[4].speed = UNITANIMSPEED;
	//animation 2 extra axis
	playerUnitAnim[3].PushBack({ 161,38 , 17,23 });
	playerUnitAnim[3].PushBack({ 144,38 , 17,23 });
	playerUnitAnim[3].PushBack({ 127,38 , 17,23 });
	playerUnitAnim[3].PushBack({ 110,38 , 17,23 });
	playerUnitAnim[3].PushBack({ 93,38 , 17,23 });
	playerUnitAnim[3].PushBack({ 76,38 , 17,23 });
	playerUnitAnim[3].PushBack({ 59,38 , 17,23 });
	playerUnitAnim[3].PushBack({ 42,38 , 17,23 });
	playerUnitAnim[3].speed = UNITANIMSPEED;
	//animation 2 basic axis
	playerUnitAnim[2].PushBack({ 21,38 , 21,21 });
	playerUnitAnim[2].PushBack({ 0,38 , 21,21 });
	playerUnitAnim[2].PushBack({ 215,17 , 21,21 });
	playerUnitAnim[2].PushBack({ 194,17 , 21,21 });
	playerUnitAnim[2].PushBack({ 173,17 , 21,21 });
	playerUnitAnim[2].PushBack({ 152,17 , 21,21 });
	playerUnitAnim[2].PushBack({ 131,17 , 21,21 });
	playerUnitAnim[2].PushBack({ 110,17 , 21,21 });
	playerUnitAnim[2].speed = UNITANIMSPEED;
	//animation 1 extra axis
	playerUnitAnim[1].PushBack({ 88,17 , 22,17 });
	playerUnitAnim[1].PushBack({ 66,17 , 22,17 });
	playerUnitAnim[1].PushBack({ 44,17 , 22,17 });
	playerUnitAnim[1].PushBack({ 22,17 , 22,17 });
	playerUnitAnim[1].PushBack({ 0,17 , 22,17 });
	playerUnitAnim[1].PushBack({ 220,0 , 22,17 });
	playerUnitAnim[1].PushBack({ 198,0 , 22,17 });
	playerUnitAnim[1].PushBack({ 176,0 , 22,17 });
	playerUnitAnim[1].speed = UNITANIMSPEED;
	//Animation 1 basic axis (pointing right (animation 1 (spawn animation cycle))
	playerUnitAnim[0].PushBack({ 154,0 , 22,16 });
	playerUnitAnim[0].PushBack({ 132,0 , 22,16 });
	playerUnitAnim[0].PushBack({ 110,0 , 22,16 });
	playerUnitAnim[0].PushBack({ 88,0 , 22,16 });
	playerUnitAnim[0].PushBack({ 66,0 , 22,16 });
	playerUnitAnim[0].PushBack({ 44,0 , 22,16 });
	playerUnitAnim[0].PushBack({ 22,0 , 22,16 });
	playerUnitAnim[0].PushBack({ 0,0 , 22,16 });
	playerUnitAnim[0].speed = UNITANIMSPEED;

	//charging and free animation
	freeAnim.PushBack({ 0, 0, 22, 22 });
	freeAnim.PushBack({ 22, 0, 24, 24 });
	freeAnim.PushBack({ 46, 0, 26, 26 });
	freeAnim.PushBack({ 72, 0, 24, 24 });
	freeAnim.PushBack({ 96, 0, 22, 22 });
	freeAnim.PushBack({ 118, 0, 20, 20 });
	freeAnim.PushBack({ 138, 0, 18, 18 });
	freeAnim.PushBack({ 156, 0, 20, 20 });
	freeAnim.speed = 0.33f;
	// ----
	//chargingAnim.PushBack({ 0, 0, 22, 22 });
	chargingAnim.PushBack({ 184, 86, 36, 36 });
	chargingAnim.PushBack({ 152, 86, 32, 32 });
	chargingAnim.PushBack({ 120, 86, 32, 32 });
	chargingAnim.PushBack({ 92, 86, 28, 28 });
	chargingAnim.PushBack({ 64, 86, 28, 28 });
	chargingAnim.PushBack({ 32, 86, 32, 32 });
	chargingAnim.PushBack({ 0, 86, 32, 32 });
	chargingAnim.PushBack({ 220, 41, 30, 30 });
	chargingAnim.PushBack({ 190, 41, 30, 30 });
	chargingAnim.PushBack({ 162, 41, 28, 27 });
	chargingAnim.PushBack({ 134, 41, 28, 27 });
	chargingAnim.PushBack({ 88, 41, 46, 45 });
	chargingAnim.PushBack({ 42, 41, 46, 45 });
	chargingAnim.PushBack({ 0, 41, 42, 41 });
	chargingAnim.PushBack({ 176,  0, 42, 41 });
	chargingAnim.speed = 0.5f;
	
	// trails animations ----------------------------
	// trail 1
	trailsData[0].anim.PushBack({ 0,124,24,24 });
	trailsData[0].anim.PushBack({ 0,0,0,0 });
	trailsData[0].anim.PushBack({ 25,124,24,23 });
	trailsData[0].anim.PushBack({ 0,0,0,0 });
	trailsData[0].anim.PushBack({ 50,124,24,24 });
	trailsData[0].anim.PushBack({ 0,0,0,0 });
	trailsData[0].anim.PushBack({ 75,124,-23,-24 });
	trailsData[0].anim.PushBack({ 0,0,0,0 });
	trailsData[0].anim.PushBack({ 0,124,-24,-24 });
	trailsData[0].anim.PushBack({ 0,0,0,0 });
	trailsData[0].anim.PushBack({ 25,124,-24,-23 });
	trailsData[0].anim.PushBack({ 0,0,0,0 });
	trailsData[0].anim.PushBack({ 50,124,-24,-24 });
	trailsData[0].anim.PushBack({ 0,0,0,0 });
	trailsData[0].anim.PushBack({ 75,124,23,24 });
	trailsData[0].anim.speed = 0.5f;

	// trail 2
	trailsData[1].anim.PushBack({ 0,150,28,26 });
	trailsData[1].anim.PushBack({ 0,0,0,0 });
	trailsData[1].anim.PushBack({ 29,150,28,28 });
	trailsData[1].anim.PushBack({ 0,0,0,0 });
	trailsData[1].anim.PushBack({ 59,150,26,28 });
	trailsData[1].anim.PushBack({ 0,0,0,0 });
	trailsData[1].anim.PushBack({ 86,150,-28,-28 });
	trailsData[1].anim.PushBack({ 0,0,0,0 });
	trailsData[1].anim.PushBack({ 0,150,-28,-26 });
	trailsData[1].anim.PushBack({ 0,0,0,0 });
	trailsData[1].anim.PushBack({ 29,150,-28,-28 });
	trailsData[1].anim.PushBack({ 0,0,0,0 });
	trailsData[1].anim.PushBack({ 59,150,-26,-28 });
	trailsData[1].anim.PushBack({ 0,0,0,0 });
	trailsData[1].anim.PushBack({ 86,150,28,28 });
	trailsData[1].anim.speed = 0.5f;

	// trail 3
	trailsData[2].anim.PushBack({ 0,181,32,30 });
	trailsData[2].anim.PushBack({ 0,0,0,0 });
	trailsData[2].anim.PushBack({ 33,181,32,32 });
	trailsData[2].anim.PushBack({ 0,0,0,0 });
	trailsData[2].anim.PushBack({ 66,181,30,32 });
	trailsData[2].anim.PushBack({ 0,0,0,0 });
	trailsData[2].anim.PushBack({ 97,181,32,32 });
	trailsData[2].anim.PushBack({ 0,0,0,0 });
	trailsData[2].anim.PushBack({ 0,181,-32,-30 });
	trailsData[2].anim.PushBack({ 0,0,0,0 });
	trailsData[2].anim.PushBack({ 33,181,-32,-32 });
	trailsData[2].anim.PushBack({ 0,0,0,0 });
	trailsData[2].anim.PushBack({ 66,181,-30,-32 });
	trailsData[2].anim.PushBack({ 0,0,0,0 });
	trailsData[2].anim.PushBack({ 97,181,-32,-32 });
	trailsData[2].anim.speed = 0.5f;

	// trail 4
	trailsData[3].anim.PushBack({ 0,216,32,32 });
	trailsData[3].anim.PushBack({ 0,0,0,0 });
	trailsData[3].anim.PushBack({ 33,216,28,32 });
	trailsData[3].anim.PushBack({ 0,0,0,0 });
	trailsData[3].anim.PushBack({ 64,216,32,32 });
	trailsData[3].anim.PushBack({ 0,0,0,0 });
	trailsData[3].anim.PushBack({ 98,216,32,28 });
	trailsData[3].anim.PushBack({ 0,0,0,0 });
	trailsData[3].anim.PushBack({ 0,216,-32,-32 });
	trailsData[3].anim.PushBack({ 0,0,0,0 });
	trailsData[3].anim.PushBack({ 33,216,-28,-32 });
	trailsData[3].anim.PushBack({ 0,0,0,0 });
	trailsData[3].anim.PushBack({ 64,216,-32,-32 });
	trailsData[3].anim.PushBack({ 0,0,0,0 });
	trailsData[3].anim.PushBack({ 98,216,-32,-28 });
	trailsData[3].anim.speed = 0.5f;
	


}

ModulePlayerUnit::~ModulePlayerUnit() {}

/*bool ModulePlayerUnit::Init()
{

	return true;
}*/

bool ModulePlayerUnit::Start()
{
	LOG("Starting playerUnit Module");

	//Audio
	App->audio->LoadAudio("assets/Audio/SFX/player/Fix_Unit.wav", "UnitLocked", SFX);
	App->audio->LoadAudio("assets/audio/SFX/player/Unfix_Unit.wav", "UnitUnlocked", SFX);
	App->audio->LoadAudio("assets/audio/SFX/player/chargingUnit.wav", "charging", SFX);
	App->audio->LoadAudio("assets/audio/SFX/player/releasingUnit.wav", "released", SFX);
	App->audio->LoadAudio("assets/audio/SFX/player/unit_collider.wav", "unitCollider", SFX);

	//delta calculations
	orbitSpeed = 1.0f;
	last_tick = 0;

	//links the animation to 0 index at every module Start
	angle = 0;
	currentUnitAnim = &playerUnitAnim[0];
	frameIncrement = 0; //starts at 0 index pos (spawn direction animation)

	unitLocked = false; //locks or unlocks circular movement

	//re assign needed values to position 0 when start/ re start

	this_state = actualState::LINKED;

	//add unit colliders
	if (this == App->playerUnit[0])
	{
		unitColliders[0] = upCollider = App->collision->AddCollider({ 0,0,1,1 }, COLLIDER_UNIT, this, unitDamage); // 0,0,6,8
		unitColliders[1] = downCollider = App->collision->AddCollider({ 0,0,1,1 }, COLLIDER_UNIT, this, unitDamage);
		unitColliders[2] = rightCollider = App->collision->AddCollider({ 0,0,1,1 }, COLLIDER_UNIT, this, unitDamage); // 0,0,5,6
		unitColliders[3] = leftCollider = App->collision->AddCollider({ 0,0,1,1 }, COLLIDER_UNIT, this, unitDamage);
		unitColliders[4] = centerCollider = App->collision->AddCollider({ 0,0,12,12 }, COLLIDER_UNIT, this, unitDamage);
	}
	else if (this == App->playerUnit[1])
	{
		unitColliders[0] = upCollider = App->collision->AddCollider({ 0,0,1,1 }, COLLIDER_UNIT2, this, unitDamage); // 0,0,6,8
		unitColliders[1] = downCollider = App->collision->AddCollider({ 0,0,1,1 }, COLLIDER_UNIT2, this, unitDamage);
		unitColliders[2] = rightCollider = App->collision->AddCollider({ 0,0,1,1 }, COLLIDER_UNIT2, this, unitDamage); // 0,0,5,6
		unitColliders[3] = leftCollider = App->collision->AddCollider({ 0,0,1,1 }, COLLIDER_UNIT2, this, unitDamage);
		unitColliders[4] = centerCollider = App->collision->AddCollider({ 0,0,12,12 }, COLLIDER_UNIT2, this, unitDamage);
	}

	

	return true;
}

update_status ModulePlayerUnit::PreUpdate()
{
	collisioned = false;

	if (this_state == actualState::LINKED || this_state == actualState::POSITIONING)
	{

		//locks and unlocks unit movement control
		if (App->player[playerIndex]->playerInput.lockUnit && this_state != actualState::POSITIONING)//App->input->keyboard[SDL_SCANCODE_LSHIFT] == KEY_STATE::KEY_DOWN)
		{
			if (unitLocked)
			{
				unitLocked = false;
				App->audio->ControlAudio("UnitUnlocked", SFX, PLAY);
			}
			else
			{
				unitLocked = true;
				App->audio->ControlAudio("UnitLocked", SFX, PLAY);
			}
		}

		//PlayerUnit movement logic and input -----------------------------------------------------------------

			//angle += orbit_speed * delta_time;
			//x = center_x + radius * cos(angle);
			//y = center_y + radius * sin(angle);

		Uint32 tick_now = SDL_GetTicks();
		if (tick_now > last_tick)
		{
			delta_time = tick_now - last_tick;
			last_tick = tick_now;
		}

		//y height ball distante to player pos up and down = 18
		//x width unit right and left = 8

		//if the unit is not locked, permits movement calculations
		if (!unitLocked)
		{

			orbitSpeed = 6.5f;

			//linear moves ----------------------------------------------------------------------------------------

			if (App->player[playerIndex]->playerInput.moveLeft &&//App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT &&
				!App->player[playerIndex]->playerInput.moveDown &&//App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE &&
				!App->player[playerIndex]->playerInput.moveUp)//App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE) //constrains upper left diagonal case
			{
				if (angle >= 3.14f)
				{
					angle += (int)orbitSpeed * (delta_time / 1000);
				}
				if (angle < 3.14f && angle >= 0) //returns upwards
				{
					angle -= (int)orbitSpeed * (delta_time / 1000);
				}
			}

			if (App->player[playerIndex]->playerInput.moveRight &&//App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT && //if right
				!App->player[playerIndex]->playerInput.moveLeft &&//App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE &&   //and not left (original opposite direction priority)
				!App->player[playerIndex]->playerInput.moveUp &&//App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE &&   //and not up (diagonal case)
				!App->player[playerIndex]->playerInput.moveDown)//App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE)     //and not down right
			{
				if (angle > 3.14f && angle < 6.28f)
				{
					angle -= (int)orbitSpeed * (delta_time / 1000);
				}
				if (angle < 3.14f)
				{
					angle += (int)orbitSpeed * (delta_time / 1000);
				}

			}

			if (angle >= 6.28f) angle = 0;
			else if (angle < 0) angle = 6.28f; //if we go under 0, full circle

			if (App->player[playerIndex]->playerInput.moveUp &&//App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT &&
				!App->player[playerIndex]->playerInput.moveDown &&//App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE   && //constrains original opposite up and down case
				!App->player[playerIndex]->playerInput.moveRight &&//App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_IDLE   &&
				!App->player[playerIndex]->playerInput.moveLeft)//App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE)    //constrains upper left diagonal case
			{

				if (angle < 1.57f && angle >= 0) //|| angle > 4.71f) //separated to avoid clack
				{
					angle -= (int)orbitSpeed * (delta_time / 1000);
				}
				//force the check to avoid mini Nicolas
				if (angle < 0) angle = 6.28f; //if we go under 0, full circle

				if (angle > 4.71f) //separate check to workaround mini Nicolas
				{
					angle -= (int)orbitSpeed * (delta_time / 1000);
				}

				if (angle >= 1.57f && angle <= 4.71)
				{
					angle += (int)orbitSpeed * (delta_time / 1000);
				}
			}

			if (App->player[playerIndex]->playerInput.moveDown &&//App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT &&
				!App->player[playerIndex]->playerInput.moveLeft &&//App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE && //constrains diagonal down and left
				!App->player[playerIndex]->playerInput.moveRight)//App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_IDLE) //constrains diagonal down and right
			{
				if (angle > 1.57f && angle < 4.71f)
				{
					angle -= (int)orbitSpeed * (delta_time / 1000);
				}

				if (angle < 1.57f && angle >= 0 || angle >= 4.71f)
				{
					angle += (int)orbitSpeed * (delta_time / 1000);
				}
			}
			// ------------------------------------------------------------------------------------------------

			//diagonal moves ----------------------------------------------------------------------------------

			//down and left case
			if (App->player[playerIndex]->playerInput.moveDown &&//App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT &&
				App->player[playerIndex]->playerInput.moveLeft)//App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
			{
				if (angle > (1.25f * 3.14f) && angle > 0)//4.71f && angle > 0)
				{
					angle += (int)orbitSpeed * (delta_time / 1000);
				}
				if (angle < 1.57f && angle >= 0 && angle < 1.57f / 2)
				{
					angle += (int)orbitSpeed * (delta_time / 1000);
				}
				if (angle < (1.25f * 3.14f) && angle > 1.57f / 2)
				{
					angle -= (int)orbitSpeed * (delta_time / 1000);
				}
			}

			//down and right case
			if (App->player[playerIndex]->playerInput.moveDown &&//App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT &&
				App->player[playerIndex]->playerInput.moveRight)//App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
			{
				if (angle > (1.75f * 3.14f) && angle > 0)
				{
					angle += (int)orbitSpeed * (delta_time / 1000);
				}
				if (angle < 0.75f * 3.14f) //(3/4*pi) quadrant
				{
					angle += (int)orbitSpeed * (delta_time / 1000);
				}
				if (angle < (1.75f * 3.14f) && angle >(0.75f * 3.14f))
				{
					angle -= (int)orbitSpeed * (delta_time / 1000);
				}
			}

			//up and left case
			if (App->player[playerIndex]->playerInput.moveUp &&//App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT &&
				App->player[playerIndex]->playerInput.moveLeft)//App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
			{
				if (angle < (0.75f * 3.14f) && angle >= 0)
				{
					angle -= (int)orbitSpeed * (delta_time / 1000);
				}

				if (angle >= 6.28f) angle = 0; //force check to avoid Nicolas
				else if (angle < 0) angle = 6.28f; //if we go under 0, full circle

				if (angle <= 0 || angle > (1.75f * 3.14f)) // 7/4*pi quadrant
				{
					angle -= (int)orbitSpeed * (delta_time / 1000);
				}
				if (angle > (0.75f* 3.14f) && angle < (1.75f * 3.14f))
				{
					angle += (int)orbitSpeed * (delta_time / 1000);
				}
			}

			//up and right case
			if (App->player[playerIndex]->playerInput.moveUp &&//App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT &&
				App->player[playerIndex]->playerInput.moveRight)//App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
			{
				if (angle > (1.75f / 2) && angle < 1.25f * 3.14f)
				{
					angle += (int)orbitSpeed * (delta_time / 1000);
				}
				if (angle <= (1.75f / 2) && angle > 0)
				{
					angle -= (int)orbitSpeed * (delta_time / 1000);
				}
				if (angle < 0) angle = 6.28f; //if we go under 0, full circle
											  //if (angle >= 6.28f) angle = 0; //force check to avoid Nicolas
				if (angle <= 6.28f && angle > (1.25f * 3.14f))
				{
					angle -= (int)orbitSpeed * (delta_time / 1000);
				}

			}
		}

		// -------------------------------------------------------------------------------------------------
	}
	else if (this_state == actualState::FREE && this_state != actualState::GRINDING) // only on unit blue
	{
		// call movement calculations

		posX += vx + 1;
		posY -= vy;

		playerPos.x = posX;
		playerPos.y = posY;

		//time
		now = SDL_GetTicks() - start_boomerang_time;

		if (now >= max_boomerang_time)
		{
			this_state = actualState::RETURN;
			LOG("Returning");
		}

	}
	else if (this_state == actualState::GRINDING) // only on unit Orange
	{
		//time
		now = SDL_GetTicks() - start_boomerang_time;

		if (now >= max_boomerang_time)
		{
			this_state = actualState::RETURN;

			// reset grinding states
			//grinding_state = grindingState::NO_GRIND;
			//first_grinding_state = grindingState::NO_GRIND;
			LOG("Returning");
		}
		else
		 grinding();

		
	}
	else if (this_state == actualState::RETURN)
	{
		// check collider states and turn off all for next throw
	    if (collisionStates.downCollision) collisionStates.downCollision = false;
		if (collisionStates.upCollision) collisionStates.upCollision = false;
		if (collisionStates.rightCollision) collisionStates.rightCollision = false;
		if (collisionStates.leftCollision) collisionStates.leftCollision = false;

		int tx = (App->player[playerIndex]->position.x + 9) - (playerPos.x);
		int ty = (App->player[playerIndex]->position.y - 4) - (playerPos.y);
		
		fPoint playerDistance;
		playerDistance.x = App->player[playerIndex]->position.x;
		playerDistance.y = App->player[playerIndex]->position.y;

		fPoint thisPosition;
		thisPosition.x = playerPos.x;
		thisPosition.y = playerPos.y;

		//get sqrt distance
		float distance = thisPosition.DistanceTo(playerDistance);

		velX = (tx / distance)*unitBoomerangSpeed;
		velY = (ty / distance)*unitBoomerangSpeed;

		playerPos.x += velX + 1;
		playerPos.y += velY;

		if (distance <= 20)
			this_state = actualState::POSITIONING;

	}

	// trails movement calculations  ---------------------------------------------------
	if (this_state != actualState::LINKED)
	{

		// positions -----
		//first trail: linked to unit, manage it different

		trailsData[0].targetPos.x = playerPos.x;
		trailsData[0].targetPos.y = playerPos.y;

		trailsData[0].distance = trailsData[0].currentPos.DistanceTo(trailsData[0].targetPos);

		int targetDistance = 0;
		iPoint destinationPosition = { 0,0 };

		if (this_state == actualState::POSITIONING)
		{
			targetDistance = 10;
			destinationPosition.x = App->player[playerIndex]->position.x; //+ 16; // 16 half player width
			destinationPosition.y = App->player[playerIndex]->position.y; // -8; //

			if (trailsData[0].distance <= 10 && trailsData[0].print)
			{
				//numTrailsPrint--;
				trailsData[0].print = false;
			}
		}
		else
		{
			targetDistance = 20;
			destinationPosition.x = playerPos.x;
			destinationPosition.y = playerPos.y;
		}

		if (trailsData[0].distance >= targetDistance)
		{
			trailsData[0].tx = destinationPosition.x - trailsData[0].currentPos.x;
			trailsData[0].ty = destinationPosition.y - trailsData[0].currentPos.y;

			trailsData[0].velX = (trailsData[0].tx / trailsData[0].distance * trailsData[0].speed);
			trailsData[0].velY = (trailsData[0].ty / trailsData[0].distance * trailsData[0].speed);

			trailsData[0].tPosX = trailsData[0].velX + 1;// + 1;
			trailsData[0].tPosY = trailsData[0].velY;

			trailsData[0].currentPos.x += trailsData[0].tPosX;
			trailsData[0].currentPos.y += trailsData[0].tPosY;

		}


		//rest of trails, linked to its anterior trail

		for (int i = 1; i < NUM_TRAILS; ++i) //links each trail position to its anterior trail
		{
			trailsData[i].targetPos = trailsData[i - 1].currentPos;

			//trailsData[i].currentPos.x += 1; //compensate player default speed x
			

			trailsData[i].distance = trailsData[i].currentPos.DistanceTo(trailsData[i - 1].currentPos);

			if (trailsData[i].distance <= targetDistance && this_state == actualState::POSITIONING && trailsData[i].print)
			{
				trailsData[i].print = false;
			}

			if (trailsData[i].distance >= targetDistance)
			{
				trailsData[i].tx = trailsData[i - 1].currentPos.x - trailsData[i].currentPos.x;
				trailsData[i].ty = trailsData[i - 1].currentPos.y - trailsData[i].currentPos.y;

				trailsData[i].velX = (trailsData[i].tx / trailsData[i].distance * trailsData[i].speed);
				trailsData[i].velY = (trailsData[i].ty / trailsData[i].distance * trailsData[i].speed);

				trailsData[i].tPosX = trailsData[i].velX + 1;
				trailsData[i].tPosY = trailsData[i].velY;

				trailsData[i].currentPos.x += trailsData[i].tPosX;
				trailsData[i].currentPos.y += trailsData[i].tPosY;

			}
			
		}

	}
	

	return UPDATE_CONTINUE;
}

update_status ModulePlayerUnit::Update()
{

	if (this_state == actualState::LINKED || this_state == actualState::POSITIONING)
	{
		// update unit position before printing anything on Linked step

		if (this_state != actualState::POSITIONING)
		{
			playerPos.x = (App->player[playerIndex]->position.x + 9) + cos(angle) * 31.5f;//orginal distance // 9
			playerPos.y = (App->player[playerIndex]->position.y - 7) - sin(angle) * 32;//24; // 7
		}
		else
		{
			
			increaseVectorX += positioningSpeed;
			increaseVectorY += positioningSpeed;

			playerPos.x = (App->player[playerIndex]->position.x + 9) + cos(angle) * increaseVectorX;//orginal distance // 9
			playerPos.y = (App->player[playerIndex]->position.y - 7) - sin(angle) * increaseVectorY;//24; // 7

			if (increaseVectorX >= 31.5f || increaseVectorY >= 32)
			{
				this_state = actualState::LINKED;
				increaseVectorX = 0;
				increaseVectorY = 0;

				//and re assign trails bools
				for (int i = 0; i < NUM_TRAILS; ++i)
					trailsData[i].print = true;

				//and reassign correct damage to colliders
				unitDamage = 1;
				upCollider->damage = unitDamage;
				downCollider->damage = unitDamage;
				rightCollider->damage = unitDamage;
				leftCollider->damage = unitDamage;
				centerCollider->damage = unitDamage;

				// reset grinding states
				grinding_state = grindingState::NO_GRIND;
				first_grinding_state = grindingState::NO_GRIND;

				// resets grindingSpeed
				grindingSpeed = fabs(grindingSpeed);
			}
		}
		

		//animation logic ----------------------------------------------------------------------------------
		//the ball moves independent of the position of the angle, only consider direction of
		//pulsations direction (and remember on a temporal value the last pulsation to stuck the animation
		//to its desired animation position (at module start links to position of spawn (animation index 0)

		SDL_Rect unitRect;
		unitRect = currentUnitAnim->GetCurrentFrame();

		float animationRotationSpeed = 0.9f;

		//if we press up
		if (App->player[playerIndex]->playerInput.moveDown &&
			!App->player[playerIndex]->playerInput.moveLeft &&
			!App->player[playerIndex]->playerInput.moveRight)//App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
		{
			//index 4 is the unit pointing up and 12 unit pointing down, the two directions to consider on this axis
			if (frameIncrement > 4 && frameIncrement < 12) //if we are on a superior animation, we go on the short way
			{											   //original game behaviour
				frameIncrement -= animationRotationSpeed;
			}
			else
			{	//the short way in some cases MUST consider 0 pos...
				frameIncrement += animationRotationSpeed;
				if ((int)frameIncrement >= MAX_ANIMS - 1) frameIncrement = 0;
			}
			if ((int)frameIncrement == 4) frameIncrement = 4; //stuck on the correct MAX frame
		}
		//if we press down
		if (App->player[playerIndex]->playerInput.moveUp &&//App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT &&
			!App->player[playerIndex]->playerInput.moveDown && ////App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE) //original game behaviour priority
			!App->player[playerIndex]->playerInput.moveLeft &&
			!App->player[playerIndex]->playerInput.moveRight)
		{
			if (frameIncrement > 12 || frameIncrement < 4)
			{
				frameIncrement -= animationRotationSpeed;
				if ((int)frameIncrement <= 0) frameIncrement = MAX_ANIMS - 1; //when we reach max anims index
			}
			else if (frameIncrement >= 4) //opposite direction
			{
				frameIncrement += animationRotationSpeed;
			}
			if ((int)frameIncrement == 12) frameIncrement = 12; //stuck on the correct MAX frame
		}
		//if we press right
		if (App->player[playerIndex]->playerInput.moveRight &&//App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT &&
			!App->player[playerIndex]->playerInput.moveLeft &&//)//App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE) //double check for original game priority
			!App->player[playerIndex]->playerInput.moveDown &&
			!App->player[playerIndex]->playerInput.moveUp)
		{
			//index 8 pointing left , index 0 pointing right
			if (frameIncrement > 8) frameIncrement -= animationRotationSpeed;
			else frameIncrement += animationRotationSpeed;
			if ((int)frameIncrement == 8) frameIncrement = 8;
		}
		//if we press left
		if (App->player[playerIndex]->playerInput.moveLeft &&
			!App->player[playerIndex]->playerInput.moveDown &&
			!App->player[playerIndex]->playerInput.moveUp)//App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
		{
			if (frameIncrement < 8 && frameIncrement > 0) frameIncrement -= animationRotationSpeed;
			else frameIncrement += animationRotationSpeed;
			if ((int)frameIncrement >= MAX_ANIMS - 1) frameIncrement = 0;
		}
		// ------------------------------------------------------------------------------------------------
		// diagonal cases ------------------------------
		// down and left
		if (App->player[playerIndex]->playerInput.moveLeft &&
			App->player[playerIndex]->playerInput.moveDown)
		{
			if (frameIncrement > 2 && frameIncrement < 10)
			{
				frameIncrement -= animationRotationSpeed;
			}
			else
			{
				frameIncrement += animationRotationSpeed;
				if ((int)frameIncrement >= MAX_ANIMS - 1) frameIncrement = 0;
			}
			if ((int)frameIncrement == 2) frameIncrement = 2;
		}

		//down and right
		//down right index = 6 || down left index = 14
		if (App->player[playerIndex]->playerInput.moveRight &&
			App->player[playerIndex]->playerInput.moveDown)
		{
			if (frameIncrement < 14 && frameIncrement > 6)
			{
				frameIncrement -= animationRotationSpeed;
			}
			else
			{
				
				frameIncrement += animationRotationSpeed;
				if ((int)frameIncrement >= MAX_ANIMS - 1) frameIncrement = 0;
			}
			if ((int)frameIncrement == 6) frameIncrement = 6;
		
		}

		//up and left
		if (App->player[playerIndex]->playerInput.moveUp &&
			App->player[playerIndex]->playerInput.moveLeft)
		{
			if (frameIncrement < 6 || frameIncrement > 14)
			{
				frameIncrement -= animationRotationSpeed;
				if ((int)frameIncrement <= 0) frameIncrement = MAX_ANIMS - 1;
			}
			else
				frameIncrement += animationRotationSpeed;

			if ((int)frameIncrement == 14) frameIncrement = 14;
		}

		// up and right
		if (App->player[playerIndex]->playerInput.moveUp &&
			App->player[playerIndex]->playerInput.moveRight)
		{
			if (frameIncrement < 2 || frameIncrement > 10)
			{
				frameIncrement -= animationRotationSpeed;
				if ((int)frameIncrement <= 0) frameIncrement = MAX_ANIMS - 1;
			}
			else
				frameIncrement += animationRotationSpeed;
			if ((int)frameIncrement == 10) frameIncrement = 10;
		}
		// ------------------------------------------------------------------------------------------------

		// Basic shooting ---------------------------------------------------------------------------------

		if (App->player[playerIndex]->playerInput.shot)//App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_DOWN)
		{
			App->particles->AddParticle(App->particles->unitBasicShot, playerPos.x, playerPos.y, COLLIDER_PLAYER_SHOT, shotVectorSpeed[(int)frameIncrement]);
		}

		// charged shot ------------------------------------------------------------------------------------

		if (App->player[playerIndex]->playerInput.chargedShot || App->player[playerIndex]->playerInput.chargedShotGamepad && this_state == actualState::LINKED)
		{
   			charge += 0.07f;
			LOG("charging shot: %f", charge);
			if (charge >= 0.7f) // if charge is superior a minimum threshold
			{
				SDL_Rect chargeRect = chargingAnim.GetCurrentFrame();
				App->render->Blit(chargeGraphics, 
				playerPos.x + 7 - chargePivotsX[(int)chargingAnim.current_frame],
				playerPos.y + 7 - chargePivotsY[(int)chargingAnim.current_frame],
				&chargeRect);
				if (!charge_fx_played)
				{
					// PLAY SFX
					App->audio->ControlAudio("charging", SFX, PLAY);
					charge_fx_played = true;
				}

			}
		}
		else
		{
			if (charge >= 0.7f)
			{
				if (charge >= 10.0f) charge = 10;
				LOG("throwing unit");
				boomerangShot(charge);
				charge_fx_played = false;
				
			}
			charge = 0;
		}
			



		//draw the unit -----------------------------------------------------------------------------------

		currentUnitAnim = &playerUnitAnim[(int)frameIncrement]; //prepares the correct draw 

		currentUnitAnim->current_frame = lastFrame; //recovery last animation frame and continues the flow
		unitRect = currentUnitAnim->GetCurrentFrame();
		lastFrame = currentUnitAnim->current_frame; //and stores the new "last frame"

		//playerPos.x = (App->player[playerIndex]->position.x + 9) + cos(angle) * 31.5f;//orginal distance // 9
		//playerPos.y = (App->player[playerIndex]->position.y - 7) - sin(angle) * 32;//24; // 7

		App->render->Blit(graphics,
			playerPos.x - pivotArrayPositionsX[(int)frameIncrement],
			playerPos.y - pivotArrayPositionsY[(int)frameIncrement],
			&unitRect);

		// ------------------------------------------------------------------------------------------------
	}
	else if (this_state == actualState::FREE || this_state == actualState::GRINDING || this_state == actualState::RETURN)
	{
		// call animations function // draw unit

		SDL_Rect throwRect = freeAnim.GetCurrentFrame();
		App->render->Blit(chargeGraphics,
			playerPos.x - 2 - throwPivots[(int)freeAnim.current_frame],
			playerPos.y - 2 - throwPivots[(int)freeAnim.current_frame],
			&throwRect);
	}

	// draw unit trails

	if (this_state != actualState::LINKED)
	{
		//for (int i = numTrailsPrint -1; i >= 0; --i)
		for (int i = 0; i < NUM_TRAILS ; ++i)
		{
			if (trailsData[i].print)
			{
				Animation* current_trailAnim;
				current_trailAnim = &trailsData[i].anim;
				SDL_Rect trailRect = current_trailAnim->GetCurrentFrame();

				App->render->Blit(chargeGraphics, trailsData[i].currentPos.x + 6 - (abs(trailRect.w) / 2), trailsData[i].currentPos.y + 7 - (abs(trailRect.h) / 2), &trailRect);
			}
		}
	}

	// always update the colliders position
	if (upCollider != nullptr && downCollider != nullptr && rightCollider != nullptr && leftCollider != nullptr)
	{
		//upCollider->SetPos(playerPos.x + 4, playerPos.y - 1); // 4,-1
		//downCollider->SetPos(playerPos.x + 4, playerPos.y + 14); // 4, 7
		//rightCollider->SetPos(playerPos.x + 14, playerPos.y + 4);
		//leftCollider->SetPos(playerPos.x - 1, playerPos.y + 4);
		upCollider->SetPos(playerPos.x + 6, playerPos.y - 1); // 4,-1
		downCollider->SetPos(playerPos.x + 6, playerPos.y + 14); // 4, 7
		rightCollider->SetPos(playerPos.x + 14, playerPos.y + 6);
		leftCollider->SetPos(playerPos.x - 1, playerPos.y + 6);
		centerCollider->SetPos(playerPos.x + 1 , playerPos.y + 1);
	}

	//collisioned = false;
	
	return UPDATE_CONTINUE;
}

void ModulePlayerUnit::boomerangShot(float charge)
{
	LOG("Throwing the unit charge: %f", charge);
	// PLAY SFX
	App->audio->ControlAudio("released", SFX,PLAY);

	this_state = actualState::FREE;

	vx = unitBoomerangSpeed * cos(angle);
	vy = unitBoomerangSpeed * sin(angle);

	posX = playerPos.x;
	posY = playerPos.y;

	start_boomerang_time = SDL_GetTicks();
	//start_next_trail_time = SDL_GetTicks();

	// assigns the charge amount to damage
	unitDamage = charge; //meh
	//assigns the unitDamage to colliders too...
	upCollider->damage = unitDamage;
	downCollider->damage = unitDamage;
	rightCollider->damage = unitDamage;
	leftCollider->damage = unitDamage;
	centerCollider->damage = unitDamage;

	// initialize trails

	for (int i = 0; i < NUM_TRAILS; ++i) //assigns initial positions
	{

		trailsData[i].tx = App->player[playerIndex]->position.x - playerPos.x;
		trailsData[i].ty = App->player[playerIndex]->position.y - playerPos.y;

		trailsData[i].tx *= 0.3f; // "substract" vector position to positioning first position
		trailsData[i].ty *= 0.3f;

		trailsData[i].currentPos.x = trailsData[i].tx + playerPos.x;
		trailsData[i].currentPos.y = trailsData[i].ty + playerPos.y;

		// assigns initial pos to returning to start point
		trailsData[i].initialPos = trailsData[i].currentPos;

		//assigns speeds
		trailsData[i].speed = unitBoomerangSpeed;

	}

	
	

}

bool ModulePlayerUnit::CleanUp()
{
	//unload textures
	if (graphics != nullptr)
	{
		App->textures->Unload(graphics);
		graphics = nullptr;
	}
	if (chargeGraphics != nullptr)
	{
		App->textures->Unload(chargeGraphics);
		chargeGraphics = nullptr;
	}
	//unload audio
	App->audio->UnloadAudio("UnitLocked", SFX);
	App->audio->UnloadAudio("UnitUnlocked", SFX);
	App->audio->UnloadAudio("charging", SFX);
	App->audio->UnloadAudio("released", SFX);
	App->audio->UnloadAudio("unitCollider", SFX);

	//returning values to unit throwing and trails

	if (this_state != actualState::LINKED)
	{
		this_state = actualState::LINKED;

		for (int i = 0; i < NUM_TRAILS; ++i)
			trailsData[i].print = true;
	}
	
	// re assign unit damage, to avoid some circunstances
	unitDamage = 1;
	charge = 0;
	//re assign needed values to position 0 when start/ re start

	this_state = actualState::LINKED;

	// deleting colliders
	
	for (int i = 0; i < 5; ++i)
	{
		if (unitColliders[i] != nullptr)
		{
			unitColliders[i]->to_delete = true;
			unitColliders[i] = nullptr;
		}
	}


	return true;
}

void ModulePlayerUnit::swapColor(powerUpColor color) //loads and swaps color
{

	if (graphics != nullptr)
	{
		App->textures->Unload(graphics);
		graphics = nullptr;
	}
	if (chargeGraphics != nullptr)
	{
		App->textures->Unload(chargeGraphics);
		chargeGraphics = nullptr;
	}

	LOG("Swaping Unit Colors and functionality");
	if (color == powerUpColor::ORANGE)
	{
		graphics = App->textures->Load("assets/Graphics/Player/OrangeUnit.png");
		chargeGraphics = App->textures->Load("assets/Graphics/Player/orangeUnitMoveAndTrail.png");
		actualUnitColor = color;
	}
	else if (color == powerUpColor::BLUE)
	{
		graphics = App->textures->Load("assets/Graphics/Player/blueUnit.png");
		chargeGraphics = App->textures->Load("assets/Graphics/Player/blueUnitMoveAndTrail.png");
		actualUnitColor = color;
	}
	

}

void ModulePlayerUnit::OnCollision(Collider* c1, Collider* c2)
{
	//LOG("Colliding");
	//if (c2->type == COLLIDER_WALL && c1 != centerCollider)
		//LOG("Colliding WALL");

	now_collision_time = SDL_GetTicks() - start_collision_time;
	
	if(actualUnitColor != powerUpColor::ORANGE )
	{ 
		
		if (this_state == actualState::FREE && c2->type == COLLIDER_WALL && !collisioned &&
			now_collision_time >= delay_collision_timer && c1 != centerCollider)
		{
			// PLAY SFX
			App->audio->ControlAudio("unitCollider", SFX, PLAY);
			//collisioned = true;
			start_collision_time = SDL_GetTicks();

			//for (int i = 0; i < 1; ++i)
			//{
			if (c1 == upCollider && !collisionStates.upCollision && !collisioned)
			{
				collisionStates.upCollision = true;
				// force the rest of conditions to false, to avoid certain situations
				collisionStates.downCollision = false;
				collisionStates.rightCollision = false;
				collisionStates.leftCollision = false;
				// updates unit position
				posY = c2->rect.y + c2->rect.h + 16;//vy * 3;
				playerPos.y = posY;
				// inverts the actual velocity
				vy = -vy;
				collisioned = true;
				//break;
			}
			if (c1 == downCollider && !collisionStates.downCollision && !collisioned)
			{

				collisionStates.downCollision = true;
				// and force to false the rest of conditions
				collisionStates.upCollision = false;
				collisionStates.rightCollision = false;
				collisionStates.leftCollision = false;
				// updates temporal float position where we assign the velocity to avoid false collisions
				// idk, but not work strictly correct..
				posY = c2->rect.y - 16;//- 12;//+ vy * 3; // works fine with 3 multiplier, only detects one collision
				playerPos.y = posY;
				// updates the inverted velocity respect collision vector
				vy = -vy;
				collisioned = true;
				//break;
			}
			if (c1 == rightCollider && !collisionStates.rightCollision && !collisioned)
			{
				collisionStates.rightCollision = true;
				// force the rest of collisions to avoid problems
				collisionStates.downCollision = false;
				collisionStates.upCollision = false;
				collisionStates.leftCollision = false;
				// updates unit position to avoid false collisions
				posX = c2->rect.x - 16;//vx * 3;//50;//vx * 3;
				playerPos.x = posX;
				// invert velocity vector
				vx = -vx;
				collisioned = true;
				//break;
			}
			if (c1 == leftCollider && !collisionStates.leftCollision && !collisioned)
			{
				collisionStates.leftCollision = true;
				// force the rest of collisions to avoid problems
				collisionStates.downCollision = false;
				collisionStates.upCollision = false;
				collisionStates.rightCollision = false;
				// updates unit position to avoid false collisions
				posX = c2->rect.x + c2->rect.w + 16;//+ 40;//+ vx * 3; //- vx * 3;
				playerPos.x = posX;
				// invert velocity vector
				vx = -vx;
				collisioned = true;
				//break;
			}
		
		}
		
	}
	else if (c2->type == COLLIDER_WALL && (this_state == actualState::FREE || this_state == actualState::GRINDING) )// && !collisioned) //check first impact direction
	{
		if (this_state == actualState::FREE)
			this_state = actualState::GRINDING;


		// updates unit position incrementer

		grindingPosIncrementX = playerPos.x;
		grindingPosIncrementY = playerPos.y;


		if (c1 == upCollider && !collisionStates.upCollision) //colliderToGrind != c2)
		{
			collisionStates.upCollision = true;
			collisionStates.downCollision = false;
			
			playerPos.y = c2->rect.y + c2->rect.h; //+ 1;

			colliderToGrind = c2;

			grinding_state = grindingState::UP;

			LOG("grinding on up");
		}
		if (c1 == downCollider && !collisionStates.downCollision)
		{
			collisionStates.downCollision = true;
			collisionStates.upCollision = false;
			
			playerPos.y = c2->rect.y - 14;
			
			colliderToGrind = c2;
			
			grinding_state = grindingState::DOWN;

			LOG("grinding on down");
		}
		if (c1 == rightCollider && !collisionStates.rightCollision)
		{
			collisionStates.rightCollision = true;
			collisionStates.leftCollision = false;

			playerPos.x = c2->rect.x - 14;

			colliderToGrind = c2;

			grinding_state = grindingState::RIGHT;

			LOG("grinding on right");
		}
		if (c1 == leftCollider && !collisionStates.leftCollision)
		{
			collisionStates.leftCollision = true;
			collisionStates.rightCollision = false;

			playerPos.x = c2->rect.x + c2->rect.w; //+ 1;

			colliderToGrind = c2;

			grinding_state = grindingState::LEFT;

			LOG("grinding on left");
		}

		if (first_grinding_state == grindingState::NO_GRIND)
		{
			first_grinding_state = grinding_state;

			if (first_grinding_state == grindingState::UP) grindingSpeed = -grindingSpeed;
			if (first_grinding_state == grindingState::DOWN) grindingSpeed = fabs(grindingSpeed);
			if (first_grinding_state == grindingState::RIGHT) grindingSpeed = -grindingSpeed;
			if (first_grinding_state == grindingState::LEFT) grindingSpeed = fabs(grindingSpeed);
		}
		
	}
}

void ModulePlayerUnit::grinding()
{
	//if (playerPos.y > colliderToGrind->rect.y - 10) grinding_state = DOWN;

	if (first_grinding_state == DOWN || first_grinding_state == LEFT)
	{
		switch (grinding_state)
		{
		case UP:

			grindingPosIncrementX -= grindingSpeed;

			playerPos.x += scrollSpeed;
			playerPos.x = grindingPosIncrementX;
			break;

		case DOWN:
			grindingPosIncrementX += grindingSpeed;
			playerPos.x = grindingPosIncrementX;

			if (playerPos.x - 1 > colliderToGrind->rect.x + colliderToGrind->rect.w)
			{
				//playerPos.y = colliderToGrind->rect.y;
				collisionStates.leftCollision = false;
				collisionStates.downCollision = false;
				grinding_state = LEFT;
			}

			//protection run out, on the middle of collider deactivate previous collision
			if (playerPos.x > colliderToGrind->rect.x + colliderToGrind->rect.w / 2)
			{
				collisionStates.rightCollision = false;
				//collisionStates.leftCollision = false;
			}
			break;

		case RIGHT:

			//collisionStates.downCollision = false;
			grindingPosIncrementY -= grindingSpeed;
			playerPos.x += scrollSpeed;
			playerPos.y = grindingPosIncrementY;

			if (playerPos.y + 14 < colliderToGrind->rect.y)
			{
				collisionStates.downCollision = false;
				grinding_state = DOWN;
			}
			break;

		case LEFT:

			grindingPosIncrementY += grindingSpeed;
			playerPos.x += scrollSpeed;
			playerPos.y = grindingPosIncrementY;

			if (playerPos.y > colliderToGrind->rect.y + 1)// colliderToGrind->rect.h  - colliderToGrind->rect.h + 1)
			{
				//collisionStates.rightCollision = false;
				//collisionStates.leftCollision = false;
				collisionStates.downCollision = false;
			}


			break;
		}
	}
	else
	{
		switch (grinding_state)
		{
		case UP:

			grindingPosIncrementX -= grindingSpeed;

			playerPos.x += scrollSpeed;
			playerPos.x = grindingPosIncrementX;
			break;

		case DOWN:

			grindingPosIncrementX += grindingSpeed;
			playerPos.x = grindingPosIncrementX;

			if (playerPos.x - 14 < colliderToGrind->rect.x)
			{
				//playerPos.y = colliderToGrind->rect.y;
				
				collisionStates.rightCollision = false;
				collisionStates.downCollision = false;
				grinding_state = RIGHT;
			}

			if (playerPos.x < colliderToGrind->rect.x + colliderToGrind->rect.w / 2)
			{
				collisionStates.leftCollision = false;
			}
			break;

		case RIGHT:

			//collisionStates.downCollision = false;
			grindingPosIncrementY -= grindingSpeed;
			playerPos.x += scrollSpeed;
			playerPos.y = grindingPosIncrementY;
			break;

		case LEFT:

			grindingPosIncrementY += grindingSpeed;
			playerPos.x += scrollSpeed;
			playerPos.y = grindingPosIncrementY;

			if (playerPos.y + 14 < colliderToGrind->rect.y)
			{

				collisionStates.downCollision = false;
				grinding_state = DOWN;
			}
			break;
		}
	}

}

update_status ModulePlayerUnit::PostUpdate()
{

	/*if (this_state == actualState::FREE)
	{
		// re assign positions to avoid false collisions
		playerPos.x = posX;
		playerPos.y = posY;
	}*/

	//collisioned = false;

	return UPDATE_CONTINUE;
}