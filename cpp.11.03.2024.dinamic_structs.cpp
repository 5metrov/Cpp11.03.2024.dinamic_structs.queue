#include <iostream>
#include <vector>
using namespace std;
//список, стек, кольцевой буфер, бинарное дерево
/*
взаимодействия с дин. структурами
1)добавление в конец или начало
2) добавление в середину
3) удаление из конца/начала
4) поиск элемента
O(1) - операция проходящее за "константное время", происходит если вы знаете где находится элемент и что с ним сделать
О(N) - элемент находится за столько операций, сколько элементов в структуре (n - колличество элеменетов)
O(logn) - колво операций будет расти с колличеством элементов, но далеко не так сильно
O(n^2) - вложеный цикл
O(n!) - перебор пароля, колво операций сильно увеличивается по сравлению с колличеством элементов*/

//список(очередь) - самая быстрая вставка в конец/начало или удаление из конца/начала. очередь можно сравнить с трубой
//каждый элемент в очереде знает кто стоит за ним и перед ним(в двунаправленной очереди. в однонаправленной видим только впередистоящего)

/*Работа с списком состоит из:
1) описания отдельной Node
2) описать операции*/
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
        Node* node = new Node(data);
        node->next = head;
        head = node;
        if (tail == NULL) tail = node;
    }

    void push_back(int data) {
        Node* node = new Node(data);
        if (head == NULL) {
            head = node;
        }
        if (tail != NULL) {
            tail->next = node;
        }
        tail = node;
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
                tmp_node = head->next;
            }
            else { break; }
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

int main(){
    setlocale(LC_ALL, "ru");
    srand(time(0));
    osn0();
    return 0;
}
