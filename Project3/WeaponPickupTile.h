#ifndef WEAPONPICKUPTILE_H
#define WEAPONPICKUPTILE_H

#include "ITile.h"
#include "IWeapon.h"

class WeaponPickupTile : public ITile
{
private:
	char _character;
	IWeapon* _weapon;
public:
	WeaponPickupTile(char ch, IWeapon* weapon);

	virtual char GetCharacter() const;
	virtual bool CanEnter(IEntity& entity);
	virtual void Enter(IEntity& entity);
};

#endif // !WEAPONPICKUPTILE_H
