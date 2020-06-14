#include "Enemy_Bosslvl2.h"

#include "Application.h"
#include "ModuleCollisions.h"
#include "ModuleParticles.h"
#include "ModuleCollisions.h"
#include "ModulePlayer.h"
#include "ModuleScene.h"
#include "ModuleFadeToBlack.h"
#include "MissionComplete.h"
#include "Enemy.h"
#include "ModuleEnemies.h"


Enemy_Bosslvl2::Enemy_Bosslvl2(int x, int y) : Enemy(x, y)
{
	flyAnim.PushBack({ 3, 278, 134, 72 });

	flyAnim.speed = 0.1;

	life = 80;

	score = 5000;
	money = 5000;

	currentAnim = &flyAnim;

	collider = App->collisions->AddCollider({ 0, 7, 134, 55 }, Collider::Type::ENEMY, (Module*)App->enemies);
}


void Enemy_Bosslvl2::Update()
{
	frameCount++;

	if (frameCount == 255 || frameCount == 405 || frameCount == 870 || frameCount == 1030 || frameCount == 1170)
	{
		App->particles->AddParticle(App->particles->bossCapsule, position.x + 20, position.y + 10, Collider::Type::ENEMY_SHOT);
	}
	if (frameCount == 275 || frameCount == 425 || frameCount == 890 || frameCount == 1050 || frameCount == 1190)
	{
		App->particles->AddParticle(App->particles->bossCapsule2, position.x + 20, position.y, Collider::Type::ENEMY_SHOT);
	}
	if (frameCount == 315 || frameCount == 465 || frameCount == 930 || frameCount == 1090 || frameCount == 1230)
	{
		App->particles->AddParticle(App->particles->bossCapsuleUp, position.x - 40, position.y - 50, Collider::Type::ENEMY_SHOT);
		App->particles->AddParticle(App->particles->bossCapsuleUpr, position.x - 40, position.y - 50, Collider::Type::ENEMY_SHOT);
		App->particles->AddParticle(App->particles->bossCapsuleUpl, position.x - 40, position.y - 50, Collider::Type::ENEMY_SHOT);
		App->particles->AddParticle(App->particles->bossCapsuleR, position.x - 40, position.y - 50, Collider::Type::ENEMY_SHOT);
		App->particles->AddParticle(App->particles->bossCapsuleL, position.x - 40, position.y - 50, Collider::Type::ENEMY_SHOT);
		App->particles->AddParticle(App->particles->bossCapsuleDnr, position.x - 40, position.y - 50, Collider::Type::ENEMY_SHOT);
		App->particles->AddParticle(App->particles->bossCapsuleDnl, position.x - 40, position.y - 50, Collider::Type::ENEMY_SHOT);
		App->particles->AddParticle(App->particles->bossCapsuleDn, position.x - 40, position.y - 50, Collider::Type::ENEMY_SHOT);
	}
	if (frameCount == 335 || frameCount == 485 || frameCount == 950 || frameCount == 1100 || frameCount == 1250)
	{
		App->particles->AddParticle(App->particles->bossCapsuleUp, position.x - 40, position.y, Collider::Type::ENEMY_SHOT);
		App->particles->AddParticle(App->particles->bossCapsuleUpr, position.x - 40, position.y, Collider::Type::ENEMY_SHOT);
		App->particles->AddParticle(App->particles->bossCapsuleUpl, position.x - 40, position.y, Collider::Type::ENEMY_SHOT);
		App->particles->AddParticle(App->particles->bossCapsuleR, position.x - 40, position.y, Collider::Type::ENEMY_SHOT);
		App->particles->AddParticle(App->particles->bossCapsuleL, position.x - 40, position.y, Collider::Type::ENEMY_SHOT);
		App->particles->AddParticle(App->particles->bossCapsuleDnr, position.x - 40, position.y, Collider::Type::ENEMY_SHOT);
		App->particles->AddParticle(App->particles->bossCapsuleDnl, position.x - 40, position.y, Collider::Type::ENEMY_SHOT);
		App->particles->AddParticle(App->particles->bossCapsuleDn, position.x - 40, position.y, Collider::Type::ENEMY_SHOT);
	}

	//Bombs
	if (frameCount == 280 || frameCount == 460 || frameCount == 900 || frameCount == 1090 || frameCount == 1200)
	{
		App->particles->AddParticle(App->particles->bossBomb, position.x + 30, position.y + 10, Collider::Type::ENEMY_SHOT);
	}
	if (frameCount == 310 || frameCount == 430 || frameCount == 930 || frameCount == 1060 || frameCount == 1230)
	{
		App->particles->AddParticle(App->particles->bossBomb, position.x + 50, position.y + 10, Collider::Type::ENEMY_SHOT);
	}
	//

	if (frameCount == 345 || frameCount == 350 || frameCount == 355 || frameCount == 360 || frameCount == 365 || frameCount == 370 || frameCount == 375 || frameCount == 380 || frameCount == 385 || frameCount == 390 || frameCount == 395 || frameCount == 400 || frameCount == 405)
	{
		App->particles->AddParticle(App->particles->bossShoot, position.x + 13, position.y + 11, Collider::Type::ENEMY_SHOT);
		App->particles->AddParticle(App->particles->bossShoot, position.x + 27, position.y + 13, Collider::Type::ENEMY_SHOT);
	}
	if (frameCount == 475 || frameCount == 480 || frameCount == 485 || frameCount == 490 || frameCount == 495 || frameCount == 500 || frameCount == 505 || frameCount == 510 || frameCount == 515 || frameCount == 520 || frameCount == 525 || frameCount == 530 || frameCount == 535 || frameCount == 540 || frameCount == 545 || frameCount == 550 || frameCount == 555)
	{
		App->particles->AddParticle(App->particles->bossShoot, position.x + 13, position.y + 10, Collider::Type::ENEMY_SHOT);
		App->particles->AddParticle(App->particles->bossShoot, position.x + 27, position.y + 15, Collider::Type::ENEMY_SHOT);
	}
	if (frameCount == 635 || frameCount == 640 || frameCount == 645 || frameCount == 650 || frameCount == 655 || frameCount == 660 || frameCount == 665 || frameCount == 670 || frameCount == 675 || frameCount == 680 || frameCount == 685 || frameCount == 690)
	{
		App->particles->AddParticle(App->particles->bossShoot, position.x + 13, position.y + 10, Collider::Type::ENEMY_SHOT);
		App->particles->AddParticle(App->particles->bossShoot, position.x + 27, position.y + 15, Collider::Type::ENEMY_SHOT);
	}
	if (frameCount == 695 || frameCount == 700 || frameCount == 705 || frameCount == 710 || frameCount == 715 || frameCount == 720 || frameCount == 725 || frameCount == 730 || frameCount == 735 || frameCount == 740 || frameCount == 745 || frameCount == 750)
	{
		App->particles->AddParticle(App->particles->bossShoot, position.x + 13, position.y + 10, Collider::Type::ENEMY_SHOT);
		App->particles->AddParticle(App->particles->bossShoot, position.x + 27, position.y + 15, Collider::Type::ENEMY_SHOT);
	}
	if (frameCount == 965 || frameCount == 970 || frameCount == 975 || frameCount == 980 || frameCount == 985 || frameCount == 990 || frameCount == 995 || frameCount == 1000 || frameCount == 1005)
	{
		App->particles->AddParticle(App->particles->bossShoot, position.x + 13, position.y + 10, Collider::Type::ENEMY_SHOT);
		App->particles->AddParticle(App->particles->bossShoot, position.x + 27, position.y + 15, Collider::Type::ENEMY_SHOT);
	}



	if (frameCount >= 0 && frameCount < 100)
	{
		position.x += 1;
	}
	else if (frameCount >= 100 && frameCount < 130)
	{
		position.x += 1;
		position.y -= 1;
	}
	else if (frameCount >= 130 && frameCount < 255)
	{
		position.x += 1;
	}
	else if (frameCount >= 255 && frameCount < 335)
	{
		position.x = position.x;
	}
	else if (frameCount >= 335 && frameCount < 405)
	{
		position.y -= 1;
	}
	else if (frameCount >= 405 && frameCount < 475)
	{
		position.x = position.x;
	}
	else if (frameCount >= 475 && frameCount < 575)
	{
		position.y -= 1;
	}
	else if (frameCount >= 575 && frameCount < 690)
	{
		position.y += 1;
	}
	else if (frameCount >= 690 && frameCount < 750)
	{
		position.y -= 1;
	}
	else if (frameCount >= 750 && frameCount < 870)
	{
		position.y += 1;
	}
	else if (frameCount >= 870 && frameCount < 940)
	{
		position.x = position.x;
	}
	else if (frameCount >= 940 && frameCount < 1030)
	{
		position.y -= 1;
	}
	else if (frameCount >= 1030 && frameCount < 1110)
	{
		position.x = position.x;
	}
	else if (frameCount >= 1110 && frameCount < 1170)
	{
		position.y -= 1;
	}
	else if (frameCount >= 1170 && frameCount < 1250)
	{
		position.x = position.x;
	}
	else if (frameCount >= 1250 && frameCount < 1600)
	{
		position.y += 1;
	}
	


	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();

}