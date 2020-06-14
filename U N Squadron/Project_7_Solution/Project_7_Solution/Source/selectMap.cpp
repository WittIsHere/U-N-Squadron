#include "selectMap.h"

#include "SceneIntro.h"
#include "GameOver.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleCollisions.h"
#include "ModuleScene.h"
#include "levelOne.h"
#include "ModulePlayer.h"
#include "shop.h"


#include "SDL/include/SDL_scancode.h"

MapSelect::MapSelect(bool startEnabled) : Module(startEnabled)
{
	_yellow = { 0,0,15,15 };
	command = { 0,0,256,224 };
	_icons = { 0,0,256,224 };
	_mouth.PushBack({ 58,522,8,7 });
	_mouth.PushBack({ 130,522,8,7 });
    _mouth.PushBack({ 208,522,8,7 });
	
	_mouth.speed = 0.12f;
}

MapSelect::~MapSelect()
{

}

// Load assets
bool MapSelect::Start()
{
	yell = 32;
	LOG("Loading background assets (mapSelect)");
	check = 0;
	bool ret = true;

	bgTexture = App->textures->Load("Assets/Screens/Command.png");
	Icons = App->textures->Load("Assets/Screens/Icons.png");
	Yellow = App->textures->Load("Assets/Screens/Yellow.png");
	App->player->portrait.loop = true;
	App->store->acc = false;
	mouth = App->textures->Load("Assets/Sprites/CharPorts.png");


	App->render->camera.x = 0;
	App->render->camera.y = 0;

	return ret;
}

update_status MapSelect::Update()
{
	GamePad& pad = App->input->pads[0];

	if ((App->input->keys[SDL_SCANCODE_S] == KEY_STATE::KEY_DOWN) || pad.l_y > 0.0f)
	{
		LOG("Pressing key S");
		if (yell == 32)
		{
			yell = yell + 16;
		}
		else if (yell == 48)
		{
			yell = yell - 16;
		}

	}

	if ((App->input->keys[SDL_SCANCODE_W] == KEY_STATE::KEY_DOWN) || pad.l_y < 0.0f)
	{
		LOG("Pressing key W");
		if (yell == 48)
		{
			yell = yell - 16;
		}
		else if (yell == 32)
		{
			yell = yell+16;
		}

	}


	if ((App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN) || (pad.a == true))
	{
		if (yell == 48) // Level One
		{
			check = 1;
			App->player->check = 1;
			App->fade->FadeToBlack(this, (Module*)App->store, 50);
		}
	}
    if ((App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN) || (pad.a == true))
	{
		if (yell == 32)
		{
			check = 2;
			App->player->check = 2;
    			App->fade->FadeToBlack(this, (Module*)App->store, 50);
		}
	}
	_mouth.Update();
	return update_status::UPDATE_CONTINUE;
}

// Update: draw background
update_status MapSelect::PostUpdate()
{
	// Draw everything --------------------------------------

	App->render->Blit(bgTexture, 0, 0, &command, 0);
	App->render->Blit(Yellow, 65, yell, &_yellow, 0);
	App->render->Blit(Icons, 0, 0, &_icons, 0);
	App->render->Blit(mouth, 28, 141, &(_mouth.GetCurrentFrame()), 0.10f); // flag animation
	

	return update_status::UPDATE_CONTINUE;
}