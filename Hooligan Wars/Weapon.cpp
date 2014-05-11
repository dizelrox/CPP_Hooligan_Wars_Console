#include <iostream>
#include <string>
#include "Item.cpp"
#pragma once
using namespace std;


class Weapon:public Item
{
public:
	Weapon(string name, bool available, int damageValue) : Item(name, available)
	{
		
		setDamageValue(damageValue);
	}

	Weapon()
	{

	}


	int getDamageValue()
	{
		return damageValue;
	}

	void setDamageValue(int val)
	{
		this->damageValue = val;
	}

	string getItemType()
	{
		return itemType;
	}

	void setItemType(string value)
	{
		//final type cannot be set
	}

private:
	int damageValue;
	const string itemType = "weapon";
};
