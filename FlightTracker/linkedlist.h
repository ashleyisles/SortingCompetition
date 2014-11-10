#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"
#include "stack.h"

class Stack;

using namespace std;
class LinkedList
{

friend class Stack;

private:

    Node* head;
    Node* tail;

public:

    LinkedList();
    LinkedList(string &);

    void append(string&, string&, double&);
    void insert_origin(string &);
    void insert_destination(string &, string &, double &);

    Node* at(int);

    void display_map();
    void output(ofstream&);

    bool has_origin(string&);
    bool has_destination(string &, string &, double &);

    bool search_requests(string &, string &, double &, Stack &, ofstream &);

    ~LinkedList();
};


#endif // LINKEDLIST_H

