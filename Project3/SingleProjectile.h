#ifndef SINGLEPROJECTILE_H
#define SINGLEPROJECTILE_H

#include "IProjectile.h"
#include "Vector2.h"
#include "Level.h"

class SingleProjectile : public IProjectile
{
	unsigned int _frameCount;
	Level& _level;
	char _character;
	Vector2 _position;
	Vector2 _velocity;
	int _damage;

	
public:
	SingleProjectile(Level& level, int damage, char ch, const Vector2& velocity);

	virtual int GetDamage();
	virtual char GetCharacter() const ;
	virtual const Vector2& GetPosition() const;
	virtual void SetPosition(const Vector2& position);
	virtual void Collide(IEntity& entity);
	virtual void Update();
};

#endif // !SINGLEPROJECTILE_H
