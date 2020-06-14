#include "ModuleParticles.h"

#include "Application.h"

#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleCollisions.h"
#include "ModulePlayer.h"

#include "SDL/include/SDL_timer.h"





ModuleParticles::ModuleParticles(bool startEnabled) : Module(startEnabled)
{
	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
		particles[i] = nullptr;
}

ModuleParticles::~ModuleParticles()
{

}

bool ModuleParticles::Start()
{
	LOG("Loading particles");
	texture = App->textures->Load("Assets/Sprites/Explosions_and_bullets.png");

	//Explosion particle

	explosion.anim.PushBack({ 430,132, 24, 24 });
	explosion.anim.PushBack({ 456, 132, 30, 24 });
	explosion.anim.PushBack({ 488, 132, 29, 25 });
	explosion.anim.PushBack({ 520, 131, 31, 27 });
	explosion.anim.PushBack({ 553, 130, 32, 28 });
	explosion.anim.PushBack({ 588, 131, 31, 27 });
	explosion.anim.PushBack({ 621, 131, 32, 26 });
	explosion.anim.speed = 0.3f;
	explosion.anim.loop = false;


	laser.anim.PushBack({ 98, 230, 18, 5 });
	laser.anim.PushBack({ 135, 229, 13, 6 });
	laser.anim.PushBack({ 162, 231, 18, 4 });
	laser.anim.PushBack({ 199, 231, 13, 4 });
	laser.anim.PushBack({ 226, 231, 18, 4 });
	laser.anim.PushBack({ 263, 231, 13, 4 });
	laser.speed.x = 5;
	laser.lifetime = 100;
	laser.anim.speed = 0.2f;

	enemyBullet.anim.PushBack({ 336, 43, 6, 6 });
	enemyBullet.anim.PushBack({ 351, 42, 6, 8 });
	enemyBullet.anim.PushBack({ 363, 43, 6, 6 });
	enemyBullet.anim.PushBack({ 375, 43, 6, 6 });
	enemyBullet.anim.PushBack({ 334, 59, 6, 8 });
	enemyBullet.anim.PushBack({ 350, 60, 6, 6 });
	enemyBullet.anim.speed = 0.2f;
	enemyBullet.speed.x = -2;
	enemyBullet.lifetime = 180;

	miniBoss.anim.PushBack({ 334, 72, 32, 24 });
	miniBoss.anim.PushBack({ 369, 72, 32, 24 });
	miniBoss.anim.speed = 0.1f;
	miniBoss.speed.x = -3;
	miniBoss.lifetime = 180;

	//Boss lvl 2 set of particles

	bossCapsule.anim.PushBack({ 429, 21, 11, 11 });
	bossCapsule.anim.PushBack({ 442, 21, 10, 11 });
	bossCapsule.anim.PushBack({ 454, 20, 13, 13 });
	bossCapsule.anim.speed = 0.1f;
	bossCapsule.speed.y = -1;
	bossCapsule.speed.x = -1;
	bossCapsule.lifetime = 60;

	bossCapsule2.anim.PushBack({ 429, 21, 11, 11 });
	bossCapsule2.anim.PushBack({ 442, 21, 10, 11 });
	bossCapsule2.anim.PushBack({ 454, 20, 13, 13 });
	bossCapsule2.anim.speed = 0.1f;
	bossCapsule2.speed.x = -1;
	bossCapsule2.lifetime = 60;

	bossCapsuleUp.anim.PushBack({ 448, 52, 5, 11 });
	bossCapsuleUp.anim.PushBack({ 493, 52, 6, 12 });
	bossCapsuleUp.anim.speed = 0.1f;
	bossCapsuleUp.speed.y = -3;
	bossCapsuleUp.lifetime = 180;

	bossCapsuleUpr.anim.PushBack({ 458, 57, 8, 9 });
	bossCapsuleUpr.anim.PushBack({ 501, 57, 9, 9 });
	bossCapsuleUpr.anim.speed = 0.1f;
	bossCapsuleUpr.speed.y = -2;
	bossCapsuleUpr.speed.x = 2;
	bossCapsuleUpr.lifetime = 180;

	bossCapsuleUpl.anim.PushBack({ 434, 57, 8, 9 });
	bossCapsuleUpl.anim.PushBack({ 478, 57, 9, 9 });
	bossCapsuleUpl.anim.speed = 0.1f;
	bossCapsuleUpl.speed.y = -2;
	bossCapsuleUpl.speed.x = -2;
	bossCapsuleUpl.lifetime = 180;

	bossCapsuleR.anim.PushBack({ 459, 71, 12, 6 });
	bossCapsuleR.anim.PushBack({ 502, 71, 14, 5 });
	bossCapsuleR.anim.speed = 0.1f;
	bossCapsuleR.speed.x = 3;
	bossCapsuleR.lifetime = 180;

	bossCapsuleL.anim.PushBack({ 429, 71, 12, 6 });
	bossCapsuleL.anim.PushBack({ 472, 71, 14, 5 });
	bossCapsuleL.anim.speed = 0.1f;
	bossCapsuleL.speed.x = -3;
	bossCapsuleL.lifetime = 180;

	bossCapsuleDnr.anim.PushBack({ 457, 78, 9, 9 });
	bossCapsuleDnr.anim.PushBack({ 500, 78, 10, 9 });
	bossCapsuleDnr.anim.speed = 0.1f;
	bossCapsuleDnr.speed.y = 2;
	bossCapsuleDnr.speed.x = 2;
	bossCapsuleDnr.lifetime = 180;

	bossCapsuleDnl.anim.PushBack({ 434, 78, 8, 9 });
	bossCapsuleDnl.anim.PushBack({ 478, 78, 9, 9 });
	bossCapsuleDnl.anim.speed = 0.1f;
	bossCapsuleDnl.speed.y = 2;
	bossCapsuleDnl.speed.x = -2;
	bossCapsuleDnl.lifetime = 180;

	bossCapsuleDn.anim.PushBack({ 448, 81, 6, 11 });
	bossCapsuleDn.anim.PushBack({ 493, 80, 5, 12 });
	bossCapsuleDn.anim.speed = 0.1f;
	bossCapsuleDn.speed.y = 3;
	bossCapsuleDn.lifetime = 180;

	bossBomb.anim.PushBack({ 429, 98, 25, 11 });
	bossBomb.anim.PushBack({ 456, 98, 25, 11 });
	bossBomb.anim.PushBack({ 483, 98, 25, 11 });
	bossBomb.anim.PushBack({ 429, 110, 25, 20 });
	bossBomb.anim.PushBack({ 456, 110, 25, 20 });
	bossBomb.anim.PushBack({ 483, 110, 25, 20 });
	bossBomb.anim.speed = 0.1f;
	bossBomb.speed.y = 2;
	bossBomb.lifetime = 180;
	bossBomb.anim.loop = false;

	bossShoot.anim.PushBack({ 405, 294, 11, 8 });
	bossShoot.anim.speed = 0.1f;
	bossShoot.speed.x = -4;
	bossShoot.lifetime = 180;

	boss1Missile.anim.PushBack({ 679, 31, 30, 12 });
	boss1Missile.anim.PushBack({ 714, 30, 30, 12 });
	boss1Missile.anim.speed = 0.1f;
	boss1Missile.speed.x = -4;
	boss1Missile.lifetime = 180;

	boss1Missile2.anim.PushBack({ 679, 47, 28, 12 });
	boss1Missile2.anim.PushBack({ 714, 48, 31, 12 });
	boss1Missile2.anim.speed = 0.1f;
	boss1Missile2.speed.x = -4;
	boss1Missile2.speed.y = -1;
	boss1Missile2.lifetime = 180;

	boss1Missile3.anim.PushBack({ 680, 65, 26, 16 });
	boss1Missile3.anim.PushBack({ 716, 65, 29, 16 });
	boss1Missile3.anim.speed = 0.1f;
	boss1Missile3.speed.x = -4;
	boss1Missile3.speed.y = -2;
	boss1Missile3.lifetime = 180;

	boss1Missile4.anim.PushBack({ 687, 87, 22, 21 });
	boss1Missile4.anim.PushBack({ 716, 86, 25, 24 });
	boss1Missile4.anim.speed = 0.1f;
	boss1Missile4.speed.x = -4;
	boss1Missile4.speed.y = -3;
	boss1Missile4.lifetime = 180;

	boss1MissileS.anim.PushBack({ 766, 67, 17, 6 });
	boss1MissileS.anim.PushBack({ 768, 90, 14, 7 });
	boss1MissileS.anim.speed = 0.1f;
	boss1MissileS.speed.x = -2;
	boss1MissileS.lifetime = 180;

	boss1MissileS2.anim.PushBack({ 815, 63, 14, 14 });
	boss1MissileS2.anim.PushBack({ 819, 87, 12, 12 });
	boss1MissileS2.anim.speed = 0.1f;
	boss1MissileS2.speed.x = -2;
	boss1MissileS2.speed.y = -2;
	boss1MissileS2.lifetime = 180;

	turretUp.anim.PushBack({ 336, 43, 6, 6 });
	turretUp.anim.PushBack({ 351, 42, 6, 8 });
	turretUp.anim.PushBack({ 363, 43, 6, 6 });
	turretUp.anim.PushBack({ 375, 43, 6, 6 });
	turretUp.anim.PushBack({ 334, 59, 6, 8 });
	turretUp.anim.PushBack({ 350, 60, 6, 6 });
	turretUp.anim.speed = 0.2f;
	turretUp.speed.y = -2;
	turretUp.lifetime = 180;

	turretUpl.anim.PushBack({ 336, 43, 6, 6 });
	turretUpl.anim.PushBack({ 351, 42, 6, 8 });
	turretUpl.anim.PushBack({ 363, 43, 6, 6 });
	turretUpl.anim.PushBack({ 375, 43, 6, 6 });
	turretUpl.anim.PushBack({ 334, 59, 6, 8 });
	turretUpl.anim.PushBack({ 350, 60, 6, 6 });
	turretUpl.anim.speed = 0.2f;
	turretUp.speed.x = -2;
	turretUpl.speed.y = -2;
	turretUpl.lifetime = 180;

	pBomb.anim.PushBack({ 516,292,13,10 });
	pBomb.anim.PushBack({ 530,288,13,14 });
	pBomb.anim.PushBack({ 545,288,11,14 });
	pBomb.speed.y = 2;
	pBomb.lifetime = 180;
	pBomb.anim.speed = 0.1f;
	pBomb.anim.loop = false;

	blueLaser1.anim.PushBack({ 514,218,15,14 });
	blueLaser1.anim.PushBack({ 529,218,14,14 });
	blueLaser1.anim.PushBack({ 544,218,15,14 });
	blueLaser1.anim.PushBack({ 559,218,15,14 });
	blueLaser1.anim.PushBack({ 574,218,30,14 });
	blueLaser1.anim.PushBack({ 604,218,30,14 });
	blueLaser1.anim.PushBack({ 634,218,33,14 });
	blueLaser1.speed.x = 4;
	blueLaser1.lifetime = 120;
	blueLaser1.anim.speed = 0.2f;
	blueLaser1.anim.loop = false;

	Megacrush.anim.PushBack({ 514,248,19,26 });
	Megacrush.anim.PushBack({ 531,248,29,26 });
	Megacrush.anim.PushBack({ 561,248,51,26 });
	Megacrush.anim.PushBack({ 610,248,81,26 });
	Megacrush.anim.PushBack({ 691,248,78,26 });
	Megacrush.speed.x = 4;
	Megacrush.lifetime = 120;
	Megacrush.anim.speed = 0.2f;
	Megacrush.anim.loop = false;

	Cluster.anim.PushBack({ 0,519,250,186 });
	Cluster.anim.PushBack({ 250,519,250,186 });
	Cluster.anim.PushBack({ 500,519,250,186 });
	Cluster.anim.PushBack({ 750,519,250,186 });
	Cluster.anim.PushBack({ 1000,519,250,186 });
	Cluster.anim.PushBack({ 1250,519,250,186 });
	Cluster.anim.PushBack({ 1500,519,250,186 });
	Cluster.anim.PushBack({ 1750,519,250,186 });
	Cluster.anim.PushBack({ 2000,519,250,186 });
	Cluster.anim.PushBack({ 2250,519,250,186 });
	Cluster.anim.PushBack({ 2500,519,250,186 });
	Cluster.anim.PushBack({ 2750,519,250,186 });
	Cluster.anim.PushBack({ 3000,519,250,186 });
	Cluster.anim.PushBack({ 3250,519,250,186 });
	Cluster.lifetime = 50;
	Cluster.anim.speed = 0.3f;
	Cluster.anim.loop = false;

	return true;
}


