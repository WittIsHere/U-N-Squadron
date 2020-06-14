#include "Enemy_Helicopter4Red.h"

#include "Application.h"
#include "ModuleCollisions.h"
#include "ModuleParticles.h"


Enemy_Helicopter4Red::Enemy_Helicopter4Red(int x, int y) : Enemy(x, y)
{
	flyAnim.PushBack({ 560, 65, 32, 11 });
	flyAnim.PushBack({ 597, 65, 32, 11 });
	flyAnim.PushBack({ 637, 59, 30, 17 });
	flyAnim.PushBack({ 670, 59, 30, 17 });
	flyAnim.PushBack({ 637, 59, 30, 17 });
	flyAnim.PushBack({ 670, 59, 30, 17 });
	flyAnim.PushBack({ 637, 59, 30, 17 });
	flyAnim.PushBack({ 670, 59, 30, 17 });
	flyAnim.PushBack({ 637, 59, 30, 17 });
	flyAnim.PushBack({ 670, 59, 30, 17 });
	flyAnim.PushBack({ 637, 59, 30, 17 });
	flyAnim.PushBack({ 670, 59, 30, 17 });
	flyAnim.PushBack({ 637, 59, 30, 17 });
	flyAnim.PushBack({ 670, 59, 30, 17 });
	flyAnim.PushBack({ 637, 59, 30, 17 });
	flyAnim.PushBack({ 670, 59, 30, 17 });
	flyAnim.PushBack({ 637, 59, 30, 17 });
	flyAnim.PushBack({ 670, 59, 30, 17 });
	flyAnim.PushBack({ 637, 59, 30, 17 });
	flyAnim.PushBack({ 670, 59, 30, 17 });
	flyAnim.PushBack({ 637, 59, 30, 17 });
	flyAnim.PushBack({ 670, 59, 30, 17 });
	flyAnim.PushBack({ 637, 59, 30, 17 });
	flyAnim.PushBack({ 670, 59, 30, 17 });
	flyAnim.PushBack({ 637, 59, 30, 17 });
	flyAnim.PushBack({ 670, 59, 30, 17 });
	flyAnim.PushBack({ 637, 59, 30, 17 });
	flyAnim.PushBack({ 670, 59, 30, 17 });


	flyAnim.speed = 0.1;

	score = 100;
	money = 300;

	currentAnim = &flyAnim;

	collider = App->collisions->AddCollider({ 0, 0, 24, 24 }, Collider::Type::ENEMY, (Module*)App->enemies);
}


void Enemy_Helicopter4Red::Update()
{
	frameCount++;

	if (frameCount == 60)
	{
		App->particles->AddParticle(App->particles->enemyBullet, position.x + 20, position.y + 5, Collider::Type::ENEMY_SHOT);
	}

	if (facingLeft == 0 && position.x > 260)
	{
		position.x -= 2;
	}
	else if (facingLeft == 0 && position.x > 150)
	{
		position.y -= 1;
		position.x -= 2;

	}
	else if (facingLeft == 0 && position.x > 60)
	{
		position.x -= 2;
	}
	else
	{
		position.x -= 2;
		position.y += 1;
	}



	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();

}