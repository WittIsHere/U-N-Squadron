#include "ModuleEnemies.h"

#include "Application.h"

#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModulePlayer.h"

#include "Enemy.h"
#include "Enemy_RedBird.h"
#include "Enemy_RedBird2.h"
#include "Enemy_BrownShip.h"
#include "Enemy_BrownShip2.h"
#include "Enemy_Mech.h"
#include "Enemy_Blue.h"
#include "Enemy_Blue2.h"
#include "Enemy_Together.h"
#include "Enemy_Together2.h"
#include "Enemy_MiniBoss.h"
#include "Enemy_Helicopter1.h"
#include "Enemy_Helicopter2.h"
#include "Enemy_Helicopter3.h"
#include "Enemy_Helicopter4.h"
#include "Enemy_Helicopter4Red.h"
#include "Enemy_TurretGreen.h"
#include "Enemy_TurretRed.h"
#include "Enemy_Tank.h"
#include "Enemy_4.h"
#include "Enemy_Bosslvl2.h"
#include "Enemy_Miniboss2.h"
#include "Enemy_Bosslvl1.h"

#define SPAWN_MARGIN 1000


ModuleEnemies::ModuleEnemies(bool startEnabled) : Module(startEnabled)
{
	for (uint i = 0; i < MAX_ENEMIES; ++i)
		enemies[i] = nullptr;
}

ModuleEnemies::~ModuleEnemies()
{

}

bool ModuleEnemies::Start()
{
	texture = App->textures->Load("Assets/Sprites/ALL_Enem_lvl2.png");
	enemyDestroyedFx = App->audio->LoadFx("Assets/explosion.wav");

	return true;
}

update_status ModuleEnemies::Update()
{
	HandleEnemiesSpawn();

	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr)
			enemies[i]->Update();
	}

	HandleEnemiesDespawn();

	return update_status::UPDATE_CONTINUE;
}

update_status ModuleEnemies::PostUpdate()
{
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr)
			enemies[i]->Draw();
	}

	return update_status::UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleEnemies::CleanUp()
{
	LOG("Freeing all enemies");

	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr)
		{
			delete enemies[i];
			enemies[i] = nullptr;
		}
	}

	return true;
}

bool ModuleEnemies::AddEnemy(ENEMY_TYPE type, int x, int y, int path)
{
	bool ret = false;

	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (spawnQueue[i].type == ENEMY_TYPE::NO_TYPE)
		{
			spawnQueue[i].type = type;
			spawnQueue[i].x = x;
			spawnQueue[i].y = y;
			ret = true;
			break;
		}
	}

	if (path == 1)


		return ret;
}

void ModuleEnemies::HandleEnemiesSpawn()
{
	// Iterate all the enemies queue
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (spawnQueue[i].type != ENEMY_TYPE::NO_TYPE)
		{
			// Spawn a new enemy if the screen has reached a spawn position
			if (spawnQueue[i].x * SCREEN_SIZE < App->render->camera.x + (App->render->camera.w * SCREEN_SIZE) + SPAWN_MARGIN)
			{
				LOG("Spawning enemy at %d", spawnQueue[i].x * SCREEN_SIZE);

				SpawnEnemy(spawnQueue[i]);
				spawnQueue[i].type = ENEMY_TYPE::NO_TYPE; // Removing the newly spawned enemy from the queue
			}
		}
	}
}

void ModuleEnemies::HandleEnemiesDespawn()
{
	// Iterate existing enemies
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr)
		{
			// Delete the enemy when it has reached the end of the screen
			if (enemies[i]->position.y * SCREEN_SIZE < (App->render->camera.y) - SPAWN_MARGIN)
			{
				LOG("DeSpawning enemy at %d", enemies[i]->position.x * SCREEN_SIZE);

				delete enemies[i];
				enemies[i] = nullptr;
			}
		}
	}
}

