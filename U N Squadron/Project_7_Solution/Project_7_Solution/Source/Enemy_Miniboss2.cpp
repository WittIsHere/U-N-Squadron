#include "Enemy_Miniboss2.h"

#include "Application.h"
#include "ModuleCollisions.h"
#include "ModuleParticles.h"
#include "ModuleCollisions.h"


Enemy_MiniBoss2::Enemy_MiniBoss2(int x, int y) : Enemy(x, y)
{
	flyAnim.PushBack({ 274, 150, 108, 40 });

	life = 15;

	score = 300;
	money = 600;

	flyAnim.speed = 0.1;

	currentAnim = &flyAnim;

	collider = App->collisions->AddCollider({ 0, 0, 100, 35 }, Collider::Type::ENEMY, (Module*)App->enemies);
}


void Enemy_MiniBoss2::Update()
{
	frameCount++;

	if (frameCount == 190 || frameCount == 230 || frameCount == 270 || frameCount == 310 || frameCount == 350 || frameCount == 440 || frameCount == 480 || frameCount == 520 || frameCount == 560 || frameCount == 600)
	{
		App->particles->AddParticle(App->particles->miniBoss, position.x + 20, position.y + 5, Collider::Type::ENEMY);
	}

	if (facingLeft == 0 && position.x < 20)
	{
		position.x += 2;
	}
	else if (facingLeft == 0 && position.x < 40)
	{
		position.y -= 1;
		position.x += 1;

	}
	else if (facingLeft == 0 && position.x < 150)
	{
		position.y -= 2;
		position.x += 1;

	}
	else if (facingLeft == 0 && position.x >= 150 && position.y < 190)
	{
		position.y += 1;
	}
	else if (facingLeft == 0 && position.x >= 150 && position.y >= 190)
	{
		position.y += 1;
		facingLeft = 1;
	}
	else if (facingLeft == 1 && position.x < 230)
	{
		position.y -= 2;
		position.x += 1;
	}
	else if (facingLeft == 1 && position.x <= 230 && position.y < 190)
	{
		position.y += 1;
	}
	else
	{
		position.y -= 2;
		position.x += 2;
	}



	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();

}