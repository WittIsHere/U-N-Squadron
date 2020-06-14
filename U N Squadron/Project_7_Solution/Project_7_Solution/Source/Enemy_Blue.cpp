#include "Enemy_Blue.h"

#include "Application.h"
#include "ModuleCollisions.h"
#include "ModuleParticles.h"

Enemy_Blue::Enemy_Blue(int x, int y) : Enemy(x, y)
{
	flyAnim.PushBack({ 307, 130, 31, 10 });
	flyAnim.PushBack({ 307, 130, 31, 10 });
	flyAnim.PushBack({ 307, 130, 31, 10 });
	flyAnim.PushBack({ 307, 130, 31, 10 });
	flyAnim.PushBack({ 307, 130, 31, 10 });
	flyAnim.PushBack({ 307, 130, 31, 10 });
	flyAnim.PushBack({ 307, 130, 31, 10 });
	flyAnim.PushBack({ 274, 130, 31, 15 });
	flyAnim.PushBack({ 274, 130, 31, 15 });
	flyAnim.PushBack({ 274, 130, 31, 15 });
	flyAnim.PushBack({ 274, 130, 31, 15 });
	flyAnim.PushBack({ 307, 130, 31, 10 });
	flyAnim.PushBack({ 307, 130, 31, 10 });
	flyAnim.PushBack({ 307, 130, 31, 10 });
	flyAnim.PushBack({ 307, 130, 31, 10 });
	flyAnim.PushBack({ 307, 130, 31, 10 });
	flyAnim.PushBack({ 307, 130, 31, 10 });


	flyAnim.speed = 0.1;

	score = 100;
	money = 300;

	currentAnim = &flyAnim;

	collider = App->collisions->AddCollider({ 0, 0, 24, 24 }, Collider::Type::ENEMY, (Module*)App->enemies);
}

void Enemy_Blue::Update()
{
	frameCount++;

	if (frameCount == 120)
	{
		App->particles->AddParticle(App->particles->enemyBullet, position.x + 20, position.y + 5, Collider::Type::ENEMY_SHOT);
	}

	if (facingLeft == 0 && position.x < 180)
	{
		position.x += 3;
		LOG("Posicion x del enemigo %d", position.x);
	}
	else if (facingLeft == 0 && position.x < 220 && position.x >0)
	{
		position.x += 2;
		position.y += 2;
	}
	else if (facingLeft == 0 && position.x < 221 && position.x >0)
	{
		position.x += 3;
		facingLeft = 1;
	}
	else
	{
		position.x += 2;

	}




	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();
}
