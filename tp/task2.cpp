#include "task2.h"

SentenceFilter::SentenceFilter() : source(""), FlagT(false) {
    cout << "Вызван конструктор без параметров для класса SentenceFilter\n";
}
SentenceFilter::SentenceFilter(const string& filename): source(filename), FlagT(false) {
    cout << "Вызван конструктор с параметрами для класса SentenceFilter\n";
}
SentenceFilter::SentenceFilter(const string& text, bool t): source(text), FlagT(t) {
    cout << "Вызван конструктор с параметрами для класса SentenceFilter\n";
}
SentenceFilter::SentenceFilter(const SentenceFilter& other) : source(other.source), FlagT(other.FlagT) {
    cout << "Вызван конструктор копирования для класса SentenceFilter\n";
}
SentenceFilter::~SentenceFilter() {
    cout << "Вызван деструктор для класса SentenceFilter\n";
}

bool SentenceFilter::check_first_char(const string& word) {
    char first_char = word[0];
    if (first_char == 'a' || first_char == 'e' || first_char == 'i' || first_char == 'o' || first_char == 'u' || first_char == 'y')
        return 1;
    else 
        return 0;
}

void SentenceFilter::output() {
    if (FlagT) { //для строки
        string text = source;
        stringstream ss(text);
        string word;
        string modifiedLine;

        while (ss >> word) { //читаем каждое слово
            if (check_first_char(word)) {
                word[0] = toupper(word[0]); //заменяем первую букву на прописную
            }
            modifiedLine += word + " "; //собираем строку с изменениями
        }
        cout << modifiedLine << std::endl;
    }
    else { //для файла
        ifstream file(source);
        if (!file.is_open()) {
            cerr << "The file couldn't be opened: " << source << endl;
            return;
        }
        string line;
        while (getline(file, line)) { //читаем файл построчно
            stringstream ss(line);
            string word;
            string modifiedLine;

            while (ss >> word) {
                if (check_first_char(word)) {
                    word[0] = toupper(word[0]);
                }
                modifiedLine += word + " ";
            }
            cout << modifiedLine << std::endl;
        }
        file.close();
    }   
}