#include "Enemy_Bosslvl1.h"


#include "Application.h"
#include "ModuleCollisions.h"
#include "ModuleParticles.h"
#include "ModuleCollisions.h"
#include "ModulePlayer.h"
#include "ModuleScene.h"
#include "levelOne.h"
#include "ModuleFadeToBlack.h"
#include "MissionComplete.h"
#include "Enemy.h"
#include "ModuleEnemies.h"


Enemy_Bosslvl1::Enemy_Bosslvl1(int x, int y) : Enemy(x, y)
{

	flyAnim.PushBack({ 571, 386, 118, 111 });
	flyAnim.PushBack({ 689, 386, 118, 111 });
	flyAnim.PushBack({ 807, 386, 118, 111 });
	flyAnim.PushBack({ 925, 386, 118, 111 });
	flyAnim.PushBack({ 571, 386, 118, 111 });
	flyAnim.PushBack({ 689, 386, 118, 111 });
	flyAnim.PushBack({ 807, 386, 118, 111 });
	flyAnim.PushBack({ 925, 386, 118, 111 });
	flyAnim.PushBack({ 571, 386, 118, 111 });
	flyAnim.PushBack({ 689, 386, 118, 111 });
	flyAnim.PushBack({ 807, 386, 118, 111 });
	flyAnim.PushBack({ 925, 386, 118, 111 });
	flyAnim.PushBack({ 571, 386, 118, 111 });
	flyAnim.PushBack({ 689, 386, 118, 111 });
	flyAnim.PushBack({ 807, 386, 118, 111 });
	flyAnim.PushBack({ 925, 386, 118, 111 });
	flyAnim.PushBack({ 571, 386, 118, 111 });
	flyAnim.PushBack({ 689, 386, 118, 111 });
	flyAnim.PushBack({ 807, 386, 118, 111 });
	flyAnim.PushBack({ 925, 386, 118, 111 });
	flyAnim.PushBack({ 571, 386, 118, 111 });
	flyAnim.PushBack({ 689, 386, 118, 111 });
	flyAnim.PushBack({ 807, 386, 118, 111 });
	flyAnim.PushBack({ 925, 386, 118, 111 });

	//primer stop
	flyAnim.PushBack({ 571, 497, 118, 111 });
	flyAnim.PushBack({ 689, 497, 118, 111 });
	flyAnim.PushBack({ 807, 497, 118, 111 });
	flyAnim.PushBack({ 925, 497, 118, 111 });
	flyAnim.PushBack({ 571, 497, 118, 111 });
	flyAnim.PushBack({ 689, 497, 118, 111 });
	flyAnim.PushBack({ 807, 497, 118, 111 });
	flyAnim.PushBack({ 925, 497, 118, 111 });
	flyAnim.PushBack({ 571, 497, 118, 111 });
	flyAnim.PushBack({ 689, 497, 118, 111 });
	flyAnim.PushBack({ 807, 497, 118, 111 });
	flyAnim.PushBack({ 925, 497, 118, 111 });
	flyAnim.PushBack({ 571, 497, 118, 111 });
	flyAnim.PushBack({ 689, 497, 118, 111 });
	flyAnim.PushBack({ 807, 497, 118, 111 });
	flyAnim.PushBack({ 925, 497, 118, 111 });
	flyAnim.PushBack({ 571, 497, 118, 111 });
	flyAnim.PushBack({ 689, 497, 118, 111 });
	flyAnim.PushBack({ 807, 497, 118, 111 });
	flyAnim.PushBack({ 925, 497, 118, 111 });
	flyAnim.PushBack({ 571, 497, 118, 111 });
	flyAnim.PushBack({ 689, 497, 118, 111 });

	//segundo stop
	flyAnim.PushBack({ 571, 386, 118, 111 });
	flyAnim.PushBack({ 689, 386, 118, 111 });
	flyAnim.PushBack({ 807, 386, 118, 111 });
	flyAnim.PushBack({ 925, 386, 118, 111 });
	flyAnim.PushBack({ 571, 386, 118, 111 });
	flyAnim.PushBack({ 689, 386, 118, 111 });
	flyAnim.PushBack({ 807, 386, 118, 111 });
	flyAnim.PushBack({ 925, 386, 118, 111 });
	flyAnim.PushBack({ 571, 386, 118, 111 });
	flyAnim.PushBack({ 689, 386, 118, 111 });
	flyAnim.PushBack({ 807, 386, 118, 111 });
	flyAnim.PushBack({ 925, 386, 118, 111 });
	flyAnim.PushBack({ 571, 386, 118, 111 });
	flyAnim.PushBack({ 689, 386, 118, 111 });

	//tercer stop
	flyAnim.PushBack({ 571, 609, 118, 111 });
	flyAnim.PushBack({ 689, 609, 118, 111 });
	flyAnim.PushBack({ 807, 609, 118, 111 });
	flyAnim.PushBack({ 925, 609, 118, 111 });
	flyAnim.PushBack({ 571, 609, 118, 111 });
	flyAnim.PushBack({ 689, 609, 118, 111 });
	flyAnim.PushBack({ 807, 609, 118, 111 });
	flyAnim.PushBack({ 925, 609, 118, 111 });
	flyAnim.PushBack({ 571, 609, 118, 111 });
	flyAnim.PushBack({ 689, 609, 118, 111 });
	flyAnim.PushBack({ 807, 609, 118, 111 });
	flyAnim.PushBack({ 925, 609, 118, 111 });
	flyAnim.PushBack({ 571, 609, 118, 111 });
	flyAnim.PushBack({ 689, 609, 118, 111 });
	flyAnim.PushBack({ 807, 609, 118, 111 });
	flyAnim.PushBack({ 925, 609, 118, 111 });

	//cuarto stop
	flyAnim.PushBack({ 571, 497, 118, 111 });
	flyAnim.PushBack({ 689, 497, 118, 111 });
	flyAnim.PushBack({ 807, 497, 118, 111 });
	flyAnim.PushBack({ 925, 497, 118, 111 });

	flyAnim.PushBack({ 571, 386, 118, 111 });
	flyAnim.PushBack({ 689, 386, 118, 111 });
	flyAnim.PushBack({ 807, 386, 118, 111 });
	flyAnim.PushBack({ 925, 386, 118, 111 });

	flyAnim.PushBack({ 571, 497, 118, 111 });
	flyAnim.PushBack({ 689, 497, 118, 111 });
	flyAnim.PushBack({ 807, 497, 118, 111 });
	flyAnim.PushBack({ 925, 497, 118, 111 });

	flyAnim.PushBack({ 571, 609, 118, 111 });
	flyAnim.PushBack({ 689, 609, 118, 111 });
	flyAnim.PushBack({ 807, 609, 118, 111 });
	flyAnim.PushBack({ 925, 609, 118, 111 });
	flyAnim.PushBack({ 571, 609, 118, 111 });
	flyAnim.PushBack({ 689, 609, 118, 111 });

	flyAnim.PushBack({ 571, 497, 118, 111 });
	flyAnim.PushBack({ 689, 497, 118, 111 });
	flyAnim.PushBack({ 807, 497, 118, 111 });
	flyAnim.PushBack({ 571, 497, 118, 111 });
	flyAnim.PushBack({ 689, 497, 118, 111 });
	flyAnim.PushBack({ 807, 497, 118, 111 });

	flyAnim.PushBack({ 571, 386, 118, 111 });
	flyAnim.PushBack({ 689, 386, 118, 111 });
	flyAnim.PushBack({ 807, 386, 118, 111 });
	flyAnim.PushBack({ 925, 386, 118, 111 });
	flyAnim.PushBack({ 571, 386, 118, 111 });
	flyAnim.PushBack({ 689, 386, 118, 111 });
	flyAnim.PushBack({ 807, 386, 118, 111 });
	flyAnim.PushBack({ 925, 386, 118, 111 });
	flyAnim.PushBack({ 571, 386, 118, 111 });
	flyAnim.PushBack({ 689, 386, 118, 111 });

	flyAnim.PushBack({ 571, 721, 118, 111 });
	flyAnim.PushBack({ 689, 721, 118, 111 });
	flyAnim.PushBack({ 807, 721, 118, 111 });
	flyAnim.PushBack({ 925, 721, 118, 111 });
	flyAnim.PushBack({ 571, 721, 118, 111 });
	flyAnim.PushBack({ 689, 721, 118, 111 });
	flyAnim.PushBack({ 807, 721, 118, 111 });
	flyAnim.PushBack({ 925, 721, 118, 111 });
	flyAnim.PushBack({ 571, 721, 118, 111 });
	flyAnim.PushBack({ 689, 721, 118, 111 });
	flyAnim.PushBack({ 807, 721, 118, 111 });
	flyAnim.PushBack({ 925, 721, 118, 111 });

	flyAnim.PushBack({ 571, 609, 118, 111 });
	flyAnim.PushBack({ 689, 609, 118, 111 });
	flyAnim.PushBack({ 807, 609, 118, 111 });
	flyAnim.PushBack({ 925, 609, 118, 111 });

	flyAnim.PushBack({ 571, 497, 118, 111 });
	flyAnim.PushBack({ 689, 497, 118, 111 });
	flyAnim.PushBack({ 807, 497, 118, 111 });
	flyAnim.PushBack({ 925, 497, 118, 111 });

	flyAnim.speed = 0.08;

	life = 80;

	score = 5000;
	money = 5000;

	currentAnim = &flyAnim;

	collider = App->collisions->AddCollider({ 500, 500, 100, 100 }, Collider::Type::ENEMY, (Module*)App->enemies);
}


