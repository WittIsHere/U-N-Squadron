#include "ModulePlayer.h"
#include "ModuleScene.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"
#include "ModuleFadeToBlack.h"
#include "ModuleFonts.h"
#include "GameOver.h"
#include "Welcome.h"
#include "MissionComplete.h"
#include "shop.h"
#include "selectMap.h"
#include "levelOne.h"
#include <stdio.h>
#include "SDL/include/SDL_scancode.h"


void ModulePlayer::WeaponsSelect()
{
	int a = 0;
	for (int i = 0; i < 4; i++)
	{
		if (Weapons[i] == true && checking[i] == false)
		{

			WPos[0] = 226;
			WPos[1] = 226;
			WPos[2] = 226;
			WPos[3] = 226;
			usingW[0] = false;
			usingW[1] = false;
			usingW[2] = false;
			usingW[3] = false;
			WPos[i] = 197;
			usingW[i] = true;
			special = WAmmo[i];
			checking[i] = true;
			break;
		}
		else
		{
			if (checking[0] == true && checking[1] == true)
			{
				if (checking[2] == true && checking[3] == true)
				{
					for (int i = 0; i < 4; i++)
					{
						checking[i] = false;
					}
				}
			}
		}
	}

}



ModulePlayer::ModulePlayer(bool startEnabled) : Module(startEnabled)
{
	// idle animation - just one sprite
	idleAnim.PushBack({ 154, 38, 33,11 });

	// move upwards
	upAnim.PushBack({ 188, 39,33,14 });

	// Move down
	downAnim.PushBack({ 119, 38, 33 ,14 });

	HuD = { 0,0,256,224 };
	Weap1 = { 131,222,94,18 };
	Weap2 = { 131,302,94,18 };
	Weap3 = { 131,63,94,18 };
	Weap4 = { 131,86,94,18 };

}

ModulePlayer::~ModulePlayer()
{
	    
}

bool ModulePlayer::Start()
{
	livesRe = 1;
	powLevel = 0;
	portrait.PushBack({ 0,0,42,34 });
	portrait.PushBack({ 0,34,42,34 });
	portrait.PushBack({ 0,68,42,34 });
	portrait.PushBack({ 0,102,42,34 });
	portrait.PushBack({ 0,136,42,34 });
	portrait.PushBack({ 0,170,42,34 });
	portrait.PushBack({ 0,204,42,34 });
	portrait.PushBack({ 0,238,42,34 });
	portrait.speed = 0.12f;
	portrait.loop = false;
	
	WPos[0] = 226;
	WPos[1] = 226;
	WPos[2] = 226;
	WPos[3] = 226;



	Weapons[0] = { App->store->bought1 };
	Weapons[1] = { App->store->bought2 };
	Weapons[2] = { App->store->bought3 };
	Weapons[3] = { App->store->bought4 };
	


	score = 0;
	countFrame = 0;
	LOG("Loading player textures");

	if(destroyed == true)
	{
		destroyed = false;
	}



	bool ret = true;

	texture = App->textures->Load("Assets/Sprites/Spaceships.png");
	currentAnimation = &idleAnim;
	
	topHud = App->textures->Load("Assets/Sprites/hud5.png");

	laserFx = App->audio->LoadFx("Assets/Music/bullet.wav");
	explosionFx = App->audio->LoadFx("Assets/Music/explosion.wav");

	portraitA = App->textures->Load("Assets/Sprites/portraits.png");
	WeaponsT = App->textures->Load("Assets/Sprites/HUD.png");

	position.x = 30;
	position.y = 115;

	
	collider = App->collisions->AddCollider({ position.x, position.y, 32, 16 }, Collider::Type::PLAYER, this);

	//char lookupTable[] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,?!$= " }; // SquadFont4
	char lookupTable[] = { "0123456789 " };


	scoreFont = App->fonts->Load("Assets/Fonts/GreenFont.png", lookupTable, 1);

	return ret;
}

