#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

#define NUM_MODULES 19

class Module;
class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModuleAudio;

class MapSelect;
class ModulePlayer;
class SceneIntro;
class Shop;
class ModuleScene;
class LevelOne;
class ModuleParticles;
class ModuleCollisions;
class ModuleEnemies;
class ModuleFadeToBlack;
class ModuleRender;
class ModuleFonts;
class GameOver;
class Welcome;
class MissionComplete;


class Application
{

public:

	//Constructor. Creates all necessary modules for the application
	Application();

	//Destructor. Removes all module objects
	~Application();

	//Initializes all modules
	bool Init();

	//Updates all modules (PreUpdate, Update and PostUpdate)
	update_status Update();

	//Releases all the application data
	bool CleanUp();

public:
	// An array to store all modules
	Module* modules[NUM_MODULES];

	// All the modules stored individually
	ModuleWindow* window = nullptr;
	ModuleInput* input = nullptr;
	ModuleTextures* textures = nullptr;
	ModuleAudio* audio = nullptr;
	Shop* store = nullptr;
	ModulePlayer* player = nullptr;

	LevelOne* levelOne = nullptr;
	SceneIntro* sceneIntro = nullptr;
	ModuleScene* scene = nullptr;
	MapSelect* selectMap = nullptr;
	ModuleEnemies* enemies = nullptr;
	ModuleParticles* particles = nullptr;

	ModuleCollisions* collisions = nullptr;
	ModuleFadeToBlack* fade = nullptr;
	ModuleFonts* fonts = nullptr;
	ModuleRender* render = nullptr;
	GameOver* gameOver = nullptr;
	MissionComplete* missionComplete = nullptr;
	Welcome* welcome = nullptr;
};

// Global var made extern for Application ---
extern Application* App;

#endif // __APPLICATION_H__