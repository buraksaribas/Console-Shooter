#ifndef HEALTHPICKUPTILE_H
#define HEALTHPICKUPTILE_H

#include "ITile.h"
#include "IWeapon.h"

class HealthPickupTile : public ITile
{
private:
	char _character;
	int _healthToGive;
public:
	HealthPickupTile(char ch, int healthToGive);

	virtual char GetCharacter() const;
	virtual bool CanEnter(IEntity& entity);
	virtual void Enter(IEntity& entity);
};

#endif // !HEALTHPICKUPTILE_H
