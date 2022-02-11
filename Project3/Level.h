#ifndef LEVEL_H
#define LEVEL_H

#include "ITile.h"
#include <Windows.h>
#include <vector>

class Level
{
private:
	bool _hasEnded;
	bool _isUpdating;
	std::vector<IEntity*> _entitiesToRemove;
	int _width, _height;
	std::vector<ITile*> _tiles;
	std::vector<IEntity*> _entities;

public:
	Level(int width, int height);
	int GetWidth() const;
	int GetHeight() const;

	void EndLevel();
	bool HasLevelEnded() const;

	void SetTile(ITile& tile, Vector2 pos);
	void SetTiles(ITile& tile, Vector2 from, Vector2 to);
	void SetEntity(IEntity* entity, Vector2 pos);
	bool MoveEntity(IEntity& entity, Vector2 pos);
	void RemoveEntity(IEntity* entity);
	void Update();

	void RenderAll();

private:
	IEntity* GetEntityAt(const Vector2& position) const;
	int GetIndexForXY(int x, int y) const;
	void SetCharacter(char ch, int x, int y);
};

#endif // !LEVEL_H
