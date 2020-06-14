#include "Enemy_Mech.h"

#include "Application.h"
#include "ModuleCollisions.h"
#include "ModuleParticles.h"

Enemy_Mech::Enemy_Mech(int x, int y) : Enemy(x, y)
{

	flyAnim.PushBack({ 125, 19, 33, 20 });






	flyAnim.speed = 0.1;

	currentAnim = &flyAnim;

	collider = App->collisions->AddCollider({ 0, 0, 24, 24 }, Collider::Type::ENEMY, (Module*)App->enemies);
}

void Enemy_Mech::Update()
{
	frameCount++;

	if (frameCount == 120)
	{
		App->particles->AddParticle(App->particles->laser, position.x + 20, position.y + 5, Collider::Type::ENEMY_SHOT);
	}

	if (facingLeft == 0 && position.x < 165)
	{
		position.x += 3;
		LOG("Posicion x del enemigo %d", position.x);
	}
	else if (facingLeft == 0 && position.x < 195 && position.x>0)
	{
		position.x += 2;
		position.y -= 1;
	}
	else if (facingLeft == 0 && position.x < 250 && position.x>0)
	{
		position.x += 2;
		position.y -= 2;
	}
	else if (facingLeft == 0 && position.x < 251 && position.x>0)
	{
		position.x += 2;
		position.y -= 2;
		facingLeft = 1;
	}
	else if (facingLeft == 1 && position.x > 180 && position.x > 0)
	{
		position.x -= 2;
		position.y -= 2;
	}
	else
	{
		position.x -= 3;
		position.y += 1;
	}

	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();
}

