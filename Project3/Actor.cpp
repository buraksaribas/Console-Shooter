#include "Actor.h"
#include "SingleProjectile.h"

Actor::Actor(Level& level, char ch)
	: _level(level), _character(ch), _health(100)
{
}

char Actor::GetCharacter() const
{
	return _character;
}
const Vector2& Actor::GetPosition() const
{
	return _position;
}

void Actor::SetWeapon(IWeapon* weapon)
{
	_weapons.push(weapon);
	weapon->Attach(*this);
}

IWeapon* Actor::GetWeapon() const
{
	return !_weapons.empty() ? _weapons.top() : NULL;
}

int Actor::GetHealth() const
{
	return _health;
}
void Actor::TakeDamage(int damage)
{
	_health -= damage;
	if (_health <= 0)
		_level.RemoveEntity(this);
}

void Actor::SetPosition(const Vector2& position)
{
	_position = position;
}

void Actor::Move(const Vector2& direction)
{
	auto newPosition = _position + direction;
	_level.MoveEntity(*this, newPosition);
	_direction = direction;
}
