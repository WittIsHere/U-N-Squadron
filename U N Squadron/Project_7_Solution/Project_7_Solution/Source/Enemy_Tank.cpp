#include "Enemy_Tank.h"

#include "Application.h"
#include "ModuleCollisions.h"
#include "ModuleParticles.h"


Enemy_Tank::Enemy_Tank(int x, int y) : Enemy(x, y)
{
	flyAnim.PushBack({ 525, 209, 51, 33 });
	flyAnim.PushBack({ 525, 242, 51, 33 });
	flyAnim.PushBack({ 525, 275, 51, 33 });
	flyAnim.PushBack({ 525, 209, 51, 33 });
	flyAnim.PushBack({ 525, 242, 51, 33 });
	flyAnim.PushBack({ 525, 275, 51, 33 });
	flyAnim.PushBack({ 525, 209, 51, 33 });
	flyAnim.PushBack({ 576, 209, 51, 33 });
	flyAnim.PushBack({ 576, 242, 51, 33 });
	flyAnim.PushBack({ 576, 275, 51, 33 });
	flyAnim.PushBack({ 576, 209, 51, 33 });
	flyAnim.PushBack({ 576, 242, 51, 33 });
	flyAnim.PushBack({ 627, 209, 51, 33 });
	flyAnim.PushBack({ 627, 242, 51, 33 });
	flyAnim.PushBack({ 627, 275, 51, 33 });
	flyAnim.PushBack({ 627, 209, 51, 33 });
	flyAnim.PushBack({ 627, 242, 51, 33 });
	flyAnim.PushBack({ 678, 209, 51, 33 });
	flyAnim.PushBack({ 678, 242, 51, 33 });
	flyAnim.PushBack({ 678, 275, 51, 33 });
	flyAnim.PushBack({ 627, 209, 51, 33 });
	flyAnim.PushBack({ 627, 242, 51, 33 });
	flyAnim.PushBack({ 627, 275, 51, 33 });
	flyAnim.PushBack({ 576, 275, 51, 33 });
	flyAnim.PushBack({ 576, 209, 51, 33 });
	flyAnim.PushBack({ 576, 242, 51, 33 });


	flyAnim.speed = 0.1;

	life = 5;

	score = 100;
	money = 300;

	currentAnim = &flyAnim;

	collider = App->collisions->AddCollider({ 0, 0, 24, 32 }, Collider::Type::ENEMY, (Module*)App->enemies);
}


void Enemy_Tank::Update()
{
	frameCount++;

	if (frameCount == 50 || frameCount == 315)
	{
		App->particles->AddParticle(App->particles->enemyBullet, position.x + 13, position.y + 18, Collider::Type::ENEMY_SHOT);
	}
	if (frameCount == 130 || frameCount == 150 || frameCount == 390 || frameCount == 410)
	{
		App->particles->AddParticle(App->particles->turretUp, position.x + 13, position.y + 15, Collider::Type::ENEMY_SHOT);
	}

	if (frameCount < 180)
	{
		position.x -= 1;
	}
	else if (frameCount < 210)
	{
	}
	else if (frameCount < 300)
	{
		position.x += 1;
	}
	else if (frameCount < 330)
	{
	}
	else
	{
		position.x -= 1;
	}

	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();

}