#include "levelOne.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"
#include "ModuleEnemies.h"
#include "ModulePlayer.h"
#include "Animation.h"
#include "GameOver.h"
#include "MissionComplete.h"
#include "ModuleFadeToBlack.h"


void LevelOne::ParallaxMount1()
{
	int endPos = mountainA + SCREEN_WIDTH;

	if (endPos >= 0)
	{
		mountainA -= 0.07f;
	}
	else
	{
		mountainA = SCREEN_WIDTH;
	}

}
void LevelOne::ParallaxMount2()
{
	int endPos = mountainB + SCREEN_WIDTH;

	if (endPos >= 0)
	{
		mountainB -= 0.07f;
	}
	else
	{
		mountainB = SCREEN_WIDTH;
	}

}
void LevelOne::ParallaxEarth1()
{
	int endPos = earthA + SCREEN_WIDTH;

	if (endPos >= 0)
	{
		earthA -= 0.25f;
	}
	else
	{
		earthA = SCREEN_WIDTH;
	}

}
void LevelOne::ParallaxEarth2()
{
	int endPos = earthB + SCREEN_WIDTH;

	if (endPos >= 0)
	{
		earthB -= 0.25f;
	}
	else
	{
		earthB = SCREEN_WIDTH;
	}

}
void LevelOne::ParallaxLevel()
{
	
	levelPos -= spLevel;

}
void LevelOne::ParallaxValla()
{

	vallaPos -= 0.7f;

}

void LevelOne::POWanim()
{
	if(powApos > 130)
	powApos -= 0.5;
	if(powBpos > 130)
	powBpos -= 0.5;

}


LevelOne::LevelOne(bool startEnabled) : Module(startEnabled)
{

	skyes = { 0,0,256,224 };

	earth1 = { 0,0,258,224 };
	earth2 = { 0,0,258,224 };

	level = { 0,0,3988,224 };

	mountain1 = { 0,0,258,224 };
	mountain2 = { 0,0,258,224 };

	vallA = { 0,0,1614,224 };

	_pow.PushBack({ 0,0,15,15 });
	_pow.PushBack({ 15,0,15,15 });
	_pow.speed = 0.1f;
}


LevelOne::~LevelOne()
{

}


bool LevelOne::Start()
{
	LOG("Loading background assets (Level One)");


	powApos = 736;
	powBpos = 1816;

	powAtaken = false;
	powBtaken = false;

	bool ret = true;

	mountains = App->textures->Load("Assets/Sprites/mountain.png");
	sky = App->textures->Load("Assets/Sprites/sky.png");
	bgTexture = App->textures->Load("Assets/Sprites/LevelBack.png");
	earth = App->textures->Load("Assets/Sprites/tierra.png");
	vallas = App->textures->Load("Assets/Sprites/vallas.png");
	POW = App->textures->Load("Assets/Sprites/Pow.png");
	

	App->audio->PlayMusic("Assets/Music/frontline_base.ogg", 1.0f);

	// Enemies here
	

	App->player->Enable();
	App->enemies->Enable();

	frameCount = 0;


	
	return ret;
}


