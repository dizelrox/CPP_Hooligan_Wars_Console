#include <iostream>
#include <string>
#pragma once

using namespace std;


class Item
{
public:
	virtual string getItemType() = 0;

	void setItemType(string value);

	Item(string name,bool available)
	{
		setName(name);
		setAvalible(available);
	}

	Item()
	{

	}

	bool isAvalible()
	{
		return available;
	}

	void setAvalible(bool val)
	{
		this->available = val;
	}

	string getName()
	{
		return name;
	}

	void setName(string val)
	{
		this->name = val;
	}

	string toString()
	{
		return getName();
	}


private:
	string name;
	bool available;
	bool inUse = false;
};

