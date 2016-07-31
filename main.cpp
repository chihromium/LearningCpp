//#include <iostream>
//
//using namespace std;
//
//int sum3(int lhs, int rhs) {
//    int h = 0xAC;
//    int i = 0xAB;
//    int j = 0xAA;
//    return lhs + rhs + h + i + j;
//}
//
//int main(int argc, char* argv[])
//{
//    int i = 0xAE;
//    int j = 0xAD;
//    int k = sum3(i, j);
//    cout << k << " hahaha\n";
//    return 0;
//}

#include <iostream>

using namespace std;

struct node {
    node* prev;
    node* next;
    int value;

    node(int value): value(value) {}
};

struct list {
    node* head;
    node* tail;
    int _size;

    list(): head(0), tail(0), _size(0) {}

//    ~list(){
//        node* new_node = head;
//        for (int i = 0; i < _size; ++i) {
//            node* next_new_node = new_node;
//            delete new_node;
//            new_node = next_new_node->next;
//        }
//    }

    ~list() {
        node* new_node = head;
        while (new_node) {
            node* next_new_node = new_node;
            delete new_node;
            new_node = next_new_node->next;
            //cout << "delete element from list \n";
        }
    }

    void push_back(int value) {
        node* p_new_node = new node(value);
        if (head == 0) {
            head = tail = p_new_node;
        } else {
            tail->next = p_new_node;
            p_new_node->prev = tail;
            tail = p_new_node;
        }
        ++_size;
    }


    void push_front(int value) {
        node* p_new_node = new node(value);
        if (head == 0) {
            head = tail = p_new_node;
        } else {
            head->prev = p_new_node;
            p_new_node->next = head;
            head = p_new_node;
        }
        ++_size;
    }

    void print() {
        for(node* p_node = head; p_node != 0; p_node = p_node->next) {
            cout << p_node->value << '\n';
        }
    }

    int pop_front() {
        if (_size == 0) {
            throw string("try to pop from empty list");
        }
        int result = head->value;
        head = head->next;
        if (head != 0) {
            delete head->prev;
            head->prev = 0;
        } else {
            tail = 0;
        }
        --_size;
        return result;
    }

    int pop_back() {

        int result = tail->value;
        tail = tail->prev;
        if (tail != 0) {
            delete tail->next;
            tail->next = 0;
        } else {
            head = 0;
        }
        --_size;
        return result;
    }

    int get(int pos) {
        node* g_node = head;
        for (int i = 0; i < pos; ++i) {
                g_node = g_node->next;
        }
        return g_node->value;
    }

    int size() {
        return _size;
    }
};

int main() {
    list l;
    l.push_back(1);
    //l.print();
    l.push_back(2);
    //l.print();
    l.push_front(3);
    cout << "l.get(2) = " << l.get(2) << "\n";
    cout << "l.pop_back() = " << l.pop_back() << "\n";
    cout <<  "l.pop_front() = " << l.pop_front() << "\n";
    l.print();
//    l.pop_front();
//    try {
//        l.pop_front();
//    } catch(string& ex) {
//        cout << "exception occured: " << ex << "\n";
//        return -1;
//    }
    cout << "l.size() = " << l.size() << "\n";
    return 0;
}
