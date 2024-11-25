#include "note.h"
NOTE::NOTE() :FIO(""), tel("") { 
	for (int i = 0; i < 3; i++)
		birthday[i] = 0;
	cout << "Вызван конструктор без параметров для объекта класса NOTE\n"; 
}
NOTE::NOTE(const string& f, const string& t, int* b) :FIO(f), tel(t) {
	for (int i = 0; i < 3; i++)
		birthday[i] = b[i];
	cout << "Вызван конструктор с параметрами для объекта класса NOTE\n";
}
NOTE::NOTE(const NOTE& tmp) :FIO(tmp.FIO), tel(tmp.tel) {
	for (int i = 0; i < 3; i++)
		birthday[i] = tmp.birthday[i];
	cout << "Вызван конструктор копирования для объекта класса NOTE\n";
}
NOTE::~NOTE() { cout << "Вызван деструктор для объекта класса NOTE\n"; }

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
	cout << "Фамилия и имя: " << get_FIO() << endl;
	cout << "Номер телефона: " << get_tel() << endl;
	cout << "Дата рождения: " << get_birthday(0) << "." << get_birthday(1) << "." << get_birthday(2) << endl;
}
void NOTE::edit_note() {
	int choice;
	cout << "Выберите, что хотите изменить:\n";
	cout << "1. Фамилию и имя\n";
	cout << "2. Номер телефона\n";
	cout << "3. Дата рождения\n";
	cout << "Введите ваш выбор: ";
	cin >> choice;

	switch (choice) {
	case 1: {
		string new_fio;
		cout << "Введите фамилию и имя: ";
		cin.ignore();
		getline(cin, new_fio);
		set_FIO(new_fio);
		break;
	}
	case 2: {
		string new_tel;
		cout << "Введите номер телефона: ";
		cin.ignore();
		getline(cin, new_tel);
		set_tel(new_tel);
		break;
	}
	case 3: {
		int bd[3];
		cout << "Введите день рождения: ";
		cin >> bd[0];
		cout << "Введите месяц рождения: ";
		cin >> bd[1];
		cout << "Введите месяц рождения: ";
		cin >> bd[2];
		if (bd[2] <= 0) { cout << "Ошибка в дате! Проверьте указанные данные и попробуйте ещё раз." << endl; break; }
		else if (bd[1] <= 0) { cout << "Ошибка в дате! Проверьте указанные данные и попробуйте ещё раз." << endl; break; }
		else if (bd[1] <= 7) {
			if (bd[1] % 2 == 1) {
				if (bd[0] > 0 && bd[0] <= 31) set_birthday(bd);
				else { cout << "Ошибка в дате! Проверьте указанные данные и попробуйте ещё раз." << endl; break; }
			}
			else {
				if (bd[1] == 2) {
					if (bd[2] % 4 == 0) {
						if (bd[0] > 0 && bd[0] <= 29) set_birthday(bd);
						else { cout << "Ошибка в дате! Проверьте указанные данные и попробуйте ещё раз." << endl; break; }
					}
					else {
						if (bd[0] > 0 && bd[0] < 29) set_birthday(bd);
						else { cout << "Ошибка в дате! Проверьте указанные данные и попробуйте ещё раз." << endl; break; }
					}
				}
				else {
					if (bd[0] > 0 && bd[0] <= 30) set_birthday(bd);
					else { cout << "Ошибка в дате! Проверьте указанные данные и попробуйте ещё раз." << endl; break; }
				}
			}
		}
		else if (bd[1] <= 12) {
			if (bd[1] % 2 == 1) {
				if (bd[0] > 0 && bd[0] < 31) set_birthday(bd);
				else { cout << "Ошибка в дате! Проверьте указанные данные и попробуйте ещё раз." << endl; break; }
			}
			else {
				if (bd[0] > 0 && bd[0] <= 31) set_birthday(bd);
				else { cout << "Ошибка в дате! Проверьте указанные данные и попробуйте ещё раз." << endl; break; }
			}
		}
		else { cout << "Ошибка в дате! Проверьте указанные данные и попробуйте ещё раз." << endl; break; }
		set_birthday(bd);
		break;
	}
	default:
		cout << "Неверный выбор!" << endl;
	}
}