#include "Application.h"
#include "ModuleWindow.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleSceneLvl1.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModulePlayerUnit.h"
#include "ModuleCollision.h"
#include "ModuleAudio.h"
#include "ModuleFadeToBlack.h"
#include "ModuleTeamLogo.h"
#include "ModuleGameTitle.h"
#include "ModuleGameOver.h"

Application::Application()
{
	
	modules[0] = window = new ModuleWindow();
	modules[1] = render = new ModuleRender();
	modules[2] = input = new ModuleInput();
	modules[3] = textures = new ModuleTextures();
	modules[4] = teamLogo = new ModuleTeamLogo();
	modules[5] = scene_lvl1 = new ModuleSceneLvl1();
	modules[6] = gameTitle = new ModuleGameTitle();
	modules[7] = gameOverScreen = new ModuleGameOver();
	modules[8] = particles = new ModuleParticles();
	modules[9] = player = new ModulePlayer();
	modules[10] = playerUnit = new ModulePlayerUnit();
	modules[11] = audio = new ModuleAudio();
	modules[12] = collision = new ModuleCollision();
	modules[13] = fade = new ModuleFadeToBlack();
	

}	

Application::~Application()
{
	for(int i = NUM_MODULES - 1; i >= 0; --i)
		delete modules[i];
}

bool Application::Init()
{
	bool ret = true;
	
	//disable modulePlayer at init
	player->Disable();
	playerUnit->Disable();
	//disable the scenes wich i dont need at start/init
	teamLogo->Disable();
	gameTitle->Disable();
	//background->Disable();
	gameOverScreen->Disable();

	//all modules have their init
	for(int i = 0; i < NUM_MODULES && ret == true; ++i)
		ret = modules[i]->Init();

	//but only the needed have start
	for(int i = 0; i < NUM_MODULES && ret == true; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Start() : true;

	return ret;
}

update_status Application::Update()
{
	update_status ret = UPDATE_CONTINUE;

	for(int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PreUpdate() : UPDATE_CONTINUE;

	for(int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Update() : UPDATE_CONTINUE;

	for(int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PostUpdate() : UPDATE_CONTINUE;

	return ret;
}

bool Application::CleanUp()
{
	bool ret = true;

	for(int i = NUM_MODULES - 1; i >= 0 && ret == true; --i)
		ret = modules[i]->CleanUp();

	return ret;
}