void Enemy_Bosslvl1::Update()
{
	frameCount++;


	if (frameCount == 240 || frameCount == 270 || frameCount == 300 || frameCount == 330 || frameCount == 360 || frameCount == 680 || frameCount == 710 || frameCount == 740 || frameCount == 770 || frameCount == 800 || frameCount == 1300 || frameCount == 1340 || frameCount == 1380 || frameCount == 1420 || frameCount == 1750 || frameCount == 1770 || frameCount == 1790)
	{
		App->particles->AddParticle(App->particles->boss1MissileS, position.x + 20, position.y + 52, Collider::Type::ENEMY_SHOT);
	}
	if (frameCount == 460 || frameCount == 490 || frameCount == 520 || frameCount == 550 || frameCount == 580 || frameCount == 900 || frameCount == 930 || frameCount == 960 || frameCount == 1100 || frameCount == 1140 || frameCount == 1200 || frameCount == 1520 || frameCount == 1570 || frameCount == 1620)
	{
		App->particles->AddParticle(App->particles->boss1MissileS2, position.x + 20, position.y + 52, Collider::Type::ENEMY_SHOT);
	}

	if (frameCount == 90 || frameCount == 170 || frameCount == 250 || frameCount == 600 || frameCount == 680 || frameCount == 1020 || frameCount == 1260 || frameCount == 1320 || frameCount == 1620 || frameCount == 1680 || frameCount == 1740 || frameCount == 1770 || frameCount == 1800)
	{
		App->particles->AddParticle(App->particles->boss1Missile, position.x + 60, position.y + 30, Collider::Type::ENEMY_SHOT);
		App->particles->AddParticle(App->particles->boss1Missile, position.x + 50, position.y + 35, Collider::Type::ENEMY_SHOT);
		App->particles->AddParticle(App->particles->boss1Missile, position.x + 65, position.y + 40, Collider::Type::ENEMY_SHOT);
		App->particles->AddParticle(App->particles->boss1Missile, position.x + 55, position.y + 45, Collider::Type::ENEMY_SHOT);
	}
	if (frameCount == 360 || frameCount == 450 || frameCount == 540 || frameCount == 960 || frameCount == 1080 || frameCount == 1200 || frameCount == 1560)
	{
		App->particles->AddParticle(App->particles->boss1Missile2, position.x + 58, position.y + 22, Collider::Type::ENEMY_SHOT);
		App->particles->AddParticle(App->particles->boss1Missile2, position.x + 50, position.y + 27, Collider::Type::ENEMY_SHOT);
		App->particles->AddParticle(App->particles->boss1Missile2, position.x + 63, position.y + 32, Collider::Type::ENEMY_SHOT);
		App->particles->AddParticle(App->particles->boss1Missile2, position.x + 55, position.y + 37, Collider::Type::ENEMY_SHOT);
	}
	if (frameCount == 750 || frameCount == 820 || frameCount == 900 || frameCount == 1140 || frameCount == 1500)
	{
		App->particles->AddParticle(App->particles->boss1Missile3, position.x + 60, position.y + 24, Collider::Type::ENEMY_SHOT);
		App->particles->AddParticle(App->particles->boss1Missile3, position.x + 50, position.y + 19, Collider::Type::ENEMY_SHOT);
		App->particles->AddParticle(App->particles->boss1Missile3, position.x + 65, position.y + 14, Collider::Type::ENEMY_SHOT);
		App->particles->AddParticle(App->particles->boss1Missile3, position.x + 55, position.y + 9, Collider::Type::ENEMY_SHOT);
	}
	if (frameCount == 1380 || frameCount == 1440)
	{
		App->particles->AddParticle(App->particles->boss1Missile4, position.x + 60, position.y + 13, Collider::Type::ENEMY_SHOT);
		App->particles->AddParticle(App->particles->boss1Missile4, position.x + 50, position.y + 7, Collider::Type::ENEMY_SHOT);
		App->particles->AddParticle(App->particles->boss1Missile4, position.x + 65, position.y + 1, Collider::Type::ENEMY_SHOT);
		App->particles->AddParticle(App->particles->boss1Missile4, position.x + 55, position.y - 6, Collider::Type::ENEMY_SHOT);
	}

	if (frameCount >= 0 && frameCount < 240)
	{
		position.x -= 1;
	}
	else if (frameCount >= 240 && frameCount < 360)
	{

	}
	else if (frameCount >= 360 && frameCount < 460)
	{
		if (frameCount1 == 0)
		{
			position.x += 1;
			frameCount1 = frameDelay;
		}
		if (frameCount1 > 0)
			--frameCount1;
	}
	else if (frameCount >= 460 && frameCount < 580)
	{

	}
	else if (frameCount >= 580 && frameCount < 680)
	{
		if (frameCount1 == 0)
		{
			position.x -= 1;
			frameCount1 = frameDelay;
		}
		if (frameCount1 > 0)
			--frameCount1;
	}
	else if (frameCount >= 680 && frameCount < 800)
	{

	}
	else if (frameCount >= 800 && frameCount < 900)
	{
		if (frameCount1 == 0)
		{
			position.x += 1;
			frameCount1 = frameDelay;
		}
		if (frameCount1 > 0)
			--frameCount1;
	}
	else if (frameCount >= 900 && frameCount < 1200)
	{

	}
	else if (frameCount >= 1200 && frameCount < 1300)
	{
		if (frameCount1 == 0)
		{
			position.x -= 1;
			frameCount1 = frameDelay;
		}
		if (frameCount1 > 0)
			--frameCount1;
	}
	else if (frameCount >= 1300 && frameCount < 1420)
	{

	}
	else if (frameCount >= 1420 && frameCount < 1520)
	{
		if (frameCount1 == 0)
		{
			position.x += 1;
			frameCount1 = frameDelay;
		}
		if (frameCount1 > 0)
			--frameCount1;
	}
	else if (frameCount >= 1520 && frameCount < 1800)
	{

	}
	else
	{
		position.x += 1;
	}




	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();

}