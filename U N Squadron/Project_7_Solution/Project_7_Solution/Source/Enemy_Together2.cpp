#include "Enemy_Together2.h"

#include "Application.h"
#include "ModuleCollisions.h"
#include "ModuleParticles.h"


Enemy_Together2::Enemy_Together2(int x, int y) : Enemy(x, y)
{

	flyAnim.PushBack({ 125, 56, 33, 20 });
	flyAnim.PushBack({ 125, 56, 33, 20 });
	flyAnim.PushBack({ 125, 56, 33, 20 });
	flyAnim.PushBack({ 125, 56, 33, 20 });
	flyAnim.PushBack({ 160, 57, 31, 19 });
	flyAnim.PushBack({ 160, 57, 31, 19 });
	flyAnim.PushBack({ 192, 50, 24, 26 });
	flyAnim.PushBack({ 192, 50, 24, 26 });
	flyAnim.PushBack({ 218, 45, 16, 31 });
	flyAnim.PushBack({ 235, 42, 10, 34 });
	flyAnim.PushBack({ 247, 42, 13, 34 });
	flyAnim.PushBack({ 262, 42, 20, 34 });
	flyAnim.PushBack({ 284, 42, 13, 34 });
	flyAnim.PushBack({ 299, 42, 10, 34 });
	flyAnim.PushBack({ 310, 45, 16, 31 });
	flyAnim.PushBack({ 328, 50, 24, 26 });
	flyAnim.PushBack({ 328, 50, 24, 26 });
	flyAnim.PushBack({ 353, 57, 31, 19 });
	flyAnim.PushBack({ 353, 57, 31, 19 });
	flyAnim.PushBack({ 386, 56, 33, 20 });
	flyAnim.PushBack({ 386, 56, 33, 20 });
	flyAnim.PushBack({ 386, 56, 33, 20 });
	flyAnim.PushBack({ 386, 56, 33, 20 });
	flyAnim.PushBack({ 386, 56, 33, 20 });
	flyAnim.PushBack({ 386, 56, 33, 20 });
	flyAnim.PushBack({ 386, 56, 33, 20 });
	flyAnim.PushBack({ 386, 56, 33, 20 });
	flyAnim.PushBack({ 386, 56, 33, 20 });
	flyAnim.PushBack({ 386, 56, 33, 20 });
	flyAnim.PushBack({ 386, 56, 33, 20 });
	flyAnim.PushBack({ 386, 56, 33, 20 });




	flyAnim.speed = 0.1;

	score = 100;
	money = 300;

	currentAnim = &flyAnim;

	collider = App->collisions->AddCollider({ 0, 0, 24, 24 }, Collider::Type::ENEMY, (Module*)App->enemies);
}


void Enemy_Together2::Update()
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
		position.y -= 1;
	}
	else if (facingLeft == 0 && position.x == 220 && position.x > 0 && position.y > 60)
	{
		position.y -= 2;
	}
	else if (facingLeft == 0 && position.x == 220 && position.x > 0 && position.y <= 60)
	{
		position.y -= 2;
		facingLeft = 1;
	}
	else if (facingLeft == 1 && position.x > 165 && position.x > 0)
	{
		position.x -= 2;
		position.y -= 1;
	}
	else
	{
		position.x -= 3;
	}

	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();

}