#include "Player.h"
#include "SingleProjectile.h"

Player::Player(Level& level, char ch)
	: Actor(level,ch)
{
}

void Player::TakeDamage(int damage)
{
	Actor::TakeDamage(damage);
	if (GetHealth() <= 0)
		_level.EndLevel();
}

void Player::Collide(IEntity& entity)
{
}
void Player::Update()
{
	
}
void Player::FireProjectile()
{
	if (_weapons.empty())
		return;

	if (!_weapons.top()->IsActive(*this))
	{
		_weapons.pop();

		if (_weapons.empty())
			return;
	}

	_weapons.top()->Fire(*this, _direction);
}
