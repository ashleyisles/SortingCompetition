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
    inputName = inputFileName;
}

bool SortingCompetition::readData()
{
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
    for(int i = 0; i < wordsList.size(); i++) {
        sortList.push_back(wordsList[i]);
    }

    for(int x = 0; x < sortList.size(); x++)
    {
        for(int y = 0; y < sortList[x].size(); y++)
        {
            sortList[x][y] = tolower(sortList[x][y]);
        }
    }
}

void SortingCompetition::sortData()
{
    string temp;
    for(int i = 0; i < sortList.size(); i++)
    {
        for(int j = 0; j < sortList.size(); j++)
        {
            if(sortList[j].size() >= sortList[i].size() && sortList[j] >= sortList[i])
            {
                //if(sortList[j] > sortList[i])
                //{
                    temp = sortList[i];
                    sortList[i] = sortList[j];
                    sortList[j] = temp;
                //}
            }

        }
        /*for(j = i; j < sortList.size()-i-1; j++)
        {
            if(strlen(names[i]) > strlen(names[j+1]))
            {
                temp=names[i];
                names[i]=names[j+1];
                names[j+1]=temp;
            }
        }*/
        //I stole this from Yahoo Answers, it's supposed to sort by length. I'm not sure how to implement it in our function though. Good luck, god speed.
    }

    for(int x = 0; x < sortList.size(); x++)
        cout << sortList[x] << " " << endl;
}

void SortingCompetition::outputData(const string& outputFileName)
{
    ofstream output;
    output.open(outputFileName);

    for(int i = 0; i < sortList.size(); i++)
       output << sortList[i] << " ";

}



