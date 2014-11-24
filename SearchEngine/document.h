#ifndef DOCUMENT_H
#define DOCUMENT_H


#include <string>
#include <vector>

using namespace std;

class Document
{

private:
    string title, timestamp, contributor;
    string text;
    int id;
public:
    Document();

    string get_title();
    string get_contributor();
    string get_text();
    string get_timestamp();
    int get_id();

    void set_contributor(string&);
    void set_title(string&);
    void set_timestamp(string&);
    void set_text(string&);
    void set_id(int&);

    ~Document();
};

#endif // DOCUMENT_H
