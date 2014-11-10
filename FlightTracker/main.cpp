#include "linkedlist.h"
#include "stack.h"


void read_flightData(LinkedList& flights, ifstream& input)
{
    int numberOfFlights;
    double cost;
    string origin, destination;
    //LinkedList flights;

    while(!input.eof())
    {
        input >> numberOfFlights;
        input.ignore();
        for(int i = 0; i < numberOfFlights; i++)
        {
            getline(input, origin, ',');
            if(flights.has_origin(origin) == false)
                flights.insert_origin(origin);
            input.ignore();
            getline(input, destination, ',');
            input.ignore();
            input >> cost;
            if(flights.has_origin(origin) == true && flights.has_destination(origin, destination, cost) == false)
                flights.insert_destination(origin, destination, cost);
            input.ignore();
        }
    }
    flights.display_map();
    cout << endl;
}

void read_requests(LinkedList& flights, Stack& flight_stack, ifstream& request_input, ofstream& output)
{
    int numberOfRequests;
    string origin, destination;
    double totalCost = 0.0;
    bool found = false;

    cout << "\n\nRequests:" << endl;
    while(!request_input.eof())
    {
        request_input >> numberOfRequests;
        request_input.ignore();
        for(int i = 0; i < numberOfRequests; i++)
        {
            getline(request_input, origin, ',');
            request_input.ignore();
            getline(request_input, destination);
            cout << origin << " to " << destination << endl;

            output << "Flight " << i + 1 << ": " << origin << " to " << destination << endl;
            found = flights.search_requests(origin, destination, totalCost, flight_stack, output);

            flight_stack.output(output);

            if(found == false)
                output << "Flight not possible." << endl;
            else
                output << "Total Cost: $" << fixed << setprecision(2) << totalCost << endl;

            output << endl;
            totalCost = 0.0;

            flight_stack.clear();
        }
    }
}

int main(int argc, char *argv[])
{
    LinkedList flights;
    Stack flight_stack;

    ifstream input, request_input;
    input.open(argv[1]);
    request_input.open(argv[2]);

    ofstream output;
    output.open(argv[3]);

    read_flightData(flights, input);
    read_requests(flights, flight_stack, request_input, output);


    return 0;
}
