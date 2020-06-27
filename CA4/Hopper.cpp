#include "Hopper.h"

Hopper::Hopper(int id, pair<int, int> position, int direction, int size, bool alive, list<pair<int, int>> path, int hopLength) : Bug(id, position, direction, size, alive, path), hopLength(hopLength)
{
	this->hopLength = hopLength;
};


int Hopper::getId()
{
    return this->id;
}
string Hopper::getPair()
{
    std::stringstream ss;
    string s;
    ss << '(' << this->position.first << ',' << this->position.second << ')';
    ss >> s;
    return s;
}
string Hopper::getDirection()
{
    switch (this->direction)
    {
    case 1:
        return "North";
    case 2:
        return "East";
    case 3:
        return "South";
    case 4:
        return "West";
    }
}
int Hopper::getSize()
{
    return this->size;
}
string Hopper::getAlive()
{
    if (this->alive)
    {
        return "alive";
    }
    else
    {
        return "dead";
    }
}

void Hopper::move()
{
    switch (this->direction)
    {
    case 1:
        this->position.second -= this->hopLength;
        this->path.push_back(this->position);
        break;
    case 2:
        this->position.first += this->hopLength;
        this->path.push_back(this->position);
        break;
    case 3:
        this->position.second += this->hopLength;
        this->path.push_back(this->position);
        break;
    case 4:
        this->position.first -= this->hopLength;
        this->path.push_back(this->position);
        break;
    }
}

//std::ostream& operator<<(std::ostream& Str, Hopper& v) {
//
//    Str << v.toString();
//
//    return Str;
//};
