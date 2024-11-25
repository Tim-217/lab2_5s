#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class NOTE {
private:
	string FIO;
	string tel;
	int birthday[3];
public:
	NOTE();
	NOTE(const string& FIO, const string& tel, int* birthday);
	NOTE(const NOTE& tmp);
	~NOTE();

	void set_FIO(const string& FIO);
	void set_tel(const string& tel);
	void set_birthday(int* birthday);

	string get_FIO();
	string get_tel();
	int get_birthday(int i);

	void print_note();
	void edit_note();
};