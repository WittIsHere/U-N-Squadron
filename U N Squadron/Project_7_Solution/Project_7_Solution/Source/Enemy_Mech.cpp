#include "Enemy_Mech.h"

#include "Application.h"
#include "ModuleCollisions.h"

Enemy_Mech::Enemy_Mech(int x, int y) : Enemy(x, y)
{

	flyAnim.PushBack({ 386, 56, 33, 20 });

	flyAnim.speed = 0.1;

	currentAnim = &flyAnim;

	collider = App->collisions->AddCollider({ 0, 0, 24, 24 }, Collider::Type::ENEMY, (Module*)App->enemies);
}

void Enemy_Mech::Update()
{
	{
		position.x -= 1;

	}
	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();
}
