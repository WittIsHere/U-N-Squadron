#include "Enemy_TurretGreen.h"

#include "Application.h"
#include "ModuleCollisions.h"
#include "ModuleParticles.h"


Enemy_TurretGreen::Enemy_TurretGreen(int x, int y) : Enemy(x, y)
{
	flyAnim.PushBack({ 550, 131, 29, 30 });
	flyAnim.PushBack({ 550, 131, 29, 30 });
	flyAnim.PushBack({ 550, 131, 29, 30 });
	flyAnim.PushBack({ 550, 131, 29, 30 });
	flyAnim.PushBack({ 550, 131, 29, 30 });
	flyAnim.PushBack({ 550, 131, 29, 30 });
	flyAnim.PushBack({ 550, 131, 29, 30 });
	flyAnim.PushBack({ 550, 131, 29, 30 });
	flyAnim.PushBack({ 550, 131, 29, 30 });
	flyAnim.PushBack({ 550, 131, 29, 30 });
	flyAnim.PushBack({ 550, 131, 29, 30 });
	flyAnim.PushBack({ 550, 131, 29, 30 });
	flyAnim.PushBack({ 550, 131, 29, 30 });
	flyAnim.PushBack({ 550, 131, 29, 30 });
	flyAnim.PushBack({ 550, 131, 29, 30 });
	flyAnim.PushBack({ 550, 131, 29, 30 });
	flyAnim.PushBack({ 579, 131, 29, 30 });
	flyAnim.PushBack({ 579, 131, 29, 30 });
	flyAnim.PushBack({ 579, 131, 29, 30 });
	flyAnim.PushBack({ 579, 131, 29, 30 });
	flyAnim.PushBack({ 579, 131, 29, 30 });
	flyAnim.PushBack({ 579, 131, 29, 30 });
	flyAnim.PushBack({ 579, 131, 29, 30 });
	flyAnim.PushBack({ 608, 131, 29, 30 });
	flyAnim.PushBack({ 608, 131, 29, 30 });
	flyAnim.PushBack({ 608, 131, 29, 30 });
	flyAnim.PushBack({ 608, 131, 29, 30 });
	flyAnim.PushBack({ 608, 131, 29, 30 });
	flyAnim.PushBack({ 608, 131, 29, 30 });
	flyAnim.PushBack({ 608, 131, 29, 30 });
	flyAnim.PushBack({ 608, 131, 29, 30 });
	flyAnim.PushBack({ 608, 131, 29, 30 });
	flyAnim.PushBack({ 638, 131, 29, 30 });
	flyAnim.PushBack({ 638, 131, 29, 30 });
	flyAnim.PushBack({ 638, 131, 29, 30 });
	flyAnim.PushBack({ 638, 131, 29, 30 });
	flyAnim.PushBack({ 638, 131, 29, 30 });
	flyAnim.PushBack({ 638, 131, 29, 30 });
	flyAnim.PushBack({ 638, 131, 29, 30 });
	flyAnim.PushBack({ 638, 131, 29, 30 });
	flyAnim.PushBack({ 666, 131, 29, 30 });
	flyAnim.PushBack({ 666, 131, 29, 30 });
	flyAnim.PushBack({ 666, 131, 29, 30 });
	flyAnim.PushBack({ 666, 131, 29, 30 });
	flyAnim.PushBack({ 666, 131, 29, 30 });
	flyAnim.PushBack({ 666, 131, 29, 30 });
	flyAnim.PushBack({ 666, 131, 29, 30 });
	flyAnim.PushBack({ 666, 131, 29, 30 });
	flyAnim.PushBack({ 666, 131, 29, 30 });
	flyAnim.PushBack({ 666, 131, 29, 30 });
	flyAnim.PushBack({ 666, 131, 29, 30 });
	flyAnim.PushBack({ 666, 131, 29, 30 });
	flyAnim.PushBack({ 666, 131, 29, 30 });
	flyAnim.PushBack({ 666, 131, 29, 30 });
	flyAnim.PushBack({ 666, 131, 29, 30 });
	flyAnim.PushBack({ 666, 131, 29, 30 });
	flyAnim.PushBack({ 666, 131, 29, 30 });
	flyAnim.PushBack({ 666, 131, 29, 30 });
	flyAnim.PushBack({ 666, 131, 29, 30 });
	flyAnim.PushBack({ 666, 131, 29, 30 });
	flyAnim.PushBack({ 666, 131, 29, 30 });
	flyAnim.PushBack({ 666, 131, 29, 30 });
	flyAnim.PushBack({ 666, 131, 29, 30 });
	flyAnim.PushBack({ 666, 131, 29, 30 });
	flyAnim.PushBack({ 666, 131, 29, 30 });
	flyAnim.PushBack({ 666, 131, 29, 30 });
	flyAnim.PushBack({ 666, 131, 29, 30 });


	flyAnim.speed = 0.1;

	life = 5;
	score = 100;
	money = 300;

	currentAnim = &flyAnim;

	collider = App->collisions->AddCollider({ 0, 0, 24, 30 }, Collider::Type::ENEMY, (Module*)App->enemies);
}


void Enemy_TurretGreen::Update()
{

	frameCount++;

	if (frameCount == 100 || frameCount == 140)
	{
		App->particles->AddParticle(App->particles->enemyBullet, position.x + 13, position.y + 7, Collider::Type::ENEMY_SHOT);
	}
	if (frameCount == 240 || frameCount == 280)
	{
		App->particles->AddParticle(App->particles->turretUp, position.x + 13, position.y + 13, Collider::Type::ENEMY_SHOT);
	}
	if (frameCount == 430 || frameCount == 470)
	{
		App->particles->AddParticle(App->particles->turretUpl, position.x + 10, position.y + 5, Collider::Type::ENEMY_SHOT);
	}


	if (frameCount1 == 0)
	{
		position.x -= 1;
		frameCount1 = frameDelay;
	}
	if (frameCount1 > 0)
		--frameCount1;

	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();

}