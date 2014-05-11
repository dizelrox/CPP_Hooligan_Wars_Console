#include <iostream>
#include <string>
#include "Item.cpp"
#pragma once
using namespace std;



class Armor : public Item
{
public:
	Armor(string name, bool available, string itemType, double defenceValue) : Item(name, available)
	{

		setItemType(itemType);
		setDefenceValue(defenceValue);

	}

	Armor()
	{

	}

	double getDefenceValue()
	{
		return defenceValue;
	}

	void setDefenceValue(double val)
	{
		this->defenceValue = val;
	}

	//Override
	string getItemType()
    {
        return this->itemType;
    }

	void setItemType(string value)
	{
		this->itemType = value;

	}




private:
	double defenceValue;
	string itemType;
};
