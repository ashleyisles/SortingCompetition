#include "linkedlist.h"

LinkedList::LinkedList()
{
    //Initializes head and tail pointers to NULL
    head = tail = NULL;
}

LinkedList::LinkedList(string& source)
{
    //Creates new Node with string value passed in
    head = tail = new Node(source);
}

void LinkedList::display_map()
{
    //Display adjacency list
    Node *origin = head;
    Node *dest = head;
    while(origin != NULL)
    {
       cout << origin -> cityName << ": ";
       while(dest -> next != NULL)
       {
           cout << dest -> next -> cityName << " ";
           dest = dest -> next;
       }
       origin = origin -> down;
       dest = origin;
       cout << endl;
    }
}

void LinkedList::append(string& originName, string& destination, double& price)
{
    Node* temp = new Node(originName, destination, price);
    if(head == NULL)
        head = tail = temp;
    else
    {
        tail -> next = temp;
        temp -> prev = tail;
        tail = temp;
    }
}

void LinkedList::insert_destination(string &origin, string &destination, double &price)
{
    //Insert new destination city

    Node* curr = head;
    if(curr == NULL)
        cout << "Error in memory allocation.";
    else
    {
        while(curr != NULL)
        {
            if(curr -> cityName == origin)
            {
                while(curr -> next != NULL)
                    curr = curr -> next;
                curr -> next = new Node(origin, destination, price);
            }
            curr = curr -> down;
        }
    }
}

void LinkedList::insert_origin(string& val)
{
    //Insert new origin city
    Node* curr = head;

    if(curr == NULL)
        head = new Node(val);
    else
    {
        while(curr -> down != NULL)
            curr = curr -> down;
        curr -> down = new Node(val);
    }

}

bool LinkedList::has_origin(string& originName)
{
    Node* curr = head;

    if(curr == NULL)
        return false;
    while(curr != NULL)
    {
        if(curr -> cityName == originName)
            return true;
        curr = curr -> down;
    }
    return false;
}

bool LinkedList::has_destination(string& originName, string& destName, double& cost)
{
    Node* curr = head;

    while(curr != NULL)
    {
        if(curr -> cityName == originName)
        {
            curr = curr -> next;
            insert_destination(originName, destName, cost);
            return true;
        }
        curr = curr -> down;
    }
    return false;
}

bool LinkedList::search_requests(string &origin, string &destination, double &totalCost, Stack &flight_stack, ofstream &output)
{
    double currentCost = 0.0;
    string dest_asOrigin;
    Node* origin_node = head;

    if(origin_node == NULL) //If there is no such origin city
        return false;
    while(origin_node != NULL)
    {
        if(origin == origin_node -> cityName)
        {
            Node* destination_node = origin_node;
            destination_node = destination_node -> next;

            while(destination_node != NULL)
            {
                currentCost = destination_node -> cost;
                dest_asOrigin = destination_node -> cityName;

                bool onStack = flight_stack.if_exists(dest_asOrigin);

                if(destination == destination_node -> cityName && onStack == false) //If destination is found
                {
                    totalCost += destination_node -> cost;
                    flight_stack.push(origin, dest_asOrigin, currentCost);
                    return true;
                }
                else if(destination != destination_node -> cityName && onStack == false)
                {
                    flight_stack.push(origin, dest_asOrigin, currentCost);
                    bool found = search_requests(dest_asOrigin, destination, totalCost, flight_stack, output);

                    if(found == true)
                    {
                            totalCost += destination_node -> cost;
                            return true;
                    }
                    else if(found == false)
                    {
                        flight_stack.pop();
                    }

                }
                destination_node = destination_node -> next;
            }
        }
        origin_node = origin_node -> down;
    }
    return false;
}

void LinkedList::output(ofstream& out)
{
    int leg = 0;
    Node* listCurr = tail;

    while(listCurr != NULL)
    {
        leg++;
        out << "Leg " << leg << ": " << listCurr -> origin << " to " << listCurr -> cityName << " $" << fixed << setprecision(2) << listCurr -> cost << endl;
        listCurr = listCurr -> prev;
    }
}


LinkedList::~LinkedList()
{
    //destructor
}

