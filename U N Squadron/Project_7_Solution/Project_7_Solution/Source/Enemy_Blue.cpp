#include "Enemy_Blue.h"

#include "Application.h"
#include "ModuleCollisions.h"
#include "ModuleParticles.h"

Enemy_Blue::Enemy_Blue(int x, int y) : Enemy(x, y)
{
	flyAnim.PushBack({ 206, 130, 31, 10 });
	flyAnim.PushBack({ 206, 130, 31, 10 });
	flyAnim.PushBack({ 206, 130, 31, 10 });
	flyAnim.PushBack({ 239, 130, 31, 15 });
	flyAnim.PushBack({ 239, 130, 31, 15 });
	flyAnim.PushBack({ 239, 130, 31, 15 });
	flyAnim.PushBack({ 239, 130, 31, 15 });
	flyAnim.PushBack({ 239, 130, 31, 15 });
	flyAnim.PushBack({ 239, 130, 31, 15 });
	flyAnim.PushBack({ 239, 130, 31, 15 });
	flyAnim.PushBack({ 239, 130, 31, 15 });
	flyAnim.PushBack({ 239, 130, 31, 15 });
	flyAnim.PushBack({ 239, 130, 31, 15 });
	flyAnim.PushBack({ 206, 130, 31, 10 });
	flyAnim.PushBack({ 206, 130, 31, 10 });
	flyAnim.PushBack({ 206, 130, 31, 10 });
	flyAnim.PushBack({ 206, 130, 31, 10 });
	flyAnim.PushBack({ 206, 130, 31, 10 });
	flyAnim.PushBack({ 206, 130, 31, 10 });


	flyAnim.speed = 0.1;

	currentAnim = &flyAnim;

	collider = App->collisions->AddCollider({ 0, 0, 24, 24 }, Collider::Type::ENEMY, (Module*)App->enemies);
}

void Enemy_Blue::Update()
{
	waveRatio += waveRatioSpeed;
	position.y = spawnPos.y + (6 * waveHeight * sinf((0.15) * waveRatio));
	position.x -= 1;

	/*App->particles->AddParticle(App->particles->enemyBullet, position.x + 20, position.y + 5, Collider::Type::ENEMY_SHOT);*/


	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();
}
