// A Debugging Exercise by Marc Chee (marcc@aie.edu.au)
// 18/12/2016

// Marines are trying to "de-bug" an area (haha . . . haha)
// However something's up with this code . . . figure out what's going wrong
// When you're finished, there should be no compiler errors or warnings
// The encounter should also run and finish correctly as per the rules in the comments

// In many cases there are differences between what's in otherwise identical sections
// for Marines and Zerglings. It's good to be able to tell what the differences are
// and why they might be important.

// What's efficient and inefficient? Why?
// What uses more memory and what doesn't? Why?

// Last modified by Terry Nguyen (terryn@aie.edu.au)
// 10/09/2018

#include <iostream>
#include "Marine.h"
#include "Zergling.h"


using std::cout;
using std::endl;

int main()
{
	Marine squad[10];
	Zergling swarm[20];

	int squadSize = 10;
	int swarmSize = 20;
	cout << "A squad of marines approaches a swarm of Zerglings and opens fire!\nThe Zerglings charge!" << endl;
	_sleep(1000);
	cout << "There are " << squadSize << " Marine(s) and " << swarmSize << " Zergling(s)." << endl;
	_sleep(1000);
	cout << "Marines start with " << squad->health << " health and Zerglings will start with " << swarm->health << " health." << endl;
	// Attack each other until only one team is left alive
	while ((marineAlive(squad, squadSize)) && (zerglingAlive(swarm, swarmSize))) // If anyone is left alive to fight . . .
	{
		if (marineAlive(squad, squadSize)) // if there's at least one marine alive
		{
			for (int i = 0; i < squadSize; ++i) // go through the squad
			{
				if (squad[i].isAlive)
				{
					if (!zerglingAlive(swarm, swarmSize))
					{
						break;
					}
					// each marine will attack the first zergling in the swarm
					_sleep(1000);
					cout << "Marine " << i + 1 << " fires for " << squad[i].attack() << " damage.\n" << endl;
					for (int i = 0; i < swarmSize; ++i)
					{
						if (swarm[i].isAlive)
						{
							int damage = squad[i].attack();
							swarm[i].takeDamage(damage);
							_sleep(1000);
							cout << "Zergling " << i + 1 << " has " << swarm[i].health << " health left!\n" << endl;
							//cout << swarm[i].health << endl;
							if (!swarm[i].isAlive)
							{
								_sleep(1000);
								cout << "The zergling target dies" << endl;
							}
							break;
						}
					}
				}
			}
		}
		if (zerglingAlive(swarm, swarmSize)) // if there's at least one zergling alive
		{
			for (int i = 0; i < swarmSize; ++i) // loop through zerglings
			{
				if (swarm[i].isAlive)
				{
					if (!marineAlive(squad, squadSize))
					{
						break;
					}
					_sleep(1000);
					cout << "Zergling " << i + 1 << " attacks for " << swarm[i].attack() << " damage.\n" << endl;
					for (int i = 0; i < squadSize; ++i)
					{
						if (squad[i].isAlive)
						{
							int damage = swarm[i].attack();
							squad[i].takeDamage(damage);
							_sleep(1000);
							cout << "Marine " << i + 1 << " has " << squad[i].health << " health left!\n" << endl;
							//cout << squad[i].health << endl;
							if (!squad[i].isAlive)
							{
								_sleep(1000);
								cout << "The marine succumbs to his wounds." << endl;
							}
							break;
						}
					}
				}	
			}
		}
	}

	// Once one team is completely eliminated, the fight ends and one team wins
	_sleep(1000);
	cout << "The fight is over. ";
	if (marineAlive(squad, squadSize))
	{
		cout << "The Marines win." << endl;
	} else 
	{
		cout << "The Zerg win." << endl;
	}
	cout << "Press Enter to quit" << endl;
	std::cin.get();
	return 0;
}

// Is there a Marine Alive?
bool marineAlive(Marine * squadArr, size_t arrSize)
{
	for (int i = 0; i < arrSize; ++i)
	{
		if (squadArr[i].isAlive)
		{
			return true;
		}
	}
	return false;
}

// Is there a zergling Alive:: loop through array to check each isAlive bool
bool zerglingAlive(Zergling * swarmArr, size_t arrSize)
{
	for (int i = 0; i < arrSize; ++i)
	{
		if (swarmArr[i].isAlive)
		{
			return true;
		}
	}
	return false;
}
