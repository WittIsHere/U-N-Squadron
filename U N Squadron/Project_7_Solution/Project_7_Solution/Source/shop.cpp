#include "shop.h"

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
#include "ModuleFonts.h"
#include <stdio.h>
                   
#include "SDL/include/SDL_scancode.h"

void Shop::ParallaxingShop()
{
		if (acc == true)
		{
		
			if (botshop2 > 1)
			{
				LOG("Parallaxing shop");
				botshop2 -= speed2;
				sel2x -= speed2;
				ctr3 = 0;
				txtPos = 225;
			}
			
		}
	

}


Shop::Shop(bool startEnabled) : Module(startEnabled)
{
	acc = false;
	

	smallSelect = { 0,0,45,53 };
	largeSelect = { 0,0,284,160 }; 

	bottom1 = { 0,0,256,106 };
	bottom2 = { 256,0,256,106 };
	top = { 0,0,256,118 };
	borders = { 0,0,256,106 };
	reddish = { 0,0,33,27 };
	text = { 0,0,85,73 };

	mouth.PushBack({ 60,693,20,15 });
	mouth.PushBack({ 210,693,20,15 });
	mouth.PushBack({ 132,693,20,15 });
	mouth.speed = 0.1f;

	Grey1 = { 14,253,33,32 };
	Grey2 = { 14,253,33,32 };
	Grey3 = { 14,253,33,32 };
	Grey4 = { 14,253,33,32 };

}

Shop::~Shop()
{

}

// Load assets
bool Shop::Start()
{
	App->player->WAmmo[0] = 0;
	App->player->WAmmo[1] = 0;
	App->player->WAmmo[2] = 0;
	App->player->WAmmo[3] = 0;

	bought1 = false;
	bought2 = false;
	bought3 = false;
	bought4 = false;

	spPress = 0;
	sel1x = 5;
	sel1y = 126;
	sel2x = 265;
	sel2y = 120;

	ctr1 = 0;
	ctr2 = 0;
	ctr3 = -1;
	ctr4 = 0;

	Grey1y = 225;
	Grey2y = 225;
	Grey3y = 225;
	Grey4y = 225;

	txtPos = 28;

	LOG("Loading background assets (Shop)");

	bool ret = true;

	topStore = App->textures->Load("Assets/Sprites/Top.png");
	botStore = App->textures->Load("Assets/Sprites/Bottom.png");
	planeSelect = App->textures->Load("Assets/Sprites/SelectPlane2.png");
	itemSelect = App->textures->Load("Assets/Sprites/SelectWeapon.png");
	Borders = App->textures->Load("Assets/Sprites/Borders.png");
	Red = App->textures->Load("Assets/Sprites/red.png");
	Ports = App->textures->Load("Assets/Sprites/CharPorts.png");
	Text = App->textures->Load("Assets/Sprites/Text1.png");
	Greys = App->textures->Load("Assets/Sprites/HUD.png");


	char lookupTable[] = { "0123456789 " };
	scoreFont = App->fonts->Load("Assets/Fonts/GreenFont.png", lookupTable, 1);
	App->audio->PlayMusic("Assets/Music/shop.ogg", 1.0f);

	money = App->player->money;
	botshop2 = 256;
	App->render->camera.x = 0;
	App->render->camera.y = 0;

	return ret;
}

