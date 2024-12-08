#include "note.h"
#include "check.h"
NOTE::NOTE() :FIO(""), tel("") { 
	for (int i = 0; i < 3; i++)
		birthday[i] = 0;
	cout << "������ ����������� ��� ���������� ��� ������� ������ NOTE\n"; 
}
NOTE::NOTE(const string& f, const string& t, int* bd) :FIO(f), tel(t) {
	check_date(bd);
	set_birthday(bd);
	cout << "������ ����������� � ����������� ��� ������� ������ NOTE\n";
}
NOTE::NOTE(const NOTE& tmp) :FIO(tmp.FIO), tel(tmp.tel) {
	for (int i = 0; i < 3; i++)
		birthday[i] = tmp.birthday[i];
	cout << "������ ����������� ����������� ��� ������� ������ NOTE\n";
}
NOTE::~NOTE() { cout << "������ ���������� ��� ������� ������ NOTE\n"; }

void NOTE::set_FIO(const string& fio) { this->FIO = fio; }
void NOTE::set_tel(const string& t) { this->tel = t; }
void NOTE::set_birthday(int* bd) {
	for (int i = 0; i < 3; i++)
		this->birthday[i] = bd[i];
}

string NOTE::get_FIO() { return this->FIO; }
string NOTE::get_tel() { return this->tel; }
int NOTE::get_birthday(int i) { return this->birthday[i]; }

void NOTE::print_note() {
	cout << "������� � ���: " << get_FIO() << endl;
	cout << "����� ��������: " << get_tel() << endl;
	cout << "���� ��������: " << get_birthday(0) << "." << get_birthday(1) << "." << get_birthday(2) << endl;
}
void NOTE::edit_note() {
	int choice;
	cout << "��������, ��� ������ ��������:\n";
	cout << "1. ������� � ���\n";
	cout << "2. ����� ��������\n";
	cout << "3. ���� ��������\n";
	cout << "������� ��� �����: ";
	choice = check_input();

	switch (choice) {
	case 1: {
		string new_fio;
		cout << "������� ������� � ���: ";
		cin.ignore();
		getline(cin, new_fio);
		set_FIO(new_fio);
		break;
	}
	case 2: {
		string new_tel;
		cout << "������� ����� ��������: ";
		cin.ignore();
		getline(cin, new_tel);
		set_tel(new_tel);
		break;
	}
	case 3: {
		int bd[3];
		cout << "������� ���� ��������: ";
		cin >> bd[0];
		cout << "������� ����� ��������: ";
		cin >> bd[1];
		cout << "������� ��� ��������: ";
		cin >> bd[2];
		check_date(bd);
		set_birthday(bd);
	}
	default:
		break;
	}
}