#include "MultiFireball.h"
#include "SingleProjectile.h"

MultiFireball::MultiFireball(char character, Level& level, int damage)
	: _level(level), _character(character), _damage(damage)
{

}

void MultiFireball::Attach(IEntity& entity)
{
	_ammo[&entity] = 20;
}
void MultiFireball::Fire(IEntity& entity, const Vector2& direction)
{
	_ammo[&entity]--;

	CreateProjectile(entity.GetPosition(), Vector2::North);
	CreateProjectile(entity.GetPosition(), Vector2::South);
	CreateProjectile(entity.GetPosition(), Vector2::East);
	CreateProjectile(entity.GetPosition(), Vector2::West);

}

bool MultiFireball::IsActive(IEntity& entity)
{
	auto iter = _ammo.find(&entity);

	if (iter == _ammo.end())
		return false;

	if ((*iter).second <= 0)
	{
		_ammo.erase(iter);
		return false;
	}

	return true;
}

void MultiFireball::CreateProjectile(const Vector2& position, const Vector2& direction)
{
	_level.SetEntity(new SingleProjectile(_level, _damage, _character, direction), position + direction);
}