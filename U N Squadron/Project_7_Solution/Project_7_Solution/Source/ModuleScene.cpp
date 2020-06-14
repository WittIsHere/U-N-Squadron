#include "ModuleScene.h"

#include "Enemy.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"
#include "ModuleEnemies.h"
#include "ModulePlayer.h"
#include "Animation.h"
#include "Collider.h"
#include "ModuleScene.h"
#include "ModuleFadeToBlack.h"
#include "MissionComplete.h"
#include "Enemy.h"
#include "ModuleEnemies.h"

void ModuleScene::ParallaxingA()
{
	int endPos = pAPosition + SCREEN_WIDTH;

	if (endPos >= 0)
	{
		pAPosition -= pAMovement;

	}
	else
	{
		pAPosition = SCREEN_WIDTH;
	}


}
void ModuleScene::ParallaxingA2()
{
	int endPos = pA2Position + SCREEN_WIDTH;

	if (endPos >= 0)
	{
		pA2Position -= pAMovement;

	}
	else
	{
		pA2Position = SCREEN_WIDTH;
	}
}
void ModuleScene::ParallaxingB()
{
	int endPos = pBPosition + SCREEN_WIDTH;

	if (endPos >= 0)
	{
		pBPosition -= pBMovement;

	}
	else
	{
		pBPosition = SCREEN_WIDTH;
	}


}
void ModuleScene::ParallaxingB2()
{
	int endPos = pB2Position + SCREEN_WIDTH;

	if (endPos >= 0)
	{
		pB2Position -= pBMovement;

	}
	else
	{
		pB2Position = SCREEN_WIDTH;
	}
}
void ModuleScene::ParallaxingC()
{
	int endPos = pCPosition + SCREEN_WIDTH;

	if (endPos >= 0)
	{
		pCPosition -= pCMovement;

	}
	else
	{
		pCPosition = SCREEN_WIDTH;
	}


}
void ModuleScene::ParallaxingC2()
{
	int endPos = pC2Position + SCREEN_WIDTH;

	if (endPos >= 0)
	{
		pC2Position -= pCMovement;

	}
	else
	{
		pC2Position = SCREEN_WIDTH;
	}
}

void ModuleScene::POWanim()
{
	if (powApos > 130)
		powApos -= 0.5;
	if (powBpos > 130)
		powBpos -= 0.5;

}

ModuleScene::ModuleScene(bool startEnabled) : Module(startEnabled)
{
	
	parallaxA1 = { 0,0,262,224 };
	parallaxA2 = { 0,0,260,224 };

	parallaxB1 = { 0,0,260,224 };
	parallaxB2 = { 0,0,258,224 };

	parallaxC1 = { 0,0,258,224 };
	parallaxC2 = { 0,0,256,224 };

	_pow.PushBack({ 0,0,15,15 });
	_pow.PushBack({ 15,0,15,15 });
	_pow.speed = 0.1f;

}

ModuleScene::~ModuleScene()
{

}


bool ModuleScene::Start()
{
	LOG("Loading background assets (Module Scene)");

	bool ret = true;

	powApos = 736;
	powBpos = 1816;

	powAtaken = false;
	powBtaken = false;

	parallaxA = App->textures->Load("Assets/Sprites/ParallaxA.png");
	parallaxB = App->textures->Load("Assets/Sprites/ParallaxB.png");
	parallaxC = App->textures->Load("Assets/Sprites/ParallaxC.png");      
	parallaxD = App->textures->Load("Assets/Sprites/ParallaxD.png");
	POW = App->textures->Load("Assets/Sprites/Pow.png");

	App->audio->PlayMusic("Assets/Music/track2.ogg", 1.0f);


	frameCount = 0;

	App->player->Enable();
	App->enemies->Enable();
	return ret;
}


