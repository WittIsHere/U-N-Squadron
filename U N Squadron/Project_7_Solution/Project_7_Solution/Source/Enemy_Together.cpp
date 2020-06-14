#include "Enemy_Together.h"

#include "Application.h"
#include "ModuleCollisions.h"
#include "ModuleParticles.h"


Enemy_Together::Enemy_Together(int x, int y) : Enemy(x, y)
{

	flyAnim.PushBack({ 125, 245, 33, 20 });
	flyAnim.PushBack({ 125, 245, 33, 20 });
	flyAnim.PushBack({ 125, 245, 33, 20 });
	flyAnim.PushBack({ 125, 245, 33, 20 });
	flyAnim.PushBack({ 160, 245, 31, 19 });
	flyAnim.PushBack({ 160, 245, 31, 19 });
	flyAnim.PushBack({ 192, 245, 24, 26 });
	flyAnim.PushBack({ 192, 245, 24, 26 });
	flyAnim.PushBack({ 218, 245, 16, 31 });
	flyAnim.PushBack({ 235, 245, 10, 34 });
	flyAnim.PushBack({ 247, 245, 13, 34 });
	flyAnim.PushBack({ 262, 245, 20, 34 });
	flyAnim.PushBack({ 284, 245, 13, 34 });
	flyAnim.PushBack({ 299, 245, 10, 34 });
	flyAnim.PushBack({ 310, 245, 16, 31 });
	flyAnim.PushBack({ 328, 245, 24, 26 });
	flyAnim.PushBack({ 328, 245, 24, 26 });
	flyAnim.PushBack({ 353, 245, 31, 19 });
	flyAnim.PushBack({ 353, 245, 31, 19 });
	flyAnim.PushBack({ 386, 245, 33, 20 });
	flyAnim.PushBack({ 386, 245, 33, 20 });
	flyAnim.PushBack({ 386, 245, 33, 20 });
	flyAnim.PushBack({ 386, 245, 33, 20 });
	flyAnim.PushBack({ 386, 245, 33, 20 });
	flyAnim.PushBack({ 386, 245, 33, 20 });
	flyAnim.PushBack({ 386, 245, 33, 20 });
	flyAnim.PushBack({ 386, 245, 33, 20 });
	flyAnim.PushBack({ 386, 245, 33, 20 });
	flyAnim.PushBack({ 386, 245, 33, 20 });
	flyAnim.PushBack({ 386, 245, 33, 20 });


	flyAnim.speed = 0.1;

	score = 100;
	money = 300;

	currentAnim = &flyAnim;

	collider = App->collisions->AddCollider({ 0, 0, 24, 24 }, Collider::Type::ENEMY, (Module*)App->enemies);
}


void Enemy_Together::Update()
{
	frameCount++;

	if (frameCount == 120)
	{
		App->particles->AddParticle(App->particles->enemyBullet, position.x + 20, position.y + 5, Collider::Type::ENEMY_SHOT);
	}

	if (facingLeft == 0 && position.x < 165)
	{
		position.x += 3;
	}
	else if (facingLeft == 0 && position.x < 220 && position.x>0)
	{
		position.x += 2;
		position.y += 1;
	}
	else if (facingLeft == 0 && position.x == 220 && position.x > 0 && position.y < 130)
	{
		position.y += 2;
	}
	else if (facingLeft == 0 && position.x == 220 && position.x > 0 && position.y >= 130)
	{
		position.y += 2;
		facingLeft = 1;
	}
	else if (facingLeft == 1 && position.x > 165 && position.x > 0)
	{
		position.x -= 2;
		position.y += 1;
	}
	else
	{
		position.x -= 3;
	}

	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();

}