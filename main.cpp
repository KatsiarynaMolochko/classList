#include <iostream>
using namespace std;


class List {
private:
    struct node {
        int  item;
        struct node* next = nullptr;
    };
    struct node* head = nullptr;
public:
    List() {
        head = nullptr;
    }

    List(const List& lst) {
        node* current = lst.head;
        insertItem(current->item);

        while (current->next != nullptr) {
            current = current->next;
            insertItem(current->item);
        }
    }

    ~List() {
        while(head) {
            del();
        }

        delete head;
    }

    void show() {
        node* current = head;
        while (current) {
            cout << current->item << "\n";
            current = current->next;
        }
    }

    void insertItem(const int& n) {
        if (head) {
            node* current = head;
            while (current->next) {
                current = current->next;
            }
            node* next = new node{ n,nullptr };
            current->next = next;
        }
        else {
            head = new node{ n,nullptr };
        }
    }

    int del() {
        if (head) {
            node* current = head;
            node* prev = current;

            while (current->next) {
                prev = current;
                current = current->next;
            }

            int x = current->item;

            if (current != prev) {
                delete current;
                prev->next = nullptr;
            } else {
                delete current;
                head = nullptr;
            }

            return x;
        }

        return -1;
    }

    bool isEmpty() {
        return head;
    };



};

int main() {
    List lst;
    lst.insertItem(5);
    lst.insertItem(10);
    lst.insertItem(15);
    lst.insertItem(25);

    List lst2(lst);

    lst.show();
    cout << "\n\n";
    lst2.show();

    lst.del();
    cout << "\n\n";
    lst.show();

    lst.del();
    lst.del();
    lst.del();
    cout << "\n\n";
    lst.show();

    return 0;
}