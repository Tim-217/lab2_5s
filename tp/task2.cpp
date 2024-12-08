#include "task2.h"

TextFilter::TextFilter() : source(""), FlagT(false) {
    cout << "Вызван конструктор без параметров для класса TextFilter." << endl;
}
TextFilter::TextFilter(const string& filename): source(filename), FlagT(false) {
    cout << "Вызван конструктор с параметрами для класса TextFilter." << endl;
}
TextFilter::TextFilter(const string& text, bool t): source(text), FlagT(t) {
    cout << "Вызван конструктор с параметрами для класса TextFilter." << endl;
}
TextFilter::TextFilter(const TextFilter& other) : source(other.source), FlagT(other.FlagT) {
    cout << "Вызван конструктор копирования для класса TextFilter." << endl;
}
TextFilter::~TextFilter() {
    cout << "Вызван деструктор для класса TextFilter." << endl;
}

bool TextFilter::check_first_char(const string& word) {
    char first_char = word[0];
    if (first_char == 'a' || first_char == 'e' || first_char == 'i' || first_char == 'o' || first_char == 'u' || first_char == 'y')
        return 1;
    else 
        return 0;
}

void TextFilter::output() {
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
        cout << modifiedLine << endl;
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
            cout << modifiedLine << endl;
        }
        file.close();
    }   
}