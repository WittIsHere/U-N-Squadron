#include "Enemy_BrownShip.h"

#include "Application.h"
#include "ModuleCollisions.h"
#include "ModuleParticles.h"

Enemy_BrownShip::Enemy_BrownShip(int x, int y) : Enemy(x, y)
{

	flyAnim.PushBack({ 125, 208, 33, 20 });
	flyAnim.PushBack({ 125, 208, 33, 20 });
	flyAnim.PushBack({ 125, 208, 33, 20 });
	flyAnim.PushBack({ 160, 208, 31, 19 });
	flyAnim.PushBack({ 192, 208, 24, 26 });
	flyAnim.PushBack({ 218, 208, 16, 31 });
	flyAnim.PushBack({ 235, 208, 10, 34 });
	flyAnim.PushBack({ 247, 208, 13, 34 });
	flyAnim.PushBack({ 262, 208, 20, 34 });
	flyAnim.PushBack({ 284, 208, 13, 34 });
	flyAnim.PushBack({ 299, 208, 10, 34 });
	flyAnim.PushBack({ 310, 208, 16, 31 });
	flyAnim.PushBack({ 328, 208, 24, 26 });
	flyAnim.PushBack({ 353, 208, 31, 19 });
	flyAnim.PushBack({ 386, 208, 33, 20 });
	flyAnim.PushBack({ 386, 208, 33, 20 });
	flyAnim.PushBack({ 386, 208, 33, 20 });
	flyAnim.PushBack({ 386, 208, 33, 20 });
	flyAnim.PushBack({ 386, 208, 33, 20 });
	flyAnim.PushBack({ 386, 208, 33, 20 });
	flyAnim.PushBack({ 386, 208, 33, 20 });
	flyAnim.PushBack({ 386, 208, 33, 20 });
	flyAnim.PushBack({ 386, 208, 33, 20 });


	flyAnim.speed = 0.1;

	score = 100;
	money = 300;

	currentAnim = &flyAnim;

	collider = App->collisions->AddCollider({ 0, 0, 24, 24 }, Collider::Type::ENEMY, (Module*)App->enemies);
}

void Enemy_BrownShip::Update()
{
	frameCount++;

	if (frameCount == 120)
	{
		App->particles->AddParticle(App->particles->enemyBullet, position.x + 20, position.y + 5, Collider::Type::ENEMY_SHOT);
	}

	if (facingLeft == 0 && position.x < 80)
	{
		position.x += 3;
		LOG("Posicion x del enemigo %d", position.x);
	}
	else if (facingLeft == 0 && position.x < 140 && position.x>0)
	{
		position.x += 2;
		position.y += 1;
	}
	else if (facingLeft == 0 && position.x < 160 && position.x>0)
	{
		position.x += 1;
		position.y += 2;
	}
	else if (facingLeft == 0 && position.x < 161 && position.x>0)
	{
		position.x += 2;
		position.y += 2;
		facingLeft = 1;
	}
	else if (facingLeft == 1 && position.x > 120 && position.x > 0)
	{
		position.x -= 2;
		position.y += 3;
	}
	else
	{
		position.x -= 3;
		position.y -= 1;
	}

	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();
}
