#include "Enemy_4.h"

#include "Application.h"
#include "ModuleCollisions.h"
#include "ModuleParticles.h"

Enemy_4::Enemy_4(int x, int y) : Enemy(x, y)
{

	flyAnim.PushBack({ 244, 111, 27, 9 });
	flyAnim.PushBack({ 244, 111, 27, 9 });
	flyAnim.PushBack({ 244, 111, 27, 9 });
	flyAnim.PushBack({ 244, 111, 27, 9 });
	flyAnim.PushBack({ 244, 111, 27, 9 });
	flyAnim.PushBack({ 244, 111, 27, 9 });
	flyAnim.PushBack({ 214, 112, 27, 11 });
	flyAnim.PushBack({ 184, 109, 27, 16 });
	flyAnim.PushBack({ 162, 109, 20, 16 });
	flyAnim.PushBack({ 143, 108, 15, 18 });
	flyAnim.PushBack({ 131, 107, 10, 20 });
	flyAnim.PushBack({ 118, 108, 12, 18 });
	flyAnim.PushBack({ 98, 109, 19, 16 });
	flyAnim.PushBack({ 68, 109, 27, 16 });
	flyAnim.PushBack({ 39, 111, 27, 11 });
	flyAnim.PushBack({ 273, 111, 27, 9 });
	flyAnim.PushBack({ 273, 111, 27, 9 });
	flyAnim.PushBack({ 273, 111, 27, 9 });
	flyAnim.PushBack({ 273, 111, 27, 9 });
	flyAnim.PushBack({ 273, 111, 27, 9 });
	flyAnim.PushBack({ 273, 111, 27, 9 });
	flyAnim.PushBack({ 273, 111, 27, 9 });
	flyAnim.PushBack({ 273, 111, 27, 9 });
	flyAnim.PushBack({ 273, 111, 27, 9 });

	flyAnim.speed = 0.1;

	score = 100;
	money = 300;

	currentAnim = &flyAnim;

	collider = App->collisions->AddCollider({ 0, 0, 24, 24 }, Collider::Type::ENEMY, (Module*)App->enemies);
}

void Enemy_4::Update()
{
	frameCount++;

	if (frameCount == 60 || frameCount == 180)
	{
		App->particles->AddParticle(App->particles->enemyBullet, position.x + 20, position.y + 5, Collider::Type::ENEMY_SHOT);
	}

	if (facingLeft == 0 && position.x > 90)
	{
		position.x -= 3;
		LOG("Posicion x del enemigo %d", position.x);
	}
	else if (facingLeft == 0 && position.x > 60)
	{
		position.x -= 2;
	}
	else if (facingLeft == 0 && position.x > 40)
	{
		position.x -= 1;

	}
	else if (facingLeft == 0 && position.x <= 40)
	{
		position.x -= 1;
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