update_status ModuleScene::Update()
{
	App->render->camera.x += 0; //(1*SCREEN_SIZE)

	frameCount++;

	if (frameCount == 90)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::REDBIRD, 300, 40, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::REDBIRD, 340, 40, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::REDBIRD, 380, 40, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::REDBIRD, 420, 40, 0);
	}
	if (frameCount == 180)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::REDBIRD2, 300, 170, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::REDBIRD2, 340, 170, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::REDBIRD2, 380, 170, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::REDBIRD2, 420, 170, 0);
	}
	if (frameCount == 360)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::BROWNSHIP2, -100, 170, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::BROWNSHIP2, -170, 170, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::BROWNSHIP2, -240, 170, 0);
	}
	if (frameCount == 420)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::BROWNSHIP, -100, 40, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::BROWNSHIP, -170, 40, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::BROWNSHIP, -240, 40, 0);
	}
	if (frameCount == 650)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::BLUE, -100, 40, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::BLUE, -150, 40, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::BLUE, -200, 40, 0);
	}
	if (frameCount == 650)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::BLUE2, -100, 170, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::BLUE2, -150, 170, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::BLUE2, -200, 170, 0);
	}
	if (frameCount == 840)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::TOGETHER, -100, 30, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::TOGETHER, -150, 30, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::TOGETHER, -200, 30, 0);
	}
	if (frameCount == 840)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::TOGETHER2, -100, 170, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::TOGETHER2, -150, 170, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::TOGETHER2, -200, 170, 0);
	}
	if (frameCount == 1100)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::FOUR, 300, 120, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::FOUR, 300, 160, 0);
	}
	if (frameCount == 1120)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::FOUR, 300, 140, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::FOUR, 300, 180, 0);
	}
	if (frameCount == 1250)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::FOUR, 300, 120, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::FOUR, 300, 160, 0);
	}
	if (frameCount == 1270)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::FOUR, 300, 140, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::FOUR, 300, 180, 0);
	}
	if (frameCount == 1500)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::MINIBOSS, -100, -40, 0);
	}
	if (frameCount == 1660)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::BLUE, -100, 40, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::BLUE, -150, 40, 0);
	}
	if (frameCount == 1720)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::BLUE2, -100, 170, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::BLUE2, -150, 170, 0);
	}
	if (frameCount == 1900)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::FOUR, 300, 105, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::FOUR, 300, 135, 0);
	}
	if (frameCount == 1920)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::FOUR, 300, 70, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::FOUR, 300, 170, 0);
	}
	if (frameCount == 2000)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::MINIBOSS2, -100, 250, 0);
	}
	if (frameCount == 2180)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::BLUE, -100, 60, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::BLUE, -150, 60, 0);
	}
	if (frameCount == 2180)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::BLUE2, -100, 150, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::BLUE2, -150, 150, 0);
	}
	if (frameCount == 2480)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::FOUR, 300, 105, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::FOUR, 300, 135, 0);
	}
	if (frameCount == 2500)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::FOUR, 300, 95, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::FOUR, 300, 125, 0);
	}
	if (frameCount == 2750)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::MINIBOSS, -100, -40, 0);
	}
	if (frameCount == 2900)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::REDBIRD, 300, 40, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::REDBIRD, 340, 40, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::REDBIRD, 380, 40, 0);
	}
	if (frameCount == 3080)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::REDBIRD2, 300, 170, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::REDBIRD2, 340, 170, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::REDBIRD2, 380, 170, 0);
	}
	if (frameCount == 3300)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::FOUR, 300, 105, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::FOUR, 300, 135, 0);
	}
	if (frameCount == 3320)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::FOUR, 300, 60, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::FOUR, 300, 180, 0);
	}
	if (frameCount == 3560)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::TOGETHER, -100, 30, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::TOGETHER, -150, 30, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::TOGETHER, -200, 30, 0);
	}
	if (frameCount == 3680)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::TOGETHER2, -100, 170, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::TOGETHER2, -150, 170, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::TOGETHER2, -200, 170, 0);
	}
	if (frameCount == 3860)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::MINIBOSS, -100, 250, 0);
	}
	if (frameCount == 4070)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::BROWNSHIP2, -100, 170, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::BROWNSHIP2, -170, 170, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::BROWNSHIP2, -240, 170, 0);
	}
	if (frameCount == 4310)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::BROWNSHIP, -100, 40, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::BROWNSHIP, -170, 40, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::BROWNSHIP, -240, 40, 0);
	}
	if (frameCount == 4500)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::FOUR, 300, 130, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::FOUR, 300, 170, 0);
	}
	if (frameCount == 4520)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::FOUR, 300, 150, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::FOUR, 300, 190, 0);
	}
	if (frameCount == 4580)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::FOUR, 300, 40, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::FOUR, 300, 80, 0);
	}
	if (frameCount == 4600)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::FOUR, 300, 60, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::FOUR, 300, 100, 0);
	}
	if (frameCount == 4860)
	{
		App->enemies->AddEnemy(ENEMY_TYPE::BOSS2, -100, 180, 0);
	}
	if (frameCount == 6460)
	{
		
		App->fade->FadeToBlack((Module*)App->scene, (Module*)App->missionComplete, 90);
	}

	ParallaxingA();
	ParallaxingA2();

	ParallaxingB();
	ParallaxingB2();

	ParallaxingC();
	ParallaxingC2();

	_pow.Update();
	POWanim();

	return update_status::UPDATE_CONTINUE;
}						



update_status ModuleScene::PostUpdate()
{

   // Draw everything --------------------------------------

	App->render->Blit(bgTexture, 0, 0, NULL);

	App->render->Blit(parallaxD, 0, 6, NULL, 0); // Medio

	App->render->Blit(parallaxC, pCPosition, 6, &parallaxC1, pCMovement);
	App->render->Blit(parallaxC, pC2Position, 6, &parallaxC2, pCMovement);


	App->render->Blit(parallaxB, pBPosition, 5, &parallaxB1, pBMovement);
	App->render->Blit(parallaxB, pB2Position, 5, &parallaxB2, pBMovement);

	App->render->Blit(parallaxA, pAPosition, -4, &parallaxA1, pAMovement);
	App->render->Blit(parallaxA, pA2Position, -4, &parallaxA2, pAMovement); // Parallax Exterior

	App->render->Blit(POW, powApos, 60, &(_pow.GetCurrentFrame()), 0.10f);
	App->render->Blit(POW, powBpos, 80, &(_pow.GetCurrentFrame()), 0.10f);

	return update_status::UPDATE_CONTINUE;
}

bool ModuleScene::CleanUp()
{
	pAPosition = -2;
	pA2Position = 256;
	pBPosition = -2;
	pB2Position = 256;
	pCPosition = -2;
	pC2Position = 256;


	App->player->Disable();
	App->enemies->Disable();

	return true;
}

