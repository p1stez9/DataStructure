#include <iostream>
using namespace std;
class Node{
    public:
        int data;
        Node *next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
};
class LinkedList{
    public:
        Node *head;
        LinkedList(){
            head = NULL;
        }
        bool check(int id){
           Node *ptr = head;
            while(ptr != NULL){
                if(ptr->data == id){
                    return true;
                }
                ptr = ptr->next;
            }
            return false;
        }
        void insert_before(int value , int id){
            if(check(value)){
                return;
            }
            Node *node = new Node(value);
            if(head == NULL){
                head = node;
                print();
                return;
            }
            if(head->data == id){
                node->next = head;
                head = node;
                print();
                return;
            }
            Node *ptr = head;
            while(ptr->next != NULL && ptr->next->data != id){
                ptr = ptr->next;
            }
            if(ptr->next == NULL){
                ptr->next = node;
                print();
                return;
            }
            node->next = ptr->next;
            ptr->next = node;
            print();
            return;
        }
        void print(){
            Node *ptr = head;
            while(ptr != NULL){
                cout << ptr->data << " ";
                ptr = ptr->next;
            }
            cout << endl;
        }
        void insert_after(int value , int id){
            if(check(value)){
                return;
            }
            Node* node = new Node(value);
            if(head == NULL){
                head = node;
                 print();
                return;
            }
            Node *ptr = head;
            while(ptr->next != NULL && ptr->data != id){
                ptr = ptr->next;
            }
            if(ptr->next == NULL){
                ptr->next = node;
                print();
                return;
            }
            node->next = ptr->next;
            ptr->next = node;
            print();
            return;
        }
        void Delete(int id){
            Node *temp;
            if(head->next == NULL){
                return;
            }
            if(head->data == id){
                temp = head;
                head = head->next;
                print();
                delete temp;
                return;
            }
            Node *ptr = head;
            while(ptr->next != NULL && ptr->next->data != id){
                ptr = ptr->next;
            }
            if(ptr->next == NULL){
                return;
            }
            temp = ptr->next;
            ptr->next = ptr->next->next;
            print();
            delete temp;
        }
};
int main(){
    LinkedList list;
    char sc;
    int id , val;
    while(true){
        cin >> sc;
        if(sc == 'A'){
            cin >> val;
            cin >> id;
            list.insert_after(val , id);
        }
        else if (sc == 'I'){
            cin >> val;
            cin >> id;
            list.insert_before(val , id);
        }else if(sc == 'E'){
            break;
        }else if(sc == 'D'){
            cin >> id;
            list.Delete(id);
        }
    }
}