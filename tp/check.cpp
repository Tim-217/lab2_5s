#include "check.h"

int check_input() {
    int val;
    while (true) {
        cin >> val;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "������������ ����! ����������, ������� �����: " << endl;
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return val;
        }
    }
}

bool exist_date(int* bd) {
	if (bd[2] <= 0) {
		cout << "������ � ����! ��������� ��������� ������ � ���������� ��� ���." << endl;
		return false;
	}
	else if (bd[1] <= 0) {
		cout << "������ � ����! ��������� ��������� ������ � ���������� ��� ���." << endl;
		return false;
	}
	else if (bd[1] <= 7) {
		if (bd[1] % 2 == 1) {
			if (bd[0] > 0 && bd[0] <= 31) {
				return true;
			}
			else {
				cout << "������ � ����! ��������� ��������� ������ � ���������� ��� ���." << endl;
				return false;
			}
		}
		else {
			if (bd[1] == 2) {
				if (bd[2] % 4 == 0) {
					if (bd[0] > 0 && bd[0] <= 29) {
						return true;
					}
					else {
						cout << "������ � ����! ��������� ��������� ������ � ���������� ��� ���." << endl;
						return false;
					}
				}
				else {
					if (bd[0] > 0 && bd[0] < 29) {
						return true;
					}
					else {
						cout << "������ � ����! ��������� ��������� ������ � ���������� ��� ���." << endl;
						return false;
					}
				}
			}
			else {
				if (bd[0] > 0 && bd[0] <= 30) {
					return true;
				}
				else {
					cout << "������ � ����! ��������� ��������� ������ � ���������� ��� ���." << endl;
					return false;
				}
			}
		}
	}
	else if (bd[1] <= 12) {
		if (bd[1] % 2 == 1) {
			if (bd[0] > 0 && bd[0] < 31) {
				return true;
			}
			else {
				cout << "������ � ����! ��������� ��������� ������ � ���������� ��� ���." << endl;
				return false;
			}
		}
		else {
			if (bd[0] > 0 && bd[0] <= 31) {
				return true;
			}
			else {
				cout << "������ � ����! ��������� ��������� ������ � ���������� ��� ���." << endl;
				return false;
			}
		}
	}
	else {
		cout << "������ � ����! ��������� ��������� ������ � ���������� ��� ���." << endl;
		return false;
	}
}

void check_date(int* bd) {
    while (true) {
        if (exist_date(bd)) {
            break;
        }
        else {
            cout << "������� ����: ";
            bd[0] = check_input();
            cout << "������� �����: ";
            bd[1] = check_input();
            cout << "������� ���: ";
            bd[2] = check_input();
        }
    }
}