#ifndef XMLPARSER_H
#define XMLPARSER_H

#include "pugixml.hpp"
#include "document.h"
#include "avlindex.h"
#include <iostream>
#include <locale>
#include <sstream>
//#include <fstream>

using namespace pugi;

class XMLParser
{
private:
    string title, contributor, file_name, timestamp, word, id_name;
    string text;
    int id;

public:
    XMLParser(const string&);

    void set_name(const string&);
    void parse_file();
    void is_alpha_space(locale&);
    ~XMLParser();
};

#endif // XMLPARSER_H
