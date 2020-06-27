#pragma once
#include "Bug.h"

class Crawler : public Bug
{
public:
	virtual void move();
	Crawler(int id, pair<int, int> position, int direction, int size, bool alive, list<pair<int, int>> path);
	virtual void toString()
	{
		cout << "Crawler " << this->getId() << "," << this->getPair() << "," << this->getSize() << "," << this->getDirection() << "," << this->getAlive() << endl;
	};
	virtual void showLife()
	{
		list<pair<int, int>>::iterator i;
		cout << "Crawler " << this->getId() << " Path: ";
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

private:
	friend std::ostream& operator<<(std::ostream&, Crawler const& v);


	

};



