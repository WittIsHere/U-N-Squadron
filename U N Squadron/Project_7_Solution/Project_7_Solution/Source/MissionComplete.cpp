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

}

MissionComplete::~MissionComplete()
{

}

// Load assets
bool MissionComplete::Start()
{
	LOG("Loading background assets");

	bool ret = true;

	bgTexture = App->textures->Load("Assets/Screens/win.png");
	App->audio->PlayMusic("Assets/Music/win.ogg", 1.0f);

	App->render->camera.x = 0;
	App->render->camera.y = 0;

	return ret;
}

update_status MissionComplete::Update()
{
	if (App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
	{
		App->fade->FadeToBlack(this, (Module*)App->welcome, 90);
	}

	return update_status::UPDATE_CONTINUE;
}

// Update: draw background
update_status MissionComplete::PostUpdate()
{
	// Draw everything --------------------------------------
	App->render->Blit(bgTexture, 0, 0, NULL);

	return update_status::UPDATE_CONTINUE;
}