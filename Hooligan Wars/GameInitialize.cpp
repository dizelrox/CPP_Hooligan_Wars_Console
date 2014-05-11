#include <string>
#include "Armor.cpp"
#include "Weapon.cpp"
#include "Player.cpp"
#pragma once
using namespace std;

class GameInitialize
{
public:
	static const string gameVersion;


	GameInitialize()
	{
		armArray[0] = Armor("Adidas Cap", true, "HEAD", 0.1);
		armArray[1] = Armor("Biker Mohawk", true, "HEAD", 0.2);
		armArray[2] = Armor("Real Men's Hat", true, "HEAD", 0.3);
		armArray[3] = Armor("Adidas Original", true, "CHEST", 0.1);
		armArray[4] = Armor("Motorcycle Armor", true, "CHEST", 0.2);
		armArray[5] = Armor("Poseidon Armor", true, "CHEST", 0.3);
		armArray[6] = Armor("Summer Shorts", true, "STOMACH", 0.1);
		armArray[7] = Armor("Motorcycle Pants", true, "STOMACH", 0.2);
		armArray[8] = Armor("Real Men's Pants", true, "STOMACH", 0.3);
		armArray[9] = Armor("Russian Style", true, "LEGS", 0.1);
		armArray[10] = Armor("Boots", true, "LEGS", 0.2);
		armArray[11] = Armor("Army Boots", true, "LEGS", 0.3);

		wepArray[0] = new Weapon("Butterfly", true, 10);
		wepArray[1] = new Weapon("Brace Knuckles", true, 10);
		wepArray[2] = new Weapon("Maccabi Bottle", true, 10);
		wepArray[3] = new Weapon("Motorcycle Chain", true, 15);
		wepArray[4] = new Weapon("Pepper Spray", true, 15);
		wepArray[5] = new Weapon("Brick", true, 10);
		wepArray[6] = new Weapon("Molotov", true, 20);
		wepArray[7] = new Weapon("Sword", true, 20);
		//bot = new Player(wepArray, armArray);
		player = new Player(wepArray, armArray, "Player1");
	}

	Player& getBot()
	{
		return *bot;
	}

	void setNewBot()
	{
		bot = new Player(wepArray, armArray);
	}

	Player& getPlayer()
	{
		return *player;
	}

private:
	Armor armArray[12];
	Weapon* wepArray[8];
	Player* player;
	Player* bot;
};