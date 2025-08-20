#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
        Node *prev;
        Node(int data) {
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
};

class doublyLinkList {
    public:
        Node *head;
        Node *tail;

        doublyLinkList() {
            head = NULL;
            tail = NULL;
        }

        void insertAtBeginning(int data) {
            Node *temp = new Node(data);
            if (!head) {
                head = temp;
                tail = temp;
                head->next = head;
                head->prev = head;
            } else {
                temp->next = head;
                temp->prev = tail;
                head->prev = temp;
                tail->next = temp;
                head = temp;
            }
        }

        void insertAtEnd(int data) {
            Node *temp = new Node(data);
            if (!head) {
                head = temp;
                tail = temp;
                head->next = head;
                head->prev = head;
            } else {
                tail->next = temp;
                temp->prev = tail;
                temp->next = head;
                head->prev = temp;
                tail = temp;
            }
        }

        void deleteAtbeginning() {
            if (!head) {
                return;
            }
            if (head == tail) {
                delete head;
                head = NULL;
                tail = NULL;
            } else {
                Node *temp = head;
                head = head->next;
                head->prev = tail;
                tail->next = head;
                delete temp;
            }
        }

        void deleteAtend() {
            if (!head) return;
            if (head == tail) {
                delete tail;
                head = NULL;
                tail = NULL;
            } else {
                Node *temp = tail;
                tail = tail->prev;
                tail->next = head;
                head->prev = tail;
                delete temp;
            }
        }

        void printList() {
            if (!head) {
                cout << "List is empty\n";
                return;
            }
            Node *temp = head;
            do {
                cout << temp->data << " ";
                temp = temp->next;
            } while (temp != head);
            cout << endl;
        }

        void printReverse() {
            if (!tail) {
                cout << "List is empty\n";
                return;
            }
            Node *temp = tail;
            do {
                cout << temp->data << " ";
                temp = temp->prev;
            } while (temp != tail);
            cout << endl;
        }
};

int main() {
    doublyLinkList *l = new doublyLinkList();
    l->insertAtBeginning(1);
    l->insertAtBeginning(3);
    l->insertAtEnd(0);
    l->insertAtBeginning(6);
    l->printList();       // ควรแสดง: 6 3 1 0
    l->printReverse();    // ควรแสดง: 0 1 3 6
}
