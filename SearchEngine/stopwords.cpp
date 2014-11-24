#include "stopwords.h"

StopWords::StopWords()
{

}

//vector<string> StopWords::get_stoplist(const string& stop_words)
//{
//    input.open(stop_words);
//    string word;
//    while(!input.eof())
//    {
//        input >> word;
//        cout << word;
//        words_list.push_back(word);
//    }
//    return words_list;
//}

//void StopWords::remove_stops(Document& doc)
//{
//    vector<string> temp_list;
//    for(int i = 0; i < words_list.size(); i++)
//    {
//        temp_list = words_list[i];
//    }
//}

StopWords::~StopWords()
{
    //destructor
}
