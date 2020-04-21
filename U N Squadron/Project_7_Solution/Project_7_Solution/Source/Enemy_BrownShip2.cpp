#include "Enemy_BrownShip2.h"

#include "Application.h"
#include "ModuleCollisions.h"

Enemy_BrownShip2::Enemy_BrownShip2(int x, int y) : Enemy(x, y)
{

	flyAnim.PushBack({ 386, 19, 33, 20 });

	flyAnim.speed = 0.1;

	currentAnim = &flyAnim;

	collider = App->collisions->AddCollider({ 0, 0, 24, 24 }, Collider::Type::ENEMY, (Module*)App->enemies);
}

void Enemy_BrownShip2::Update()
{
	waveRatio += waveRatioSpeed;
	position.y = spawnPos.y - (13 * waveHeight * sinf((0.15) * waveRatio));
	position.x -= 1;

	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();
}