void ModuleEnemies::SpawnEnemy(const EnemySpawnpoint& info)
{
	// Find an empty slot in the enemies array
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] == nullptr)
		{
			switch (info.type)
			{
			case ENEMY_TYPE::REDBIRD:
				enemies[i] = new Enemy_RedBird(info.x, info.y);
				break;
			case ENEMY_TYPE::REDBIRD2:
				enemies[i] = new Enemy_RedBird2(info.x, info.y);
				break;
			case ENEMY_TYPE::BROWNSHIP:
				enemies[i] = new Enemy_BrownShip(info.x, info.y);
				break;
			case ENEMY_TYPE::BROWNSHIP2:
				enemies[i] = new Enemy_BrownShip2(info.x, info.y);
				break;
			case ENEMY_TYPE::MECH:
				enemies[i] = new Enemy_Mech(info.x, info.y);
				break;
			case ENEMY_TYPE::BLUE:
				enemies[i] = new Enemy_Blue(info.x, info.y);
				break;
			case ENEMY_TYPE::BLUE2:
				enemies[i] = new Enemy_Blue2(info.x, info.y);
				break;
			case ENEMY_TYPE::TOGETHER:
				enemies[i] = new Enemy_Together(info.x, info.y);
				break;
			case ENEMY_TYPE::TOGETHER2:
				enemies[i] = new Enemy_Together2(info.x, info.y);
				break;
			case ENEMY_TYPE::MINIBOSS:
				enemies[i] = new Enemy_MiniBoss(info.x, info.y);
				break;
			case ENEMY_TYPE::MINIBOSS2:
				enemies[i] = new Enemy_MiniBoss2(info.x, info.y);
				break;
			case ENEMY_TYPE::FOUR:
				enemies[i] = new Enemy_4(info.x, info.y);
				break;
			case ENEMY_TYPE::BOSS2:
				enemies[i] = new Enemy_Bosslvl2(info.x, info.y);
				break;
			case ENEMY_TYPE::HELICOPTER1:
				enemies[i] = new Enemy_Helicopter1(info.x, info.y);
				break;
			case ENEMY_TYPE::HELICOPTER2:
				enemies[i] = new Enemy_Helicopter2(info.x, info.y);
				break;
			case ENEMY_TYPE::HELICOPTER3:
				enemies[i] = new Enemy_Helicopter3(info.x, info.y);
				break;
			case ENEMY_TYPE::HELICOPTER4:
				enemies[i] = new Enemy_Helicopter4(info.x, info.y);
				break;
			case ENEMY_TYPE::HELICOPTER4RED:
				enemies[i] = new Enemy_Helicopter4Red(info.x, info.y);
				break;
			case ENEMY_TYPE::TURRETGREEN:
				enemies[i] = new Enemy_TurretGreen(info.x, info.y);
				break;
			case ENEMY_TYPE::TURRETRED:
				enemies[i] = new Enemy_TurretRed(info.x, info.y);
				break;
			case ENEMY_TYPE::TANK:
				enemies[i] = new Enemy_Tank(info.x, info.y);
				break;
			case ENEMY_TYPE::BOSS1:
				enemies[i] = new Enemy_Bosslvl1(info.x, info.y);
				break;
			}


			enemies[i]->texture = texture;
			enemies[i]->destroyedFx = enemyDestroyedFx;
			break;
		}
	}
}

void ModuleEnemies::OnCollision(Collider* c1, Collider* c2)
{
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{

		if (enemies[i] != nullptr && enemies[i]->GetCollider() == c1)
		{
			if (enemies[i]->life > 0)
			{

				enemies[i]->life--;

			}

			else if (enemies[i]->life == 0)
			{
				enemies[i]->OnCollision(c2); //Notify the enemy of a collision

				App->player->score += enemies[i]->score;
				App->player->money += enemies[i]->money;

				delete enemies[i];
				enemies[i] = nullptr;
				break;

			}

		}
	}
}

