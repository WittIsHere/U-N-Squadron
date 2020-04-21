#include "SceneIntro.h"
#include "GameOver.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleCollisions.h"
#include "SDL/include/SDL_scancode.h"

GameOver::GameOver(bool startEnabled) : Module(startEnabled)
{

}

GameOver::~GameOver()
{

}

// Load assets
bool GameOver::Start()
{
	LOG("Loading background assets");

	bool ret = true;

	bgTexture = App->textures->Load("Assets/Screens/loss.png");
	App->audio->PlayMusic("Assets/Music/gameover.wav", 1.0f);

	App->render->camera.x = 0;
	App->render->camera.y = 0;

	return ret;
}

update_status GameOver::Update()
{
	if (App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
	{
		App->fade->FadeToBlack(this, (Module*)App->welcome, 90);
	}

	return update_status::UPDATE_CONTINUE;
}

// Update: draw background
update_status GameOver::PostUpdate()
{
	// Draw everything --------------------------------------
	App->render->Blit(bgTexture, 0, 0, NULL);

	return update_status::UPDATE_CONTINUE;
}