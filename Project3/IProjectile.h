#ifndef IPROJECTILE_H
#define IPROJECTILE_H

#include "IEntity.h"

class IProjectile : public IEntity
{
public:
	virtual int GetDamage() = 0;
};

#endif