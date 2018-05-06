#include "Globals.h"
#include "Application.h"
#include "ModuleInput.h"
#include "SDL/include/SDL.h"

#include "ModuleSceneLvl1.h" //for now scene lv1 spawn enemies debug mode

ModuleInput::ModuleInput() : Module()
{
	for (uint i = 0; i < MAX_KEYS; ++i)
		keyboard[i] = KEY_IDLE;
}

// Destructor
ModuleInput::~ModuleInput()
{}

// Called before render is available
bool ModuleInput::Init()
{
	LOG("Init SDL input event system");
	bool ret = true;
	SDL_Init(0);

	if(SDL_InitSubSystem(SDL_INIT_EVENTS) < 0)
	{
		LOG("SDL_EVENTS could not initialize! SDL_Error: %s\n", SDL_GetError());
		ret = false;
	}

	//controller
	LOG("Initialzng controller-----------");
	SDL_Init(SDL_INIT_GAMECONTROLLER);
	return ret;
}

// Called every draw update
update_status ModuleInput::PreUpdate()
{
	// Keyboard input
	SDL_PumpEvents();
	
	const Uint8* keys = SDL_GetKeyboardState(NULL);

	for (int i = 0; i < MAX_KEYS; ++i)
	{
		if (keys[i] == 1)
		{
			if (keyboard[i] == KEY_IDLE)
				keyboard[i] = KEY_DOWN;
			else
				keyboard[i] = KEY_REPEAT;
		}
		else
		{
			if (keyboard[i] == KEY_REPEAT || keyboard[i] == KEY_DOWN)
				keyboard[i] = KEY_UP;
			else
				keyboard[i] = KEY_IDLE;
		}
	}

	//keyboard = SDL_GetKeyboardState(NULL);

	if(keyboard[SDL_SCANCODE_ESCAPE])
		return update_status::UPDATE_STOP;

	while (SDL_PollEvent(&Event)) //close window with mouse
	{
		if (Event.type == SDL_QUIT)
			return update_status::UPDATE_STOP;

		if (Event.type == SDL_MOUSEBUTTONDOWN)
		{
			App->scene_lvl1->spawnEnemies(Event.button.x, Event.button.y);
		}

		//gamepad
		else if (Event.type == SDL_CONTROLLERBUTTONDOWN)
		{
			if (Event.cbutton.button == SDL_CONTROLLER_BUTTON_A)
				App->input->keyboard[SDL_SCANCODE_SPACE] = KEY_DOWN;

			else if (Event.cbutton.button == SDL_CONTROLLER_BUTTON_DPAD_UP)
				App->input->keyboard[SDL_SCANCODE_W] = KEY_DOWN;

			else if (Event.cbutton.button == SDL_CONTROLLER_BUTTON_DPAD_DOWN)
				App->input->keyboard[SDL_SCANCODE_S] = KEY_DOWN;

			else if (Event.cbutton.button == SDL_CONTROLLER_BUTTON_DPAD_LEFT)
				App->input->keyboard[SDL_SCANCODE_A] = KEY_DOWN;

			else if (Event.cbutton.button == SDL_CONTROLLER_BUTTON_DPAD_RIGHT)
				App->input->keyboard[SDL_SCANCODE_D] = KEY_DOWN;

			else if (Event.cbutton.button == SDL_CONTROLLER_BUTTON_RIGHTSHOULDER)
				App->input->keyboard[SDL_SCANCODE_LSHIFT] = KEY_DOWN;
		}
	}

	// GamePad input


	return update_status::UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleInput::CleanUp()
{
	LOG("Quitting SDL input event subsystem");
	SDL_QuitSubSystem(SDL_INIT_EVENTS);
	return true;
}