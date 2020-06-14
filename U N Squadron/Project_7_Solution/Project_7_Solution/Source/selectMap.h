#ifndef __SCENE_SELECT_H__
#define __SCENE_SELECT_H__

#include "Module.h"
#include "Animation.h"

struct SDL_Texture;

class MapSelect : public Module
{
public:
	//Constructor
	MapSelect(bool startEnabled);

	//Destructor
	~MapSelect();

	// Called when the module is activated
	// Loads the necessary textures for the map background
	bool Start() override;

	// Called at the middle of the application loop
	// Updates the scene's background animations
	update_status Update() override;

	// Called at the end of the application loop.
	// Performs the render call of all the parts of the scene's background
	update_status PostUpdate() override;

public:
	// The scene sprite sheet loaded into an SDL_Texture
	SDL_Texture* bgTexture = nullptr;
	SDL_Texture* Icons = nullptr;
	SDL_Texture* Yellow = nullptr;
	SDL_Texture* mouth = nullptr;


	Animation _mouth;

	SDL_Rect command;
	SDL_Rect _yellow;
	SDL_Rect _icons;

	int yell = 32;

	int check = 0;
};

#endif