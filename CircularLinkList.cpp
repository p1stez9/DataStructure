#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
        Node(int data) {
            this->data = data;
            this->next = NULL;
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

        void insertAtbeginning(int data) {
            Node *temp = new Node(data);
            if(!head) {
                head = temp;
                tail = temp;
                tail->next = head;
            } else {
                temp->next = head;
                head = temp;
                tail->next = head;
            }
        }
        
        void insertAtend(int data) {
            Node *temp = new Node(data);
            if(!head) {
                head = temp;
                tail = temp;
            } else {
                tail->next = temp;
                tail = temp;
                tail->next = head;
            }
        }

        void deleteAtBeginning() {
            if(!head) {
                return;
            }
            if(head == tail) {
                delete head;
                head = tail = NULL;
            } else {
                Node *temp = head;
                head = head->next;
                tail->next = head;
                delete temp;
            }
        }

        void deleteAtend() {
            if(!head) {
                return;
            }
            if(head == tail) {
                delete tail;
                head = tail = NULL;
            } else {
                Node *temp = tail;
                while(temp->next != tail) {
                    temp = temp->next;
                }
                temp->next = head;
                delete tail;
                tail = temp;
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
        }while (temp != head);
            cout << endl;
        }
};

int main() {
    LinkList *l = new LinkList();
    l->insertAtbeginning(1); // 1
    l->insertAtbeginning(2); // 2 1
    l->insertAtend(3); // 2 1 3
    l->deleteAtBeginning(); // 1 3
    l->deleteAtend(); // 1
    l->printList();
}