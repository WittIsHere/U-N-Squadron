#ifndef __ENEMY_BOSSLVL2_H__
#define __ENEMY_BOSSLVL2_H__

#include "Enemy.h"

class Enemy_Bosslvl2 : public Enemy
{
public:

	// Constructor (x y coordinates in the world)
	// Creates animation data and the collider
	Enemy_Bosslvl2(int x, int y);

	// The enemy is going to perform a sinusoidal movement
	void Update() override;

private:
	// The position (as ratio) in the wave at a specific moment
	float waveRatio = 0.5f;

	// The speed at which the wave ratio is increased
	float waveRatioSpeed = 0.05f;

	// The original spawning position. The wave will be calculated from that
	int spawn_y = 0;

	// The total height of the wave
	int waveHeight = 15;

	int i = 0;

	bool facingLeft = 0;

	int frameCount = 0;

	bool isHist = 0;

	// The enemy animation
	Animation flyAnim;


};

#endif // __ENEMY_BOSSLVL2_H__