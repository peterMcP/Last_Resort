#include "Application.h"
#include "ModuleWindow.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleSceneLvl1.h"
#include "ModuleSceneLvl3.h"
#include "ModuleReady.h"
#include "ModuleParticles.h"
//#include "ModulePlayer.h"

#include "Player.h"

//#include "ModulePlayer2.h"
#include "ModulePlayerUnit.h"
//#include "ModulePlayer2Unit.h"
#include "ModuleCollision.h"
#include "ModuleAudio.h"
#include "ModuleFadeToBlack.h"
#include "ModuleTeamLogo.h"
#include "ModuleGameTitle.h"
#include "ModuleContinue.h"
#include "ModuleGameOver.h"
#include "ModuleEnemies.h"
#include "ModuleUI.h"
#include "ModulePowerUp.h"
#include "ModuleWin.h"

Application::Application()
{
	int i = 0;
	modules[i++] = window = new ModuleWindow();
	modules[i++] = input = new ModuleInput();
	modules[i++] = textures = new ModuleTextures();
	modules[i++] = teamLogo = new ModuleTeamLogo();

	modules[i++] = scene_lvl1 = new ModuleSceneLvl1();
	modules[i++] = scene_lvl3 = new ModuleSceneLvl3();
	modules[i++] = readyScreen = new ModuleReady();
	modules[i++] = continueScreen = new ModuleContinue();
	modules[i++] = gameTitle = new ModuleGameTitle();
	modules[i++] = gameOverScreen = new ModuleGameOver();
	modules[i++] = winScreen = new ModuleWin();
	modules[i++] = moduleUI = new ModuleUI();
	
	modules[i++] = enemies = new ModuleEnemies();
	
	modules[i++] = modulePowerUp = new ModulePowerUp();
	
	modules[i++] = player[0] = new Player();
	modules[i++] = player[1] = new Player();
	modules[i++] = playerUnit[0] = new ModulePlayerUnit();
	modules[i++] = playerUnit[1] = new ModulePlayerUnit();

	modules[i++] = particles = new ModuleParticles();
	modules[i++] = render = new ModuleRender();
	modules[i++] = collision = new ModuleCollision();
	modules[i++] = audio = new ModuleAudio();
	modules[i++] = fade = new ModuleFadeToBlack();

}	

Application::~Application()
{
	for(int i = NUM_MODULES - 1; i >= 0; --i)
		delete modules[i];
}

bool Application::Init()
{
	bool ret = true;
	
	//desactivate Modules ----------------
	//disable modulePlayer at init -------
	//scenes ------------
	//teamLogo->Disable();
	gameTitle->Disable();
	readyScreen->Disable();
	scene_lvl1->Disable();
	scene_lvl3->Disable();
	continueScreen->Disable();
	gameOverScreen->Disable();
	//other modules -----
	player[0]->Disable();
	player[1]->Disable(); //second player
	//player2->Disable();
	playerUnit[0]->Disable();
	playerUnit[1]->Disable();
	//player2Unit->Disable();
	collision->Disable();
	particles->Disable();
	modulePowerUp->Disable();
	winScreen->Disable();
	enemies->Disable();
	
	// -----------------------------------
	//all modules have their init
	for(int i = 0; i < NUM_MODULES && ret == true; ++i)
		ret = modules[i]->Init();

	//but only the needed have start
	for(int i = 0; i < NUM_MODULES && ret == true; ++i)
	//for (int i = NUM_MODULES; i >= 0 && ret == true; --i)            //only if the scene is load at first stage
		ret = modules[i]->IsEnabled() ? modules[i]->Start() : true;  //(for debug and testing new functionalities)
	
	return ret;
}

update_status Application::Update()
{
	update_status ret = UPDATE_CONTINUE;

	if (App->input->keyboard[SDL_SCANCODE_P] == KEY_DOWN && (moduleUI->UI == SCENE || moduleUI->UI == PAUSE))
	{
		if (gamePause)
		{
			gamePause = false;
			Mix_ResumeMusic();
			Mix_Resume(-1);
			moduleUI->UI = SCENE;
		}
		else
		{
			gamePause = true;
			Mix_PauseMusic();
			Mix_Pause(-1);
			moduleUI->UI = PAUSE;
		}

	}
	if (!gamePause)
	{
		for (int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
			ret = modules[i]->IsEnabled() ? modules[i]->PreUpdate() : UPDATE_CONTINUE;

		for (int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
			ret = modules[i]->IsEnabled() ? modules[i]->Update() : UPDATE_CONTINUE;

		for (int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
			ret = modules[i]->IsEnabled() ? modules[i]->PostUpdate() : UPDATE_CONTINUE;
	}
	else
	{
		// check input
		// update only basic modules
		ret = input->PreUpdate();
		moduleUI->PostUpdate();
		//render->PreUpdate();
		render->PostUpdate();
	}
	

	return ret;
}

bool Application::CleanUp()
{
	bool ret = true;

	for(int i = NUM_MODULES - 1; i >= 0 && ret == true; --i)
		ret = modules[i]->CleanUp();

	App->collision->CleanUp(); // individual cleanup when all modules are cleanedUp when exits gameLoop
	//App->render->CleanUp();

	return ret;
}