update_status Shop::Update()
{
	GamePad& pad = App->input->pads[0];

	if ((App->input->keys[SDL_SCANCODE_W] == KEY_STATE::KEY_DOWN) || pad.l_y < 0.0f)
	{
		if ((acc == false)&&(ctr1>0))
		{
			ctr1--;
			LOG("Pressing key W");
			if (sel1y >= 126 && sel1y <= 190)
			{
				sel1y = sel1y - 32;
			}

		}
		else if ((acc == true) && (ctr3 > 0))
		{
			ctr3--;
			if (sel2y >= 120 && sel2y <= 168)
			{
				sel2y = sel2y - 48;
			}
		}
	}

	if ((App->input->keys[SDL_SCANCODE_S] == KEY_STATE::KEY_DOWN) || pad.l_y > 0.0f)
	{
		if ((acc == false) && (ctr1 <2))
		{
			ctr1++;
			LOG("Pressing key S");
			if (sel1y >= 126 && sel1y <= 190)
			{
				sel1y = sel1y + 32;
			}

		}
		else if ((acc == true) && (ctr3 < 1))
		{
			ctr3++;
			LOG("Pressing key S");
			if (sel2y >= 120 && sel2y <= 168)
			{
				sel2y = sel2y + 48;
			}

		}
	}


	if ((App->input->keys[SDL_SCANCODE_D] == KEY_STATE::KEY_DOWN) || pad.l_x > 0.0f)
	{
		if ((acc == false)&&(ctr2 <1))
		{
			ctr2++;
			LOG("Pressing key D");
			if (sel1x >= 5 && sel1x <= 131)
			{
				sel1x = sel1x + 126;
			}

		}
		else if ((acc == true) && (ctr4 < 5))
		{
			ctr4++;
			LOG("Pressing key D");
			if (sel2x >= 9 && sel2x <= 249)
			{
				sel2x = sel2x + 40;
			}

		}
	}

	if ((App->input->keys[SDL_SCANCODE_A] == KEY_STATE::KEY_DOWN) || pad.l_x < 0.0f)
	{
		if ((acc == false) && (ctr2 >0))
		{
			ctr2--;
			LOG("Pressing key A");
			if (sel1x >= 5 && sel1x <= 131)
			{
				sel1x = sel1x - 126;
			}

		}
		else if ((acc == true) && (ctr4 > 0))
		{
			ctr4--;
			LOG("Pressing key D");
			if (sel2x >= 9 && sel2x <= 249)
			{
				sel2x = sel2x - 40;
			}

		}
	}
	
	if (spPress == 0)
	{
		
		if ((App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN) || (pad.a == true))
		{
			if ((sel1x == 5) && (sel1y == 126))
			{
				LOG("spPress == 0 (Shop.cpp -> Update");
				spPress = 1;
				acc = true;
				
			}
		}
	}

	if (spPress == 1)
	{
		if ((App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN) || (pad.a == true))
		{
			if (ctr3 == 1 && ctr4 == 5)
			{

				if (App->selectMap->check == 1)
				{
					App->fade->FadeToBlack(this, (Module*)App->levelOne, 90);
				}
				else if (App->selectMap->check == 2)
				{
					App->fade->FadeToBlack(this, (Module*)App->scene, 90);
				}
			}

			if ((ctr3 == 0 && ctr4 == 0) && (bought1 == false))
			{
				if (money >= item1)
				{
						App->player->money -= item1;
						money -= item1;
						bought1 = true;
						App->player->WAmmo[0] = 3;
						Grey1y -= 99;
				}
			}

			if ((ctr3 == 1 && ctr4 == 0) && (bought2 == false))
			{
				if (money >= item2)
				{
					
						App->player->money -= item2;
						money -= item2;
						bought2 = true;
						App->player->WAmmo[1] = 50;
						Grey2y -= 51;
				}
			}

			if ((ctr3 == 0 && ctr4 == 1) && (bought3 == false))
			{
				if (money >= item3)
				{

					App->player->money -= item3;
					money -= item3;
					bought3 = true;
					App->player->WAmmo[2] = 5;
					Grey3y -= 99;
				}
			}

			if ((ctr3 == 0 && ctr4 == 4) && (bought4 == false))
			{
				if (money >= item4)
				{
			
						App->player->money -= item4;
						money -= item4;
						bought4 = true;
						App->player->WAmmo[3] = 10;
						Grey4y -= 99;
					
				}
				
			}

		}
	}

	if (App->input->keys[SDL_SCANCODE_6] == KEY_STATE::KEY_DOWN)
	{
		App->player->money = 999999;
		money = 999999;
	}


	mouth.Update();
	ParallaxingShop();
	return update_status::UPDATE_CONTINUE;
}

// Update: draw background
update_status Shop::PostUpdate()
{
	// Draw everything --------------------------------------

	

	

	App->render->Blit(botStore, 0, 118, &bottom1, 0);
	
	App->render->Blit(planeSelect, (sel1x - 125), (sel1y - 65), &largeSelect, 0);
	App->render->Blit(Red, 6, 126, &reddish, 0);
	App->render->Blit(Borders, 0, 118, &borders, 0);
	App->render->Blit(botStore, botshop2, 118, &bottom2, 0);
	App->render->Blit(Greys, 16, Grey1y, &Grey1, 0);
	App->render->Blit(Greys, 16, Grey2y, &Grey2, 0);
	App->render->Blit(Greys, 57, Grey3y, &Grey3, 0);
	App->render->Blit(Greys, 176, Grey4y, &Grey4, 0);
	App->render->Blit(itemSelect, sel2x, sel2y, &smallSelect, 0);

	App->render->Blit(topStore, 0, 0, &top, 0);
	//App->render->Blit(planeSelect, (sel1x-4), (sel1y-2), &largeSelect, 0);
	sprintf_s(scoreText, 10, " %7d", money);
	App->fonts->BlitText(8, 111, scoreFont, scoreText);
	App->render->Blit(Ports, 110, 45, &(mouth.GetCurrentFrame()), 0.10f); // flag animation
	App->render->Blit(Text, 157, txtPos, &text, 0);

	return update_status::UPDATE_CONTINUE;
}