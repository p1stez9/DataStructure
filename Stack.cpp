#include <bits/stdc++.h>
#define MAXSIZE 100
using namespace std;

class Stack {
    public:
        int top;
        int arr[MAXSIZE];
        Stack() {
            top = -1;
        }

        void push(int data) {
            if(full()) {
                cout << "Stack overflow : " << endl;
            } else {
                top++;
                arr[top] = data;
            }
        }

        int pop() {
            if(empty()) {
                cout << "Stack Underflow" << endl;
                return 0;
            } else {
                int data = arr[top--];
                return data;
            }
        }

        bool full() {
            if(top >= MAXSIZE - 1) {
                return true;
            }
            return false;
        }

        bool empty() {
            if(top < 0) {
                return true;
            }
            return false;
        }
        
};

int main() {
    Stack s;
    string str;
    cin >> str;
    for(int i = 0 ; i < str.length() ; i++) {
        if(str[i] == '(') {
            s.push(str[i]);
        } else if(str[i] == ')') {
            if(s.empty()) {
                cout << "Error";
                return 0;
            }
            s.pop();
        }
    }
    if(s.empty()) {
        cout << "Pass";
        return 0;
    }
    cout << "Error";
    return 0;
}