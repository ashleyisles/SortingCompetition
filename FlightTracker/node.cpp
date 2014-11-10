#include "node.h"


Node::Node()
{
    next = prev = down = NULL;
}

Node::Node(string& source)
{
    cityName = source;
    next = prev = down = NULL;
}

Node::Node(string& city, double& price)
{
    cityName = city;
    cost = price;
    next = prev = down = NULL;
}

Node::Node(string& origin, string& destination, double& price)
{
    this -> origin = origin;
    cityName = destination;
    cost = price;
    next = prev = down = NULL;
}


string Node::get_origin()
{
    return origin;
}

string Node::get_destination()
{
    return cityName;
}

double Node::get_cost()
{
    return cost;
}

Node::~Node()
{
    //destructor
}
