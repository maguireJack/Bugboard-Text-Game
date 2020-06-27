#pragma once
#include "Bug.h"
class Hopper : public Bug
{
public:
	int hopLength;
	
	Hopper(int id, pair<int, int> position, int direction, int size, bool alive, list<pair<int, int>> path, int hopLength);
	
	virtual void toString()
	{
		cout << "Hopper " << this->getId() << "," << this->getPair() << "," << this->getSize() << "," << this->getDirection() << "," << this->getAlive() << endl;
	};
	virtual void showLife()
	{
		list<pair<int, int>>::iterator i;
		cout << "Hopper " << this->getId() << " Path: ";
		for (i = path.begin(); i != path.end(); ++i)
		{
			cout << '(' << i->first << ',' << i->second << ')';
		}
		cout << endl;
	};
	virtual int getId();
	virtual string getPair();
	virtual string getDirection();
	virtual int getSize();
	virtual string getAlive();
	virtual void move();
	

private:
	friend std::ostream& operator<<(std::ostream&, Hopper const& v);

};

