#include <string>
#include "Item.cpp"
#include "Weapon.cpp"
#include "Armor.cpp"
using namespace std;
#pragma once
class Player
{
public:

	Player(Weapon* wepArr[], Armor armArr[]) //Bot constructor
	{

		int rndStrength = rand() % 3 + 1;
		double f = (double)rand() / RAND_MAX;
		double rndDefence = 0.1 + f * (0.4 - 0.1);
		setStrengthFactor(rndStrength);
		setDefenceFactor(rndDefence);
		for (int area = 0; area < 4;)
		{
			Armor randomItem = armArr[rand() % 12];
			if (attackAreaToInt(randomItem.getItemType()) == area)
			if (randomItem.isAvalible())
			{
				armor[area] = randomItem;
				area++;
			}
		}


		do 
		{
			weapon =  wepArr[rand() % 8];
		} while (weapon->isAvalible() == false);

		string botNames[] = { "Destructor", "Garbage Collector", "Static Member", "Exception Handler" };
		setName(botNames[rand() % 4]);
		setHealth(100);
		//setGold(100); //disabled PRICE

	}

	string numberToArea(int area)
	{
		if (area == 0)
			return "HEAD";
		if (area == 1)
			return "CHEST";
		if (area == 2)
			return "STOMACH";
		if (area == 3)
			return "LEGS";
	}

	Player(Weapon* wepArr[8], Armor armArr[12], string name) :Player(wepArr, armArr)
	{
		setName(name);
	}

	Player()
	{

	}

	string getConsoleText()
	{
		return this->consoleText;
	}

	string getRandomAttackArea()
	{
		int random = rand() % 4;
		if (random == 0)
			return "HEAD";
		if (random == 1)
			return "CHEST";
		if (random == 2)
			return "STOMACH";
		if (random == 3)
			return "LEGS";
	}

	double getDefenceFactor()
	{
		return this->defenceFactor;
	}

	void setDefenceFactor(double val)
	{
		this->defenceFactor = val;
	}

	int getHealth()
	{
		return this->health;
	}

	void setHealth(int val)
	{
		this->health = val;
	}

	string getName()
	{
		return this->name;
	}

	void setName(string val)
	{
		this->name = val;
	}

	int getStrengthFactor()
	{
		return strengthFactor;
	}

	void setStrengthFactor(int val)
	{
		this->strengthFactor = val;
	}

	void toString()
	{
		cout<< "player name is "<< getName() <<"\nplayer strength factor is "<<getStrengthFactor()<<"\nplayer def factor is "<<getDefenceFactor()<<"\n"
			<< "player helmet is " << armor[0].toString() << "\n"
			<< "player armor is " << armor[1].toString() << "\n"
			<< "player belt is " << armor[2].toString() << "\n"
			<< "player legs is " << armor[3].toString() << "\n"
			<< "player weapon is " << weapon->toString() << "\n"
			<< "player health is " << getHealth()<<endl;
	}

	void throwHit(Weapon* weapon, int strFactor, string attackArea, Player &target)
	{
		int damage = (weapon != NULL) ? weapon->getDamageValue() + strFactor : strFactor;
		target.getHit(damage,attackArea, *weapon);
	}

	int attackAreaToInt(string attackArea)
	{
		if (attackArea == "HEAD")
			return 0;
		if (attackArea == "CHEST")
			return 1;
		if (attackArea == "STOMACH")
			return 2;
		if (attackArea == "LEGS")
			return 3;
	}

	void getHit(int damage, string attackArea, Weapon weapon)
	{
		double rawDamage; // damage thrown by the attacker
		rawDamage = damage - damage*getDefenceFactor(); //subtract the defence factor (random for each match) from the damage received

		if (&(this->armor[attackAreaToInt(attackArea)]) != NULL)
			rawDamage -= rawDamage * ((Armor) this->armor[attackAreaToInt(attackArea)]).getDefenceValue();


		if (attackArea == getDefenceArea()) //is area attacked the same as defended?
		{
			if ((int)rawDamage / 2 > getHealth())
				this->health = 0;
			else
				this->health -= (int)rawDamage / 2;

			string convertToString;
			convertToString = std::to_string((int)(rawDamage / 2));
			this->consoleText = this->getName() + " has been hit with " + weapon.getName() + " in the " + attackArea + "."+"\n"+"This attack was successfully blocked.\nGot " + convertToString  +  " points of damage!\n";
				 
		}
		else
		{
			if ((int)rawDamage > getHealth())
				this->health = 0;
			else
				this->health -= (int)rawDamage;
			string convertToString;
			convertToString = std::to_string((int)(rawDamage));
			consoleText = this->getName() + " has been hit with " + weapon.getName() + " in the " + attackArea + "." +"\n"+ "This attack wasn't properly blocked.\nGot " + convertToString + " points of damage!\n";
		}



	}

	string getAttackArea()
	{
		return this->attackArea;
	}

	void setAttackArea(int area)
	{
		this->attackArea = numberToArea(area);
	}

	string getDefenceArea()
	{
		return defenceArea;
	}

	void setDefenceArea(int area)
	{
		this->defenceArea = numberToArea(area);
	}

	Armor getItem(string area)
	{
		return armor[attackAreaToInt(area)];
	}

	Weapon* getWeapon()
	{
		return weapon;
	}


private:
	int strengthFactor;
	double defenceFactor;
	Armor armor[4];
	Weapon* weapon;
	string name;
	int health;
	string defenceArea;
	string attackArea;
	string consoleText;
};