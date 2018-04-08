#ifndef __MODULESCENEINTRO_H__
#define __MODULESCENEINTRO_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro();
    ~ModuleSceneIntro();

	bool Start();
	update_status Update();
	//bool CleanUp();

public:
	SDL_Texture* LTexture = nullptr;
	SDL_Texture* ATexture = nullptr;
	SDL_Texture* S1Texture = nullptr;
	SDL_Texture* T1Texture = nullptr;
	SDL_Texture* R1Texture = nullptr;
	SDL_Texture* ETexture = nullptr;
	SDL_Texture* S2Texture = nullptr;
	SDL_Texture* OTexture = nullptr;
	SDL_Texture* R2Texture = nullptr;
	SDL_Texture* T2Texture = nullptr;
	SDL_Texture* titleScreen = nullptr;
	SDL_Texture* blackScreenTexture = nullptr;
	SDL_Texture* logoTexture = nullptr;

	Animation animationL;
	Animation animationA;
	Animation animationS1;
	Animation animationT1;
	Animation animationR1;
	Animation animationE;
	Animation animationS2;
	Animation animationO;
	Animation animationR2;
	Animation animationT2;

	int pivotArrayA[31] = {-19,-19,-19,-19,-19,-19,-19,-19,-19,-18,-18,-17,-15,-15,-14,-13,0,-8,-5,-5,1,1,1,1,1,1,1,1,1,1,1};

	Uint32 now;
	bool logoDone = false;

	float start_time;
	float total_time;
	float lastFadeFromWhiteTime;
	//float now;

	SDL_Rect jerry_smith;


	float timeBetweenLetters;

private:

	enum intro_step
	{
		teamLogo,
		firstSecuence,
		fade_to_white,
		fade_from_white,
		press_start_screen,
	} current_step = intro_step::teamLogo;
};


#endif //__MODULESCENEINTRO_H__