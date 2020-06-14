#include "SceneIntro.h"
#include "Welcome.h"
#include "GameOver.h"
#include "MissionComplete.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "SDL/include/SDL_scancode.h"
#include "ModuleCollisions.h"
Welcome::Welcome(bool startEnabled) : Module(startEnabled)
{

}

Welcome::~Welcome()
{

}

// Load assets
bool Welcome::Start()
{
	LOG("Loading background assets");

	bool ret = true;

	bgTexture = App->textures->Load("Assets/Screens/welcome.png");
	App->audio->PlayMusic("---", 1.0f);
	// App->audio->PlayMusic("Assets/introTitle.ogg", 1.0f);

	App->render->camera.x = 0;
	App->render->camera.y = 0;

	return ret;
}

update_status Welcome::Update()
{
	GamePad& pad = App->input->pads[0];
	if ((App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN) || (pad.a == true))
	{
		App->fade->FadeToBlack(this, (Module*)App->sceneIntro, 90);
	}

	return update_status::UPDATE_CONTINUE;
}

// Update: draw background
update_status Welcome::PostUpdate()
{
	// Draw everything --------------------------------------
	App->render->Blit(bgTexture, 0, 0, NULL);

	return update_status::UPDATE_CONTINUE;
}