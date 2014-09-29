#ifndef SORTINGCOMPETITION_H
#define SORTINGCOMPETITION_H

#include <string>

using namespace std;

class SortingCompetition
{
private:
     string inputName;
     string outputName;
public:
    SortingCompetition(const string& inputFileName);
    void setFileName(const string& inputFileName);
    bool readData();
    bool prepareData();
    void sortData();
    void outputData(const string& ouputFileName);
};

#endif // SORTINGCOMPETITION_H
