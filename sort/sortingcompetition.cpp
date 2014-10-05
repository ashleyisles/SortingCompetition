#include "sortingcompetition.h"
#include <string>
#include <iostream>
#include <fstream>


using namespace std;

SortingCompetition::SortingCompetition(const string& inputFileName)
{
    setFileName(inputFileName);
}

void SortingCompetition::setFileName(const string& inputFileName)
{
    //Sets input file name

    inputName = inputFileName;
}

bool SortingCompetition::readData()
{
    //Creates vector with wrods from file

    ifstream inputFile;
    inputFile.open("mobyDick.txt");
    if(!inputFile.is_open())
    {
        cerr << "Unable to open file.\n";
        return false;
    }
    else
    {
        while(inputFile >> word)
            wordsList.push_back(word);
        return true;
    }
    return true;

}

bool SortingCompetition::prepareData()
{

    //Copies contents of vector into separate vector
    for(int i = 0; i < wordsList.size(); i++) {
        sortList.push_back(wordsList[i]);
    }

    for(int x = 0; x < sortList.size(); x++)
    {
        //Lowercases all characters in each word so that words may be properly alphabetized
        for(int y = 0; y < sortList[x].size(); y++)
        {
            sortList[x][y] = tolower(sortList[x][y]);
        }
    }
}

void SortingCompetition::sortData()
{
    string temp;
    //Sorts words by length

    for(int i = 0; i < sortList.size(); i++)
    {
        for(int j = 1 + i; j < sortList.size(); j++)
        {
            if(sortList[j].size() < sortList[i].size())
            {
                temp = sortList[i];
                sortList[i] = sortList[j];
                sortList[j] = temp;
            }
            if(sortList[j].size() == sortList[i].size())
            {
                if(sortList[j] < sortList[i])
                {
                    temp = sortList[i];
                    sortList[i] = sortList[j];
                    sortList[j] = temp;
                }
            }
        }
    }
}

void SortingCompetition::outputData(const string& outputFileName)
{
    ofstream output;
    output.open(outputFileName);

    for(int i = 0; i < sortList.size(); i++)
       output << sortList[i] << " ";

}