update_status LevelOne::Update()
{
	App->render->camera.x += 0; //(1*SCREEN_SIZE)

	frameCount++;

	if (frameCount == 180)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::HELICOPTER1, 300, 55, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::HELICOPTER1, 325, 55, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::HELICOPTER1, 350, 55, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::HELICOPTER1, 375, 55, 0);
	}
	if (frameCount == 480)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::HELICOPTER2, 300, 55, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::HELICOPTER2, 325, 55, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::HELICOPTER2, 350, 55, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::HELICOPTER2, 375, 55, 0);
	}
	if (frameCount == 600)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::TANK, 300, 160, 0);
	}
	if (frameCount == 600)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::TANK, 250, 170, 0);
	}
	if (frameCount == 690)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::HELICOPTER3, 300, 105, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::HELICOPTER3, 325, 105, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::HELICOPTER3, 350, 105, 0);
	}
	if (frameCount == 780)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::TANK, 300, 155, 0);
	}
	if (frameCount == 780)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::TANK, 250, 165, 0);
	}
	if (frameCount == 960)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::HELICOPTER4, 300, 70, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::HELICOPTER4, 325, 110, 0);
	}
	if (frameCount == 1000)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::HELICOPTER4, 300, 70, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::HELICOPTER4, 325, 110, 0);
	}
	if (frameCount == 1030)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::TURRETGREEN, 300, 143, 0);
	}
	if (frameCount == 1080)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::TURRETRED, 300, 143, 0);
	}
	if (frameCount == 1200)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::HELICOPTER1, 300, 55, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::HELICOPTER1, 325, 55, 0);
	
	}
	if (frameCount == 1220)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::HELICOPTER3, 300, 105, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::HELICOPTER3, 350, 105, 0);
	}
	if (frameCount == 1260)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::HELICOPTER1, 300, 55, 0);
	}
	if (frameCount == 1350)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::HELICOPTER4, 300, 70, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::HELICOPTER4, 325, 110, 0);
	}
	if (frameCount == 1390)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::HELICOPTER4, 300, 70, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::HELICOPTER4, 325, 110, 0);
	}
	if (frameCount == 1340)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::TURRETGREEN, 300, 160, 0);
	}
	if (frameCount == 1620)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::HELICOPTER3, 300, 105, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::HELICOPTER3, 325, 105, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::HELICOPTER3, 350, 105, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::HELICOPTER3, 350, 105, 0);
	}
	if (frameCount == 1620)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::TURRETGREEN, 260, 160, 0);
	}
	if (frameCount == 1710)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::TURRETGREEN, 260, 140, 0);
	}
	if (frameCount == 1800)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::HELICOPTER1, 300, 55, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::HELICOPTER1, 350, 55, 0);
	}
	if (frameCount == 1800)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::TURRETGREEN, 260, 126, 0);
	}
	if (frameCount == 1190)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::HELICOPTER3, 300, 140, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::HELICOPTER3, 340, 140, 0);
	}
	if (frameCount == 2010)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::TURRETGREEN, 263, 158, 0);
	}
	if (frameCount == 2130)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::TURRETGREEN, 255, 166, 0);
	}
	if (frameCount == 2220)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::TURRETGREEN, 260, 158, 0);
	}
	if (frameCount == 2310)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::TURRETGREEN, 260, 166, 0);
	}
	if (frameCount == 2340)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::HELICOPTER2, 300, 55, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::HELICOPTER2, 325, 55, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::HELICOPTER2, 350, 55, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::HELICOPTER2, 375, 55, 0);
	}
	if (frameCount == 2760)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::HELICOPTER1, 300, 55, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::HELICOPTER1, 325, 55, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::HELICOPTER1, 350, 55, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::HELICOPTER1, 375, 55, 0);
	}
	if (frameCount == 2700)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::TURRETGREEN, 269, 166, 0);
	}
	if (frameCount == 2800)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::TURRETGREEN, 255, 127, 0);
	}
	if (frameCount == 2875)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::TURRETGREEN, 256, 163, 0);
	}
	if (frameCount == 2960)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::TURRETGREEN, 260, 168, 0);
	}
	if (frameCount == 3540)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::HELICOPTER4RED, 300, 70, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::HELICOPTER4RED, 325, 110, 0);
	}
	if (frameCount == 3580)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::HELICOPTER4RED, 300, 70, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::HELICOPTER4RED, 325, 110, 0);
	}
	if (frameCount == 3720)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::HELICOPTER3, 300, 105, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::HELICOPTER3, 325, 105, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::HELICOPTER3, 350, 105, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::HELICOPTER3, 350, 105, 0);
	}
	if (frameCount == 3840)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::HELICOPTER1, 300, 55, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::HELICOPTER1, 325, 55, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::HELICOPTER1, 350, 55, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::HELICOPTER1, 375, 55, 0);
	}
	if (frameCount == 3900)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::HELICOPTER2, 300, 20, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::HELICOPTER2, 325, 20, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::HELICOPTER2, 350, 20, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::HELICOPTER2, 375, 20, 0);
	}
	if (frameCount == 4250)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::BOSS1, 300, 100, 0);
	}
	if (frameCount == 6100)
	{
		
		App->fade->FadeToBlack((Module*)App->levelOne, (Module*)App->missionComplete, 90);
	}


	ParallaxMount1();
	ParallaxMount2();

	ParallaxEarth1();
	ParallaxEarth2();

	ParallaxLevel();
	ParallaxValla();

	_pow.Update();
	POWanim();



	return update_status::UPDATE_CONTINUE;
}


update_status LevelOne::PostUpdate()
{

	// Draw everything --------------------------------------

	App->render->Blit(sky, 0, 0, &skyes, 0);

	App->render->Blit(earth, earthA, -1, &earth1, 0.25f);
	App->render->Blit(earth, earthB, -1, &earth2, 0.25f);

	App->render->Blit(mountains, mountainA, -1, &mountain1, 0.07f);
	App->render->Blit(mountains, mountainB, -1, &mountain2, 0.07f);

	App->render->Blit(bgTexture, levelPos, 0, &level, spLevel);
	App->render->Blit(vallas, vallaPos, 0, &vallA, 0.7f);

	App->render->Blit(POW, powApos, 60, &(_pow.GetCurrentFrame()), 0.10f);
	App->render->Blit(POW, powBpos, 80, &(_pow.GetCurrentFrame()), 0.10f);

	return update_status::UPDATE_CONTINUE;
}


bool LevelOne::CleanUp()
{

	mountainA = 0;
	mountainB = 256;
	earthA = 0;
	earthB = 256;
	levelPos = 0;
	vallaPos = 0;

	App->player->Disable();
	App->enemies->Disable();
	return true;
}

