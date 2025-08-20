#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
        Node(int data) {
            this->data = data;
            next = NULL;
        }
};

class Linklist {
    public:
        Node *head;
        Linklist() {
            head = NULL;
        }

        void insertAtBeginning(int data) {
            Node *newNode = new Node(data);
            newNode->next = head;
            head = newNode;
            printList();
            return;
        }

        void insertAtEnd(int data) {
            Node *newNode = new Node(data);
            if(!head) {
                head = newNode;
                printList();
                return;
            }
            Node *temp = head;
            while(temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
            printList();
            return;
        }

        bool check(int id) {
            Node *temp = head;
            while(temp != NULL) {
                if(temp->data == id) {
                    cout << "Duplicate data, not inserted.\n";
                    return true;
                }
                temp = temp->next;
            }
            return false;
        }

        void insertBefore(int data,int id) {
            Node *newNode = new Node(data);
            if(check(data)) {
                return;
            }
            if(!head) {
                head = newNode;
                printList();
                return;
            }
            if(head->data == id) {
                newNode->next = head;
                head = newNode;
                printList();
                return;
            }
            Node *temp = head;
            while(temp ->next != NULL && temp->next->data != id) {
                temp = temp->next;
            }
            if(temp->next == NULL) {
                temp->next = newNode;
                printList();
                return;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            printList();
            return;
        }

        void insertAfter(int data,int id) {
            Node *newNode = new Node(data);
            if(check(data)) {
                return;
            }
            if(!head) {
                head = newNode;
                printList();
                return;
            }
            Node *temp = head;
            while(temp->next != NULL && temp->data != id) {
                temp = temp->next;
            }
            if(temp->next == NULL) {
                temp->next = newNode;
                printList();
                return;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            printList();
            return;
        }

        void DeleteAtBeginning() {
            if(!head) {
                printList();
                return;
            }
            if(head->next == NULL) {
                delete head;
                head = NULL;
                printList();
                return;
            }
            Node *temp = head;
            head = head->next;
            delete temp;
            printList();
        }

        void DeleteAtEnd() {
            if(!head) {
                printList();
                return;
            }
            if(head->next == NULL) {
                delete head;
                head = NULL;
                printList();
                return;
            }
            Node *temp = head;
            while(temp->next->next != NULL) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = NULL;
            printList();
        }

        void printList() {
            Node *temp = head;
            while(temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};

int main() {
    Linklist myList;

    myList.insertAtBeginning(10);   // 10
    myList.insertAtBeginning(20);   // 20 10
    myList.insertAtEnd(30);         // 20 10 30
    myList.insertBefore(15, 10);    // 20 15 10 30
    myList.insertAfter(25, 10);     // 20 15 10 25 30
    myList.DeleteAtBeginning();     // 15 10 25 30
    myList.DeleteAtEnd();           // 15 10 25

    return 0;
}
