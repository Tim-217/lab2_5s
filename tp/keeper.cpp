#include "keeper.h"
#include <windows.h>

Keeper::Keeper() : head(nullptr), tail(nullptr), count(0) { cout << "������ ����������� ������ Keeper\n"; }
Keeper::Keeper(Element* h, Element* t, int c) : head(h), tail(t), count(c) { cout << "������ ����������� � ����������� ������ Keeper\n"; }
Keeper::Keeper(Keeper& other) : head(other.head), tail(other.tail), count(other.count) { cout << "������ ����������� ����������� ������ Keeper\n"; }
Keeper::~Keeper() { 
    while (head != nullptr) {
        Element* tmp = head;
        head = head->next;
        delete tmp->data;
        delete tmp;
    }
    tail = nullptr;
    count = 0;
	cout << "������ ���������� ������ Keeper\n"; 
}

Element* Keeper::get_head() { return this->head; }
Element* Keeper::get_tail() { return this->tail; }
int Keeper::get_count() { return count; }

void Keeper::add_element(NOTE* el, int n) {
    if (n < 1 || n > count+1)
        throw out_of_range("Index out of range");

    Element* el_to_add = new Element;
    el_to_add->data = el;
    el_to_add->next = nullptr;

    if (n == 1) {
        el_to_add->next = head;
        head = el_to_add;
        if (count == 0) {
            tail = el_to_add;
        }
    }
    else {
        Element* prev = head;
        for (int i = 1; i < n-1; ++i) {
            prev = prev->next;
        }
        el_to_add->next = prev->next;
        prev->next = el_to_add;
        if (el_to_add->next == nullptr) {
            tail = el_to_add;
        }
    }
    count++;
}
Keeper& Keeper::delete_element(int n) {
    if (n < 1 || n > count)
        throw out_of_range("Index out of range");
    
    Element* el_to_del = head;
    if (n == 1) {
        head = head->next;
        delete el_to_del->data;
        delete el_to_del;
        if (head == nullptr)
            tail = nullptr;
    }
    else{
        Element* prev = nullptr;
        for (int i = 1; i < n; i++) {
            prev = el_to_del;
            el_to_del = el_to_del->next;
        }
        prev->next = el_to_del->next;
        if (el_to_del == tail) {
            tail = prev;
        }
        delete el_to_del->data;
        delete el_to_del;
    }
    count--;
    cout << "�� ������� ���� �������." << endl;
    return *this;
}
Keeper& Keeper::edit_element(int n) {
    if (n < 1 || n > count)
        throw out_of_range("Index out of range");
    
    Element* tmp = head;
    for (int i = 1; i < n; i++) {
        tmp = tmp->next;
    }
    if (tmp->data) {
        tmp->data->edit_note();
    }
    else {
        cout << "������ � ������� �������� ���." << endl;
    }
    return *this;
}

void Keeper::search_element(int mounth) { 
    if (mounth < 1 || mounth>12) {
        cout << "������: �� ����� �������������� �����. ����������, ��������� ������." << endl;
        return;
    }
    Element* tmp = head;
    while (tmp != nullptr) {
        if (tmp->data->get_birthday(1) == mounth) {
            tmp->data->print_note();
            return;
        }
        tmp = tmp->next;
    }
    cout << "��� �����, ���������� � ������ ������:  " << mounth << endl;
}
void Keeper::print_keeper() {
    Element* tmp = head;
    if (count == 0) {
        cout << "��������� ����." << endl;
        return;
    }
    int i = 1;
    while (tmp != 0) {
        cout << i << " - ";
        if (tmp->data) {
            tmp->data->print_note();
        }
        else {
            cout << "��������� ����.";
        }
        cout << " " << endl;
        tmp = tmp->next;
        i++;
    }
}
void Keeper::sort() {
    if (count < 2) return;

    for (Element* i = head; i != nullptr; i = i->next) {
        for (Element* j = head; j->next != nullptr; j = j->next) {
            if (j->data->get_FIO() > j->next->data->get_FIO()) {
                NOTE* temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
            }
        }
    }
}

Keeper& Keeper::operator++(int) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string fio, tel;
    int n, arr[3];
    cout << "������� ������� � ���: ";
    getline(cin, fio);
    cout << "������� ����� ��������: ";
    getline(cin, tel);
    cout << "������� ���� ��������: ";
    cin >> arr[0];
    cout << "������� ����� ��������: ";
    cin >> arr[1];
    cout << "������� ��� ��������: ";
    cin >> arr[2];
    NOTE* el = new NOTE(fio, tel, arr);
    cout << "������� �������, �� ������� ������ �������� �������: ";
    cin >> n;
    this->add_element(el, n);
    return *this;
}
Keeper& Keeper::operator--(int) {
    int n;
    cout << "������� ����� ��������, ������� ������ �������: ";
    cin >> n;
    this->delete_element(n);
    return *this;
}