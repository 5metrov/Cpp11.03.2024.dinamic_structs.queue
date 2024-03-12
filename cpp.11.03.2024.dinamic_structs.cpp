#include <iostream>
#include <vector>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int _data): data(_data) {}
};

class OneLinkedList {
public:
    Node* head, * tail;

    OneLinkedList() {
        this->head = NULL;
        this->tail = NULL;
    }

    ~OneLinkedList() {

    }

    void push_front(int data) {
        Node* tmp_node = new Node(data);
        tmp_node->next = head;
        head = tmp_node;
        if (tail == NULL) tail = tmp_node;
    }

    void push_back(int data) {
        Node* tmp_node = new Node(data);
        if (head == NULL) {
            head = tmp_node;
        }
        if (tail != NULL) {
            tail->next = tmp_node;
        }
        tail = tmp_node;
    }

    void show_head() {
        cout << "Head: " << head->data << endl;
    }
    void show_tail() {
        cout << "Tail: " << tail->data << endl;
    }
    void show_all() {
        Node* tmp_node = head;
        while (true){
            if (tmp_node != NULL) {
                cout << tmp_node->data << ' '; 
                tmp_node = tmp_node->next;
            }
            else { break; }
        }
    }
    void pop_front() {
        Node* tmp_node = head;
        if (head == NULL) return;
        if (head == tail) {
            delete tail;
            head = tail = NULL;
            return;
        }

        head = tmp_node->next;
        delete tmp_node;
    }

    void pop_back() {
        if (tail == NULL) return;
        if (tail == head) {
            delete head;
            tail = head = NULL;
            return;
        }

        Node* tmp_node = tail;
        //не доделан
    }
};

class Nodee {
public:
    int data;
    Nodee* next;
    Nodee* prev;

    Nodee(int _data) : data(_data) {}
};

class TwoLinkedList {
public:
    Nodee* head, * tail;

    TwoLinkedList() {
        this->head = NULL;
        this->tail = NULL;
    }

    void push_front(int data) {
        Nodee* tmp_node = new Nodee(data);
        
        if (head != NULL) {
            tmp_node->next = head;
            head->prev = tmp_node;
        }
        else {
            tail = tmp_node;
        }
        head = tmp_node;
    }

    void push_back(int data) {
        Nodee* tmp_node = new Nodee(data);

        if (tail != NULL) {
            tmp_node->prev = tail;
            tail->next = tmp_node;
        }
        else {
            head = tmp_node;
        }

        tail = tmp_node;

    }

    void show_head() {
        cout << "Head: " << head->data << endl;
        cout << "(head)Prev from next: " << head->next->prev->data << endl;
    }

    void show_tail() {
        cout << "Tail: " << tail->data << endl;
        cout << "Tail prev: " << tail->prev->next->data << endl;
    }

    void pop_front() {
        Nodee* tmp_node = head;
        if (head == NULL) return;
        if (head == tail) {
            delete tail;
            head = tail = NULL;
            return;
        }

        head = tmp_node->next;
        head->prev = NULL;
        delete tmp_node;
    }

    void pop_back() {
        if (tail == NULL) return;
        if (tail == head) {
            delete head;
            tail = head = NULL;
            return;
        }

        Nodee* tmp_node = tail;
        tail = tmp_node->prev;
        tail->next = NULL;
        delete tmp_node;
    }

    void insert(int _data_prev, int data) {
        Nodee* tmp_node = head;
        while (true) {
            if (tmp_node->data == _data_prev) {
                cout << tmp_node->next->data << ' ';
                tmp_node = tmp_node->next;
            }
            else { break; }
        }
    }

    void show_from_head() {
        Nodee* tmp_node = head;
        while (true) {
            if (tmp_node != NULL) {
                cout << tmp_node->data << ' ';
                tmp_node = tmp_node->next;
            }
            else { cout << endl; break; }
        }
    }

    void show_from_tail() {
        Nodee* tmp_node = tail;
        while (true) {
            if (tmp_node != NULL) {
                cout << tmp_node->data << ' ';
                tmp_node = tmp_node->prev;
            }
            else { cout << endl; break; }
        }
    }
};

void osn0() {
    OneLinkedList list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);

    list.show_head();
    list.show_tail();

    list.show_all();
}

void osn1() {
    TwoLinkedList list;

    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_back(10);
    list.push_back(11);
    list.push_back(12);
    list.push_back(13);

    list.show_head();
    list.show_tail();

    list.show_from_head();
    list.show_from_tail();
}

int main(){
    setlocale(LC_ALL, "ru");
    srand(time(0));
    osn1();
    return 0;
}
