#include "Enemy_RedBird.h"

#include "Application.h"
#include "ModuleCollisions.h"
#include "ModuleParticles.h"

Enemy_RedBird::Enemy_RedBird(int x, int y) : Enemy(x, y)
{
	flyAnim.PushBack({ 239, 95, 31, 10 });
	flyAnim.PushBack({ 239, 95, 31, 10 });
	flyAnim.PushBack({ 239, 95, 31, 10 });
	flyAnim.PushBack({ 239, 95, 31, 10 });
	flyAnim.PushBack({ 239, 95, 31, 10 });
	flyAnim.PushBack({ 204, 87, 31, 18 });
	flyAnim.PushBack({ 204, 87, 31, 18 });
	flyAnim.PushBack({ 204, 87, 31, 18 });
	flyAnim.PushBack({ 204, 87, 31, 18 });
	flyAnim.PushBack({ 172, 81, 31, 24 });
	flyAnim.PushBack({ 172, 81, 31, 24 });
	flyAnim.PushBack({ 146, 81, 25, 24 });
	flyAnim.PushBack({ 126, 81, 18, 24 });
	flyAnim.PushBack({ 112, 81, 11, 24 });
	flyAnim.PushBack({ 93, 81, 17, 24 });
	flyAnim.PushBack({ 67, 80, 24, 25 });
	flyAnim.PushBack({ 67, 80, 24, 25 });
	flyAnim.PushBack({ 35, 80, 31, 25 });
	flyAnim.PushBack({ 35, 80, 31, 25 });
	flyAnim.PushBack({ 3, 88, 31, 22 });
	flyAnim.PushBack({ 3, 88, 31, 22 });
	flyAnim.PushBack({ 274, 95, 31, 10 });
	flyAnim.PushBack({ 274, 95, 31, 10 });
	flyAnim.PushBack({ 274, 95, 31, 10 });
	flyAnim.PushBack({ 274, 95, 31, 10 });

	

	flyAnim.speed = 0.1;

	currentAnim = &flyAnim;

	collider = App->collisions->AddCollider({ 0, 0, 24, 24 }, Collider::Type::ENEMY, (Module*)App->enemies);
}

void Enemy_RedBird::Update()
{
	if (facingLeft == 0 && position.x > 470)
	{

		position.x = position.x - 1;

	}
	else
	{
		position.y = position.y + 1;
		position.x = position.x + 2;
		facingLeft = 1;
	}

	/*App->particles->AddParticle(App->particles->enemyBullet, position.x, position.y, Collider::Type::ENEMY_SHOT);*/


	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();
}
