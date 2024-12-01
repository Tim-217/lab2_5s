#include "note.h"

struct Element {
	Element* next;
	NOTE* data;
};

class Keeper {
private:
	Element* head;
	Element* tail;
	int count;
public:
    Keeper();
    Keeper(Element* h, Element* t, int c);
    Keeper(Keeper& other);
    ~Keeper();

    Element* get_head();
    Element* get_tail();
    int get_count();

    void add_element(NOTE* el, int n);
    Keeper& delete_element(int n);
    Keeper& edit_element(int n);

    void search_element(int mounth);
    void print_keeper();
    void sort();

    Keeper& operator++(int);
    Keeper& operator--(int);
};