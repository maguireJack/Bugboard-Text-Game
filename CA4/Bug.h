#pragma once
using namespace std;
#include <iostream>
#include <list>
#include <sstream>

class Bug {
protected:
    int id;
    pair<int, int> position;
    int direction;
    int size;
    bool alive;
    list<pair<int, int>> path;
    
    
    //virtual bool isWayBlocked() {};
    
    Bug(int id, pair<int, int>position, int direction, int size, bool alive, list<pair<int,int>>path);
    

public:
    friend std::ostream& operator<<(std::ostream&, Bug const& v);
    virtual void toString() = 0;
    virtual int getId() = 0;
    virtual string getPair() = 0;
    virtual string getDirection() = 0;
    virtual int getSize() = 0;
    virtual string getAlive();
    virtual void move() = 0;
    virtual void showLife() = 0;
    

};