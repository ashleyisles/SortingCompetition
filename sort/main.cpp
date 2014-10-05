//ASHLEY ISLES AND RYAN EDSON
//Due: October 5, 2014
//Program 3: Ready, Set, Sort!
//This program uses a sorting algorithm to sort words in a text file.


#include <algorithm>
#include <fstream>
#include <iostream>
#include <chrono>
#include <ctime>
#include <cstring> 
#include <iomanip>
#include <string>
#include <vector>
#include "sortingcompetition.h"

using namespace std;

int main(int argc, char *argv[])
{

    SortingCompetition* run = new SortingCompetition(argv[1]);
    string outputFile = "";

    run->readData();
    run->prepareData();

    //Time Sort Function

    chrono::time_point<chrono::system_clock> start, end;

    start = chrono::system_clock::now();
    run->sortData();
    end = chrono::system_clock::now();

    chrono::duration<double> elapsed_seconds = end-start;
    time_t end_time = chrono::system_clock::to_time_t(end);

    cout << "\nfinished computation at " << ctime(&end_time) << "elapsed time: " << fixed << elapsed_seconds.count() << "s\n";
    run->outputData(argv[2]);

}

