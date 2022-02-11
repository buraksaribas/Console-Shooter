#include "WeaponPickupTile.h"
#include "IActor.h"
#include <iostream>

WeaponPickupTile::WeaponPickupTile(char ch, IWeapon* weapon)
	:_character(ch), _weapon(weapon)
{
}

char WeaponPickupTile::GetCharacter() const
{
	return _character;
}
bool WeaponPickupTile::CanEnter(IEntity& entity)
{
	return true;
}
void WeaponPickupTile::Enter(IEntity& entity)
{
	auto actor = dynamic_cast<IActor*>(&entity);
	if (actor == NULL)
		return;

	actor->SetWeapon(_weapon);
}