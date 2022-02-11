#ifndef PLAYER_H
#define PLAYER_H

#include <stack>
#include "IWeapon.h"
#include "IEntity.h"
#include "Level.h"
#include "Actor.h"

class Player : public Actor
{
public:
	Player(Level& level, char ch);

	void FireProjectile();
	
	virtual void TakeDamage(int damage);
	virtual void Collide(IEntity& entity);
	virtual void Update();
};

#endif // PLAYER_H

