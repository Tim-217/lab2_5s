#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cctype>
#include <string>

using namespace std;

class SentenceFilter {
private:
    string source;
    bool FlagT;
public:
    SentenceFilter();
    SentenceFilter(const string& filename);
    SentenceFilter(const string& text, bool t);
    SentenceFilter(const SentenceFilter& other);
    ~SentenceFilter();

    bool check_first_char(const string& word);
    void output();
};