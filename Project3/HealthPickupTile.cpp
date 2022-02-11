#include <iostream>
#include "IActor.h"
#include "HealthPickupTile.h"

HealthPickupTile::HealthPickupTile(char ch, int healthToGive)
	:_character(ch), _healthToGive(healthToGive)
{
}
char HealthPickupTile::GetCharacter() const
{
	return _character;
}
bool HealthPickupTile::CanEnter(IEntity& entity)
{
	return true;
}
void HealthPickupTile::Enter(IEntity& entity)
{
	auto actor = dynamic_cast<IActor*>(&entity);
	if (actor == NULL)
		return;

	actor->TakeDamage(-_healthToGive);
}