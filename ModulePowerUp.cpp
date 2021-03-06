#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
//#include "ModuleParticles.h"
#include "Animation.h"
#include "ModuleAudio.h"

//#include "ModulePlayer.h"
#include "ModuleCollision.h"
#include "ModulePowerUp.h"
//#include "ModuleEnemies.h"

#include "ModulePlayerUnit.h"



ModulePowerUp::ModulePowerUp() 
{

	for (uint i = 0; i < MAX_TYPES; ++i)
		active_powerUps[i] = nullptr;

	//testing purposes rect

	testRect.x = 0;
	testRect.y = 0;
	testRect.w = 31;
	testRect.h = 16;

	//powerUp Animation rects
	powerUpG.anim.PushBack({ 18,96,31,16 });
	powerUpG.anim.PushBack({ 49,96,31,16 });
	powerUpG.anim.speed = 0.01f;
	powerUpG.type = powerUpTypes::BOMBS;

	powerUpH.anim.PushBack({18,64,31,16});
	powerUpH.anim.PushBack({ 49,64,31,16 });
	powerUpH.anim.speed = 0.01f;
	powerUpH.type = powerUpTypes::MISSILES;
	
	powerUpL.anim.PushBack({ 18, 80, 31, 16 });
	powerUpL.anim.PushBack({ 49, 80, 31, 16 });
	powerUpL.anim.speed = 0.01f;
	powerUpL.type = powerUpTypes::LASER;

	powerUpS.anim.PushBack({ 0,64,18,21 });
	powerUpS.type = powerUpTypes::BOOST;

	powerUpZ.anim.PushBack({ 0,85,18,21 });
	powerUpZ.type = powerUpTypes::BRAKE;
	

}

ModulePowerUp::~ModulePowerUp() {}

bool ModulePowerUp::Start()
{
	powerUpTextures = App->textures->Load("assets/Graphics/Player/PowerUps.png");

	//Audio
	App->audio->LoadAudio("assets/Audio/SFX/Player/taking_Unit.wav", "Taking_Unit", SFX);
	App->audio->LoadAudio("assets/Audio/SFX/Player/pickPowerUp.wav", "pickPowerUp", SFX);


	return true;
}

update_status ModulePowerUp::Update()
{
	for (uint i = 0; i < MAX_ACTIVE_POWERUPS; ++i)
	{
		PowerUp* p = active_powerUps[i];

		if (p == nullptr)
			continue;

		if (p->Update() == false)
		{
			delete p;
			active_powerUps[i] = nullptr;
		}
		
  			App->render->Blit(powerUpTextures, p->position.x, p->position.y, &(p->anim.GetCurrentFrame()));
			if (p->fx_played == false && p->fx != nullptr)
			{
				p->fx_played = true;

				// PLAY SPAWN power up effect

				App->audio->ControlAudio(p->fx, SFX, PLAY);


			}
	}

	return UPDATE_CONTINUE;

}

bool ModulePowerUp::CleanUp()
{
	//remove powerups and its colliders
	for (uint i = 0; i < MAX_ACTIVE_POWERUPS; ++i)
	{
		if (active_powerUps[i] != nullptr)
		{
			active_powerUps[i]->collider->to_delete = true; //delete colliders
			delete active_powerUps[i]; //delete poweUp instance
			active_powerUps[i] = nullptr;
		}
	}
	//unload textures
	if (powerUpTextures != nullptr)
	App->textures->Unload(powerUpTextures);
	//unload audio
	App->audio->UnloadAudio("Taking_Unit", SFX);
	App->audio->UnloadAudio("pickPowerUp", SFX);

	return true;
}

void ModulePowerUp::SpawnPowerUp(iPoint position, powerUpTypes type)
{
	if (type != powerUpTypes::NONE)
	{
		LOG("Spawning powerUP");

		for (uint i = 0; i < MAX_ACTIVE_POWERUPS; ++i)
		{
			if (active_powerUps[i] == nullptr) //find room
			{
				PowerUp* p = nullptr;
				switch (type)
				{
				case powerUpTypes::BOMBS:
					p = new PowerUp(powerUpG);
					break;
				case powerUpTypes::LASER:
					p = new PowerUp(powerUpL); 
					break;
				case powerUpTypes::MISSILES:
					p = new PowerUp(powerUpH);
					break;
				case powerUpTypes::BOOST:
					p = new PowerUp(powerUpS);
					break;
				case powerUpTypes::BRAKE:
					p = new PowerUp(powerUpZ);
					break;
				default:
					//untill we got all powerup working, for avoid memory violations, assigns default powerup
					p = new PowerUp(powerUpG);//continue; //if we send invalid type, or not contempled, do nothing
					break;
				}
				p->position = position;
				p->type = type;
				if (p->collider == nullptr)
					p->collider = App->collision->AddCollider(p->anim.GetCurrentFrame(), COLLIDER_POWER_UP, this);
				active_powerUps[i] = p;
				break;
			}
		}
	}
}


