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
#include <stdio.h>
#include "SDL/include/SDL_scancode.h"


ModulePlayer::ModulePlayer(bool startEnabled) : Module(startEnabled)
{
	// idle animation - just one sprite
	idleAnim.PushBack({ 154, 38, 33,11 });

	// move upwards
	upAnim.PushBack({ 188, 39,33,14 });

	// Move down
	downAnim.PushBack({ 119, 38, 33 ,14 });

}

ModulePlayer::~ModulePlayer()
{
	
}

bool ModulePlayer::Start()
{
	
	LOG("Loading player textures");

	if(destroyed == true)
	{
		destroyed = false;
	}



	bool ret = true;

	texture = App->textures->Load("Assets/Sprites/Spaceships.png");
	currentAnimation = &idleAnim;
	
	lives = App->textures->Load("Assets/Sprites/lives.png");
	portrait = App->textures->Load("Assets/Sprites/portrait.png");

	laserFx = App->audio->LoadFx("Assets/Music/bullet.wav");
	explosionFx = App->audio->LoadFx("Assets/Music/explosion.wav");

	position.x = 30;
	position.y = 105;

	limits1.x = 0;
	limits2.x = 300;
	collider = App->collisions->AddCollider({ position.x, position.y, 32, 16 }, Collider::Type::PLAYER, this);

	// TODO 4: Try loading "rtype_font3.png" that has two rows to test if all calculations are correct
	char lookupTable[] = { "! @,_./0123456789$;< ?abcdefghijklmnopqrstuvwxyz" };
	scoreFont = App->fonts->Load("Assets/Fonts/rtype_font3.png", lookupTable, 2);

	return ret;
}

update_status ModulePlayer::Update()
{
	if ((position.x > 5000) || (App->input->keys[SDL_SCANCODE_3] == KEY_STATE::KEY_DOWN))
	{
		
		App->fade->FadeToBlack((Module*)App->scene, (Module*)App->missionComplete, 90);
		
	}

	// Moving the player and the limits with the camera scroll
	 App->player->position.x += 1;
	 App->player->limits1.x += 1;
	 App->player->limits2.x += 1;

	if (App->input->keys[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
	{
		if (position.x > limits1.x)
		{
			position.x -= speed;
		}
	}

	if (App->input->keys[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
	{
		if (position.x < limits2.x)
		{
			position.x += speed;
		}
	}

	if (App->input->keys[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
	{
		if (position.y < 210)
		{
			position.y += speed;
			if (currentAnimation != &downAnim)
			{
				downAnim.Reset();
				currentAnimation = &downAnim;
			}
		}
	}

	if (App->input->keys[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT)
	{
		if (position.y > 30)
		{
			position.y -= speed;
			if (currentAnimation != &upAnim)
			{
				upAnim.Reset();
				currentAnimation = &upAnim;
			}
		}
	}

	if (App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
	{
		App->particles->AddParticle(App->particles->laser, position.x + 20, position.y+5, Collider::Type::PLAYER_SHOT);
		App->audio->PlayFx(laserFx);
	}
	if (App->input->keys[SDL_SCANCODE_1] == KEY_STATE::KEY_DOWN)
	{
		if (godMode == FALSE)
		{
			godMode = TRUE;
		}
		else
		{
			godMode = FALSE;
		}

	}
	if (App->input->keys[SDL_SCANCODE_4] == KEY_STATE::KEY_DOWN)
	{
		App->fade->FadeToBlack((Module*)App->scene, (Module*)App->gameOver, 90);
	}
	
	// If no up/down movement detected, set the current animation back to idle
	if (App->input->keys[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE)
		currentAnimation = &idleAnim;

	collider->SetPos(position.x, position.y);

	currentAnimation->Update();

	if(destroyed)
	{
		
		destroyedCountdown--;
		if (destroyedCountdown <= 0)
			
			App->fade->FadeToBlack((Module*)App->scene, (Module*)App->gameOver, 90);
			//return update_status::UPDATE_STOP;
	}

	return update_status::UPDATE_CONTINUE;
}

update_status ModulePlayer::PostUpdate()
{
	if (!destroyed)
	{
		SDL_Rect rect = currentAnimation->GetCurrentFrame();
		App->render->Blit(texture, position.x, position.y, &rect);
	}
	// Draw UI (score) --------------------------------------
	sprintf_s(scoreText, 10, "%7d", score);

	// TODO 3: Blit the text of the score in at the bottom of the screen
	App->fonts->BlitText(50, 20, scoreFont, scoreText);

	App->fonts->BlitText(20, 10, scoreFont, "score");

	App->render->Blit(portrait, 90, 5, nullptr, 0, false);
	App->render->Blit(lives, 15, 200, nullptr, 0, false);

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

			destroyed = true;
		
			
		}
	}
}