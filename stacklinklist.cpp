#include <bits/stdc++.h>
using namespace std;

class node {
    public:
        int data;
        node *next;
        node(int data) {
            this->data = data;
            next = NULL;
        }
};

class Stack {
    public:
        node *top;

        Stack() {
            top = NULL;
        }

        bool empty() {
            return top == NULL;
        }

        void push(int data) {
            node *newNode = new node(data);
            newNode->next = top;
            top = newNode;
        }

        int pop() {
            if (empty()) {
                cout << "Stack Underflow!" << endl;
                return -1;
            }
            node *temp = top;
            int val = temp->data;
            top = top->next;
            delete temp;
            return val;
        }

        int peek() {
            if (empty()) {
                cout << "Stack is empty!" << endl;
                return -1;
            }
            return top->data;
        }

        void printList() {
            for (node *list = top; list != NULL; list = list->next) {
                cout << list->data << " ";
            }
            cout << endl;
        }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.printList();
    cout << "Peek: " << s.peek() << endl;
    cout << "Pop: " << s.pop() << endl;
    cout << "Pop: " << s.pop() << endl;
    s.printList();
    return 0;
}
