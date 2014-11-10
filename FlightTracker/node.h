#ifndef NODE_H
#define NODE_H

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

class Node
{

friend class LinkedList;
friend class Stack;

private:

    string cityName, origin;
    double cost;

    Node* next;
    Node* prev;
    Node* down;

public:
    Node();

    Node(string&);
    Node(string&, double&);
    Node(string&, string&, double&);


    string get_origin();
    string get_destination();
    double get_cost();

    ~Node();
};

#endif // NODE_H
