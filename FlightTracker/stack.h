#ifndef STACK_H
#define STACK_H

#include "node.h"
#include "linkedlist.h"

using namespace std;

class Stack
{

private:
    int count;
    Node* top;
public:
    Stack();

    void push(string&, string&, double&);
    void pop();

    void output(ofstream&);

    int size();
    bool is_empty();

    bool if_exists(string&);

    void clear();

    ~Stack();
};

#endif // STACK_H

