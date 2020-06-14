#include "Enemy_BrownShip2.h"

#include "Application.h"
#include "ModuleCollisions.h"
#include "ModuleParticles.h"

Enemy_BrownShip2::Enemy_BrownShip2(int x, int y) : Enemy(x, y)
{

	flyAnim.PushBack({ 125, 19, 33, 20 });
	flyAnim.PushBack({ 125, 19, 33, 20 });
	flyAnim.PushBack({ 125, 19, 33, 20 });
	flyAnim.PushBack({ 125, 19, 33, 20 });
	flyAnim.PushBack({ 125, 19, 33, 20 });
	flyAnim.PushBack({ 160, 20, 31, 19 });
	flyAnim.PushBack({ 192, 13, 24, 26 });
	flyAnim.PushBack({ 218, 8, 16, 31 });
	flyAnim.PushBack({ 235, 5, 10, 34 });
	flyAnim.PushBack({ 247, 5, 13, 34 });
	flyAnim.PushBack({ 262, 5, 20, 34 });
	flyAnim.PushBack({ 284, 5, 13, 34 });
	flyAnim.PushBack({ 299, 5, 10, 34 });
	flyAnim.PushBack({ 310, 8, 16, 31 });
	flyAnim.PushBack({ 328, 13, 24, 26 });
	flyAnim.PushBack({ 353, 20, 31, 19 });
	flyAnim.PushBack({ 386, 19, 33, 20 });
	flyAnim.PushBack({ 386, 19, 33, 20 });
	flyAnim.PushBack({ 386, 19, 33, 20 });
	flyAnim.PushBack({ 386, 19, 33, 20 });
	flyAnim.PushBack({ 386, 19, 33, 20 });
	flyAnim.PushBack({ 386, 19, 33, 20 });
	flyAnim.PushBack({ 386, 19, 33, 20 });
	flyAnim.PushBack({ 386, 19, 33, 20 });
	flyAnim.PushBack({ 386, 19, 33, 20 });
	flyAnim.PushBack({ 386, 19, 33, 20 });


	flyAnim.speed = 0.1;

	score = 100;
	money = 300;

	currentAnim = &flyAnim;

	collider = App->collisions->AddCollider({ 0, 0, 24, 24 }, Collider::Type::ENEMY, (Module*)App->enemies);
}

void Enemy_BrownShip2::Update()
{
	frameCount++;

	if (frameCount == 120)
	{
		App->particles->AddParticle(App->particles->enemyBullet, position.x + 20, position.y + 5, Collider::Type::ENEMY_SHOT);
	}

	if (facingLeft == 0 && position.x < 155)
	{
		position.x += 3;
		LOG("Posicion x del enemigo %d", position.x);
	}
	else if (facingLeft == 0 && position.x < 175 && position.x>0)
	{
		position.x += 2;
		position.y -= 1;
	}
	else if (facingLeft == 0 && position.x < 210 && position.x>0)
	{
		position.x += 2;
		position.y -= 2;
	}
	else if (facingLeft == 0 && position.x < 211 && position.x>0)
	{
		position.x += 2;
		position.y -= 2;
		facingLeft = 1;
	}
	else if (facingLeft == 1 && position.x > 180 && position.x > 0)
	{
		position.x -= 2;
		position.y -= 2;
	}
	else
	{
		position.x -= 3;
		position.y += 1;
	}

	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();
}
