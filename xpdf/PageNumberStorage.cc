#include "PageNumberStorage.h"
#include <iostream>
#include <fstream>
#include <map>
using namespace std;
static map<string, int> pages;
static  string current_document;

string& current_filename()
{
    return current_document;
}

int& current_page()
{
    string& filename = current_filename();
    if(not pages.count(filename))
        pages[filename] = 1;

    return pages[filename];
}

void save_page_numbers(const string& filename)
{
    if(pages.empty())
        return;
    ofstream f(filename.c_str(), ios_base::trunc);
    for(map<string, int>::const_iterator i = pages.begin(); i != pages.end(); i++)
        f << i->first << " " << i->second << "\n";
}

void load_page_numbers(const string& filename)
{
    ifstream f(filename.c_str());
    while(f.good()){
        string line;
        getline(f, line);
        if(line.empty())
            continue;
        size_t count_pos = line.rfind(' ');
        if(count_pos == string::npos)
            continue;
        pages[line.substr(0, count_pos)] = atoi(line.substr(count_pos).c_str());
    }
}
