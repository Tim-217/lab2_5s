#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cctype>
#include <string>

using namespace std;

class TextFilter {
private:
    string source;
    bool FlagT;
public:
    TextFilter();
    TextFilter(const string& filename);
    TextFilter(const string& text, bool t);
    TextFilter(const TextFilter& other);
    ~TextFilter();

    bool check_first_char(const string& word);
    void output();
};