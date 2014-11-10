#include "stack.h"

Stack::Stack()
{
    top = NULL;
}

void Stack::push(string& origin, string& destination, double& price)
{
    Node* curr = new Node(origin, destination, price);

    if(top == NULL)
    {
        top = curr;
        count++;
    }
    else
    {
        curr -> next = top;
        top = curr;
        count++;
    }
}

void Stack::output(ofstream& out)
{
    Node* curr = top;
    LinkedList myList;
    string originName, destination;
    double price = 0.0;

    if(top == NULL)
    {
        return;
    }

    while(curr != NULL)
    {
        originName = curr -> get_origin();
        destination = curr -> get_destination();
        price = curr -> get_cost();

        myList.append(originName, destination, price);
        cout << "hi!" << endl;
        curr = curr -> next;
    }
    myList.output(out);
}

bool Stack::if_exists(string& destination)
{
    Node* curr = top;
    if(curr == NULL)
    {
        return false;
    }
    while(curr != NULL)
    {
        if(curr -> origin == destination)
        {
            return true;
        }
        curr = curr -> next;
    }
    return false;
}

void Stack::pop()
{
    Node* curr = top;
    if(count == 0)
    {
        cout << "Stack is empty!" << endl;
        return;
    }
    else
    {
        top = top -> next;
        count--;
        delete curr;
    }

}

int Stack::size()
{
    return count;
}

bool Stack::is_empty()
{
    if(count == 0)
        return true;
    return false;
}

void Stack::clear()
{
    Node* curr = top;
    while (curr != NULL)
    {
        top = top -> next;
        delete curr;
        curr = top;
    }
    top = NULL;

}

Stack::~Stack()
{
    clear();
}

