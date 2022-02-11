#include "Fireball.h"
#include "SingleProjectile.h"

Fireball::Fireball(char character, Level& level, int damage)
	: _level(level), _character(character), _damage(damage)
{
}

void Fireball::Attach(IEntity& entity)
{
}
void Fireball::Fire(IEntity& entity, const Vector2& direction) 
{
	_level.SetEntity(new SingleProjectile(_level, _damage, _character, direction), entity.GetPosition() + direction);
}
bool Fireball::IsActive(IEntity& entity)
{
	return true;
}
