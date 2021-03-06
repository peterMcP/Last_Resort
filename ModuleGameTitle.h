#ifndef __MODULEGAMETITLE_H__
#define __MODULEGAMETITLE_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleGameTitle : public Module
{
public:
	ModuleGameTitle();
    ~ModuleGameTitle();

	bool Init();
	bool Start();
	update_status Update();
	bool CleanUp();

public:
	SDL_Texture* titleScreen = nullptr;
	SDL_Texture* blackScreenTexture = nullptr;
	SDL_Texture* insertCoinTexture = nullptr;
	SDL_Texture* pushStartTexture = nullptr;
	SDL_Texture* snkTexture = nullptr;
	SDL_Texture* snkCorpTexture = nullptr;
	SDL_Texture* lettersTexture[10];

	Animation letters[10];
	Animation pushStart;

	int positionsLettersX[10] = {55,104,163,208,20,70,113,147,194,238};
	int positionsLettersY[10] = {16,15,15,14,86,87,87,85,86,85};
	float letterTransitionPositions[10] = { 96,96,96,96,169,169,169,169,169,169 }; //{95,135,106,68,148,157,178,148,148,140};
	float const lettersTransitions0pos[10] = { 96,96,96,96,169,169,169,169,169,169 };
	int pivotMegaDimensionalX[10][33] = 
	{
		{ -3,-3,-2,-2,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, // L
		{ -19,-19,-19,-19,-19,-19,-19,-19,-19,-18,-18,-17,-15,-15,-14,-13,0,-8,-5,-5,1,1,1,1,1,1,1,1,1,0,0,0 }, //A
		{ -13,-13,-1,-5,-4,-3,-1,-1,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, //S
		{ -1,-1,-1,-1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0 }, //T
		{ -5,-5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, //R
		{ -2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, //E
		{ -13,-13,-1,-5,-4,-3,-1,-1,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, //S
		{ -14,-14,-14,-13,-9,-9,-8,-6,-5,-3,-3,-3,-2,-2,-1,-1,-1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0 }, //O
		{ -5,-5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, //R
		{ -1,-1,-1,-1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0 }  //T (1 more frame)
	};
	int pivotMegaDimensionalY[10][33] =
	{
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0 }, // L
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, //A
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, //S
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, //T
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0 }, //R
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, //E
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, //S
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, //O
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0 }, //R
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }  //T (1 more frame)
	};

	Uint32 now;
	float start_time;
	float total_time;
	float lastFadeFromWhiteTime;
	int timeInWhite;

	SDL_Rect titleScreenRect;
	SDL_Rect snk;
	SDL_Rect snkCorp;

	int timeBetweenLetters;

	int showMeNext;

private:

	enum intro_step
	{
		firstSecuence,
		fade_to_white,
		time_in_white,
		fade_from_white,
		press_start_screen,
	} current_step = intro_step::firstSecuence;
};


#endif //__MODULEGAMETITLE_H__