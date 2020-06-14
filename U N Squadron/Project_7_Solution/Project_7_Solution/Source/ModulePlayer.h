#ifndef __MODULE_PLAYER_H__
#define __MODULE_PLAYER_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"

struct SDL_Texture;
struct Collider;

class ModulePlayer : public Module
{
public:
	// Constructor
	ModulePlayer(bool startEnabled);


	// Destructor
	~ModulePlayer();

	// Called when the module is activated
	// Loads the necessary textures for the player
	bool Start() override;

	// Called at the middle of the application loop
	// Processes new input and handles player movement
	update_status Update() override;

	// Called at the end of the application loop
	// Performs the render call of the player sprite
	update_status PostUpdate() override;

	// Collision callback, called when the player intersects with another collider
	void OnCollision(Collider* c1, Collider* c2) override;


	// Position of the player in the map
	iPoint position;
	// Position for the camera limits // removable
	iPoint limits1;
	iPoint limits2;

	// The speed in which we move the player (pixels per frame)
	int speed = 2;

	// Countdown to handle shot spacing
	int shotMaxCountdown = 20;
	int shotCountdown = 0;

	// The player spritesheet loaded into an SDL_Texture
	SDL_Texture* texture = nullptr;
	
	SDL_Texture* lives = nullptr;

	SDL_Texture* topHud = nullptr;

	SDL_Texture* portraitA = nullptr;

	SDL_Texture* WeaponsT = nullptr;

	SDL_Rect HuD;
	SDL_Rect Weap1;
	SDL_Rect Weap2;
	SDL_Rect Weap3;
	SDL_Rect Weap4;

	int WPos[4] = { 226,226,226,226 };

	bool Weapons[4];
	bool checking[4] = { false,false,false,false };
	bool usingW[4] = { false,false,false,false };



	void WeaponsSelect();

	int countFrame = 0;
	
	// The pointer to the current player animation
	// It will be switched depending on the player's movement direction
	Animation* currentAnimation = nullptr;

	// A set of animations
	Animation idleAnim;
	Animation upAnim;
	Animation downAnim;

	Animation portrait;



	// The player's collider
	Collider* collider = nullptr;

	// A flag to detect when the player has been destroyed
	bool destroyed = false;
	
	// A countdown to when the player gets destroyed. After a while, the game exits
	uint destroyedCountdown = 120;

	// Sound effects indices
	uint laserFx = 0;
	uint explosionFx = 0;

	// godMode
	bool godMode = FALSE;
	// Font score index
	uint score = 000;
	int scoreFont = -1;
	char scoreText[10] = { "\0" };
	
	uint money = 3000;
	uint level = 000;
	uint powC = 000;
	uint totalPow = 000;
	uint livesRe = 1;
	uint special = 000;

	int powLevel;
	int check = 0;

	int Experiment = 0;
	



	unsigned int WAmmo[4] = { 0,0,0,0 };

};

#endif //!__MODULE_PLAYER_H__