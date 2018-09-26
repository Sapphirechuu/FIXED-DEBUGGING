#pragma once

class Zergling //: public Entity
{
public:
	Zergling();
	~Zergling();

	bool isAlive = true;
	int health;
	int attack();
	void takeDamage(int damage);
};

bool zerglingAlive(Zergling * swarmArr, size_t arrSize);