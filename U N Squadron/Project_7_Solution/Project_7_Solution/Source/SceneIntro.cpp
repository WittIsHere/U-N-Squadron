#include "SceneIntro.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "SDL/include/SDL_scancode.h"
#include "Animation.h"
#include "ModuleCollisions.h"


SceneIntro::SceneIntro(bool startEnabled) : Module(startEnabled)
{
	Title = { 0,0,239,69 }; 
	Tm = {0,0, 17,9 };
	Options = {0,0,94,31  }; 
	Select = {0,0,13,16  };
	Credits = {0,0,218,35  };


	Horses.PushBack({ 0,0,116,166 });
	Horses.PushBack({ 116,0,126,166 });
	Horses.PushBack({ 242,0,129,166 });
	Horses.speed = 0.11f;


}

SceneIntro::~SceneIntro()
{

}

// Load assets
bool SceneIntro::Start()
{
	LOG("Loading background assets (MenuScreen)");
	TmY = 109;
	timer = 0;
	bool ret = true;

	mTitle = App->textures->Load("Assets/Screens/Title.png");
	mTm = App->textures->Load("Assets/Screens/Tm.png");
	mSelect = App->textures->Load("Assets/Screens/Select.png");
	mOptions = App->textures->Load("Assets/Screens/Options.png");
	mCredits = App->textures->Load("Assets/Screens/Credits.png");

	Horse = App->textures->Load("Assets/Screens/HorseAnim.png");
	
	App->collisions->CleanUp();


	App->audio->PlayMusic("Assets/Music/introTitle.ogg", 1.0f);

	App->render->camera.x = 0;
	App->render->camera.y = 0;

	return ret;
}

update_status SceneIntro::Update()
{
	timer++;

	GamePad& pad = App->input->pads[0];

	if ((App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN) || (pad.a == true))
	{
		if (TmY == 109)
		{
			App->fade->FadeToBlack(this, (Module*)App->selectMap, 90);
		}
	}


	if ((App->input->keys[SDL_SCANCODE_S] == KEY_STATE::KEY_DOWN) || pad.l_y > 0.0f)
	{
		LOG("Pressing key S");
		if (TmY == 109) 
		{
			TmY = TmY + 17;
		}
		else if (TmY == 126) 
		{
			TmY = TmY - 17;
		}

	}

	if ((App->input->keys[SDL_SCANCODE_W] == KEY_STATE::KEY_DOWN) || pad.l_y < 0.0f)
	{
		LOG("Pressing key W");
		if (TmY == 109) 
		{
			TmY = TmY + 17;
		}
		else if (TmY == 126) 
		{
			TmY = TmY - 17;
		}

	}

	Horses.Update();
	return update_status::UPDATE_CONTINUE;
}

// Update: draw background
update_status SceneIntro::PostUpdate()
{
	// Draw everything --------------------------------------
	

	
	App->render->Blit(Horse, 75, 32, &(Horses.GetCurrentFrame()), 0.10f); // flag animation

	App->render->Blit(mTitle, 9, 16, &Title,0);
	App->render->Blit(mTm, 227, 85, &Tm,0);
	App->render->Blit(mSelect, 68, TmY, &Select,0);
	App->render->Blit(mOptions, 83, 114, &Options,0);
	App->render->Blit(mCredits, 20, 184, &Credits,0);
	

	return update_status::UPDATE_CONTINUE;
}  