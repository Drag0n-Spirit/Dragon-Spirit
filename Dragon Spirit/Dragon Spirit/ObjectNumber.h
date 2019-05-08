#pragma once


/* A list objects turned into their corresponding element of the groups array
   in Game. This is also needed in AssetManager to make sure objects are 
   being put in the right element. */
enum ObjectNumber
{
	gameObject = 0,
	dragon,
	powerup,
	enemyProjectile,
	airEnemy,
	groundEnemy,
	dormant,
	dragonFire, 
	dragonBomb,
	effects,
	terrain,
	OBJNUM_SIZE
};