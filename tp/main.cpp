#include "note.h"
#include "task2.h"
#include "keeper.h"
#include "check.h"

void menu() {
    cout << "\n===== Меню задания 1 =====" << endl;
    cout << "1. Добавить элемент" << endl;
    cout << "2. Удалить элемент" << endl;
    cout << "3. Редактировать элемент" << endl;
    cout << "4. Показать все элементы" << endl;
    cout << "5. Сортировать элементы по алфавиту" << endl;
    cout << "6. Поиск по месяцу рождения" << endl;
    cout << "0. Выйти" << endl;
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
            cout << "Введите номер элемента который хотите изменить: ";
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
            cout << "Список отсортирован по алфавиту." << endl;
            N.print_keeper();
            break;
        }
        case 6: {
            cout << "Введите месяц: ";
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
        cout << "Выберите источник (1 - строка, 2 - файл): ";
        if (!(cin >> choice)) {
            throw invalid_argument("Ошибка: некорректный ввод выбора источника.");
        }
        if (choice == 1) {
            cin.ignore();
            char text[8192];
            cout << "Введите текст: ";
            cin.getline(text, sizeof(text));

            if (cin.fail()) {
                throw overflow_error("Ошибка: превышена максимальная длина текста.");
            }

            TextFilter filter(text, true);
            filter.output();
        }
        else if (choice == 2) {
            char filename[256];
            cout << "Введите имя файла: ";
            cin >> filename;
            ifstream file(filename);
            if (!file) {
                throw runtime_error("Ошибка: файл не найден или не может быть открыт.");
            }
            file.close();
            TextFilter filter(filename);
            filter.output();
        }
        else {
            throw out_of_range("Ошибка: выбран несуществующий источник.");
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
        cerr << "Произошла неизвестная ошибка." << endl;
        return -1;
    }
    return 0;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int choice;
    while (true) {
        cout << "Выберите номер задания:" << endl;
        cout << "1 - Стандартные потоки" << endl;
        cout << "2 - Файловые и строковые потоки" << endl;
        cout << "0 - Выход" << endl;
        choice = check_input();

        switch (choice) {
        case 1:
            program1();
            break;
        case 2:
            program2();
            break;
        case 0:
            cout << "Завершение работы." << endl;
            return 0;
        default:
            cout << "Неверный выбор! Попробуйте снова." << endl;
            break;
        }
    }
}