bool ModuleParticles::CleanUp()
{
	LOG("Unloading particles");

	// Delete all remaining active particles on application exit 
	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if(particles[i] != nullptr)
		{
			delete particles[i];
			particles[i] = nullptr;
		}
	}

	return true;
}

void ModuleParticles::OnCollision(Collider* c1, Collider* c2)
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		// Always destroy particles that collide
		if (particles[i] != nullptr && particles[i]->collider == c1)
		{
			delete particles[i];
			particles[i] = nullptr;
			break;
		}
	}
}

update_status ModuleParticles::Update()
{
	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		Particle* particle = particles[i];

		if(particle == nullptr)	continue;

		// Call particle Update. If it has reached its lifetime, destroy it
		if(particle->Update() == false)
		{
			delete particle;
			particles[i] = nullptr;
		}
	}

	return update_status::UPDATE_CONTINUE;
}

update_status ModuleParticles::PostUpdate()
{
	//Iterating all particle array and drawing any active particles
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		Particle* particle = particles[i];

		if (particle != nullptr && particle->isAlive)
		{
			App->render->Blit(texture, particle->position.x, particle->position.y, &(particle->anim.GetCurrentFrame()));
		}
	}

	return update_status::UPDATE_CONTINUE;
}

Particle* ModuleParticles::AddParticle(const Particle& particle, int x, int y, Collider::Type colliderType, uint delay)
{
	Particle* newParticle = nullptr;

	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		//Finding an empty slot for a new particle
		if (particles[i] == nullptr)
		{
			newParticle = new Particle(particle);
			newParticle->frameCount = -(int)delay;			// We start the frameCount as the negative delay
			newParticle->position.x = x;						// so when frameCount reaches 0 the particle will be activated
			newParticle->position.y = y;

			//Adding the particle's collider
			if (colliderType != Collider::Type::NONE)
				newParticle->collider = App->collisions->AddCollider(newParticle->anim.GetCurrentFrame(), colliderType, this);

			particles[i] = newParticle;
			break;
		}
	}

	return newParticle;
}