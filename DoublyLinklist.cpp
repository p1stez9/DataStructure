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

class LinkList {
    public:
        Node *head;
        Node *tail;
        LinkList() {
            this->head = NULL;
            this->tail = NULL;
        }

        void addAtBeginning(int data) {
            Node *temp = new Node(data);
            if(!head) {
                head = temp;
                tail = temp;
            } else {
                temp->next = head;
                head->prev = temp;
                head = temp;
            }
        }

        void addAtEnd(int data) {
            Node *temp = new Node(data);
            if(!head) {
                head = temp;
                tail = temp;
            } else {
                tail->next = temp;
                temp->prev = tail;
                tail = temp;
            }
        }

        void deleteAtbeginning() {
            if(!head) {
                return;
            }
            if(head == tail) {
                delete head;
                head = NULL;
                tail = NULL;
            } else {
                Node *temp = head;
                head = head->next;
                head->prev = NULL;
                delete temp;
            }
        }

        void deleteAtend() {
            if(!head) {
                return;
            }
            if(head == tail) {
                delete tail;
                head = NULL;
                tail = NULL;
            } else {
                Node *temp = tail;
                tail = tail->prev;
                tail->next = NULL;
                delete temp;
            }
        }

        void printList() {
            if(!head) {
                cout << "List is empty\n";
                return;
            }
            Node *temp = head;
            while(temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};

int main() {
    LinkList *l = new LinkList();
    l->addAtBeginning(1); // 1
    l->addAtBeginning(3); // 3 1
    l->addAtEnd(0); // 3 1 0
    l->addAtBeginning(6); // 6 3 1 0
    l->printList(); // 6 3 1 0

    l->deleteAtend(); // 6 3 1
    l->printList(); // 6 3 1
    
    l->deleteAtbeginning(); // 3 1
    l->printList(); // 3 1
}