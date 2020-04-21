#include "ModuleScene.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"
#include "ModuleEnemies.h"
#include "ModulePlayer.h"

ModuleScene::ModuleScene(bool startEnabled) : Module(startEnabled)
{

}

ModuleScene::~ModuleScene()
{

}

// Load assets
bool ModuleScene::Start()
{
	LOG("Loading background assets");

	bool ret = true;

	

	parallaxA = App->textures->Load("Assets/Sprites/ParallaxA5.png");
	parallaxB = App->textures->Load("Assets/Sprites/ParallaxB4.png");
	parallaxC = App->textures->Load("Assets/Sprites/ParallaxC4.png");
	parallaxD = App->textures->Load("Assets/Sprites/ParallaxD4.png");

	App->audio->PlayMusic("Assets/Music/track2.ogg", 1.0f);


	// Enemies ---
	App->enemies->AddEnemy(ENEMY_TYPE::REDBIRD, 600, 40);
	App->enemies->AddEnemy(ENEMY_TYPE::REDBIRD, 625, 40);
	App->enemies->AddEnemy(ENEMY_TYPE::REDBIRD, 650, 40);
	App->enemies->AddEnemy(ENEMY_TYPE::REDBIRD, 675, 40);

	// TODO 1: Add a new wave of red birds
	App->enemies->AddEnemy(ENEMY_TYPE::REDBIRD2, 735, 170);
	App->enemies->AddEnemy(ENEMY_TYPE::REDBIRD2, 760, 170);
	App->enemies->AddEnemy(ENEMY_TYPE::REDBIRD2, 785, 170);
	App->enemies->AddEnemy(ENEMY_TYPE::REDBIRD2, 810, 170);

	// TODO 2: Add a new wave of brown cookies


		App->enemies->AddEnemy(ENEMY_TYPE::MECH, 1130, 10);
		App->enemies->AddEnemy(ENEMY_TYPE::MECH, 1170, 10);
		App->enemies->AddEnemy(ENEMY_TYPE::MECH, 1210, 10);
		App->enemies->AddEnemy(ENEMY_TYPE::MECH, 1130, 190);
		App->enemies->AddEnemy(ENEMY_TYPE::MECH, 1170, 190);
		App->enemies->AddEnemy(ENEMY_TYPE::MECH, 1210, 190);
	
	
		App->enemies->AddEnemy(ENEMY_TYPE::BROWNSHIP, 1500, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::BROWNSHIP, 1520, 0);
		App->enemies->AddEnemy(ENEMY_TYPE::BROWNSHIP, 1540, 0);

		App->enemies->AddEnemy(ENEMY_TYPE::BROWNSHIP2, 1500, 200);
		App->enemies->AddEnemy(ENEMY_TYPE::BROWNSHIP2, 1520, 200);
		App->enemies->AddEnemy(ENEMY_TYPE::BROWNSHIP2, 1540, 200);
	
	App->enemies->AddEnemy(ENEMY_TYPE::BLUE, 1800, 0);
	App->enemies->AddEnemy(ENEMY_TYPE::BLUE, 1825, 0);
	App->enemies->AddEnemy(ENEMY_TYPE::BLUE, 1850, 0);
	App->enemies->AddEnemy(ENEMY_TYPE::BLUE, 1875, 0);

	App->enemies->AddEnemy(ENEMY_TYPE::BLUE2, 1800, 230);
	App->enemies->AddEnemy(ENEMY_TYPE::BLUE2, 1825, 230);
	App->enemies->AddEnemy(ENEMY_TYPE::BLUE2, 1850, 230);
	App->enemies->AddEnemy(ENEMY_TYPE::BLUE2, 1875, 230);

	App->player->Enable();
	App->enemies->Enable();
	return ret;
}

update_status ModuleScene::Update()
{
	App->render->camera.x += 3;

	return update_status::UPDATE_CONTINUE;
}

// Update: draw background
update_status ModuleScene::PostUpdate()
{
	// Draw everything --------------------------------------
	App->render->Blit(bgTexture, 0, 0, NULL);

	

	App->render->Blit(parallaxD, 0, -25, NULL, 0); // Medio

	App->render->Blit(parallaxC, 0, -20, NULL, 2); // Capa mas cercana a medio
	App->render->Blit(parallaxC, 5000, -20, NULL, 2);
	App->render->Blit(parallaxC, 10000, -20, NULL, 2);
	App->render->Blit(parallaxC, 15000, -20, NULL, 2);

	App->render->Blit(parallaxB, 0, -20, NULL, 4); // Capa mas cercana a la externa
	App->render->Blit(parallaxB, 5000, -20, NULL, 4);
	App->render->Blit(parallaxB, 10000, -20, NULL, 4);
	App->render->Blit(parallaxB, 15000, -20, NULL, 4);
	App->render->Blit(parallaxB, 20000, -20, NULL, 4);
	App->render->Blit(parallaxB, 25000, -20, NULL, 4);
	App->render->Blit(parallaxB, 30000, -20, NULL, 4);


	App->render->Blit(parallaxA, 0, -20, NULL, 6); // Capa externa
	App->render->Blit(parallaxA, 5000, -20, NULL, 6);
	App->render->Blit(parallaxA, 10000, -20, NULL, 6);
	App->render->Blit(parallaxA, 15000, -20, NULL, 6);
	App->render->Blit(parallaxA, 20000, -20, NULL, 6);
	App->render->Blit(parallaxA, 25000, -20, NULL, 6);
	App->render->Blit(parallaxA, 30000, -20, NULL, 6);
	App->render->Blit(parallaxA, 35000, -20, NULL, 6);
	App->render->Blit(parallaxA, 40000, -20, NULL, 6);
	App->render->Blit(parallaxA, 45000, -20, NULL, 6);

	return update_status::UPDATE_CONTINUE;
}

bool ModuleScene::CleanUp()
{
	
	App->player->Disable();
	App->enemies->Disable();

	return true;
}
