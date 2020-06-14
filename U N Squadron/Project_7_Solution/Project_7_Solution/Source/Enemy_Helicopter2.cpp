#include "Enemy_Helicopter2.h"

#include "Application.h"
#include "ModuleCollisions.h"
#include "ModuleParticles.h"


Enemy_Helicopter2::Enemy_Helicopter2(int x, int y) : Enemy(x, y)
{
	flyAnim.PushBack({ 560, 65, 32, 11 });
	flyAnim.PushBack({ 597, 65, 32, 11 });
	flyAnim.PushBack({ 637, 59, 30, 17 });
	flyAnim.PushBack({ 670, 59, 30, 17 });
	flyAnim.PushBack({ 637, 59, 30, 17 });
	flyAnim.PushBack({ 670, 59, 30, 17 });
	flyAnim.PushBack({ 637, 59, 30, 17 });
	flyAnim.PushBack({ 670, 59, 30, 17 });
	flyAnim.PushBack({ 637, 59, 30, 17 });
	flyAnim.PushBack({ 670, 59, 30, 17 });
	flyAnim.PushBack({ 637, 59, 30, 17 });
	flyAnim.PushBack({ 670, 59, 30, 17 });
	flyAnim.PushBack({ 637, 59, 30, 17 });

	flyAnim.PushBack({ 673, 78, 27, 12 });
	flyAnim.PushBack({ 642, 78, 27, 12 });
	flyAnim.PushBack({ 615, 78, 22, 12 });
	flyAnim.PushBack({ 589, 78, 22, 12 });
	flyAnim.PushBack({ 793, 78, 22, 12 });
	flyAnim.PushBack({ 767, 78, 22, 12 });
	flyAnim.PushBack({ 735, 78, 27, 12 });
	flyAnim.PushBack({ 704, 78, 27, 12 });

	flyAnim.PushBack({ 737, 59, 30, 17 });
	flyAnim.PushBack({ 704, 59, 30, 17 });
	flyAnim.PushBack({ 737, 59, 30, 17 });
	flyAnim.PushBack({ 704, 59, 30, 17 });
	flyAnim.PushBack({ 737, 59, 30, 17 });
	flyAnim.PushBack({ 704, 59, 30, 17 });
	flyAnim.PushBack({ 737, 59, 30, 17 });
	flyAnim.PushBack({ 704, 59, 30, 17 });
	flyAnim.PushBack({ 737, 59, 30, 17 });
	flyAnim.PushBack({ 704, 59, 30, 17 });
	flyAnim.PushBack({ 737, 59, 30, 17 });
	flyAnim.PushBack({ 704, 59, 30, 17 });
	flyAnim.PushBack({ 737, 59, 30, 17 });
	flyAnim.PushBack({ 704, 59, 30, 17 });
	flyAnim.PushBack({ 737, 59, 30, 17 });
	flyAnim.PushBack({ 704, 59, 30, 17 });


	flyAnim.speed = 0.1;

	score = 100;
	money = 300;

	currentAnim = &flyAnim;

	collider = App->collisions->AddCollider({ 0, 0, 24, 24 }, Collider::Type::ENEMY, (Module*)App->enemies);
}


void Enemy_Helicopter2::Update()
{
	frameCount++;

	if (frameCount == 50 || frameCount == 240)
	{
		App->particles->AddParticle(App->particles->enemyBullet, position.x + 20, position.y + 5, Collider::Type::ENEMY_SHOT);
	}

	if (facingLeft == 0 && position.x > 270)
	{
		position.x = position.x - 2;
	}
	else if (facingLeft == 0 && position.x > 170)
	{
		position.y += 3;
		position.x -= 2;

	}
	else if (facingLeft == 0 && position.x > 110)
	{
		position.x -= 2;
	}
	else if (facingLeft == 0 && position.x > 40)
	{
		position.x -= 2;
		position.y -= 1;
	}
	else if (facingLeft == 0 && position.x <= 40 && position.y > 60)
	{
		position.y -= 1;
	}
	else if (facingLeft == 0 && position.x <= 40 && position.y <= 60)
	{
		position.y -= 1;
		facingLeft = 1;
	}
	else if (facingLeft == 1 && position.x < 80)
	{
		position.x += 2;
	}
	else if (facingLeft == 1 && position.x < 140)
	{
		position.y += 1;
		position.x += 2;
	}
	else
	{
		position.x += 2;
	}



	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();

}