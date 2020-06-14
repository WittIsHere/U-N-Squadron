#ifndef __MODULE_SCENE_H__
#define __MODULE_SCENE_H__

#include "Module.h"
#include "Animation.h"

struct SDL_Texture;

class ModuleScene : public Module
{
public:
	//Constructor
	ModuleScene(bool startEnabled);


	//Destructor
	~ModuleScene();

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
	
;

	// Parallax textures

	SDL_Texture* parallaxA = nullptr;
	
	SDL_Texture* parallaxB = nullptr;
	
	SDL_Texture* parallaxC = nullptr;
	
	SDL_Texture* parallaxD = nullptr;

	SDL_Rect parallaxA1;
	SDL_Rect parallaxB1;
	SDL_Rect parallaxC1;

	SDL_Rect parallaxA2;
	SDL_Rect parallaxB2;
	SDL_Rect parallaxC2;


	void ParallaxingA();
	void ParallaxingA2();

	void ParallaxingB();
	void ParallaxingB2();

	void ParallaxingC();
	void ParallaxingC2();

	int pAPosition = -2;
	int pA2Position = 256;

	int pBPosition = -2;
	int pB2Position = 256;

	int pCPosition = -2;
	int pC2Position = 256;

	int frameCount = 0;

	int pAMovement = 4;
	int pBMovement = 2;
	int pCMovement = 1;

	SDL_Texture* POW = nullptr;
	SDL_Rect pow;
	Animation _pow;

	void POWanim();
	float powApos;
	float powBpos;

	bool powAtaken;
	bool powBtaken;




	bool CleanUp();
};

#endif