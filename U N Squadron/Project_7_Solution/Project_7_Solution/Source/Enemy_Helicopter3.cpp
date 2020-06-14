#include "Enemy_Helicopter3.h"

#include "Application.h"
#include "ModuleCollisions.h"
#include "ModuleParticles.h"


Enemy_Helicopter3::Enemy_Helicopter3(int x, int y) : Enemy(x, y)
{
	flyAnim.PushBack({ 560, 17, 32, 11 });
	flyAnim.PushBack({ 597, 17, 32, 11 });
	flyAnim.PushBack({ 560, 17, 32, 11 });
	flyAnim.PushBack({ 597, 17, 32, 11 });

	flyAnim.PushBack({ 673, 30, 27, 12 });
	flyAnim.PushBack({ 642, 30, 27, 12 });
	flyAnim.PushBack({ 615, 30, 22, 12 });
	flyAnim.PushBack({ 589, 30, 22, 12 });
	flyAnim.PushBack({ 793, 30, 22, 12 });
	flyAnim.PushBack({ 767, 30, 22, 12 });
	flyAnim.PushBack({ 735, 30, 27, 12 });
	flyAnim.PushBack({ 704, 30, 27, 12 });

	flyAnim.PushBack({ 704, 30, 27, 12 });
	flyAnim.PushBack({ 735, 30, 27, 12 });
	flyAnim.PushBack({ 767, 30, 22, 12 });
	flyAnim.PushBack({ 793, 30, 22, 12 });
	flyAnim.PushBack({ 589, 30, 22, 12 });
	flyAnim.PushBack({ 615, 30, 22, 12 });
	flyAnim.PushBack({ 642, 30, 27, 12 });
	flyAnim.PushBack({ 673, 30, 27, 12 });

	flyAnim.PushBack({ 673, 30, 27, 12 });
	flyAnim.PushBack({ 642, 30, 27, 12 });
	flyAnim.PushBack({ 615, 30, 22, 12 });
	flyAnim.PushBack({ 589, 30, 22, 12 });
	flyAnim.PushBack({ 793, 30, 22, 12 });
	flyAnim.PushBack({ 767, 30, 22, 12 });
	flyAnim.PushBack({ 735, 30, 27, 12 });
	flyAnim.PushBack({ 704, 30, 27, 12 });

	flyAnim.PushBack({ 704, 11, 30, 17 });
	flyAnim.PushBack({ 737, 11, 30, 17 });
	flyAnim.PushBack({ 704, 11, 30, 17 });
	flyAnim.PushBack({ 737, 11, 30, 17 });
	flyAnim.PushBack({ 704, 11, 30, 17 });
	flyAnim.PushBack({ 737, 11, 30, 17 });
	flyAnim.PushBack({ 704, 11, 30, 17 });
	flyAnim.PushBack({ 737, 11, 30, 17 });
	flyAnim.PushBack({ 704, 11, 30, 17 });
	flyAnim.PushBack({ 737, 11, 30, 17 });
	flyAnim.PushBack({ 704, 11, 30, 17 });
	flyAnim.PushBack({ 737, 11, 30, 17 });
	flyAnim.PushBack({ 704, 11, 30, 17 });
	flyAnim.PushBack({ 737, 11, 30, 17 });
	flyAnim.PushBack({ 704, 11, 30, 17 });
	flyAnim.PushBack({ 737, 11, 30, 17 });


	flyAnim.speed = 0.15;

	score = 100;
	money = 300;

	currentAnim = &flyAnim;

	collider = App->collisions->AddCollider({ 0, 0, 24, 24 }, Collider::Type::ENEMY, (Module*)App->enemies);
}


void Enemy_Helicopter3::Update()
{
	frameCount++;

	if (frameCount == 110)
	{
		App->particles->AddParticle(App->particles->enemyBullet, position.x + 20, position.y + 5, Collider::Type::ENEMY_SHOT);
	}

	if (facingLeft == 0 && facingRight == 0 && facingUp == 0 && position.x > 155)
	{
		position.x = position.x - 2;
	}
	else if (facingLeft == 0 && facingRight == 0 && facingUp == 0 && position.x > 130)
	{
		position.y -= 1;
		position.x -= 1;
	}
	else if (facingLeft == 0 && facingRight == 0 && facingUp == 0 && position.x <= 130)
	{
		position.y -= 1;
		position.x -= 1;
		facingRight = 1;
	}
	else if (facingLeft == 0 && facingRight == 1 && facingUp == 0 && position.x < 155)
	{
		position.y -= 1;
		position.x += 1;
	}
	else if (facingLeft == 0 && facingRight == 1 && facingUp == 0 && position.x >= 155)
	{
		position.y -= 1;
		position.x += 1;
		facingLeft = 1;
	}
	else if (facingLeft == 1 && facingRight == 1 && facingUp == 0 && position.x > 50)
	{
		position.x -= 2;
		position.y += 1;
	}
	else if (facingLeft == 1 && facingRight == 1 && facingUp == 0 && position.x <= 50)
	{
		position.x -= 2;
		position.y += 1;
		facingUp = 1;
	}
	else if (facingLeft == 1 && facingRight == 1 && facingUp == 1 && position.x < 170)
	{
		position.x += 2;
		position.y += 1;
	}
	else
	{
		position.x += 2;
	}



	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();

}