#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleSceneIntro.h"
//#include "ModuleBackground.h"
#include "ModuleGameOver.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"

//#include "SDL/include/SDL_timer.h"

//#include "SDL/include/SDL_render.h"

ModuleGameOver::ModuleGameOver()
{
	gameOverRect = { 0,320,234,132 };

}

ModuleGameOver::~ModuleGameOver()
{}

bool ModuleGameOver::Start()
{
	LOG("---- Starting Module Game Over");

	gameOverTexture = App->textures->Load("assets/GameOver.png");

	return true;
}

update_status ModuleGameOver::Update()
{

	App->render->Blit(gameOverTexture, 0,0, &gameOverRect);

	if (App->input->keyboard[SDL_SCANCODE_RETURN] == 1)
		App->fade->FadeToBlack(App->gameOverScreen, App->introScreen);

	return UPDATE_CONTINUE;
}

bool ModuleGameOver::CleanUp()
{
	//unload textures
	App->textures->Unload(gameOverTexture);

	return true;
}