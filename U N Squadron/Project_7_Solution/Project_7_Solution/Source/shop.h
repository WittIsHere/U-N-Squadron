#ifndef __SCENE_SHOP_H__
#define __SCENE_SHOP_H__

#include "Module.h"
#include "Animation.h"

struct SDL_Texture;

class Shop : public Module
{
public:
	//Constructor
	Shop(bool startEnabled);

	//Destructor
	~Shop();

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

	SDL_Texture* topStore = nullptr;
	SDL_Texture* botStore = nullptr;
	SDL_Texture* planeSelect = nullptr;
	SDL_Texture* itemSelect = nullptr;
	SDL_Texture* Borders = nullptr;
	SDL_Texture* Red = nullptr;
	SDL_Texture* Ports = nullptr;
	SDL_Texture* Text = nullptr;
	SDL_Texture* Greys = nullptr;



	SDL_Rect Grey1;
	SDL_Rect Grey2;
	SDL_Rect Grey3;
	SDL_Rect Grey4;

	int Grey1y;
	int Grey2y;
	int Grey3y;
	int Grey4y;
	
	SDL_Rect smallSelect;
	SDL_Rect largeSelect;
	SDL_Rect bottom1;
	SDL_Rect bottom2;
	SDL_Rect top;
	SDL_Rect borders;
	SDL_Rect reddish;
	SDL_Rect text;
	Animation mouth;


	void ParallaxingShop();
	
	uint money = 000;
	int scoreFont = -1;
	char scoreText[10] = { "\0" };

	int botshop2;
	int sel1x;
	int sel1y;

	int sel2x;
	int sel2y;

	int speed2 = 5;
	bool acc = FALSE;

	int ctr1;
	int ctr2;
	
	int spPress = 0;


	int item1 = 3000;
	bool bought1;
	int item2 = 2000;
	bool bought2;
	int item3 = 10000;
	bool bought3;
	int item4 = 10000;
	bool bought4;
	int ctr3;
	int ctr4;

	int txtPos;

};

#endif