#pragma once

class Marine //: public Entity
{
public:
	Marine();
	~Marine();

	bool isAlive = true;
	int health;
	int attack();
	void takeDamage(int damage);
};

bool marineAlive(Marine * squadArr, size_t arrSize);

