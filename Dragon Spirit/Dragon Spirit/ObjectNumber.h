#pragma once


/* A list objects turned into their corresponding element of the groups array
   in Game. This is also needed in AssetManager to make sure objects are 
   being put in the right element. */
enum ObjectNumber
{
	dragon = 0,
	powerup,
	enemyProjectile,
	airEnemy,
	groundEnemy,
	dormant,
	dragonFire, 
	dragonBomb,
	Effects,
	Terrain
};