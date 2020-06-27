#include "Crawler.h"

Crawler::Crawler(int id, pair<int, int> position, int direction, int size, bool alive, list<pair<int, int>> path) : Bug(id, position, direction, size, alive, path)
{

}
int Crawler::getId()
{
    return this->id;
}
string Crawler::getPair()
{
    std::stringstream ss;
    string s;
    ss << '(' << this->position.first << ',' << this->position.second << ')';
    ss >> s;
    return s;
}
string Crawler::getDirection()
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
int Crawler::getSize()
{
    return this->size;
}
string Crawler::getAlive()
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

void Crawler::move()
{
    switch (this->direction)
    {
    case 1:
        this->position.second -= 1;
        this->path.push_back(this->position);
        break;
    case 2:
        this->position.first += 1;
        this->path.push_back(this->position);
        break;
    case 3:
        this->position.second += 1;
        this->path.push_back(this->position);
        break;
    case 4:
        this->position.first -= 1;
        this->path.push_back(this->position);
        break;
    }
}
//std::ostream& operator<<(std::ostream& Str, Crawler& v) {
//   
//    Str << v.toString();
//
//   return Str;
//};
