#include "xmlparser.h"

XMLParser::XMLParser(const string& input_name)
{
    set_name(input_name);
}

void XMLParser::set_name(const string& input_name)
{
    file_name = input_name;
}

void XMLParser::parse_file()
{
    AVLIndex idx;
    xml_document doc;
    xml_parse_result result = doc.load_file(file_name.c_str());
    //locale loc;

    if(!result)
    {
        cerr << "File not found." << endl;
        return;
    }

    Document* doc_ptr = new Document;
    //StopWords get_stops;
    vector<Document*> doc_list;
    int i = 0, count = 0;

    xml_node beginning = doc.child("mediawiki");
    for(xml_node first_node = beginning.first_child(); first_node; first_node = first_node.next_sibling())
    {
        if(first_node.value())
        {
            title = first_node.child_value("title");
            doc_ptr -> set_title(title);
            title.clear();
        }

        if(first_node.child("revision"))
        {
            for(xml_node inner_node = first_node.first_child(); inner_node; inner_node = inner_node.next_sibling())
            {
                if(inner_node.child("timestamp"))
                {
                    timestamp = inner_node.child_value("timestamp");
                    doc_ptr -> set_timestamp(timestamp);
                    timestamp.clear();
                }

                if(inner_node.child("id"))
                {

                    id_name = inner_node.child_value("id");
                    const char* temp = id_name.c_str();
                    id = atoi(temp);

                    doc_ptr -> set_id(id);
                }

                if(inner_node.child("contributor"))
                {
                    for(xml_node inside_node = inner_node.first_child(); inside_node; inside_node = inside_node.next_sibling())
                    {
                        if(inside_node.child("username"))
                        {
                            contributor = inside_node.child_value("username");
                            doc_ptr -> set_contributor(contributor);
                            contributor.clear();
                        }
                    }
                }

                if(inner_node.child("text"))
                {
//                    vector<char*> text_list;
//                    char* temp, *buff;
                    text = inner_node.child_value("text");
//                    temp = new char[text.size()];
//                    strcpy(temp, text.c_str());
//                    temp[text.size()] = '\0';
//                    buff = strchr(temp, ' ');
//                    while(buff != NULL)
//                    {
//                        *buff = '\0';
//                        text_list.push_back(temp);
//                        buff = strchr(temp+1, ' ');
//                        temp = buff+1;
//                    int i = 0;
//                    while(temp != NULL)
//                    {
//                        if(*temp == ' ')
//                        {
//                            *temp++ = '\0';
//                            text_list.push_back(buff);
//                            buff = temp;

//                        }
//                        cout << text_list[i] << " ";
//                        i++;

//                    }
                    doc_ptr -> set_text(text);
                    text.clear();
                }
            }
        }

        doc_list.push_back(doc_ptr);
        //cout << "\nDocument Title: " << doc_list[i] -> get_title() << "\nContributor: " << doc_list[i] -> get_contributor() << "\nID Number: " << doc_list[i] -> get_id() << "\nTimestamp: " << doc_list[i] -> get_timestamp() << "\nText: " << doc_list[i] -> get_text() << endl << endl << endl << endl;
        //string temp_title = doc_list[i] -> get_title();
        stringstream tempTitle(doc_list[i]->get_title());

        while (tempTitle.good()) {

            char *cstr;
            string single;
            getline(tempTitle, single, ' ');
            cstr = new char[single.length() + 1];
            strcpy(cstr, single.c_str());

            idx.insertWord(cstr, doc_list[i] -> get_id());
        }


        //idx.insertWord(temp_title, doc_list[i] -> get_id());

        cout << "\n\nCOUNT!!! " << count << endl << endl;
        count++;

        if (count == 80000) {
            break;
        }

    }
//    cout << "Total Number of Documents: " << count << endl;
    idx.print(idx.head);
    //cout << "Total Number of Documents: " << count << endl;
}


XMLParser::~XMLParser()
{

}
