#include "note.h"
#include "task2.h"
#include "keeper.h"
#include "check.h"

void menu() {
    cout << "\n===== ���� ������� 1 =====" << endl;
    cout << "1. �������� �������" << endl;
    cout << "2. ������� �������" << endl;
    cout << "3. ������������� �������" << endl;
    cout << "4. �������� ��� ��������" << endl;
    cout << "5. ����������� �������� �� ��������" << endl;
    cout << "6. ����� �� ������ ��������" << endl;
    cout << "0. �����" << endl;
}

int program1() {
    Keeper N;
    int choice;

    while (true) {
        menu();
        choice = check_input();

        switch (choice) {
        case 1: {
            try {
                N++;
            }
            catch (const out_of_range& e) {
                cout << e.what() << endl;
            }
            break;
        }
        case 2: {
            try {
                N--;
            }
            catch (const out_of_range& e) {
                cout << e.what() << endl;
            }
            break;
        }
        case 3: {
            int n;
            cout << "������� ����� �������� ������� ������ ��������: ";
            n = check_input();
            try {
                N.edit_element(n);
            }
            catch (const out_of_range& e) {
                cout << e.what() << endl;
            }
            break;
        }
        case 4: {
            N.print_keeper();
            break;
        }
        case 5: {
            N.sort();
            cout << "������ ������������ �� ��������." << endl;
            N.print_keeper();
            break;
        }
        case 6: {
            cout << "������� �����: ";
            int mounth;
            mounth = check_input();
            N.search_element(mounth);
            break;
        }
        case 0: {
            cout << "Exit." << endl;
            return 0;
        }
        default: {
            break;
        }
        }
    }

    return 0;
}

int program2() {
    try {
        int choice;
        cout << "�������� �������� (1 - ������, 2 - ����): ";
        if (!(cin >> choice)) {
            throw invalid_argument("������: ������������ ���� ������ ���������.");
        }
        if (choice == 1) {
            cin.ignore();
            char text[8192];
            cout << "������� �����: ";
            cin.getline(text, sizeof(text));

            if (cin.fail()) {
                throw overflow_error("������: ��������� ������������ ����� ������.");
            }

            TextFilter filter(text, true);
            filter.output();
        }
        else if (choice == 2) {
            char filename[256];
            cout << "������� ��� �����: ";
            cin >> filename;
            ifstream file(filename);
            if (!file) {
                throw runtime_error("������: ���� �� ������ ��� �� ����� ���� ������.");
            }
            file.close();
            TextFilter filter(filename);
            filter.output();
        }
        else {
            throw out_of_range("������: ������ �������������� ��������.");
        }
    }
    catch (const invalid_argument& e) {
        cerr << e.what() << endl;
        return 1;
    }
    catch (const overflow_error& e) {
        cerr << e.what() << endl;
        return 2;
    }
    catch (const runtime_error& e) {
        cerr << e.what() << endl;
        return 3;
    }
    catch (const out_of_range& e) {
        cerr << e.what() << endl;
        return 4;
    }
    catch (...) {
        cerr << "��������� ����������� ������." << endl;
        return -1;
    }
    return 0;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int choice;
    while (true) {
        cout << "�������� ����� �������:" << endl;
        cout << "1 - ����������� ������" << endl;
        cout << "2 - �������� � ��������� ������" << endl;
        cout << "0 - �����" << endl;
        choice = check_input();

        switch (choice) {
        case 1:
            program1();
            break;
        case 2:
            program2();
            break;
        case 0:
            cout << "���������� ������." << endl;
            return 0;
        default:
            cout << "�������� �����! ���������� �����." << endl;
            break;
        }
    }
}