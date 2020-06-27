#include "Bug.h"
Bug::Bug(int id, pair<int, int> position, int direction, int size, bool alive, list<pair<int, int>> path)
{

    this->id = id;
    this->position = position;
    this->direction = direction;
    this->size = size;
    this->alive = true;
    this->path.push_back(this->position);
}

int Bug::getId()
{
    return this->id;
}
string Bug::getPair()
{
    return '(' + this->position.first +"" + ',' + this->position.second + ')';
}
string Bug::getDirection()
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
int Bug::getSize()
{
    return this->size;
}
string Bug::getAlive()
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


//std::ostream& operator<<(std::ostream& ost, Bug& v)
//{
//    return NULL;
//}
