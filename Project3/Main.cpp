#include <iostream>
#include <string>
#include <conio.h>
#include "Level.h"
#include "SingleProjectile.h"
#include "Player.h"
#include "Fireball.h"
#include "WeaponPickupTile.h"
#include "MultiFireball.h"
#include "Enemy.h"
#include "HealthPickupTile.h"
#include <fstream>

using namespace std;

class BasicTile : public ITile
{
private:
	char _character;
	bool _canEnter;
public:
	BasicTile(char ch, bool canEnter) : _character(ch), _canEnter(canEnter)
	{

	}

	virtual char GetCharacter() const { return _character; }
	virtual bool CanEnter(IEntity& entity) { return _canEnter; }
	virtual void Enter(IEntity& entity) { }
};

class BasicEntity : public IEntity
{
private:
	char _character;
	Vector2 _position;
public:
	BasicEntity(char ch) : _character(ch), _position(0, 0)
	{
	}

	virtual char GetCharacter() const { return _character; }
	virtual const Vector2& GetPosition() const { return _position; }
	virtual void SetPosition(const Vector2& position) { _position = position; }
	virtual void Collide(IEntity& entity) {}
	virtual void Update() { }
};

int main()
{
	ifstream levelStream("level");
	if (!levelStream)
	{
		cout << "Can't find level\n";
		cin.get();
		return 1;
	}

	vector<string> levelMap;
	int levelWidth = 0;
	while (!levelStream.eof())
	{
		string line;
		getline(levelStream, line);
		levelWidth = levelWidth < line.size() ? line.size() : levelWidth;
		levelMap.push_back(line);
	}
	levelStream.close();
	Level level(levelWidth, levelMap.size());

	BasicTile empty(' ', true);
	BasicTile wall('#', false);
	HealthPickupTile health('+', 100);
	WeaponPickupTile weapon1('%', new MultiFireball('^', level, 30));

	Player* player = NULL;

	for (auto y = 0; y < levelMap.size(); y++)
	{
		auto line = levelMap[y];
		for (auto x = 0; x < levelWidth; x++)
		{
			char currentCell = x < line.size() ? line[x] : ' ';
			if (currentCell == ' ')
				level.SetTile(empty, Vector2(x, y));
			else if (currentCell == '#')
				level.SetTile(wall, Vector2(x, y));
			else if (currentCell == '+')
				level.SetTile(health, Vector2(x, y));
			else if (currentCell == '%')
				level.SetTile(weapon1, Vector2(x, y));
			else
			{
				level.SetTile(empty, Vector2(x, y));
				if (currentCell == '$')
				{
					level.SetEntity(player = new Player(level, '$'), Vector2(x, y));
					player->SetWeapon(new Fireball('*', level, 20));
				}
				else if (currentCell == '!')
				{
					Enemy* enemy = NULL;
					level.SetEntity(enemy = new Enemy(level, '!'), Vector2(x, y));
					enemy->SetWeapon(new Fireball('*', level, 20));
				}

			}
		}
	}

	/*
	BasicTile empty(' ', true);
	BasicTile wall('#', false);
	HealthPickupTile health('+', 100);
	WeaponPickupTile weapon1('%', new MultiFireball('^', level, 30));

	level.SetTiles(empty, Vector2(0, 0), Vector2(49, 19));
	level.SetTiles(wall, Vector2(0, 0), Vector2(0, 19));
	level.SetTiles(wall, Vector2(0, 0), Vector2(49, 0));
	level.SetTiles(wall, Vector2(49, 0), Vector2(49, 19));
	level.SetTiles(wall, Vector2(0, 19), Vector2(49, 19));
	level.SetTiles(wall, Vector2(4, 4), Vector2(6, 6));
	level.SetTile(weapon1, Vector2(8, 8));
	level.SetTile(health, Vector2(1, 1));
	level.SetTile(weapon1, Vector2(29, 15));
	level.SetTile(health, Vector2(25, 16));

	auto player = new Player(level, '$');
	player->SetWeapon(new Fireball('*', level, 20));

	level.SetEntity(player, Vector2(1, 2));

	auto e1 = new Enemy(level, '!');
	e1->SetWeapon(new Fireball('*', level, 20));
	auto e2 = new Enemy(level, '!');
	e2->SetWeapon(new Fireball('*', level, 20));
	auto e3 = new Enemy(level, '!');
	e3->SetWeapon(new Fireball('*', level, 20));


	level.SetEntity(e1, Vector2(30, 15));
	level.SetEntity(e2, Vector2(31, 15));
	level.SetEntity(e3, Vector2(32, 15));
	*/

	char input = '\0';

	level.RenderAll();
	auto lastTime = timeGetTime();
	while (input != 27)
	{
		if (level.HasLevelEnded())
		{
			cout << "you died!";
			break;
		}
		auto currentElapsed = timeGetTime() - lastTime;
		if (currentElapsed > 33.3)
		{
			lastTime = timeGetTime();
			level.Update();
		}
		if (_kbhit())
		{
			input = _getch();

			auto pos = player->GetPosition();
			if (input == 'w')
				player->Move(Vector2::North);
			else if (input == 'a')
				player->Move(Vector2::West);
			else if (input == 's')
				player->Move(Vector2::South);
			else if (input == 'd')
				player->Move(Vector2::East);
			else if (input == ' ')
			{
				player->FireProjectile();
				//auto projectile = new SingleProjectile(level, 10, '*', Vector2(0, 1));
				//level.SetEntity(*projectile, pos + Vector2(0, 1));
			}

		}
	}



	cin.get();
	return 0;
}