update_status ModulePlayer::Update()
{
	
	if (App->store->bought1 == false)
	{
		checking[0] = true;
	}
	if (App->store->bought2 == false)
	{
		checking[1] = true;
	}
	if (App->store->bought3 == false)
	{
		checking[2] = true;
	}
	if (App->store->bought4 == false)
	{
		checking[3] = true;
	}

	countFrame++;
	GamePad& pad = App->input->pads[0];


	 // If no up/down movement detected, set the current animation back to idle
	 if (App->input->keys[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE
		 && App->input->keys[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE)
		 currentAnimation = &idleAnim;

	 collider->SetPos(position.x, position.y);

	 currentAnimation->Update();


	 // Player Movement
	if (App->input->keys[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT || pad.l_x < 0.0f)
	{
		if (position.x > 1)
		{
			position.x -= speed;
		}
	}

	if (App->input->keys[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT || pad.l_x > 0.0f)
	{
		if (position.x < 220) 
		{
			position.x += speed;
		}
	}

	if (App->input->keys[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT || pad.l_y > 0.0f)
	{
		if (position.y < 185)
		{
			position.y += speed;
			if (currentAnimation != &downAnim)
			{
				downAnim.Reset();
				currentAnimation = &downAnim;
			}
		}
	}

	if (App->input->keys[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT || pad.l_y < 0.0f)
	{
		if (position.y > 40)
		{
			position.y -= speed;
			if (currentAnimation != &upAnim)
			{
				upAnim.Reset();
				currentAnimation = &upAnim;
			}
		}
	}

	// Shooting
	if (((App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_REPEAT) && (destroyed == false))||(pad.a == true && destroyed == false))
	{
		if (shotCountdown == 0)
		{
			if (powLevel == 0)
			{
				Particle* newParticle = App->particles->AddParticle(App->particles->laser, position.x + 20, position.y + 5, Collider::Type::PLAYER_SHOT);
				newParticle->collider->AddListener(this);
				App->audio->PlayFx(laserFx);
				shotCountdown = shotMaxCountdown;
			}
			else if (powLevel == 1)
			{
				Particle* newParticle = App->particles->AddParticle(App->particles->laser, position.x + 20, position.y + 7, Collider::Type::PLAYER_SHOT);
				Particle* newParticle2 = App->particles->AddParticle(App->particles->laser, position.x + 20, position.y+4, Collider::Type::PLAYER_SHOT);
				newParticle->collider->AddListener(this);
				newParticle2->collider->AddListener(this);
			
				App->audio->PlayFx(laserFx);
				shotCountdown = shotMaxCountdown;
			}
			else if (powLevel >= 2)
			{
				Particle* newParticle = App->particles->AddParticle(App->particles->laser, position.x + 15, position.y , Collider::Type::PLAYER_SHOT);
				Particle* newParticle2 = App->particles->AddParticle(App->particles->laser, position.x + 20, position.y + 5, Collider::Type::PLAYER_SHOT);
				Particle* newParticle3 = App->particles->AddParticle(App->particles->laser, position.x + 15, position.y + 10, Collider::Type::PLAYER_SHOT);
				newParticle->collider->AddListener(this);
				newParticle2->collider->AddListener(this);
				newParticle3->collider->AddListener(this);
				App->audio->PlayFx(laserFx);
				shotCountdown = shotMaxCountdown;
			}
		}
	}
	// Update shot countdown
	if (shotCountdown > 0)
		--shotCountdown; 
	// Debugging
	if (App->input->keys[SDL_SCANCODE_1] == KEY_STATE::KEY_DOWN)
	{
		if (godMode == FALSE)
		{
			LOG("GodMode Enabled");
			godMode = TRUE;
		}
		else
		{
			LOG("GodMode Disabled");
			godMode = FALSE;
		}
    }

	if (App->input->keys[SDL_SCANCODE_3] == KEY_STATE::KEY_DOWN)
	{
	
		if (App->selectMap->check == 1)
			App->fade->FadeToBlack((Module*)App->levelOne, (Module*)App->missionComplete, 90);
		else if (App->selectMap->check == 2)
			App->fade->FadeToBlack((Module*)App->scene, (Module*)App->missionComplete         , 90);
	}

	if (App->input->keys[SDL_SCANCODE_4] == KEY_STATE::KEY_DOWN)
	{
	
		if (App->selectMap->check == 1)
			App->fade->FadeToBlack((Module*)App->levelOne, (Module*)App->gameOver, 90);
		else if (App->selectMap->check == 2)
			App->fade->FadeToBlack((Module*)App->scene, (Module*)App->gameOver, 90);
	
	}

	if (App->input->keys[SDL_SCANCODE_5] == KEY_STATE::KEY_DOWN)
	{
		for (int i = 0; i < 4; i++)
		{
			LOG("Ammo up");
			WAmmo[i] = 99;
		}
	}

	

	if(destroyed)
	{
		

			if (App->selectMap->check == 2)
			{
				App->fade->FadeToBlack((Module*)App->scene, (Module*)App->gameOver, 90);
			}
			else if (App->selectMap->check == 1)
			{
				App->fade->FadeToBlack((Module*)App->levelOne, (Module*)App->gameOver, 90);
			}
			//return update_status::UPDATE_STOP;
	}

	if (App->input->keys[SDL_SCANCODE_E] == KEY_STATE::KEY_DOWN || (pad.b == true))
	{
		WeaponsSelect();
	}
		
	if (App->input->keys[SDL_SCANCODE_R] == KEY_STATE::KEY_DOWN || (pad.x == true))
	{
		for (int i = 0; i < 4; i++)
		{
			if (usingW[i] == true && WAmmo[i] > 0 )
			{
				WAmmo[i]--;
				special = WAmmo[i];
				if (i == 0)
				{
					LOG("Weapon 1");
					App->particles->AddParticle(App->particles->Cluster, position.x - 115, position.y - 85, Collider::Type::PLAYER_SHOT);
					App->particles->AddParticle(App->particles->Cluster, position.x - 115, position.y - 85, Collider::Type::PLAYER_SHOT);
					App->particles->AddParticle(App->particles->Cluster, position.x - 115, position.y - 85, Collider::Type::NONE);

				}            
				else if (i == 1)
				{
					LOG("Weapon 2");
					App->particles->AddParticle(App->particles->pBomb, position.x + 10, position.y + 5, Collider::Type::PLAYER_SHOT);
					App->particles->AddParticle(App->particles->pBomb, position.x + 10, position.y + 5, Collider::Type::PLAYER_SHOT);
				}
				else if (i == 2)
				{
					LOG("Weapon 3");
					App->particles->AddParticle(App->particles->Megacrush, position.x + 20, position.y - 5, Collider::Type::PLAYER_SHOT);
					App->particles->AddParticle(App->particles->Megacrush, position.x + 20, position.y - 5, Collider::Type::PLAYER_SHOT);
					App->particles->AddParticle(App->particles->Megacrush, position.x + 20, position.y - 5, Collider::Type::PLAYER_SHOT);            
					App->particles->AddParticle(App->particles->Megacrush, position.x + 20, position.y - 5, Collider::Type::PLAYER_SHOT);
					App->particles->AddParticle(App->particles->Megacrush, position.x + 20, position.y - 5, Collider::Type::PLAYER_SHOT);
				}
				else if (i == 3)
				{         
					LOG("Weapon 4");
					App->particles->AddParticle(App->particles->blueLaser1, position.x + 23, position.y + 2, Collider::Type::PLAYER_SHOT);
					App->particles->AddParticle(App->particles->blueLaser1, position.x + 23, position.y + 2, Collider::Type::PLAYER_SHOT);
					App->particles->AddParticle(App->particles->blueLaser1, position.x + 23, position.y + 2, Collider::Type::PLAYER_SHOT);
					App->particles->AddParticle(App->particles->blueLaser1, position.x + 23, position.y + 2, Collider::Type::PLAYER_SHOT);
					App->particles->AddParticle(App->particles->blueLaser1, position.x + 23, position.y + 2, Collider::Type::PLAYER_SHOT);
				}
			}
		
		}
	}




	if (App->selectMap->check == 1)
	{
		if (App->levelOne->powAtaken == false)
		{
			if ((position.x + 20 >= App->levelOne->powApos) && (position.x + 20 < App->levelOne->powApos + 15))
				if (position.y + 5 >= 60 && position.y + 5 < 75)
				{
					powLevel++;
					App->levelOne->powApos -= 400;
					App->levelOne->powAtaken = true;
					powC++;
					totalPow++;
				}
		}

		if (App->levelOne->powBtaken == false)
		{
			if ((position.x + 20 >= App->levelOne->powBpos) && (position.x + 20 < App->levelOne->powBpos + 15))
				if (position.y + 5 >= 80 && position.y + 5 < 105)
				{
					powLevel++;
					App->levelOne->powBpos -= 400;
					App->levelOne->powBtaken = true;
					powC++;
					totalPow++;
				}
		}

	}
	if (App->selectMap->check == 2)
	{
		if (App->scene->powAtaken == false)
		{
			if ((position.x + 20 >= App->scene->powApos) && (position.x + 20 < App->scene->powApos + 15))
				if (position.y + 5 >= 60 && position.y + 5 < 75)
				{
					powLevel++;
					App->scene->powApos -= 400;
					App->scene->powAtaken = true;
					powC++;
					totalPow++;
				}
		}

		if (App->scene->powBtaken == false)
		{
			if ((position.x + 20 >= App->scene->powBpos) && (position.x + 20 < App->scene->powBpos + 15))
				if (position.y + 5 >= 80 && position.y + 5 < 105)
				{
					powLevel++;
					App->scene->powBpos -= 400;
					App->scene->powBtaken = true;
					powC++;
					totalPow++;
				}
		}

	}




	portrait.Update();
	return update_status::UPDATE_CONTINUE;
}

update_status ModulePlayer::PostUpdate()
{
	if (!destroyed)
	{
		
		SDL_Rect rect = currentAnimation->GetCurrentFrame();
		App->render->Blit(texture, position.x, position.y, &rect);
	}

	Experiment++;

	App->render->Blit(topHud, 0, 0, &HuD, 0);
	App->render->Blit(portraitA, 70, 6, &(portrait.GetCurrentFrame()), 0.10f);

	sprintf_s(scoreText, 10, " %7d", score);
	App->fonts->BlitText(-9, 29, scoreFont, scoreText);

	sprintf_s(scoreText, 10, " %7d", money);
	App->fonts->BlitText(110, 29, scoreFont, scoreText);


	sprintf_s(scoreText, 10, " %7d", powC);
	App->fonts->BlitText(142, 29, scoreFont, scoreText);

	sprintf_s(scoreText, 10, " %7d", totalPow);
	App->fonts->BlitText(175, 29, scoreFont, scoreText);

	sprintf_s(scoreText, 10, " %7d", livesRe);
	App->fonts->BlitText(-25, 205, scoreFont, scoreText);


	App->render->Blit(WeaponsT, 134, WPos[0], &Weap1, 0);
	App->render->Blit(WeaponsT, 134, WPos[1], &Weap2, 0);
	App->render->Blit(WeaponsT, 134, WPos[2], &Weap3, 0);
	App->render->Blit(WeaponsT, 134, WPos[3], &Weap4, 0);

	sprintf_s(scoreText, 10, " %7d", special);
	App->fonts->BlitText(170, 207, scoreFont, scoreText);

	return update_status::UPDATE_CONTINUE;
}

void ModulePlayer::OnCollision(Collider* c1, Collider* c2)
{
	if (godMode == FALSE)
	{
		if (c1 == collider && destroyed == false)
		{
			App->particles->AddParticle(App->particles->explosion, position.x, position.y, Collider::Type::NONE, 9);
			App->particles->AddParticle(App->particles->explosion, position.x + 8, position.y + 11, Collider::Type::NONE, 14);
			App->particles->AddParticle(App->particles->explosion, position.x - 7, position.y + 12, Collider::Type::NONE, 40);
			App->particles->AddParticle(App->particles->explosion, position.x + 5, position.y - 5, Collider::Type::NONE, 28);
			App->particles->AddParticle(App->particles->explosion, position.x - 4, position.y - 4, Collider::Type::NONE, 21);

			App->audio->PlayFx(explosionFx);
			livesRe = 0;
			destroyed = true;
			powC = 0;
	
			
		}
	}
}