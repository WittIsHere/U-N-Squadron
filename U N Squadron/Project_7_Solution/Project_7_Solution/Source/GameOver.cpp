#include "SceneIntro.h"
#include "GameOver.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleCollisions.h"
#include "levelOne.h"

#include "SDL/include/SDL_scancode.h"

GameOver::GameOver(bool startEnabled) : Module(startEnabled)
{


	
	
	flames.PushBack({ 0,0,256,224 });
	flames.PushBack({ 256,0,512,224 });
	/*flames.PushBack({ 512,0,768,224 });
	flames.PushBack({ 768,0,1024,224 });*/
	flames.speed = 0.05f;
}

GameOver::~GameOver()
{

}

// Load assets
bool GameOver::Start()
{
	LOG("Loading background assets (GameOver)");

	bool ret = true;

	bgTexture = App->textures->Load("Assets/Screens/LoseScreen.png");
	App->audio->PlayMusic("Assets/Music/gameover.wav", 1.0f);

	App->render->camera.x = 0;
	App->render->camera.y = 0;

	return ret;
}

update_status GameOver::Update()
{
	GamePad& pad = App->input->pads[0];

	if ((App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN )||(pad.a == true))
	{
		App->fade->FadeToBlack(this, (Module*)App->sceneIntro, 90);
	}

	flames.Update();
	return update_status::UPDATE_CONTINUE;
}

// Update: draw background
update_status GameOver::PostUpdate()
{
	// Draw everything --------------------------------------

	
	
	App->render->Blit(bgTexture, 0, 0, &(flames.GetCurrentFrame()), 0.10f); // flag animation

	return update_status::UPDATE_CONTINUE;
}