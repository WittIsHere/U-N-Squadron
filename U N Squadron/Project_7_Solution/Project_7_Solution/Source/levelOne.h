#ifndef __LEVEL_ONE_H__
#define __LEVEL_ONE_H__

#include "Module.h"
#include "Animation.h"

struct SDL_Texture;

class LevelOne : public Module
{
public:
	//Constructor
	LevelOne(bool startEnabled);


	//Destructor
	~LevelOne();

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

	SDL_Texture* mountains = nullptr;
	SDL_Texture* sky = nullptr;
    SDL_Texture* bgTexture = nullptr;
	SDL_Texture* earth = nullptr;
	SDL_Texture* vallas = nullptr;

	SDL_Texture* POW = nullptr;
	SDL_Rect pow;
	Animation _pow;

	void POWanim();
	float powApos;
	float powBpos;

	bool powAtaken;
	bool powBtaken;

	int frameCount = 0;

	SDL_Rect vallA;
	SDL_Rect earth1;
	SDL_Rect earth2;

	SDL_Rect skyes;
	SDL_Rect level;

	SDL_Rect mountain1;
	SDL_Rect mountain2;

	void ParallaxMount1();
	void ParallaxMount2();

	void ParallaxEarth1();
	void ParallaxEarth2();

	void ParallaxLevel();
	void ParallaxValla();

	float mountainA = 0.0f;
	float mountainB = 256.0f;

	float earthA = 0.0f;
	float earthB = 256.0f;

	float levelPos = 0.0f;
	float spLevel = 0.5;
	float vallaPos = 0.0f;


	int frameCount1 = 0;
	int frameDelay = 2;

	bool CleanUp();
};

#endif
