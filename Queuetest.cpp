#include <bits/stdc++.h>
using namespace std;
#define SIZE 1024

class Queue {
    public:
        int front;
        int rear;
        int arr[SIZE];
        Queue() {
            front = 0;
            rear = -1;
        }

        bool full() {
            if(rear == SIZE - 1) {
                return true;
            }
            return false;
        }

        bool empty() {
            if(front > rear) {
                return true;
            }
            return false;
        }

        void enqueue(int data) {
            if(full()) {
                cout << "Queue is full" << endl;
            } else {
                rear++;
                arr[rear] = data;
            }
        }

        int dequeue() {
            if(empty()) {
                cout << "Queue is empty" << endl;
                return -1;
            } else {
                return arr[front++];
            }
        }

        void printList() {
            for(int i = front ; i <= rear ; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main() {
    Queue q;
    char ch;
    do {
        cin >> ch;
        if(ch == 'e') {
            int num;
            cin >> num;
            q.enqueue(num);
        } else if(ch == 'd') {
            cout << q.dequeue() << endl;
        } else if(ch == 'p') {
            q.printList();
        } else if(ch == 'n') {
            cout << q.rear + 1 << endl;
        } else if(ch == 's') {
            cout << q.arr[q.front] << " " << q.arr[q.rear] << endl;
        }
    } while(ch != 'x');
}
