#include "SceneIntro.h"
#include "MissionComplete.h"
#include "GameOver.h"
#include "Welcome.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "SDL/include/SDL_scancode.h"

MissionComplete::MissionComplete(bool startEnabled) : Module(startEnabled)
{
	win = { 0 ,0, 256,224 };
}

MissionComplete::~MissionComplete()
{

}

// Load assets
bool MissionComplete::Start()
{
	LOG("Loading background assets");

	bool ret = true;

	bgTexture = App->textures->Load("Assets/Screens/WinScreen.png");
	App->audio->PlayMusic("Assets/Music/win.ogg", 1.0f);

	App->render->camera.x = 0;
	App->render->camera.y = 0;

	return ret;
}

update_status MissionComplete::Update()
{
	GamePad& pad = App->input->pads[0];

	if ((App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN) || (pad.a == true))
	{
		App->fade->FadeToBlack(this, (Module*)App->sceneIntro, 90);
	}

	return update_status::UPDATE_CONTINUE;
}

// Update: draw background
update_status MissionComplete::PostUpdate()
{
	// Draw everything --------------------------------------
	App->render->Blit(bgTexture, 0, 0, &win,0);

	return update_status::UPDATE_CONTINUE;
}