void ModulePowerUp::OnCollision(Collider* c1, Collider* c2)
{
	//check what player are picking the powerUp
	int playerIndex;
	if (c2->callback == App->player[0]) playerIndex = 0;
	else playerIndex = 1;

	for (uint i = 0; i < MAX_ACTIVE_POWERUPS; ++i)
	{
		// and destroy power up when pick up
		if (active_powerUps[i] != nullptr && active_powerUps[i]->collider == c1) //and assure if is the powerup who tells he is
		{
			//assigns the color of the pickup item, if not is a brake or boost wich only has one frame per anim
			//
 			if (active_powerUps[i]->anim.current_frame < 1)// &&
				/*active_powerUps[i]->type != powerUpTypes::BOOST ||
				active_powerUps[i]->type != powerUpTypes::BRAKE)*/ color = powerUpColor::ORANGE;
			else if (active_powerUps[i]->anim.current_frame > 1)// &&
				/*active_powerUps[i]->type != powerUpTypes::BOOST ||
				active_powerUps[i]->type != powerUpTypes::BRAKE)*/ color = powerUpColor::BLUE;
			
			//add particle or fx, etc when pickup

			switch (active_powerUps[i]->type)
			{
			case powerUpTypes::BOMBS:
					//call the functionality of the bombs powerup
				App->player[playerIndex]->powerUpActive = powerUpTypes::BOMBS;
				App->audio->ControlAudio("pickPowerUp", SFX, PLAY);
				break;
			case powerUpTypes::BOOST:
					//call the functionality of the bombs powerup
					//play FX
				//App->audio->ControlAudio("speedUP", SFX, PLAY);

					App->player[playerIndex]->powerUpActive = powerUpTypes::BOOST;


				color = App->playerUnit[playerIndex]->actualUnitColor; //this not change the color of the unit
				break;
			case powerUpTypes::BRAKE:
				//call the functionality of the bombs powerup
				App->audio->ControlAudio("speedDN", SFX, PLAY);
				color = App->playerUnit[playerIndex]->actualUnitColor; //this not change the color of the unit
				App->player[playerIndex]->powerUpActive = powerUpTypes::BRAKE;
				break;
			case powerUpTypes::LASER:
				//call the functionality of the laser powerup
				App->player[playerIndex]->powerUpActive = powerUpTypes::LASER;
				App->audio->ControlAudio("pickPowerUp", SFX, PLAY);
				break;
			case powerUpTypes::MISSILES:

				//call the functionality of the missiles powerup
				App->player[playerIndex]->powerUpActive = powerUpTypes::MISSILES;
				App->audio->ControlAudio("pickPowerUp", SFX, PLAY);

				break;
			case powerUpTypes::NONE:
					//for some functionality, if we need
				break;
			default:
				break;
			}
			//always check the color of picked power up, for change the functionality and color of the unit
			App->playerUnit[playerIndex]->swapColor(color); //swap color to the right picked up item
			if (!App->playerUnit[playerIndex]->IsEnabled()) //if the player does not have the unit active, activate and swap color
			{
				App->audio->ControlAudio("Taking_Unit", SFX, PLAY);
				App->playerUnit[playerIndex]->playerIndex = playerIndex;
				App->playerUnit[playerIndex]->Enable();
			}

			//delete the instanciated powerup
		    delete active_powerUps[i];
			active_powerUps[i] = nullptr;
			//delete the collider
			c1->to_delete = true;
			break;
		}
	}
}

PowerUp::PowerUp()
{
	
	position.SetToZero();
	speed.SetToZero();
}

PowerUp::~PowerUp()
{
	if (collider != nullptr)
		collider->to_delete = true;
}

bool PowerUp::Update()
{
	bool ret = true;
	
	if (position.x < (abs(App->render->camera.x) / SCREEN_SIZE) - 30) //if powerUp passes without the attention of the player, destroy it
		ret = false;

	if(collider != nullptr) //updates collider position
		collider->SetPos(position.x, position.y);

	return ret;
}